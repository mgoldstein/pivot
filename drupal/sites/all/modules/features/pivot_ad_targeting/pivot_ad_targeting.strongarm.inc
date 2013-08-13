<?php
/**
 * @file
 * pivot_ad_targeting.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function pivot_ad_targeting_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dfp_targeting';
  $strongarm->value = array(
    0 => array(
      'target' => 'page-title',
      'value' => '[current-page:page-title]',
    ),
    1 => array(
      'target' => 'show',
      'value' => '[current-page:url:args:value:1]',
    ),
  );
  $export['dfp_targeting'] = $strongarm;

  return $export;
}
