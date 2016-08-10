<?php
/**
 * @file
 * unesco_organizations.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function unesco_organizations_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'unesco_organizations';
  $feeds_importer->config = array(
    'name' => 'UNESCO Organizations',
    'description' => 'Import ngos from http://ngo-db.unesco.org/s/or/en',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'organization',
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'Name',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Acronym',
            'target' => 'field_acronym',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'City',
            'target' => 'field_postal_address:locality',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Country',
            'target' => 'field_postal_address:data',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['unesco_organizations'] = $feeds_importer;

  return $export;
}
