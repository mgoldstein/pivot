<?php
/**
 * @file
 * pivot_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function pivot_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: promo_square.
  $styles['promo_square'] = array(
    'name' => 'promo_square',
    'effects' => array(
      1 => array(
	'label' => 'Scale and crop',
	'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
	'effect callback' => 'image_scale_and_crop_effect',
	'dimensions callback' => 'image_resize_dimensions',
	'form callback' => 'image_resize_form',
	'summary theme' => 'image_resize_summary',
	'module' => 'image',
	'name' => 'image_scale_and_crop',
	'data' => array(
	  'width' => 300,
	  'height' => 300,
	),
	'weight' => 1,
      ),
    ),
  );

  // Exported image style: promo_widescreen.
  $styles['promo_widescreen'] = array(
    'name' => 'promo_widescreen',
    'effects' => array(
      2 => array(
	'label' => 'Scale and crop',
	'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
	'effect callback' => 'image_scale_and_crop_effect',
	'dimensions callback' => 'image_resize_dimensions',
	'form callback' => 'image_resize_form',
	'summary theme' => 'image_resize_summary',
	'module' => 'image',
	'name' => 'image_scale_and_crop',
	'data' => array(
	  'width' => 300,
	  'height' => 168,
	),
	'weight' => 1,
      ),
    ),
  );

  return $styles;
}
