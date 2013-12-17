<?php
/**
 * @file
 * impact_movies_nodequeue_features.features.inc
 */

/**
 * Implements hook_views_api().
 */
function impact_movies_nodequeue_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function impact_movies_nodequeue_features_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: impact_movies
  $nodequeues['impact_movies'] = array(
    'name' => 'impact_movies',
    'title' => 'Impact Movies',
    'subqueue_title' => '',
    'size' => 0,
    'link' => 'Add to Impact Movies',
    'link_remove' => 'Remove from Impact Movies',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 1,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'types' => array(
      0 => 'movie',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function impact_movies_nodequeue_features_image_default_styles() {
  $styles = array();

  // Exported image style: impact_promo_imagestyle.
  $styles['impact_promo_imagestyle'] = array(
    'name' => 'impact_promo_imagestyle',
    'label' => 'Impact Promo Imagestyle',
    'effects' => array(
      3 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 620,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
