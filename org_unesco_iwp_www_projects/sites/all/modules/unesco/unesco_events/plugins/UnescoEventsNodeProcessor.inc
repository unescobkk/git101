<?php

/**
 * @file
 * Class definition of UnescoEventsNodeProcessor.
 */

/**
 * Creates nodes from feed items.
 */
class UnescoEventsNodeProcessor extends FeedsNodeProcessor {
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
    $node->type = 'event';
    return $node;
  }

  /**
   * Save a node.
   */
  public function entitySave($node) {
    // If nid is set and a node with that id doesn't exist, flag as new.
    if (!empty($node->nid) && !node_load($node->nid)) {
      $node->is_new = TRUE;
    }

    if (!empty($node->status)) {
      if ($node->status == 'Published') {
        $node->status = 1;
      } else {
        $node->status = 0;
      }
    } 

    if (isset($node->field_description['und'][0]['value']) && !empty($node->field_description['und'][0]['value'])) {
//      drupal_set_message(t('File %string processed.', array('%string' => $node->field_description['und'][0]['value'])), 'error');
      $node->field_description['und'][0]['format'] = 'filtered_html';
      $node->field_description['und'][0]['value'] = check_markup($node->field_description['und'][0]['value'], 'filtered_html');
    }

    // Process field "Language of Event"
    if (isset($node->field_language_of_event['und'][0]['value']) && !empty($node->field_language_of_event['und'][0]['value'])) {
      $event_languages_raw = $node->field_language_of_event['und'][0]['value'];
      $event_languages_parsed = _unesco_events_parse_languages($event_languages_raw);
      if (is_array($event_languages_parsed)) {
        $node->field_language_of_event['und'] = $event_languages_parsed;
      }
    }

    // Process image Caption and Copyright
    if (isset($node->field_media_image['und'][0]['fid']) && !empty($node->field_media_image['und'][0]['fid'])) {
      $image = file_load($node->field_media_image['und'][0]['fid']);
      if (isset($node->unesco_event_image_caption) && !empty($node->unesco_event_image_caption)) {
        $image->field_caption = array('und' => array(array('value' => $node->unesco_event_image_caption)));
      }
      if (isset($node->unesco_event_image_copyright) && !empty($node->unesco_event_image_copyright)) {
        $image->field_copy = array('und' => array(array('value' => $node->unesco_event_image_copyright)));
      }
      file_save($image);
    }

    // Process theme page
    if (isset($node->unesco_event_theme_page) && !empty($node->unesco_event_theme_page)) {
      foreach (explode("; ", $node->unesco_event_theme_page) as $i){
        $theme_page_nid = _unesco_events_get_theme_page_nid($i, $node->language);
        if ($theme_page_nid) {
          $node->field_theme_page['und'][] = array('target_id' => $theme_page_nid);
        }
      }
    }

    // Process organizer
    if (isset($node->unesco_event_organizer) && !empty($node->unesco_event_organizer)) {
      if ($organizer_nid = _unesco_events_get_organization_nid($node->unesco_event_organizer)) {
        $node->field_organizer = array('und' => array(array('target_id' => $organizer_nid)));
      }
    }

    // Process partner
    if (isset($node->unesco_event_partner) && !empty($node->unesco_event_partner)) {
      if ($partner_nid = _unesco_events_get_organization_nid($node->unesco_event_partner)) {
        $node->field_partner = array('und' => array(array('target_id' => $partner_nid)));
      }
    }

    // Process Delegation
    if (isset($node->unesco_event_delegation) && !empty($node->unesco_event_delegation)) {
      if ($delegation_nid = _unesco_events_get_organization_nid($node->unesco_event_delegation)) {
        $node->field_delegation = array('und' => array(array('target_id' => $delegation_nid)));
      }
    }

    // Process MajorProgramme
    if (isset($node->unesco_major_programme) && !empty($node->unesco_major_programme)) {
      if ($major_programme_tid = _unesco_events_get_tid('major_programme_c_5', $node->unesco_major_programme, $node->language)) {
        $node->field_major_programme = array('und' => array(array('tid' => $major_programme_tid)));
      }
    }

    // Process TypeOfEvent
    if (isset($node->unesco_type_of_event) && !empty($node->unesco_type_of_event)) {
      if ($type_of_event_tid = _unesco_events_get_tid('type_of_event', $node->unesco_type_of_event, $node->language)) {
        $node->field_type_of_event = array('und' => array(array('tid' => $type_of_event_tid)));
      }
    }

    // Process Responsible
    if (isset($node->unesco_responsible_unit) && !empty($node->unesco_responsible_unit)) {
      if ($responsible_unit_tid = _unesco_events_get_tid('responsible_unit', $node->unesco_responsible_unit, $node->language)) {
        $node->field_responsible_unit = array('und' => array(array('tid' => $responsible_unit_tid)));
      }
    }

    // Process Sector
    if (isset($node->unesco_event_focal_point) && !empty($node->unesco_event_focal_point)) {
      if ($sector_tid = _unesco_events_get_tid('responsible_unit', $node->unesco_event_focal_point, $node->language)) {
        $node->field_focal_point = array('und' => array(array('tid' => $sector_tid)));
      }
    }

    // Process Responsible Staff
    if (isset($node->unesco_responsible_staff) && !empty($node->unesco_responsible_staff)) {
      if ($responsible_staff_uid = _unesco_events_get_uid_from_nice($node->unesco_responsible_staff)) {
        $node->field_responsible_staff = array('und' => array(array('target_id' => $responsible_staff_uid)));
      }
    }

    node_save($node);
    _unesco_events_set_tnid($node);
  }

  /**
   * Overrides parent::getMappingTargets().
   */
  public function getMappingTargets() {
    $targets = array();

    // Image caption and copyright
    $targets['unesco_event_image_caption'] = array(
      'name' => t('UNESCO Image Caption'),
      'description' => t('UNESCO Image Caption'),
    );
    $targets['unesco_event_image_copyright'] = array(
      'name' => t('UNESCO Image Copyright'),
      'description' => t('UNESCO Image Copyright'),
    );

    // Node reference
    $targets['unesco_event_theme_page'] = array(
      'name' => t('UNESCO Theme Page'),
      'description' => t('UNESCO Theme Page'),
    );
    $targets['unesco_event_organizer'] = array(
      'name' => t('UNESCO Organizer'),
      'description' => t('UNESCO Organizer'),
    );
    $targets['unesco_event_delegation'] = array(
      'name' => t('UNESCO Delegation'),
      'description' => t('UNESCO Delegation'),
    );
    $targets['unesco_event_partner'] = array(
      'name' => t('UNESCO Partner'),
      'description' => t('UNESCO Partner'),
    );

    // Term reference
    $targets['unesco_major_programme'] = array(
      'name' => t('UNESCO Major Programme'),
      'description' => t('UNESCO Major Programme'),
    );
    $targets['unesco_type_of_event'] = array(
      'name' => t('UNESCO Type of Event'),
      'description' => t('UNESCO Type of Event'),
    );
    $targets['unesco_responsible_unit'] = array(
      'name' => t('UNESCO Responsible Unit'),
      'description' => t('UNESCO Responsible Unit'),
    );
    $targets['unesco_event_focal_point'] = array(
      'name' => t('UNESCO Focal Point'),
      'description' => t('UNESCO Focal Point'),
    );

    // User reference
    $targets['unesco_responsible_staff'] = array(
      'name' => t('UNESCO Responsible Staff'),
      'description' => t('UNESCO Responsible Staff'),
    );

    return $targets + parent::getMappingTargets();
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

    $form['content_type']['#options'] = array('event' => $form['content_type']['#options']['event']);
    return $form;
  }

}
