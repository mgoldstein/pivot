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
  $context->name = 'blog_post';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article' => 'article',
      ),
      'options' => array(
        'node_form' => '0',
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
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['blog_post'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'campaign_dml';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'error' => array(
      'values' => array(
        1 => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'campaigns/eyes-wide-open' => 'campaigns/eyes-wide-open',
        'campaigns/eyes-wide-open/*' => 'campaigns/eyes-wide-open/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'pivot_dml-pivot_dml_hero' => array(
          'module' => 'pivot_dml',
          'delta' => 'pivot_dml_hero',
          'region' => 'preface',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['campaign_dml'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'campaign_pivot';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'pivot/blog' => 'pivot/blog',
        'pivot/blog/*' => 'pivot/blog/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'pivot_campaign-pivot_campaign_hero' => array(
          'module' => 'pivot_campaign',
          'delta' => 'pivot_campaign_hero',
          'region' => 'preface',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['campaign_pivot'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'feed';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'feed' => 'feed',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-feed_items-block' => array(
          'module' => 'views',
          'delta' => 'feed_items-block',
          'region' => 'content',
          'weight' => '-9',
        ),
        'newsletter_campaign-1' => array(
          'module' => 'newsletter_campaign',
          'delta' => '1',
          'region' => 'right_sidebar',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['feed'] = $context;

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
        'pivot_global-pivot_global_footer' => array(
          'module' => 'pivot_global',
          'delta' => 'pivot_global_footer',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['global'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'global_non_header';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'dfp-pivot_ros_leaderboard_728x90' => array(
          'module' => 'dfp',
          'delta' => 'pivot_ros_leaderboard_728x90',
          'region' => 'header',
          'weight' => '-10',
        ),
        'pivot_global-pivot_global_header_nav' => array(
          'module' => 'pivot_global',
          'delta' => 'pivot_global_header_nav',
          'region' => 'header',
          'weight' => '-9',
        ),
        'dfp-pivot_ros_background_1x1' => array(
          'module' => 'dfp',
          'delta' => 'pivot_ros_background_1x1',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['global_non_header'] = $context;

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
        'pivot_schedule-primetime_listing' => array(
          'module' => 'pivot_schedule',
          'delta' => 'primetime_listing',
          'region' => 'header',
          'weight' => '-10',
        ),
        'views-homepage_slider-block' => array(
          'module' => 'views',
          'delta' => 'homepage_slider-block',
          'region' => 'header',
          'weight' => '-9',
        ),
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

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'movies_landing';
  $context->description = 'The Movies Landing Page';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'movies' => 'movies',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'pivot_schedule-primetime_listing' => array(
          'module' => 'pivot_schedule',
          'delta' => 'primetime_listing',
          'region' => 'preface',
          'weight' => '-10',
        ),
        'dfp-pivot_ros_rr_300x250' => array(
          'module' => 'dfp',
          'delta' => 'pivot_ros_rr_300x250',
          'region' => 'right_sidebar',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('The Movies Landing Page');
  $export['movies_landing'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'shows';
  $context->description = 'Show node pages';
  $context->tag = '';
  $context->conditions = array(
    'error' => array(
      'values' => array(
        1 => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'shows/*' => 'shows/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'pivot_shows-pivot_shows_hero' => array(
          'module' => 'pivot_shows',
          'delta' => 'pivot_shows_hero',
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
  t('Show node pages');
  $export['shows'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'shows_landing';
  $context->description = 'The Shows Landing Page';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'shows' => 'shows',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'pivot_schedule-primetime_listing' => array(
          'module' => 'pivot_schedule',
          'delta' => 'primetime_listing',
          'region' => 'preface',
          'weight' => '-10',
        ),
        'dfp-pivot_ros_rr_300x250' => array(
          'module' => 'dfp',
          'delta' => 'pivot_ros_rr_300x250',
          'region' => 'right_sidebar',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('The Shows Landing Page');
  $export['shows_landing'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'videos';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'video' => 'video',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-must_see_videos-block' => array(
          'module' => 'views',
          'delta' => 'must_see_videos-block',
          'region' => 'right_sidebar',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['videos'] = $context;

  return $export;
}
