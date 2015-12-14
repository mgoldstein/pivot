<?php
/**
 * @file
 * pivot_newsletter_signups.features.pm_signup_endpoint.inc
 */

/**
 * Implements hook_pm_signup_endpoint_defaults().
 */
function pivot_newsletter_signups_participant_pm_signup_endpoint_defaults() {
  $endpoints = array();
  $endpoints[] = array(
    'type' => 'TakePartUserSignupEndpoint',
    'name' => 'mentor_strong',
    'label' => 'Mentor Strong Search Signup',
    'configuration' => array(),
    'plugins' => array(
      'participant.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'lists' => array(
            'MentorStrong', 'MENTOR',
          ),
          'source' => 'signup',
        ),
      ),
    ),
  );
  $endpoints[] = array(
    'type' => 'NewsletterCampaignSignupEndpoint',
    'name' => 'pivot_newsletter',
    'label' => 'Pivot Newsletter',
    'configuration' => array(),
    'plugins' => array(
      'participant.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'lists' => array(
            'PIVOT',
          ),
		'user_vars' => array(
            'pivot',
          ),
          'source' => 'signup',
        ),
      ),
    ),
  );
  return $endpoints;
}
