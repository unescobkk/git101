<?php
/**
 * @file
 * unesco_media.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function unesco_media_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function unesco_media_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function unesco_media_image_default_styles() {
  $styles = array();

  // Exported image style: img_143x107.
  $styles['img_143x107'] = array(
    'name' => 'img_143x107',
    'label' => 'img_143x107',
    'effects' => array(
      138 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '143',
          'height' => '107',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: img_146x89.
  $styles['img_146x89'] = array(
    'name' => 'img_146x89',
    'label' => 'img_146x89',
    'effects' => array(
      126 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '146',
          'height' => '89',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: img_480x249.
  $styles['img_480x249'] = array(
    'name' => 'img_480x249',
    'label' => 'img_480x249',
    'effects' => array(
      127 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '480',
          'height' => '249',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: img_800x600.
  $styles['img_800x600'] = array(
    'name' => 'img_800x600',
    'label' => 'img_800x600',
    'effects' => array(
      139 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '800',
          'height' => '600',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function unesco_media_node_info() {
  $items = array(
    'photos' => array(
      'name' => t('Photos'),
      'base' => 'node_content',
      'description' => t('photos?'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'videos' => array(
      'name' => t('Videos'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_styles_default_styles().
 */
function unesco_media_styles_default_styles() {
  $styles = array();

  // Exported style: img_143x107

  $styles['file']['styles']['img_143x107'] = array(
    'label' => 'img_143x107',
    'description' => '',
    'preset_info' => array(
      'image' => array(
        'img_143x107' => array(
          'default preset' => 'original',
          'preset' => 'img_143x107',
        ),
      ),
      'audio' => array(
        'img_143x107' => array(
          'default preset' => 'original',
        ),
      ),
      'video' => array(
        'img_143x107' => array(
          'default preset' => 'original',
        ),
      ),
      'default' => array(
        'img_143x107' => array(
          'default preset' => 'original',
        ),
      ),
    ),
  );
  // Exported style: img_600x800

  $styles['file']['styles']['img_600x800'] = array(
    'label' => 'img_600x800',
    'description' => '',
    'preset_info' => array(
      'image' => array(
        'img_600x800' => array(
          'default preset' => 'original',
        ),
      ),
      'audio' => array(
        'img_600x800' => array(
          'default preset' => 'original',
        ),
      ),
      'video' => array(
        'img_600x800' => array(
          'default preset' => 'original',
        ),
      ),
      'default' => array(
        'img_600x800' => array(
          'default preset' => 'original',
        ),
      ),
    ),
  );
  // Exported style: img_copy_146x89

  $styles['file']['styles']['img_copy_146x89'] = array(
    'label' => 'img_copy_146x89',
    'description' => '',
    'preset_info' => array(
      'image' => array(
        'img_copy_146x89' => array(
          'default preset' => 'original',
          'preset' => 'img_146x89',
        ),
      ),
      'audio' => array(
        'img_copy_146x89' => array(
          'default preset' => 'original',
        ),
      ),
      'video' => array(
        'img_copy_146x89' => array(
          'default preset' => 'original',
        ),
      ),
      'default' => array(
        'img_copy_146x89' => array(
          'default preset' => 'original',
        ),
      ),
    ),
  );
  // Exported style: img_title_cpt_480x249

  $styles['file']['styles']['img_title_cpt_480x249'] = array(
    'label' => 'img_title_cpt_480x249',
    'description' => '',
    'preset_info' => array(
      'image' => array(
        'img_title_cpt_480x249' => array(
          'default preset' => 'original',
          'preset' => 'img_480x249',
        ),
      ),
      'audio' => array(
        'img_title_cpt_480x249' => array(
          'default preset' => 'original',
        ),
      ),
      'video' => array(
        'img_title_cpt_480x249' => array(
          'default preset' => 'original',
        ),
      ),
      'default' => array(
        'img_title_cpt_480x249' => array(
          'default preset' => 'original',
        ),
      ),
    ),
  );
  // Exported style: img_143x107

  $styles['file']['styles']['img_143x107'] = array(
    'label' => 'img_143x107',
    'description' => '',
    'preset_info' => array(
      'image' => array(
        'img_143x107' => array(
          'default preset' => 'original',
          'preset' => 'img_143x107',
        ),
      ),
      'audio' => array(
        'img_143x107' => array(
          'default preset' => 'original',
        ),
      ),
      'video' => array(
        'img_143x107' => array(
          'default preset' => 'original',
        ),
      ),
      'default' => array(
        'img_143x107' => array(
          'default preset' => 'original',
        ),
      ),
    ),
  );
  // Exported style: img_600x800

  $styles['file']['styles']['img_600x800'] = array(
    'label' => 'img_600x800',
    'description' => '',
    'preset_info' => array(
      'image' => array(
        'img_600x800' => array(
          'default preset' => 'original',
        ),
      ),
      'audio' => array(
        'img_600x800' => array(
          'default preset' => 'original',
        ),
      ),
      'video' => array(
        'img_600x800' => array(
          'default preset' => 'original',
        ),
      ),
      'default' => array(
        'img_600x800' => array(
          'default preset' => 'original',
        ),
      ),
    ),
  );
  // Exported style: img_copy_146x89

  $styles['file']['styles']['img_copy_146x89'] = array(
    'label' => 'img_copy_146x89',
    'description' => '',
    'preset_info' => array(
      'image' => array(
        'img_copy_146x89' => array(
          'default preset' => 'original',
          'preset' => 'img_146x89',
        ),
      ),
      'audio' => array(
        'img_copy_146x89' => array(
          'default preset' => 'original',
        ),
      ),
      'video' => array(
        'img_copy_146x89' => array(
          'default preset' => 'original',
        ),
      ),
      'default' => array(
        'img_copy_146x89' => array(
          'default preset' => 'original',
        ),
      ),
    ),
  );
  // Exported style: img_title_cpt_480x249

  $styles['file']['styles']['img_title_cpt_480x249'] = array(
    'label' => 'img_title_cpt_480x249',
    'description' => '',
    'preset_info' => array(
      'image' => array(
        'img_title_cpt_480x249' => array(
          'default preset' => 'original',
          'preset' => 'img_480x249',
        ),
      ),
      'audio' => array(
        'img_title_cpt_480x249' => array(
          'default preset' => 'original',
        ),
      ),
      'video' => array(
        'img_title_cpt_480x249' => array(
          'default preset' => 'original',
        ),
      ),
      'default' => array(
        'img_title_cpt_480x249' => array(
          'default preset' => 'original',
        ),
      ),
    ),
  );
  return $styles;
}

