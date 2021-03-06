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
  $context->name = 'blog_landing';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog' => 'blog',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-blog_listing-block_1' => array(
          'module' => 'views',
          'delta' => 'blog_listing-block_1',
          'region' => 'content',
          'weight' => '10',
        ),
        'pivot_global-find_pivot_sidebar' => array(
          'module' => 'pivot_global',
          'delta' => 'find_pivot_sidebar',
          'region' => 'right_sidebar',
          'weight' => '5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['blog_landing'] = $context;

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
        'pivot_global-find_pivot_sidebar' => array(
          'module' => 'pivot_global',
          'delta' => 'find_pivot_sidebar',
          'region' => 'right_sidebar',
          'weight' => '5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['blog_post'] = $context;

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
        'menu-menu-primary' => array(
          'module' => 'menu',
          'delta' => 'menu-primary',
          'region' => 'left_drawer',
          'weight' => '-10',
        ),
        'dfp-pivot_ros_leaderboard_728x90' => array(
          'module' => 'dfp',
          'delta' => 'pivot_ros_leaderboard_728x90',
          'region' => 'header',
          'weight' => '-10',
        ),
        'pivot_navigation-pivot_navigation' => array(
          'module' => 'pivot_navigation',
          'delta' => 'pivot_navigation',
          'region' => 'header',
          'weight' => '-8',
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
        'menu-menu-primary' => array(
          'module' => 'menu',
          'delta' => 'menu-primary',
          'region' => 'left_drawer',
          'weight' => '-10',
        ),
        'dfp-pivot_ros_leaderboard_728x90' => array(
          'module' => 'dfp',
          'delta' => 'pivot_ros_leaderboard_728x90',
          'region' => 'header',
          'weight' => '-89',
        ),
        'pivot_navigation-pivot_navigation' => array(
          'module' => 'pivot_navigation',
          'delta' => 'pivot_navigation',
          'region' => 'header',
          'weight' => '-88',
        ),
        'pivot_hpslider-hpslider' => array(
          'module' => 'pivot_hpslider',
          'delta' => 'hpslider',
          'region' => 'header',
          'weight' => '-87',
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
        'pivot_dynamic_blocks-pivot_promo_blocks_block_1' => array(
          'module' => 'pivot_dynamic_blocks',
          'delta' => 'pivot_promo_blocks_block_1',
          'region' => 'right_sidebar',
          'weight' => '-7',
        ),
        'pivot_global-pivot_twitter_widget' => array(
          'module' => 'pivot_global',
          'delta' => 'pivot_twitter_widget',
          'region' => 'right_sidebar',
          'weight' => '-6',
        ),
        'newsletter_campaign-1' => array(
          'module' => 'newsletter_campaign',
          'delta' => '1',
          'region' => 'right_sidebar',
          'weight' => '-8',
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
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for the homepage');
  $export['homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'interstitial_exclusions';
  $context->description = 'Pages that should not show an interstitial';
  $context->tag = 'Interstitials';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/*' => 'admin/*',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => '',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Interstitials');
  t('Pages that should not show an interstitial');
  $export['interstitial_exclusions'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'interstitial_referers';
  $context->description = 'Pages that should be marked with an interstitial referer type';
  $context->tag = 'Interstitials';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'pm_interstitial_referer' => array(
      'actve' => TRUE,
    ),
    'theme' => array(
      'title' => '',
      'subtitle' => '',
    ),
    'theme_html' => array(
      'class' => '',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Interstitials');
  t('Pages that should be marked with an interstitial referer type');
  $export['interstitial_referers'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'interstitials';
  $context->description = 'Pages that can show an interstitial';
  $context->tag = 'Interstitials';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~interstitial_exclusions' => '~interstitial_exclusions',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'pm_interstitial-interstitials' => array(
          'module' => 'pm_interstitial',
          'delta' => 'interstitials',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
    'theme' => array(
      'title' => '',
      'subtitle' => '',
    ),
    'theme_html' => array(
      'class' => '',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Interstitials');
  t('Pages that can show an interstitial');
  $export['interstitials'] = $context;

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
        'views-impact_movies-block_1' => array(
          'module' => 'views',
          'delta' => 'impact_movies-block_1',
          'region' => 'content',
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
        '~shows/teach' => '~shows/teach',
        '~shows/teach/*' => '~shows/teach/*',
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
          'weight' => '0',
        ),
        'pivot_global-find_pivot_sidebar' => array(
          'module' => 'pivot_global',
          'delta' => 'find_pivot_sidebar',
          'region' => 'right_sidebar',
          'weight' => '-5',
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
          'weight' => '32',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['videos'] = $context;

  return $export;
}
