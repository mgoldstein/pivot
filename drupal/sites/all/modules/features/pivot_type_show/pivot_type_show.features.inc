<?php
/**
 * @file
 * pivot_type_show.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pivot_type_show_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function pivot_type_show_node_info() {
  $items = array(
    'show' => array(
      'name' => t('Show'),
      'base' => 'node_content',
      'description' => t('A show landing page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
