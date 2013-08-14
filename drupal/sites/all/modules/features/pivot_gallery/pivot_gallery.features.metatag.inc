<?php
/**
 * @file
 * pivot_gallery.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function pivot_gallery_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:gallery.
  $config['node:gallery'] = array(
    'instance' => 'node:gallery',
    'config' => array(
      'title' => array(
        'value' => '[current-page:page-title] | [site:name]',
      ),
      'description' => array(
        'value' => '[node:field_description]',
      ),
      'og:title' => array(
        'value' => '[current-page:page-title] | [site:name]',
      ),
      'og:description' => array(
        'value' => '[node:field_description]',
      ),
    ),
  );

  return $config;
}
