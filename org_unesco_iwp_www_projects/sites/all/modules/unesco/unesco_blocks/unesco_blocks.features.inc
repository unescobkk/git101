<?php
/**
 * @file
 * unesco_blocks.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function unesco_blocks_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function unesco_blocks_node_info() {
  $items = array(
    'blocks_content' => array(
      'name' => t('Blocks Content'),
      'base' => 'node_content',
      'description' => t('Content to be shown in blocks for the home page. You can put an image, a url, a description, the block where you want to add the content and a title. Usually used for first pages.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
