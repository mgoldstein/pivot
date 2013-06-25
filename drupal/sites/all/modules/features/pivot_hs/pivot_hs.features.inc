<?php
/**
 * @file
 * pivot_hs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pivot_hs_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
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
  return $items;
}
