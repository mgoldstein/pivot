<?php
/**
 * @file
 * pivot_ad_targeting.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function pivot_ad_targeting_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_dfp_ad_categories'
  $field_bases['field_dfp_ad_categories'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_dfp_ad_categories',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'dfp_ad_categories',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
