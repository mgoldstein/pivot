<?php
/**
 * @file
 * pivot_channels.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function pivot_channels_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'pivot_channels';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*' => '*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-pivot_channels-pivot_channels' => array(
          'module' => 'views',
          'delta' => 'pivot_channels-pivot_channels',
          'region' => 'prefix_footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['pivot_channels'] = $context;

  return $export;
}
