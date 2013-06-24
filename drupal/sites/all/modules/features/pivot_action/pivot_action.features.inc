<?php
/**
 * @file
 * pivot_action.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pivot_action_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function pivot_action_node_info() {
  $items = array(
    'action' => array(
      'name' => t('Action'),
      'base' => 'node_content',
      'description' => t('Link to a TAB campaign'),
      'has_title' => '1',
      'title_label' => t('Call to action'),
      'help' => '',
    ),
  );
  return $items;
}
