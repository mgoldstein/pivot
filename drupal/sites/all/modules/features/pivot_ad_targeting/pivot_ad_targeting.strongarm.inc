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
  $strongarm->name = 'dfp_adtest_adunit';
  $strongarm->value = '';
  $export['dfp_adtest_adunit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dfp_async_rendering';
  $strongarm->value = 1;
  $export['dfp_async_rendering'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dfp_collapse_empty_divs';
  $strongarm->value = 1;
  $export['dfp_collapse_empty_divs'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dfp_default_slug';
  $strongarm->value = '';
  $export['dfp_default_slug'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dfp_enable_ad_categories';
  $strongarm->value = 0;
  $export['dfp_enable_ad_categories'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dfp_enable_ad_categories_bundles';
  $strongarm->value = array(
    'person_to_media_relationship' => 0,
    'global_tags' => 0,
  );
  $export['dfp_enable_ad_categories_bundles'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dfp_injected_js';
  $strongarm->value = '';
  $export['dfp_injected_js'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dfp_network_id';
  $strongarm->value = '/4355895';
  $export['dfp_network_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dfp_single_request';
  $strongarm->value = 1;
  $export['dfp_single_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dfp_targeting';
  $strongarm->value = array(
    0 => array(
      'target' => 'PageTitle',
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
