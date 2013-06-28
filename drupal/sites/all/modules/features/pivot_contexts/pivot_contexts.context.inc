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
        'menu-menu-pivot-footer' => array(
          'module' => 'menu',
          'delta' => 'menu-pivot-footer',
          'region' => 'footer',
          'weight' => '-16',
        ),
        'menu-menu-follow-us' => array(
          'module' => 'menu',
          'delta' => 'menu-follow-us',
          'region' => 'footer',
          'weight' => '-15',
        ),
        'menu-menu-get-our-app' => array(
          'module' => 'menu',
          'delta' => 'menu-get-our-app',
          'region' => 'footer',
          'weight' => '-14',
        ),
        'menu-menu-participant-media' => array(
          'module' => 'menu',
          'delta' => 'menu-participant-media',
          'region' => 'footer',
          'weight' => '-13',
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
        'views-homepage_slider-block' => array(
          'module' => 'views',
          'delta' => 'homepage_slider-block',
          'region' => 'preface',
          'weight' => '-10',
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
