<?php
/**
 * @file
 * pivot_text_formats.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function pivot_text_formats_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'embeddable_default_hide_links';
  $strongarm->value = 1;
  $export['embeddable_default_hide_links'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'embeddable_default_hide_title';
  $strongarm->value = 1;
  $export['embeddable_default_hide_title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'embeddable_default_node_bundles';
  $strongarm->value = array(
    'video' => 'video',
    'action' => 0,
    'article' => 0,
    'page' => 0,
    'blog' => 0,
    'campaign' => 0,
    'download' => 0,
    'episode' => 0,
    'feed' => 0,
    'feed_item' => 0,
    'gallery' => 0,
    'homepage_slide' => 0,
    'movie' => 0,
    'person' => 0,
    'promo' => 0,
    'show' => 0,
    'webform' => 0,
  );
  $export['embeddable_default_node_bundles'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'embeddable_default_view_modes';
  $strongarm->value = array(
    'embedded' => 'embedded',
    'full' => 0,
    'teaser' => 0,
    'rss' => 0,
    'search_index' => 0,
    'search_result' => 0,
    'diff_standard' => 0,
    'promo' => 0,
    'promo_alt' => 0,
    'promo_impact' => 0,
    'token' => 0,
  );
  $export['embeddable_default_view_modes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_view_modes';
  $strongarm->value = array(
    'node' => array(
      'embedded' => array(
        'label' => 'Embedded',
        'custom settings' => 1,
      ),
    ),
  );
  $export['entity_view_modes'] = $strongarm;

  return $export;
}
