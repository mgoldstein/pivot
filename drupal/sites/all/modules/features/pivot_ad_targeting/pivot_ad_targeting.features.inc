<?php
/**
 * @file
 * pivot_ad_targeting.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pivot_ad_targeting_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "dfp" && $api == "default_dfp_tags") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
