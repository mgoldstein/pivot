<?php
/**
 * @file
 * pivot_ad_targeting.default_dfp_tags.inc
 */

/**
 * Implements hook_default_dfp_tag().
 */
function pivot_ad_targeting_default_dfp_tag() {
  $export = array();

  $tag = new stdClass();
  $tag->disabled = FALSE; /* Edit this to true to make a default tag disabled initially */
  $tag->api_version = 1;
  $tag->machinename = 'pivot_ros_background_1x1';
  $tag->slot = 'Pivot_ROS_Background_1x1';
  $tag->adunit = 'Pivot_ROS_Background_1x1';
  $tag->size = '1x1';
  $tag->block = 1;
  $tag->settings = array(
    'slug' => '',
    'short_tag' => 0,
    'adsense_ad_types' => '',
    'adsense_channel_ids' => '',
    'adsense_colors' => array(
      'background' => '',
      'border' => '',
      'link' => '',
      'text' => '',
      'url' => '',
    ),
    'targeting' => array(
      0 => array(
        'target' => 'show',
        'value' => '[current-page:url:args:value:1]',
      ),
    ),
  );
  $export['pivot_ros_background_1x1'] = $tag;

  $tag = new stdClass();
  $tag->disabled = FALSE; /* Edit this to true to make a default tag disabled initially */
  $tag->api_version = 1;
  $tag->machinename = 'pivot_ros_leaderboard_728x90';
  $tag->slot = 'Pivot_ROS_Leaderboard_728x90';
  $tag->adunit = 'Pivot_ROS_Leaderboard_728x90';
  $tag->size = '728x90';
  $tag->block = 1;
  $tag->settings = array(
    'slug' => '',
    'short_tag' => 0,
    'adsense_ad_types' => '',
    'adsense_channel_ids' => '',
    'adsense_colors' => array(
      'background' => '',
      'border' => '',
      'link' => '',
      'text' => '',
      'url' => '',
    ),
    'targeting' => array(
      0 => array(
        'target' => 'show',
        'value' => '[current-page:url:args:value:1]',
      ),
    ),
  );
  $export['pivot_ros_leaderboard_728x90'] = $tag;

  $tag = new stdClass();
  $tag->disabled = FALSE; /* Edit this to true to make a default tag disabled initially */
  $tag->api_version = 1;
  $tag->machinename = 'pivot_ros_mobile_300x50';
  $tag->slot = 'Pivot_ROS_Mobile_300x50';
  $tag->adunit = 'Pivot_ROS_Mobile_300x50';
  $tag->size = '300x50';
  $tag->block = 1;
  $tag->settings = array(
    'slug' => '',
    'short_tag' => 0,
    'adsense_ad_types' => '',
    'adsense_channel_ids' => '',
    'adsense_colors' => array(
      'background' => '',
      'border' => '',
      'link' => '',
      'text' => '',
      'url' => '',
    ),
    'targeting' => array(
      0 => array(
        'target' => 'show',
        'value' => '[current-page:url:args:value:1]',
      ),
    ),
  );
  $export['pivot_ros_mobile_300x50'] = $tag;

  $tag = new stdClass();
  $tag->disabled = FALSE; /* Edit this to true to make a default tag disabled initially */
  $tag->api_version = 1;
  $tag->machinename = 'pivot_ros_rr_300x250';
  $tag->slot = 'Pivot_ROS_RR_300x250';
  $tag->adunit = 'Pivot_ROS_RR_300x250';
  $tag->size = '300x250';
  $tag->block = 1;
  $tag->settings = array(
    'slug' => '',
    'short_tag' => 0,
    'adsense_ad_types' => '',
    'adsense_channel_ids' => '',
    'adsense_colors' => array(
      'background' => '',
      'border' => '',
      'link' => '',
      'text' => '',
      'url' => '',
    ),
    'targeting' => array(
      0 => array(
        'target' => 'show',
        'value' => '[current-page:url:args:value:1]',
      ),
    ),
  );
  $export['pivot_ros_rr_300x250'] = $tag;

  return $export;
}
