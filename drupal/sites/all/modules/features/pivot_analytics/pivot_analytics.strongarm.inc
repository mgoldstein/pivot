<?php
/**
 * @file
 * pivot_analytics.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function pivot_analytics_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sitecatalyst_codesnippet';
  $strongarm->value = 's.trackingServer="metrics.pivot.tv";
if ("[current-page:url:path]" == "node") {
  s.pageName = "homepage";
} else {
  s.pageName = (window.location.pathname.replace(/^\//, ""));
  s.channel = (window.location.pathname.replace(/^\//, "")).split( \'/\' )[0];
}
if ("[current-page:url:path]" == "404") {
  s.pageType="errorPage";
}
if(\'[node:content-type:name]\'.length > 0) {
	s.hier1 = "[node:content-type:name]";
	if(\'[node:title]\'.length > 0) {
		s.hier2 = "[node:content-type:name]:[node:title]";
		if(\'[node:field_episode_number]\'.length > 0) {
			s.hier3 = "[node:content-type:name]:[node:title]:Episode [node:field_episode_number]";
		}
	}
}';
  $export['sitecatalyst_codesnippet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sitecatalyst_image_file_location';
  $strongarm->value = 'http://metrics.pivot.tv/b/ss/takepartpivot/1/H.25.4--NS/0';
  $export['sitecatalyst_image_file_location'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sitecatalyst_js_file_location';
  $strongarm->value = '/sites/all/libraries/sitecatalyst/s_code_h25_core.js';
  $export['sitecatalyst_js_file_location'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sitecatalyst_track_administrator';
  $strongarm->value = 0;
  $export['sitecatalyst_track_administrator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sitecatalyst_track_anonymous_user';
  $strongarm->value = 1;
  $export['sitecatalyst_track_anonymous_user'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sitecatalyst_track_authenticated_user';
  $strongarm->value = 1;
  $export['sitecatalyst_track_authenticated_user'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sitecatalyst_track_contributor';
  $strongarm->value = 0;
  $export['sitecatalyst_track_contributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sitecatalyst_track_editor';
  $strongarm->value = 0;
  $export['sitecatalyst_track_editor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sitecatalyst_track_layout_editor';
  $strongarm->value = 0;
  $export['sitecatalyst_track_layout_editor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sitecatalyst_track_supervising_editor';
  $strongarm->value = 0;
  $export['sitecatalyst_track_supervising_editor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sitecatalyst_variables';
  $strongarm->value = array(
    0 => array(
      'name' => 's.prop4',
      'value' => '[node:content-type:name]',
    ),
    1 => array(
      'name' => 's.eVar4',
      'value' => '[node:content-type:name]',
    ),
    2 => array(
      'name' => 's.eVar20',
      'value' => '[node:published:custom:Y-m-d]',
    ),
    3 => array(
      'name' => 's.prop19',
      'value' => '[node:published:custom:Y-m-d]',
    ),
    4 => array(
      'name' => 's.eVar17',
      'value' => '[node:field-person-ref:field_person_name]',
    ),
    5 => array(
      'name' => 's.prop16',
      'value' => '[node:field-person-ref:field_person_name]',
    ),
    6 => array(
      'name' => 's.eVar19',
      'value' => '[node:field_series]',
    ),
    7 => array(
      'name' => 's.prop18',
      'value' => '[node:field_series]',
    ),
    8 => array(
      'name' => 's.eVar70',
      'value' => '[node:field_show]',
    ),
    9 => array(
      'name' => 's.prop70',
      'value' => '[node:field_show]',
    ),
  );
  $export['sitecatalyst_variables'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sitecatalyst_version';
  $strongarm->value = 'H.25.4.';
  $export['sitecatalyst_version'] = $strongarm;

  return $export;
}
