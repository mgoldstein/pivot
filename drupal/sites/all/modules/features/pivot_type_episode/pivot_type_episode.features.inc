<?php
/**
 * @file
 * pivot_type_episode.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pivot_type_episode_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function pivot_type_episode_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function pivot_type_episode_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: show_episodes
  $nodequeues['show_episodes'] = array(
    'name' => 'show_episodes',
    'title' => 'Show Episodes',
    'subqueue_title' => '%subqueue Episodes',
    'size' => 0,
    'link' => 'Add to List',
    'link_remove' => 'Remove from List',
    'owner' => 'smartqueue_taxonomy',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 1,
    'reference' => 'field_show',
    'reverse' => 0,
    'i18n' => 0,
    'types' => array(
      0 => 'episode',
    ),
    'roles' => array(),
    'count' => 0,
    'use_parents' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_node_info().
 */
function pivot_type_episode_node_info() {
  $items = array(
    'episode' => array(
      'name' => t('Episode'),
      'base' => 'node_content',
      'description' => t('A single episode of a show.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
