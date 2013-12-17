<?php
/**
 * @file
 * pivot_impact_movies.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pivot_impact_movies_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function pivot_impact_movies_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function pivot_impact_movies_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: impact_movies
  $nodequeues['impact_movies'] = array(
    'name' => 'impact_movies',
    'title' => 'Impact Movies',
    'subqueue_title' => '',
    'size' => 0,
    'link' => 'Add to Impact Movies',
    'link_remove' => 'Remove from Impact Movies',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 1,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'types' => array(
      0 => 'movie',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}
