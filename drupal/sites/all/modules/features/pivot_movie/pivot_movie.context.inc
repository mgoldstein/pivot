<?php
/**
 * @file
 * pivot_movie.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function pivot_movie_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'movies';
  $context->description = 'Movies node pages';
  $context->tag = '';
  $context->conditions = array(
    'error' => array(
      'values' => array(
        1 => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'movies/*' => 'movies/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'pivot_movies-pivot_movies_hero' => array(
          'module' => 'pivot_movies',
          'delta' => 'pivot_movies_hero',
          'region' => 'preface',
          'weight' => '-10',
        ),
        'dfp-pivot_ros_rr_300x250' => array(
          'module' => 'dfp',
          'delta' => 'pivot_ros_rr_300x250',
          'region' => 'right_sidebar',
          'weight' => '-10',
        ),
        'pivot_schedule-show_listing' => array(
          'module' => 'pivot_schedule',
          'delta' => 'show_listing',
          'region' => 'right_sidebar',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Movies node pages');
  $export['movies'] = $context;

  return $export;
}
