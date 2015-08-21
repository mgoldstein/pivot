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

  // Exported image style: blog_article.
  $styles['blog_article'] = array(
    'effects' => array(
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 528,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'blog_article',
  );

  // Exported image style: gallery_image.
  $styles['gallery_image'] = array(
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 600,
          'height' => 335,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'gallery_image',
  );

  // Exported image style: impact_promo_imagestyle.
  $styles['impact_promo_imagestyle'] = array(
    'label' => 'Impact Promo Imagestyle',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 620,
          'height' => 237,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: must_see_videos_125x70.
  $styles['must_see_videos_125x70'] = array(
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 125,
          'height' => 70,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'must_see_videos_125x70',
  );

  // Exported image style: profile_image.
  $styles['profile_image'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'profile_image',
  );

  // Exported image style: promo_square.
  $styles['promo_square'] = array(
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'promo_square',
  );

  // Exported image style: promo_widescreen.
  $styles['promo_widescreen'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 620,
          'height' => 348,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'promo_widescreen',
  );

  return $styles;
}
