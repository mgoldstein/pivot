<?php

define('WORDLET_CSS_DIRECTORY', 'sites/all/themes/pivot1/');
define('WORDLET_JS_DIRECTORY', 'sites/all/themes/pivot1/');

/**
 * Templates can be placed in any directory under
 *
 *   profiles/takepart/themes/takepart3/templates
 *
 * Template names should use underscores (_) here, and dashes (-) in the actual
 * filename. The reason for the difference is so templates can be have a
 * preprocess hook function (the name of which may not include dashes)
 */

/*
    // Wordlet page.
    'intel_girls_home' => array(
      'title' => 'Intel Girls Home',
      // Path relative to site root (do NOT include the initial slash)
      'path' => 'intelgirls',
      // Access control flag
      'published' => TRUE,
      // When rendering a page Drupal uses two templates, one for the content
      // and second to wrap around the content. These are the wrapper templates
      // if this key is left out it will be defaulted to a single 'html' wrapper
      'wrappers' => array('html'),
      // CSS files to add when rendering the page, paths are relative to
      // WORDLET_CSS_DIRECTORY defined at the top of this file.
      'css' => array(
        //'reset.css',
        'campaigns/intelchange/intelchange.css',
      ),
      // JS files to add when rendering the page, paths are relative to
      // WORDLET_JS_DIRECTORY defined at the top of this file.
      'js' => array(
        //'plugin.js',
        //'intelgirls.js',
      ),
      // Additional wordlet groups to load ordered by precedence (lower to higer)
      'load' => array('site', 'intel_girls_campaign'),
    ),
*/

function _wordlet_configuration() {
  return array(

    // Simple wordlet group.
    'site' => array(
      'title' => 'Site Wordlets',
    ),

    // Test
    'test' => array(
      'title' => 'Test',
      'path' => 'wordletstest',
      'published' => FALSE,
      'wrappers' => array(),
    ),

    // Blank Wordlet Page
    'test_blank' => array(
      'title' => 'Test - Blank Campaign',
      'path' => 'test/blank-campaign-page',
      'published' => TRUE,
      'wrappers' => array('html'),
      'css' => array(),
      'js' => array(),
      'load' => array(),
    ),

    // Longtail video
    'longtail_video' => array(
      'title' => 'Video',
      'path' => 'video/players',
      'published' => TRUE,
      'wrappers' => array(),
      'css' => array(),
      'js' => array(),
      'load' => array(),
    ),
  );
}
