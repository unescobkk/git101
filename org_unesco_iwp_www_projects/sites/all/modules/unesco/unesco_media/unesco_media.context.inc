<?php
/**
 * @file
 * unesco_media.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function unesco_media_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'unesco_media';
  $context->description = '';
  $context->tag = 'media';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'photo-galleries/*' => 'photo-galleries/*',
        'video-galleries/*' => 'video-galleries/*',
        'galleries' => 'galleries',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-event_page_map-block_3' => array(
          'module' => 'views',
          'delta' => 'event_page_map-block_3',
          'region' => 'sidebar_second',
          'weight' => '-77',
        ),
        'views-site_page_banners-block_1' => array(
          'module' => 'views',
          'delta' => 'site_page_banners-block_1',
          'region' => 'sidebar_second',
          'weight' => '-77',
        ),
        'views-event_page_details-block' => array(
          'module' => 'views',
          'delta' => 'event_page_details-block',
          'region' => 'sidebar_second',
          'weight' => '-76',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('media');
  $export['unesco_media'] = $context;

  return $export;
}
