<?php

include_once dirname(__FILE__) . '/bluehornet.lib.inc';

/**
 * BlueHornet API Wrapper
 */
class BlueHornet {

  public static function Api() {
    static $instance = NULL;
    if ($instance === NULL) {
      $api_domain = variable_get('bluehornet_api_domain', '');
      $api_key = variable_get('bluehornet_api_key', '');
      $shared_secret = variable_get('bluehornet_shared_secret', '');
      $instance = new BlueHornet($api_domain, $api_key, $shared_secret);
    }
    return $instance;
  }

  private $core;

  private function __construct($api_domain, $api_key, $shared_secret) {
    $auth = array(
      'apiKey' => $api_key,
      'sharedSecret' => $shared_secret,
      'apiDomain' => $api_domain,
    );
    $this->core = new BF_Esp_Bluehornet($auth);
  }

  public function addUpdateSubscriber($data, $segments, $custom_fields,
    $send_welcome) {

    // Include the segments to which the user should be added (if any).
    if (count($segments) > 0) {
      $data['grp'] = implode(',', $segments);
    }

    // Add any custom field values.
    foreach($custom_fields as $number => $value) {
      $data["custval{$number}"] = $value;
    }

    if ($send_welcome) {
      $data['welcomeletter'] = '1';
    }

    if (variable_get('pm_signup_log', FALSE)) {
      db_insert('pm_signup_log')
        ->fields(array(
          'handler' => 'bluehornet.api.inc',
          'message' => 'api request',
          'exception' => print_r($data, true),
          'backtrace' => '',
          'created' => REQUEST_TIME,
        ))
        ->execute();
    }

    // Add or update the subscriber.
    $response = $this->core->addUpdateSubscriber($data);

    return $response;
  }
}