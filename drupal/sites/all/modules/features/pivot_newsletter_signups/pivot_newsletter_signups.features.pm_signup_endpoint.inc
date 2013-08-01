<?php
/**
 * @file
 * pivot_newsletter_signups.features.pm_signup_endpoint.inc
 */

/**
 * Implements hook_pm_signup_endpoint_defaults().
 */
function pivot_newsletter_signups_pm_signup_endpoint_defaults() {
  $endpoints = array();
  $endpoints[] = array(
    'type' => 'NewsletterCampaignSignupEndpoint',
    'name' => 'pivot_newsletter',
    'label' => 'Pivot Newsletter',
    'configuration' => array(),
    'plugins' => array(
      'bluehornet.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'segments' => array('1009409'),
          'fields' => array(
            '253169' => 'Webform',
            '253168' => 'PIVOT',
          ),
          'send-welcome' => TRUE,
        ),
      ),
    ),
  );
  return $endpoints;
}