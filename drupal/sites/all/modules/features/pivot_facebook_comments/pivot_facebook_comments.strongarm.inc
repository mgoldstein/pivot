<?php
/**
 * @file
 * pivot_facebook_comments.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function pivot_facebook_comments_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facebook_comments_appid';
  $strongarm->value = '1395504993999657';
  $export['facebook_comments_appid'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facebook_comments_applyall';
  $strongarm->value = 0;
  $export['facebook_comments_applyall'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facebook_comments_block_amount';
  $strongarm->value = '15';
  $export['facebook_comments_block_amount'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facebook_comments_block_width';
  $strongarm->value = '300';
  $export['facebook_comments_block_width'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facebook_comments_style';
  $strongarm->value = 'light';
  $export['facebook_comments_style'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facebook_comments_types';
  $strongarm->value = array(
    'article' => 'article',
    'action' => 0,
    'page' => 0,
    'download' => 0,
    'episode' => 0,
    'campaign' => 0,
    'gallery' => 0,
    'homepage_slide' => 0,
    'movie' => 0,
    'person' => 0,
    'show' => 0,
    'video' => 0,
    'webform' => 0,
  );
  $export['facebook_comments_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facebook_comments_viewmode';
  $strongarm->value = 'full';
  $export['facebook_comments_viewmode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facebook_comments_width';
  $strongarm->value = '580';
  $export['facebook_comments_width'] = $strongarm;

  return $export;
}
