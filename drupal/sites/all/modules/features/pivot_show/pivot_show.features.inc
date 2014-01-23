<?php
/**
 * @file
 * pivot_show.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pivot_show_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function pivot_show_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: shows
  $nodequeues['shows'] = array(
    'name' => 'shows',
    'title' => 'Shows',
    'subqueue_title' => '',
    'size' => 0,
    'link' => 'Add to Shows Landing Page',
    'link_remove' => 'Remove from Shows Landing Page',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 1,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'types' => array(
      0 => 'show',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_node_info().
 */
function pivot_show_node_info() {
  $items = array(
    'show' => array(
      'name' => t('Show'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Show Title'),
      'help' => '',
    ),
  );
  return $items;
}
