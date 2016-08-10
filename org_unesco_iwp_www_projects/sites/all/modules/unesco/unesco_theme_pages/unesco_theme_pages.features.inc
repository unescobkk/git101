<?php
/**
 * @file
 * unesco_theme_pages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function unesco_theme_pages_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function unesco_theme_pages_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function unesco_theme_pages_node_info() {
  $items = array(
    'theme_page' => array(
      'name' => t('Theme'),
      'base' => 'node_content',
      'description' => t('A specially-formatted page, to highlight specific themes.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
