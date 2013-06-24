<?php
/**
 * @file
 * pivot_movie.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pivot_movie_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function pivot_movie_node_info() {
  $items = array(
    'movie' => array(
      'name' => t('Movie'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Movie Title'),
      'help' => '',
    ),
  );
  return $items;
}
