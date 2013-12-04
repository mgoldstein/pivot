<?php
/**
 * @file
 * pivot_video.pm_jwplayer_presets.inc
 */

/**
 * Implements hook_default_pm_jwplayer_presets().
 */
function pivot_video_default_pm_jwplayer_presets() {
  $export = array();

  $pm_jwplayer_preset = new stdClass();
  $pm_jwplayer_preset->disabled = FALSE; /* Edit this to true to make a default pm_jwplayer_preset disabled initially */
  $pm_jwplayer_preset->api_version = 1;
  $pm_jwplayer_preset->preset_name = 'Full Content';
  $pm_jwplayer_preset->machine_name = 'full_content';
  $pm_jwplayer_preset->description = 'Configuration for player on video node pages.';
  $pm_jwplayer_preset->settings = array(
    'promo' => array(
      'image' => '',
      'title' => '[node:title]',
      'displaytitle' => '1',
    ),
    'layout' => array(
      'controls' => '1',
      'responsive' => '1',
      'aspectratio' => '16:9',
      'width' => '',
      'height' => '',
      'skin' => 'glow',
      'stretching' => 'uniform',
    ),
    'playback' => array(
      'autostart' => '0',
      'fallback' => '0',
      'mute' => '0',
      'primary' => 'flash',
      'repeat' => '0',
    ),
    'region_limits' => array(
      'allowed_regions' => '[node:field-allowed-regions]',
    ),
    'listbar' => array(
      'position' => '',
      'size' => '',
      'layout' => '',
    ),
    'sharing' => array(
      'link' => '[node:url:absolute]',
      'code' => '',
      'heading' => 'Share This Video',
    ),
    'related' => array(
      'file' => '',
      'onclick' => '',
      'oncomplete' => '',
      'heading' => '',
      'dimensions' => '',
    ),
    'advertising' => array(
      'client' => '',
      'tag' => '',
    ),
    'jwplayer_analytics' => array(
      'enabled' => '0',
    ),
    'google_analytics' => array(
      'idstring' => '',
      'trackingobject' => '',
    ),
    'sitecatalyst' => array(
      'mediaName' => '',
      'playerName' => '',
    ),
  );
  $export['full_content'] = $pm_jwplayer_preset;

  $pm_jwplayer_preset = new stdClass();
  $pm_jwplayer_preset->disabled = FALSE; /* Edit this to true to make a default pm_jwplayer_preset disabled initially */
  $pm_jwplayer_preset->api_version = 1;
  $pm_jwplayer_preset->preset_name = 'Teaser';
  $pm_jwplayer_preset->machine_name = 'teaser';
  $pm_jwplayer_preset->description = 'Teaser player configuration';
  $pm_jwplayer_preset->settings = array(
    'promo' => array(
      'image' => '',
      'title' => '[node:title]',
      'displaytitle' => '1',
    ),
    'layout' => array(
      'controls' => '1',
      'responsive' => '1',
      'aspectratio' => '16:9',
      'width' => '',
      'height' => '',
      'skin' => 'glow',
      'stretching' => 'uniform',
    ),
    'playback' => array(
      'autostart' => '0',
      'fallback' => '0',
      'mute' => '0',
      'primary' => 'flash',
      'repeat' => '0',
    ),
    'region_limits' => array(
      'allowed_regions' => '[node:field-allowed-regions]',
    ),
    'listbar' => array(
      'position' => '',
      'size' => '',
      'layout' => '',
    ),
    'sharing' => array(
      'link' => '[node:url:absolute]',
      'code' => '',
      'heading' => 'Share This Video',
    ),
    'related' => array(
      'file' => '',
      'onclick' => '',
      'oncomplete' => '',
      'heading' => '',
      'dimensions' => '',
    ),
    'advertising' => array(
      'client' => '',
      'tag' => '',
    ),
    'jwplayer_analytics' => array(
      'enabled' => '0',
    ),
    'google_analytics' => array(
      'idstring' => '',
      'trackingobject' => '',
    ),
    'sitecatalyst' => array(
      'mediaName' => '',
      'playerName' => '',
    ),
  );
  $export['teaser'] = $pm_jwplayer_preset;

  return $export;
}
