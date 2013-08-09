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
  $strongarm->value = '(function ($, Drupal, window, document, s, undefined) {
  s.trackingServer = "metrics.pivot.tv";
  var url_path = "[current-page:url:path]";
  if (url_path == "node" || url_path == "homepage") {
    s.pageName = s.channel = "homepage";
  } else if (url_path == "404") {
    s.pageType = "errorPage";
  }
  else {
    s.pageName = (window.location.pathname.replace(/^\\//, ""));
    s.channel = (window.location.pathname.replace(/^\\//, "")).split( \'/\' )[0];
  }
  s.eVar30 = url_path;
  if (window.location.pathname == "/") {
    s.eVar12 = s.prop12 = (window.location.href.replace(/\\/$/, ""));
  }
  else {
    s.eVar12 = s.prop12 = window.location.href;
  }
  var published_date = "[node:published:custom:Y-m-d]";
  if (published_date.length > 0) {
    s.eVar20 = s.prop19 = published_date;
  }
  var author_name = "[node:field-person-ref:name-field-person-name]";
  if (author_name.length > 0) {
    s.eVar17 = s.prop16 = author_name;
  }
  var url_parts = url_path.split("/");
  if (url_parts.length > 1 && url_parts[0] == "search") {
    s.eVar7 = "[current-page:url:args:last]";
  }
  var node_type = "[node:content-type:name]";
  var node_title = "[node:title]";
  if (node_type.length > 0) {
    s.hier1 = node_type;
    if(node_title.length > 0) {
      s.hier2 = [node_type, node_title].join(":");
    }
    s.eVar4 = s.prop4 = node_type;
  }
  var sections = ["pivot/blog","movies","shows"];
  var machine_name = "[node:content-type:machine-name]";
  if (sections.indexOf(url_path) != -1) {
    s.eVar4 = s.prop4 = "Section Landing";
  }
  else if (machine_name == "webform") {
    s.eVar4 = s.prop4 = "Contact Us";
  }
  else if (url_parts.length >= 3) {
    if (url_parts[0] == \'shows\' && url_parts[2] == \'episodes\') {
      s.eVar4 = s.prop4 = "Episode List";
    }
    else if (url_parts[0] == \'shows\' && url_parts[2] == \'cast\') {
      s.eVar4 = s.prop4 = "Cast List";
    }
  }
  var now = new Date();
  var weekdays = ["Sunday","Monday","Tuesday","Wednesday","Thursday","Friday",
    "Saturday"];
  var mins = now.getMinutes() < 30 ? "00" : "30";
  var meridiem  = now.getHours() < 12 ? "AM" : "PM";
  var hour = now.getHours();
  if (hour == 0) { hour = 12; } else if (hour > 12) { hour = hour - 12; }
  s.eVar8 = s.prop8 = hour.toString() + ":" + mins + " " + meridiem;
  s.eVar9 = s.prop9 = weekdays[now.getDay()];
  var show_title = $(\'#show-header\').data(\'show-title\');
  if (show_title && show_title.length > 0) {
    s.eVar70 = s.prop70 = show_title;
  }
})(jQuery, Drupal, this, this.document, window.s);
';
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
  $strongarm->value = array();
  $export['sitecatalyst_variables'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sitecatalyst_version';
  $strongarm->value = 'H.25.4.';
  $export['sitecatalyst_version'] = $strongarm;

  return $export;
}
