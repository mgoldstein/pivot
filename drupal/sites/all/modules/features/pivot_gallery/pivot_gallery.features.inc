<?php
/**
 * @file
 * pivot_gallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pivot_gallery_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function pivot_gallery_node_info() {
  $items = array(
    'gallery' => array(
      'name' => t('Gallery'),
      'base' => 'node_content',
      'description' => t('Gallery for images'),
      'has_title' => '1',
      'title_label' => t('Gallery Title'),
      'help' => '',
    ),
  );
  return $items;
}
