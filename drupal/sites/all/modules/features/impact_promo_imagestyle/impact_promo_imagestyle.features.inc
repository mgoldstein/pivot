<?php
/**
 * @file
 * impact_promo_imagestyle.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function impact_promo_imagestyle_image_default_styles() {
  $styles = array();

  // Exported image style: impact_promo_imagestyle.
  $styles['impact_promo_imagestyle'] = array(
    'name' => 'impact_promo_imagestyle',
    'label' => 'Impact Promo Imagestyle',
    'effects' => array(
      4 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 620,
          'height' => 237,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
