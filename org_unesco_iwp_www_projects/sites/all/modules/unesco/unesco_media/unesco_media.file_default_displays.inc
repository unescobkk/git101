<?php
/**
 * @file
 * unesco_media.file_default_displays.inc
 */

/**
 * Implements hook_file_default_displays().
 */
function unesco_media_file_default_displays() {
  $export = array();

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__file_styles_unesco_media_143x107__file_field_styles_file_unesco_media_143x107';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['image__file_styles_unesco_media_143x107__file_field_styles_file_unesco_media_143x107'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__file_styles_unesco_media_colorbox_600x800__file_field_styles_file_unesco_media_colorbox_600x800';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['image__file_styles_unesco_media_colorbox_600x800__file_field_styles_file_unesco_media_colorbox_600x800'] = $file_display;

  return $export;
}
