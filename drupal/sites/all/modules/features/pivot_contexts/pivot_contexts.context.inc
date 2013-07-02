<?php
/**
 * @file
 * pivot_contexts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function pivot_contexts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'global';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-primary' => array(
          'module' => 'menu',
          'delta' => 'menu-primary',
          'region' => 'header',
          'weight' => '-10',
        ),
        'menu-menu-secondary' => array(
          'module' => 'menu',
          'delta' => 'menu-secondary',
          'region' => 'header',
          'weight' => '-9',
        ),
        'menu-menu-watch-live' => array(
          'module' => 'menu',
          'delta' => 'menu-watch-live',
          'region' => 'header',
          'weight' => '-8',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'header',
          'weight' => '-7',
        ),
        'pivot_global-pivot_global_footer' => array(
          'module' => 'pivot_global',
          'delta' => 'pivot_global_footer',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'dfp-pivot_ros_background_1x1' => array(
          'module' => 'dfp',
          'delta' => 'pivot_ros_background_1x1',
          'region' => 'footer',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['global'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage';
  $context->description = 'Context for the homepage';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'dfp-pivot_ros_rr_300x250' => array(
          'module' => 'dfp',
          'delta' => 'pivot_ros_rr_300x250',
          'region' => 'right_sidebar',
          'weight' => '-10',
        ),
        'pivot_global-find_pivot_sidebar' => array(
          'module' => 'pivot_global',
          'delta' => 'find_pivot_sidebar',
          'region' => 'right_sidebar',
          'weight' => '-9',
        ),
        'pivot_global-pivot_twitter_widget' => array(
          'module' => 'pivot_global',
          'delta' => 'pivot_twitter_widget',
          'region' => 'right_sidebar',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for the homepage');
  $export['homepage'] = $context;

  return $export;
}
