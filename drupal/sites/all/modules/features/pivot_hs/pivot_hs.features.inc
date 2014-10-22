<?php
/**
 * @file
 * pivot_hs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pivot_hs_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function pivot_hs_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: homepage_slider
  $nodequeues['homepage_slider'] = array(
    'name' => 'homepage_slider',
    'title' => 'Homepage Slider',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'types' => array(
      0 => 'homepage_slide',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_node_info().
 */
function pivot_hs_node_info() {
  $items = array(
    'homepage_slide' => array(
      'name' => t('Homepage Slide'),
      'base' => 'node_content',
      'description' => t('A slide for the homepage slideshow'),
      'has_title' => '1',
      'title_label' => t('Slide Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
