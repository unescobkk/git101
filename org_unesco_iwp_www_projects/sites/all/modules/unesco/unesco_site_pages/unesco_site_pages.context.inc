<?php
/**
 * @file
 * unesco_site_pages.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function unesco_site_pages_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home';
  $context->description = '';
  $context->tag = 'Home';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-news-front_infocus_block' => array(
          'module' => 'views',
          'delta' => 'news-front_infocus_block',
          'region' => 'content',
          'weight' => '-76',
        ),
        'views-news-front_news_block' => array(
          'module' => 'views',
          'delta' => 'news-front_news_block',
          'region' => 'content_left',
          'weight' => '-10',
        ),
        'views-events-block_1' => array(
          'module' => 'views',
          'delta' => 'events-block_1',
          'region' => 'content_right',
          'weight' => '-10',
        ),
        'views-publications-block_3' => array(
          'module' => 'views',
          'delta' => 'publications-block_3',
          'region' => 'sidebar_second',
          'weight' => '-76',
        ),
        'views-publications-block_1' => array(
          'module' => 'views',
          'delta' => 'publications-block_1',
          'region' => 'sidebar_second',
          'weight' => '-75',
        ),
        'views-front_description-block' => array(
          'module' => 'views',
          'delta' => 'front_description-block',
          'region' => 'sidebar_second',
          'weight' => '-74',
        ),
        'views-publications-block' => array(
          'module' => 'views',
          'delta' => 'publications-block',
          'region' => 'sidebar_second',
          'weight' => '-73',
        ),
        'views-publications-block_2' => array(
          'module' => 'views',
          'delta' => 'publications-block_2',
          'region' => 'sidebar_second',
          'weight' => '-72',
        ),
        'menu-menu-footer-info' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-info',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Home');
  $export['home'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site_page';
  $context->description = 'Blocks for "Theme" site pages';
  $context->tag = 'section';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'theme_page' => 'theme_page',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-site_page_news_infocus-block' => array(
          'module' => 'views',
          'delta' => 'site_page_news_infocus-block',
          'region' => 'content_below',
          'weight' => '-10',
        ),
        'views-site_page_news_block-block' => array(
          'module' => 'views',
          'delta' => 'site_page_news_block-block',
          'region' => 'content_below',
          'weight' => '-9',
        ),
        'views-site_page_event_block-block' => array(
          'module' => 'views',
          'delta' => 'site_page_event_block-block',
          'region' => 'content_below',
          'weight' => '-8',
        ),
        'views-site_page_publications-block_1' => array(
          'module' => 'views',
          'delta' => 'site_page_publications-block_1',
          'region' => 'content_below',
          'weight' => '-7',
        ),
        'views-theme_page_subthemes-block' => array(
          'module' => 'views',
          'delta' => 'theme_page_subthemes-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-site_page_banners-block' => array(
          'module' => 'views',
          'delta' => 'site_page_banners-block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-page_second_col-block_1' => array(
          'module' => 'views',
          'delta' => 'page_second_col-block_1',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-34f12e3f13af1502053adca17ae2d226' => array(
          'module' => 'views',
          'delta' => '34f12e3f13af1502053adca17ae2d226',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'views-site_page_video_block-block' => array(
          'module' => 'views',
          'delta' => 'site_page_video_block-block',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'views-site_page_banners-block_1' => array(
          'module' => 'views',
          'delta' => 'site_page_banners-block_1',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
        'block-145' => array(
          'module' => 'block',
          'delta' => '145',
          'region' => 'sidebar_second',
          'weight' => '-4',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks for "Theme" site pages');
  t('section');
  $export['site_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site_page_country';
  $context->description = 'Blocks for "Country profile" site pages';
  $context->tag = 'section';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'country_profile' => 'country_profile',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-country_map-block' => array(
          'module' => 'views',
          'delta' => 'country_map-block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-site_page_news_infocus-block' => array(
          'module' => 'views',
          'delta' => 'site_page_news_infocus-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-site_page_news_block-block' => array(
          'module' => 'views',
          'delta' => 'site_page_news_block-block',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-site_page_event_block-block' => array(
          'module' => 'views',
          'delta' => 'site_page_event_block-block',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-dc0cbbace3e65bde84c0e3c03994da51' => array(
          'module' => 'views',
          'delta' => 'dc0cbbace3e65bde84c0e3c03994da51',
          'region' => 'content_below',
          'weight' => '-6',
        ),
        'views-site_page_video_block-block' => array(
          'module' => 'views',
          'delta' => 'site_page_video_block-block',
          'region' => 'content_below',
          'weight' => '-5',
        ),
        'views-site_page_photo_gallery-block_1' => array(
          'module' => 'views',
          'delta' => 'site_page_photo_gallery-block_1',
          'region' => 'content_below',
          'weight' => '-4',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks for "Country profile" site pages');
  t('section');
  $export['site_page_country'] = $context;

  return $export;
}
