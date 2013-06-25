<?php
/**
 * @file
 * pivot_dl_file.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pivot_dl_file_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function pivot_dl_file_node_info() {
  $items = array(
    'download' => array(
      'name' => t('Downloadable File'),
      'base' => 'node_content',
      'description' => t('A downloadable file related to a show or campaign.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