/**
 * Implements hook_styles_default_presets_alter().
 */
function unesco_media_styles_default_presets_alter(&$presets) {
  $styles = styles_default_styles();
  if ($styles['file']['styles']['img_143x107']['storage'] == STYLES_STORAGE_DEFAULT) {
    $presets['file']['containers']['image']['styles']['img_143x107'] = array(
      'default preset' => 'original',
      'preset' => 'img_143x107',
    );

    $presets['file']['containers']['audio']['styles']['img_143x107'] = array(
      'default preset' => 'original',
    );

    $presets['file']['containers']['video']['styles']['img_143x107'] = array(
      'default preset' => 'original',
    );

    $presets['file']['containers']['default']['styles']['img_143x107'] = array(
      'default preset' => 'original',
    );

  }
  if ($styles['file']['styles']['img_600x800']['storage'] == STYLES_STORAGE_DEFAULT) {
    $presets['file']['containers']['image']['styles']['img_600x800'] = array(
      'default preset' => 'original',
    );

    $presets['file']['containers']['audio']['styles']['img_600x800'] = array(
      'default preset' => 'original',
    );

    $presets['file']['containers']['video']['styles']['img_600x800'] = array(
      'default preset' => 'original',
    );

    $presets['file']['containers']['default']['styles']['img_600x800'] = array(
      'default preset' => 'original',
    );

  }
  if ($styles['file']['styles']['img_copy_146x89']['storage'] == STYLES_STORAGE_DEFAULT) {
    $presets['file']['containers']['image']['styles']['img_copy_146x89'] = array(
      'default preset' => 'original',
      'preset' => 'img_146x89',
    );

    $presets['file']['containers']['audio']['styles']['img_copy_146x89'] = array(
      'default preset' => 'original',
    );

    $presets['file']['containers']['video']['styles']['img_copy_146x89'] = array(
      'default preset' => 'original',
    );

    $presets['file']['containers']['default']['styles']['img_copy_146x89'] = array(
      'default preset' => 'original',
    );

  }
  if ($styles['file']['styles']['img_title_cpt_480x249']['storage'] == STYLES_STORAGE_DEFAULT) {
    $presets['file']['containers']['image']['styles']['img_title_cpt_480x249'] = array(
      'default preset' => 'original',
      'preset' => 'img_480x249',
    );

    $presets['file']['containers']['audio']['styles']['img_title_cpt_480x249'] = array(
      'default preset' => 'original',
    );

    $presets['file']['containers']['video']['styles']['img_title_cpt_480x249'] = array(
      'default preset' => 'original',
    );

    $presets['file']['containers']['default']['styles']['img_title_cpt_480x249'] = array(
      'default preset' => 'original',
    );

  }
  if ($styles['media']['styles']['img_143x107']['storage'] == STYLES_STORAGE_DEFAULT) {
    $presets['media']['containers']['image']['styles']['img_143x107'] = array(
      'default preset' => 'original',
      'preset' => 'img_143x107',
    );

    $presets['media']['containers']['audio']['styles']['img_143x107'] = array(
      'default preset' => 'original',
    );

    $presets['media']['containers']['video']['styles']['img_143x107'] = array(
      'default preset' => 'original',
    );

    $presets['media']['containers']['default']['styles']['img_143x107'] = array(
      'default preset' => 'original',
    );

  }
  if ($styles['media']['styles']['img_600x800']['storage'] == STYLES_STORAGE_DEFAULT) {
    $presets['media']['containers']['image']['styles']['img_600x800'] = array(
      'default preset' => 'original',
    );

    $presets['media']['containers']['audio']['styles']['img_600x800'] = array(
      'default preset' => 'original',
    );

    $presets['media']['containers']['video']['styles']['img_600x800'] = array(
      'default preset' => 'original',
    );

    $presets['media']['containers']['default']['styles']['img_600x800'] = array(
      'default preset' => 'original',
    );

  }
  if ($styles['media']['styles']['img_copy_146x89']['storage'] == STYLES_STORAGE_DEFAULT) {
    $presets['media']['containers']['image']['styles']['img_copy_146x89'] = array(
      'default preset' => 'original',
      'preset' => 'img_146x89',
    );

    $presets['media']['containers']['audio']['styles']['img_copy_146x89'] = array(
      'default preset' => 'original',
    );

    $presets['media']['containers']['video']['styles']['img_copy_146x89'] = array(
      'default preset' => 'original',
    );

    $presets['media']['containers']['default']['styles']['img_copy_146x89'] = array(
      'default preset' => 'original',
    );

  }
  if ($styles['media']['styles']['img_title_cpt_480x249']['storage'] == STYLES_STORAGE_DEFAULT) {
    $presets['media']['containers']['image']['styles']['img_title_cpt_480x249'] = array(
      'default preset' => 'original',
      'preset' => 'img_480x249',
    );

    $presets['media']['containers']['audio']['styles']['img_title_cpt_480x249'] = array(
      'default preset' => 'original',
    );

    $presets['media']['containers']['video']['styles']['img_title_cpt_480x249'] = array(
      'default preset' => 'original',
    );

    $presets['media']['containers']['default']['styles']['img_title_cpt_480x249'] = array(
      'default preset' => 'original',
    );

  }
}
