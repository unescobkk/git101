<?php
/**
 * @file
 * unesco_events.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function unesco_events_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'event_page';
  $context->description = '';
  $context->tag = 'node_type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'event' => 'event',
      ),
      'options' => array(
        'node_form' => '0',
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
          'weight' => '-10',
        ),
        'views-event_page_details-block' => array(
          'module' => 'views',
          'delta' => 'event_page_details-block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-9190c7d54d3981fbf68f581208986932' => array(
          'module' => 'views',
          'delta' => '9190c7d54d3981fbf68f581208986932',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'views-event_page_event_block-block' => array(
          'module' => 'views',
          'delta' => 'event_page_event_block-block',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'views-event_page_news_block-block' => array(
          'module' => 'views',
          'delta' => 'event_page_news_block-block',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
        'views-event_page_media-block' => array(
          'module' => 'views',
          'delta' => 'event_page_media-block',
          'region' => 'sidebar_second',
          'weight' => '-4',
        ),
        'views-event_page_media-block_1' => array(
          'module' => 'views',
          'delta' => 'event_page_media-block_1',
          'region' => 'sidebar_second',
          'weight' => '-3',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('node_type');
  $export['event_page'] = $context;

  return $export;
}
