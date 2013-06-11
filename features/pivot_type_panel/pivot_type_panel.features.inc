<?php
/**
 * @file
 * pivot_type_panel.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pivot_type_panel_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
