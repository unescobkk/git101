<?php
/**
 * @file
 * unesco_media.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function unesco_media_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'galleries';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Galleries';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Media galleries';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'machine_name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Cover */
  $handler->display->display_options['fields']['field_photo_tags_cover']['id'] = 'field_photo_tags_cover';
  $handler->display->display_options['fields']['field_photo_tags_cover']['table'] = 'field_data_field_photo_tags_cover';
  $handler->display->display_options['fields']['field_photo_tags_cover']['field'] = 'field_photo_tags_cover';
  $handler->display->display_options['fields']['field_photo_tags_cover']['label'] = '';
  $handler->display->display_options['fields']['field_photo_tags_cover']['alter']['path'] = 'lolololololololololoolo';
  $handler->display->display_options['fields']['field_photo_tags_cover']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_photo_tags_cover']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_photo_tags_cover']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_photo_tags_cover']['settings'] = array(
    'file_view_mode' => 'file_styles_unesco_media_gallery_143x107',
  );
  /* Field: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['fields']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['label'] = '';
  $handler->display->display_options['fields']['machine_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['machine_name']['element_label_colon'] = FALSE;
  /* Sort criterion: Taxonomy term: Term ID */
  $handler->display->display_options['sorts']['tid']['id'] = 'tid';
  $handler->display->display_options['sorts']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['tid']['field'] = 'tid';
  $handler->display->display_options['sorts']['tid']['order'] = 'DESC';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'photo_tags' => 'photo_tags',
    'video_tags' => 'video_tags',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'galleries';

  /* Display: Photo galleries */
  $handler = $view->new_display('block', 'Photo galleries', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Photo gallery';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'views-block-gallery';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Cover */
  $handler->display->display_options['fields']['field_photo_tags_cover']['id'] = 'field_photo_tags_cover';
  $handler->display->display_options['fields']['field_photo_tags_cover']['table'] = 'field_data_field_photo_tags_cover';
  $handler->display->display_options['fields']['field_photo_tags_cover']['field'] = 'field_photo_tags_cover';
  $handler->display->display_options['fields']['field_photo_tags_cover']['label'] = '';
  $handler->display->display_options['fields']['field_photo_tags_cover']['alter']['path'] = 'lolololololololololoolo';
  $handler->display->display_options['fields']['field_photo_tags_cover']['element_class'] = 'media';
  $handler->display->display_options['fields']['field_photo_tags_cover']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_photo_tags_cover']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_photo_tags_cover']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_photo_tags_cover']['settings'] = array(
    'file_view_mode' => 'file_styles_img_title_cpt_480x249',
  );
  /* Field: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['fields']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['label'] = '';
  $handler->display->display_options['fields']['machine_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['machine_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'photo_tags' => 'photo_tags',
  );
  /* Filter criterion: Taxonomy term: Front Page (field_front_page) */
  $handler->display->display_options['filters']['field_front_page_value']['id'] = 'field_front_page_value';
  $handler->display->display_options['filters']['field_front_page_value']['table'] = 'field_data_field_front_page';
  $handler->display->display_options['filters']['field_front_page_value']['field'] = 'field_front_page_value';
  $handler->display->display_options['filters']['field_front_page_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Taxonomy term: Main image (field_main_image) */
  $handler->display->display_options['filters']['field_main_image_value']['id'] = 'field_main_image_value';
  $handler->display->display_options['filters']['field_main_image_value']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['filters']['field_main_image_value']['field'] = 'field_main_image_value';
  $handler->display->display_options['filters']['field_main_image_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'Photo galleries';

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Image galleries';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'views-block-gallery';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Cover */
  $handler->display->display_options['fields']['field_photo_tags_cover']['id'] = 'field_photo_tags_cover';
  $handler->display->display_options['fields']['field_photo_tags_cover']['table'] = 'field_data_field_photo_tags_cover';
  $handler->display->display_options['fields']['field_photo_tags_cover']['field'] = 'field_photo_tags_cover';
  $handler->display->display_options['fields']['field_photo_tags_cover']['label'] = '';
  $handler->display->display_options['fields']['field_photo_tags_cover']['alter']['path'] = 'lolololololololololoolo';
  $handler->display->display_options['fields']['field_photo_tags_cover']['element_class'] = 'media';
  $handler->display->display_options['fields']['field_photo_tags_cover']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_photo_tags_cover']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_photo_tags_cover']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_photo_tags_cover']['settings'] = array(
    'file_view_mode' => 'file_styles_img_copy_146x89',
  );
  /* Field: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['fields']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['label'] = '';
  $handler->display->display_options['fields']['machine_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['machine_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'photo_tags' => 'photo_tags',
  );
  /* Filter criterion: Taxonomy term: Front Page (field_front_page) */
  $handler->display->display_options['filters']['field_front_page_value']['id'] = 'field_front_page_value';
  $handler->display->display_options['filters']['field_front_page_value']['table'] = 'field_data_field_front_page';
  $handler->display->display_options['filters']['field_front_page_value']['field'] = 'field_front_page_value';
  $handler->display->display_options['filters']['field_front_page_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Taxonomy term: Main image (field_main_image) */
  $handler->display->display_options['filters']['field_main_image_value']['id'] = 'field_main_image_value';
  $handler->display->display_options['filters']['field_main_image_value']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['filters']['field_main_image_value']['field'] = 'field_main_image_value';
  $handler->display->display_options['filters']['field_main_image_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['displays'] = array(
    'block_1' => 'block_1',
    'default' => 0,
    'page' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $translatables['galleries'] = array(
    t('Master'),
    t('Media galleries'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Page'),
    t('Photo galleries'),
    t('Photo gallery'),
    t('Attachment'),
    t('Image galleries'),
  );
  $export['galleries'] = $view;

  $view = new view();
  $view->name = 'photo_gallery';
  $view->description = '';
  $view->tag = 'gallery';
  $view->base_table = 'node';
  $view->human_name = 'Gallery Photo';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Image gallery';
  $handler->display->display_options['css_class'] = 'views-block-gallery';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'jcarousel';
  $handler->display->display_options['style_options']['wrap'] = '0';
  $handler->display->display_options['style_options']['visible'] = '3';
  $handler->display->display_options['style_options']['auto'] = '0';
  $handler->display->display_options['style_options']['autoPause'] = 1;
  $handler->display->display_options['style_options']['easing'] = '';
  $handler->display->display_options['style_options']['vertical'] = 0;
  $handler->display->display_options['style_options']['ajax'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Url */
  $handler->display->display_options['fields']['field_url']['id'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['table'] = 'field_data_field_url';
  $handler->display->display_options['fields']['field_url']['field'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['label'] = '';
  $handler->display->display_options['fields']['field_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_url']['element_label_colon'] = FALSE;
  /* Field: Content: Media */
  $handler->display->display_options['fields']['field_media_image']['id'] = 'field_media_image';
  $handler->display->display_options['fields']['field_media_image']['table'] = 'field_data_field_media_image';
  $handler->display->display_options['fields']['field_media_image']['field'] = 'field_media_image';
  $handler->display->display_options['fields']['field_media_image']['label'] = '';
  $handler->display->display_options['fields']['field_media_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_media_image']['alter']['path'] = '[field_url]';
  $handler->display->display_options['fields']['field_media_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_media_image']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_media_image']['settings'] = array(
    'file_view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_media_image']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_media_image']['multi_type'] = 'ul';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['granularity'] = 'minute';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Gallery Photos */
  $handler = $view->new_display('block', 'Gallery Photos', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Photo gallery';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Url */
  $handler->display->display_options['fields']['field_url']['id'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['table'] = 'field_data_field_url';
  $handler->display->display_options['fields']['field_url']['field'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['label'] = '';
  $handler->display->display_options['fields']['field_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_url']['element_label_colon'] = FALSE;
  /* Field: Content: Media */
  $handler->display->display_options['fields']['field_media_image']['id'] = 'field_media_image';
  $handler->display->display_options['fields']['field_media_image']['table'] = 'field_data_field_media_image';
  $handler->display->display_options['fields']['field_media_image']['field'] = 'field_media_image';
  $handler->display->display_options['fields']['field_media_image']['label'] = '';
  $handler->display->display_options['fields']['field_media_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_media_image']['alter']['path'] = '[field_url]';
  $handler->display->display_options['fields']['field_media_image']['element_class'] = 'media';
  $handler->display->display_options['fields']['field_media_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_media_image']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_media_image']['settings'] = array(
    'file_view_mode' => 'file_styles_big_photo_480x249',
    'linked_field' => array(
      'linked' => 0,
      'destination' => '[field_url]',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  $handler->display->display_options['fields']['field_media_image']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_media_image']['multi_type'] = 'ul';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['granularity'] = 'minute';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'photos' => 'photos',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 1;
  /* Filter criterion: Content: Sticky */
  $handler->display->display_options['filters']['sticky']['id'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['table'] = 'node';
  $handler->display->display_options['filters']['sticky']['field'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['value'] = '1';
  $handler->display->display_options['filters']['sticky']['group'] = 1;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['block_description'] = 'Gallery photos';

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Url */
  $handler->display->display_options['fields']['field_url']['id'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['table'] = 'field_data_field_url';
  $handler->display->display_options['fields']['field_url']['field'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['label'] = '';
  $handler->display->display_options['fields']['field_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_url']['element_label_colon'] = FALSE;
  /* Field: Content: Media */
  $handler->display->display_options['fields']['field_media_image']['id'] = 'field_media_image';
  $handler->display->display_options['fields']['field_media_image']['table'] = 'field_data_field_media_image';
  $handler->display->display_options['fields']['field_media_image']['field'] = 'field_media_image';
  $handler->display->display_options['fields']['field_media_image']['label'] = '';
  $handler->display->display_options['fields']['field_media_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_media_image']['alter']['path'] = '[field_url]';
  $handler->display->display_options['fields']['field_media_image']['element_class'] = 'media';
  $handler->display->display_options['fields']['field_media_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_media_image']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_media_image']['settings'] = array(
    'file_view_mode' => 'file_styles_small_photo_146x89',
    'linked_field' => array(
      'linked' => 0,
      'destination' => '[field_url]',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  $handler->display->display_options['fields']['field_media_image']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'photos' => 'photos',
  );
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  /* Filter criterion: Content: Sticky */
  $handler->display->display_options['filters']['sticky']['id'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['table'] = 'node';
  $handler->display->display_options['filters']['sticky']['field'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['value'] = '0';
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['displays'] = array(
    'block_1' => 'block_1',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Media (field_media_image:fid) */
  $handler->display->display_options['relationships']['field_media_image_fid']['id'] = 'field_media_image_fid';
  $handler->display->display_options['relationships']['field_media_image_fid']['table'] = 'field_data_field_media_image';
  $handler->display->display_options['relationships']['field_media_image_fid']['field'] = 'field_media_image_fid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Media */
  $handler->display->display_options['fields']['field_media_image']['id'] = 'field_media_image';
  $handler->display->display_options['fields']['field_media_image']['table'] = 'field_data_field_media_image';
  $handler->display->display_options['fields']['field_media_image']['field'] = 'field_media_image';
  $handler->display->display_options['fields']['field_media_image']['label'] = '';
  $handler->display->display_options['fields']['field_media_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_media_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_media_image']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_media_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_media_image']['type'] = 'styles_file_img_143x107';
  $handler->display->display_options['fields']['field_media_image']['settings'] = array(
    'file_view_mode' => 'file_styles_photo_gallery_143x107',
  );
  $handler->display->display_options['fields']['field_media_image']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_media_image']['multi_type'] = 'ul';
  /* Field: Content: Media */
  $handler->display->display_options['fields']['field_media_image_1']['id'] = 'field_media_image_1';
  $handler->display->display_options['fields']['field_media_image_1']['table'] = 'field_data_field_media_image';
  $handler->display->display_options['fields']['field_media_image_1']['field'] = 'field_media_image';
  $handler->display->display_options['fields']['field_media_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_media_image_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_media_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_media_image_1']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_media_image_1']['settings'] = array(
    'file_view_mode' => 'file_styles_img_600x800',
  );
  $handler->display->display_options['fields']['field_media_image_1']['delta_offset'] = '0';
  /* Field: File: Caption */
  $handler->display->display_options['fields']['field_caption']['id'] = 'field_caption';
  $handler->display->display_options['fields']['field_caption']['table'] = 'field_data_field_caption';
  $handler->display->display_options['fields']['field_caption']['field'] = 'field_caption';
  $handler->display->display_options['fields']['field_caption']['relationship'] = 'field_media_image_fid';
  $handler->display->display_options['fields']['field_caption']['label'] = '';
  $handler->display->display_options['fields']['field_caption']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_caption']['element_label_colon'] = FALSE;
  /* Field: File: Copyright */
  $handler->display->display_options['fields']['field_copy']['id'] = 'field_copy';
  $handler->display->display_options['fields']['field_copy']['table'] = 'field_data_field_copy';
  $handler->display->display_options['fields']['field_copy']['field'] = 'field_copy';
  $handler->display->display_options['fields']['field_copy']['relationship'] = 'field_media_image_fid';
  $handler->display->display_options['fields']['field_copy']['label'] = '';
  $handler->display->display_options['fields']['field_copy']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_copy']['element_label_colon'] = FALSE;
  /* Field: Colorbox: Colorbox trigger */
  $handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['label'] = '';
  $handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['trigger_field'] = 'field_media_image';
  $handler->display->display_options['fields']['colorbox']['popup'] = '[field_media_image_1]';
  $handler->display->display_options['fields']['colorbox']['caption'] = '[field_copy]/[field_caption]';
  $handler->display->display_options['fields']['colorbox']['gid'] = 1;
  $handler->display->display_options['fields']['colorbox']['width'] = '800px';
  $handler->display->display_options['fields']['colorbox']['height'] = '600px';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Tags (field_photo_tags) */
  $handler->display->display_options['arguments']['field_photo_tags_tid']['id'] = 'field_photo_tags_tid';
  $handler->display->display_options['arguments']['field_photo_tags_tid']['table'] = 'field_data_field_photo_tags';
  $handler->display->display_options['arguments']['field_photo_tags_tid']['field'] = 'field_photo_tags_tid';
  $handler->display->display_options['arguments']['field_photo_tags_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_photo_tags_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_photo_tags_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_photo_tags_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_photo_tags_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_photo_tags_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_photo_tags_tid']['validate_options']['vocabularies'] = array(
    'photo_tags' => 'photo_tags',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'photos' => 'photos',
  );
  $handler->display->display_options['path'] = 'photo-galleries/%';

  /* Display: Attachment 2 */
  $handler = $view->new_display('attachment', 'Attachment 2', 'attachment_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Tags (field_photo_tags) */
  $handler->display->display_options['arguments']['field_photo_tags_tid']['id'] = 'field_photo_tags_tid';
  $handler->display->display_options['arguments']['field_photo_tags_tid']['table'] = 'field_data_field_photo_tags';
  $handler->display->display_options['arguments']['field_photo_tags_tid']['field'] = 'field_photo_tags_tid';
  $handler->display->display_options['arguments']['field_photo_tags_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_photo_tags_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_photo_tags_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_photo_tags_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_photo_tags_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_photo_tags_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_photo_tags_tid']['validate_options']['vocabularies'] = array(
    'photo_tags' => 'photo_tags',
  );
  $handler->display->display_options['arguments']['field_photo_tags_tid']['validate']['fail'] = 'empty';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'page' => 'page',
  );
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
    'block_1' => 0,
  );
  $translatables['photo_gallery'] = array(
    t('Defaults'),
    t('Image gallery'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Gallery Photos'),
    t('Photo gallery'),
    t('Gallery photos'),
    t('Attachment'),
    t('Page'),
    t('file from field_media_image'),
    t('All'),
    t('Attachment 2'),
  );
  $export['photo_gallery'] = $view;

  $view = new view();
  $view->name = 'video_gallery';
  $view->description = '';
  $view->tag = 'gallery';
  $view->base_table = 'node';
  $view->human_name = 'Gallery Video';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Video Features';
  $handler->display->display_options['css_class'] = 'views-block-gallery';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Flags: unescommunity_only */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'unescommunity_only';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Field: Content: Media Video */
  $handler->display->display_options['fields']['field_media_video']['id'] = 'field_media_video';
  $handler->display->display_options['fields']['field_media_video']['table'] = 'field_data_field_media_video';
  $handler->display->display_options['fields']['field_media_video']['field'] = 'field_media_video';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['granularity'] = 'minute';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Gallery Videos */
  $handler = $view->new_display('block', 'Gallery Videos', 'block_1');
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: unescommunity_only */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'flag only';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'unescommunity_only';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Media Video */
  $handler->display->display_options['fields']['field_media_video']['id'] = 'field_media_video';
  $handler->display->display_options['fields']['field_media_video']['table'] = 'field_data_field_media_video';
  $handler->display->display_options['fields']['field_media_video']['field'] = 'field_media_video';
  $handler->display->display_options['fields']['field_media_video']['label'] = '';
  $handler->display->display_options['fields']['field_media_video']['element_class'] = 'media';
  $handler->display->display_options['fields']['field_media_video']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_video']['click_sort_column'] = 'video_url';
  $handler->display->display_options['fields']['field_media_video']['type'] = 'video_embed_field_thumbnail_colorbox';
  $handler->display->display_options['fields']['field_media_video']['settings'] = array(
    'video_style' => 'normal',
    'image_style' => 'img_480x249',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'videos' => 'videos',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 1;
  /* Filter criterion: Content: Sticky */
  $handler->display->display_options['filters']['sticky']['id'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['table'] = 'node';
  $handler->display->display_options['filters']['sticky']['field'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['value'] = '1';
  $handler->display->display_options['filters']['sticky']['group'] = 1;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flag_content';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = '0';
  $handler->display->display_options['block_description'] = 'Gallery videos';

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Media Video */
  $handler->display->display_options['fields']['field_media_video']['id'] = 'field_media_video';
  $handler->display->display_options['fields']['field_media_video']['table'] = 'field_data_field_media_video';
  $handler->display->display_options['fields']['field_media_video']['field'] = 'field_media_video';
  $handler->display->display_options['fields']['field_media_video']['label'] = '';
  $handler->display->display_options['fields']['field_media_video']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_video']['click_sort_column'] = 'video_url';
  $handler->display->display_options['fields']['field_media_video']['type'] = 'video_embed_field_thumbnail_colorbox';
  $handler->display->display_options['fields']['field_media_video']['settings'] = array(
    'video_style' => 'normal',
    'image_style' => 'img_146x89',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['granularity'] = 'minute';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'videos' => 'videos',
  );
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  /* Filter criterion: Content: Sticky */
  $handler->display->display_options['filters']['sticky']['id'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['table'] = 'node';
  $handler->display->display_options['filters']['sticky']['field'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['value'] = '0';
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flag_content';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = '0';
  $handler->display->display_options['displays'] = array(
    'block_1' => 'block_1',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Media Video */
  $handler->display->display_options['fields']['field_media_video']['id'] = 'field_media_video';
  $handler->display->display_options['fields']['field_media_video']['table'] = 'field_data_field_media_video';
  $handler->display->display_options['fields']['field_media_video']['field'] = 'field_media_video';
  $handler->display->display_options['fields']['field_media_video']['label'] = '';
  $handler->display->display_options['fields']['field_media_video']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_media_video']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_video']['click_sort_column'] = 'video_url';
  $handler->display->display_options['fields']['field_media_video']['type'] = 'video_embed_field_thumbnail_colorbox';
  $handler->display->display_options['fields']['field_media_video']['settings'] = array(
    'video_style' => 'normal',
    'image_style' => 'unesco_media_gallery_143x107',
  );
  /* Field: Content: Media Video */
  $handler->display->display_options['fields']['field_media_video_1']['id'] = 'field_media_video_1';
  $handler->display->display_options['fields']['field_media_video_1']['table'] = 'field_data_field_media_video';
  $handler->display->display_options['fields']['field_media_video_1']['field'] = 'field_media_video';
  $handler->display->display_options['fields']['field_media_video_1']['label'] = '';
  $handler->display->display_options['fields']['field_media_video_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_media_video_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_video_1']['click_sort_column'] = 'video_url';
  $handler->display->display_options['fields']['field_media_video_1']['settings'] = array(
    'video_style' => 'normal',
  );
  /* Field: Colorbox: Colorbox trigger */
  $handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['label'] = '';
  $handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['trigger_field'] = 'field_media_video';
  $handler->display->display_options['fields']['colorbox']['popup'] = '[field_media_video_1]';
  $handler->display->display_options['fields']['colorbox']['gid'] = 1;
  $handler->display->display_options['fields']['colorbox']['width'] = '800px';
  $handler->display->display_options['fields']['colorbox']['height'] = '600px';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Tags (field_video_tags) */
  $handler->display->display_options['arguments']['field_video_tags_tid']['id'] = 'field_video_tags_tid';
  $handler->display->display_options['arguments']['field_video_tags_tid']['table'] = 'field_data_field_video_tags';
  $handler->display->display_options['arguments']['field_video_tags_tid']['field'] = 'field_video_tags_tid';
  $handler->display->display_options['arguments']['field_video_tags_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_video_tags_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_video_tags_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_video_tags_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_video_tags_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_video_tags_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_video_tags_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_video_tags_tid']['validate_options']['vocabularies'] = array(
    'video_tags' => 'video_tags',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'videos' => 'videos',
  );
  $handler->display->display_options['path'] = 'video-galleries/%';

  /* Display: Attachment 2 */
  $handler = $view->new_display('attachment', 'Attachment 2', 'attachment_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: unescommunity_only */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'unescommunity_only';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Tags (field_video_tags) */
  $handler->display->display_options['arguments']['field_video_tags_tid']['id'] = 'field_video_tags_tid';
  $handler->display->display_options['arguments']['field_video_tags_tid']['table'] = 'field_data_field_video_tags';
  $handler->display->display_options['arguments']['field_video_tags_tid']['field'] = 'field_video_tags_tid';
  $handler->display->display_options['arguments']['field_video_tags_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_video_tags_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_video_tags_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_video_tags_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_video_tags_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_video_tags_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_video_tags_tid']['validate_options']['vocabularies'] = array(
    'video_tags' => 'video_tags',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'page' => 'page',
  );
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
    'block_1' => 0,
  );
  $translatables['video_gallery'] = array(
    t('Defaults'),
    t('Video Features'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('flag'),
    t('Media Video'),
    t('Gallery Videos'),
    t('flag only'),
    t('Gallery videos'),
    t('Attachment'),
    t('Page'),
    t('All'),
    t('Attachment 2'),
  );
  $export['video_gallery'] = $view;

  return $export;
}
