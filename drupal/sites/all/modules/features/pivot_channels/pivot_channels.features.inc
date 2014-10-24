<?php
/**
 * @file
 * pivot_channels.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pivot_channels_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function pivot_channels_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function pivot_channels_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: pivot_channels
  $nodequeues['pivot_channels'] = array(
    'name' => 'pivot_channels',
    'title' => 'Pivot Channels',
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
      0 => 'channel',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_node_info().
 */
function pivot_channels_node_info() {
  $items = array(
    'channel' => array(
      'name' => t('Channel'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
