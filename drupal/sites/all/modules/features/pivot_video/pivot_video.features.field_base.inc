<?php
/**
 * @file
 * pivot_video.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function pivot_video_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_video_type'
  $field_bases['field_video_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_video_type',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        1 => 'Single Video',
        2 => 'Playlist',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  return $field_bases;
}
