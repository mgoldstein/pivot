<?php
/**
 * @file
 * pivot_feed.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function pivot_feed_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'feed';
  $feeds_importer->config = array(
    'name' => 'DML Headlines',
    'description' => 'Import RSS or Atom feeds, create nodes from feed items.',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 1,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsSyndicationParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'bundle' => 'feed_item',
        'update_existing' => '0',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'timestamp',
            'target' => 'created',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'url',
            'target' => 'url',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'description',
            'target' => 'field_feed_item_description',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'url',
            'target' => 'field_feed_link',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'description',
            'target' => 'field_promo_image',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'parent:nid',
            'target' => 'field_feed_ref_id',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'timestamp',
            'target' => 'field_feed_created_date',
            'unique' => FALSE,
          ),
        ),
        'input_format' => 'full_html',
        'author' => 0,
        'authorize' => 1,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => 'feed',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['feed'] = $feeds_importer;

  return $export;
}
