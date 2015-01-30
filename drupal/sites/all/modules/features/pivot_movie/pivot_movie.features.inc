<?php
/**
 * @file
 * pivot_movie.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pivot_movie_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
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
function pivot_movie_fe_nodequeue_export_fields() {
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

  // Exported nodequeues: movies
  $nodequeues['movies'] = array(
    'name' => 'movies',
    'title' => 'Movies',
    'subqueue_title' => '',
    'size' => 0,
    'link' => 'Add to Movies Landing Page',
    'link_remove' => 'Remove from Movies Landing Page',
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
  drupal_alter('node_info', $items);
  return $items;
}
