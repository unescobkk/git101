<?php

/**
 * @file
 * Class definition of UnescoNewsNodeProcessor.
 */

/**
 * Creates nodes from feed items.
 */
class UnescoNewsNodeProcessor extends FeedsNodeProcessor {
  /**
   * Define entity type.
   */
  public function entityType() {
    return 'node';
  }

  /**
   * Creates a new node in memory and returns it.
   */
  protected function newEntity(FeedsSource $source) {
    $node = parent::newEntity($source);
    $node->type = 'article';
    return $node;
  }

  public function getMappingTargets() {
    $targets = parent::getMappingTargets();
    $targets += array(
      'categories' => array(
        'name' => t('Categories'),
        'description' => t('All categories, to be moved to proper taxonomy fields.'),
      ),
    );

    return $targets;
  }

  public function setTargetElement(FeedsSource $source, $target_entity, $target_element, $value) {
    switch ($target_element) {
      case 'categories':
        $target_entity->categories = $value;
        break;
      default:
        parent::setTargetElement($source, $target_entity, $target_element, $value);
        break;
    }
  }

  /**
   * Save a node.
   */
  public function entitySave($entity) {
    // If nid is set and a node with that id doesn't exist, flag as new.
    if (!empty($entity->nid) && !node_load($entity->nid)) {
      $entity->is_new = TRUE;
    }

    // Process categories
    if (!empty($entity->categories)) {
      if (is_array($entity->categories)) {
        $categories = $entity->categories;
      }
      else {
        $categories = array($entity->categories);
      }

      foreach ($categories as $category) {
        $category = trim($category);

        // Check block list (children from News item in the blocks_type
        // vocabulary - see admin/structure/taxonomy/blocks_type )
        $sql = "SELECT ttd.tid, ttd.vid FROM {taxonomy_term_data} ttd
          INNER JOIN {taxonomy_vocabulary} tv ON ttd.vid = tv.vid
          INNER JOIN {taxonomy_term_hierarchy} tth ON ttd.tid = tth.tid
          INNER JOIN {taxonomy_term_data} parent ON tth.parent = parent.tid
          WHERE ttd.name = :tname AND parent.name = 'News' AND tv.machine_name = 'blocks_type'";

        $block_list_term = db_query($sql, array(':tname' => $category))->fetchAssoc();
        if (!empty($block_list_term['tid'])) {
          $entity->field_block_list[LANGUAGE_NONE][] = array('tid' => $block_list_term['tid']);

          // [12:28:00 PM] Denis: it must be sticky=1 only for infocus
          if ($category == 'Infocus') {
            $entity->sticky = 1;
          // [25-01-13] Trujillo want infocus to be published manually
            $entity->status = 0;
            $entity->promoted = 0;
          }
          continue;
        }

        // ^ Note the continue; there.
        // Check country profile
        // [10:20:59 AM] felipe.eltermann: q3- country profile nodes are
        // translatable now. We are going to query the english field and find
        // the corresponding translation to that node. For instance, I'm
        // importing an article in french and find the category "Syrian Arab
        // Republic". I'll query the EN country profile node and then search the
        // french node associated to it to be referred.
        // If no french node is found, the english one will be used as a error
        // placeholder.
        $sql = "SELECT n.nid FROM {node} n INNER JOIN {field_data_field_short_name} fsn ON n.vid = fsn.revision_id WHERE n.type = 'country_profile' AND n.language = 'en' AND fsn.field_short_name_value = :countryname";
        $en_country_nid = db_query($sql, array(':countryname' => $category))->fetchField();
        if (!empty($en_country_nid)) {
          $sql = 'SELECT nid FROM {node} WHERE language = :lang AND tnid = :ennid'; 
          $tr_country_nid = db_query($sql, array(':lang' => $entity->language, ':ennid' => $en_country_nid))->fetchField();
          if (!empty($tr_country_nid)) {
            // translated node found!
            $country_nid = $tr_country_nid;
          }
          else {
            // fallback
            $country_nid = $en_country_nid;
          }

          $entity->field_country_reference[LANGUAGE_NONE][] = array('target_id' => $country_nid);
          continue;
        }

        // ^ Note the continue; there.
        // Check theme.
        // If a drupal theme has been specified in the news, then this code will set to the appropriate theme/subtheme page.
        // As in typo3 the classification is done only in english, we will have only english terms here
        $sql = "SELECT nid FROM node WHERE type = 'theme_page' AND language = 'en' and title = :themename";
        if ( $category == "One Planet" ) { 
          $category = 'One Planet, One Ocean'; 
        }
        $en_theme_nid = db_query($sql, array(':themename' => $category))->fetchField();
        if (!empty($en_theme_nid)){
          $sql = 'SELECT nid FROM {node} WHERE language = :lang AND tnid = :ennid'; 
          $tr_theme_nid = db_query($sql, array(':lang' => $entity->language, ':ennid' => $en_theme_nid))->fetchField();
          if (!empty($tr_theme_nid)) {
            // translated node found!
            $theme_nid = $tr_theme_nid;
          } else {
            // fallback
            $theme_nid = $en_theme_nid;
          }
          if (!empty($theme_nid)) {
            //drupal_set_message(t('category: %string.', array('%string' => $theme_nid)), 'error');
            $entity->field_theme_page[LANGUAGE_NONE][] = array ('target_id' => $theme_nid);
            continue;
          }
        }

        // ^ Note the continue; there.
        // Everything else is a tag
        $sql = "SELECT ttd.tid FROM {taxonomy_term_data} ttd
          INNER JOIN {taxonomy_vocabulary} tv ON ttd.vid = tv.vid
          WHERE ttd.name = :tname AND tv.machine_name = 'tags'";
        $tag_tid = db_query($sql, array(':tname' => $category))->fetchField();
        if (empty($tag_tid)) {
          // if tag doesn't exist, create it
          $tags_vid = db_query("SELECT vid FROM {taxonomy_vocabulary} WHERE machine_name = 'tags'")->fetchField();
          if (empty($tags_vid)) {
            // strange error here. just continue to next category item
            continue;
          }

          $term = new stdClass();
          $term->vid = $tags_vid;
          $term->name = $category;
          taxonomy_term_save($term);
          $tag_tid = $term->tid;
        }

        $entity->field_tags[LANGUAGE_NONE][] = array('tid' => $tag_tid);
      }
    }

    // Set body field format
    $entity->body[LANGUAGE_NONE][0]['format'] = 'full_html';

    // saves node
    node_save($entity);

    _unesco_news_store_redirect($entity);
    _unesco_news_update_translations($entity);
  }

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    return array(
      'expire' => FEEDS_EXPIRE_NEVER,
      'author' => 1,
      'update_existing' => FEEDS_UPDATE_EXISTING,
    ) + parent::configDefaults();
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);

    $form['content_type']['#options'] = array('article' => $form['content_type']['#options']['article']);
    return $form;
  }

}
