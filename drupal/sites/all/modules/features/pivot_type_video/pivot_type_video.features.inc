<?php
/**
 * @file
 * pivot_type_video.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pivot_type_video_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function pivot_type_video_node_info() {
  $items = array(
    'video' => array(
      'name' => t('Video'),
      'base' => 'node_content',
      'description' => t('A Longtail video for the site or for a specific show.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('If the Bits on the Run video selector is not shown, you must log in <a href="/admin/config/media/botr">here</a> to activate it.'),
    ),
  );
  return $items;
}
