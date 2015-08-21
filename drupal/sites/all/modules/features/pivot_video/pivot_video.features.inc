<?php
/**
 * @file
 * pivot_video.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pivot_video_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "pm_jwplayer" && $api == "pm_jwplayer_presets") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function pivot_video_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: must_see_videos
  $nodequeues['must_see_videos'] = array(
    'name' => 'must_see_videos',
    'title' => 'Must See Videos',
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
      0 => 'video',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_node_info().
 */
function pivot_video_node_info() {
  $items = array(
    'video' => array(
      'name' => t('Video'),
      'base' => 'node_content',
      'description' => t('An uploaded or embedded video'),
      'has_title' => '1',
      'title_label' => t('Video Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
