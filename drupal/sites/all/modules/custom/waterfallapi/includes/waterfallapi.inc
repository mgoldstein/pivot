<?php

/**
 * Waterfall API Wrapper
 */
class Waterfall {

  public static function Api() {
    static $instance = NULL;
    if ($instance === NULL) {
      $instance = new Waterfall(
        'http://three.waterfallmobile.com/api/v1/', 10, '/tmp'
      );
    }
    return $instance;
  }

  private $base;
  private $timeout;
  private $cookieJar;

  private function __construct($base, $timeout, $sessions) {

    $this->base = $base;
    if (substr($this->base, -1) != '/') {
      $this->base .= '/';
    }
    $this->timeout = $timeout;

    $this->cookieJar = tempnam($sessions, 'waterfall.session.');
    $fp = fopen($this->cookieJar, 'w+');
    fclose($fp);
  }

  function __destruct() {
    unlink($this->cookieJar);
  }

  protected function makeRequest($method, $url, $params = array(), $payload = array()) {

    $url = $this->base . $url;
    if (!empty($params)) {
      // Add query string to request URL.
      $url .= '?' . http_build_query($params);
    }

    $ch = curl_init();

    if ($method !== 'GET' && $method !== 'POST') {
      curl_setopt($ch, CURLOPT_CUSTOMREQUEST, $method);
    }

    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_TIMEOUT, $this->timeout);

    // COOOOOOKIEEEEES!!!
    curl_setopt($ch, CURLOPT_COOKIEJAR, $this->cookieJar);
    curl_setopt($ch, CURLOPT_COOKIEFILE, $this->cookieJar);

    // Return the transfer as a string.
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);

    // Include headers in the request.
    $headers = array(
      "Content-Type: application/json",
      // Instruct the API to return JSON
      "Accept: application/json",
    );
    curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);

    // Include the header in result.
    curl_setopt($ch, CURLOPT_HEADER, 1);

    // Add in the payload.
    if ($method !== 'GET' && !empty($payload)) {
      curl_setopt($ch, CURLOPT_POST, 1);
      $json = json_encode($payload);
      curl_setopt($ch, CURLOPT_POSTFIELDS, $json);
    }

    $response = @curl_exec($ch);
    $http_code = curl_getinfo($ch, CURLINFO_HTTP_CODE);
    $header_length = curl_getinfo($ch, CURLINFO_HEADER_SIZE);
    $body = trim(substr($response, $header_length));

    curl_close($ch);

    if ($http_code === 200) {
      return json_decode($body);
    }
    elseif($http_code === 204) {
      return TRUE;
    }
    else {
      return json_decode($body);
    }
  }

  public function get($url, $params = NULL) {
    return $this->makeRequest('GET', $url, $params);
  }

  public function post($url, $payload = NULL, $params = NULL) {
    return $this->makeRequest('POST', $url, $params, $payload);
  }

  public function put($url, $payload = NULL, $params = NULL) {
    return $this->makeRequest('PUT', $url, $params, $payload);
  }

  public function delete($url, $payload = NULL, $params = NULL) {
    return $this->makeRequest('DELETE', $url, $params, $payload);
  }
}

/**
 * Mobile phone campaign management API.
 */
class PhoneCampaigns {

  const US_SHORT_CODE = '50ac121203644bd985ef24d4';
  const CANADIAN_SHORT_CODE = '505b80e60364fb7d2e2f10e6';

  public static function ForShortCode($short_code) {
    static $instances = array();
    if (!isset($instances[$short_code])) {
      $instance = new PhoneCampaigns($short_code);
    }
    return $instances[$short_code];
  }

  public static function US() {
    return self::ForShortCode(self::US_SHORT_CODE);
  }

  public static function Canada() {
    return self::ForShortCode(self::CANADIAN_SHORT_CODE);
  }

  public static function ForAreaCode($number) {
    $number = self::Sanitize($number);
    if (strlen($number) > 3) {
      $number = substr($number, 0, 3);
    }
    return self::IsCanadianAreaCode($number) ? self::Canada() : self::US();
  }

  public static function Sanitize($number) {
    return str_replace(array('(',')',' ','-','.'), '', "{$number}");
  }

  public static function IsCanadianAreaCode($area_code) {
    static $canadianAreaCodes = array(
      204, 226, 236, 249, 250, 289, 306, 343, 365,
      416, 418, 431, 437, 438, 450, 483, 506, 514,
      519, 579, 581, 587, 613, 639, 647, 705, 709,
      778, 780, 807, 819, 867, 873, 902, 905,
    );
    return in_array($area_code, $canadianAreaCodes);
  }

  private $shortCode;

  private function __construct($short_code) {
    $this->shortCode = $short_code;
  }

  public function flows() {
    $flows = Waterfall::Api()->get('mobileflow', array(
      'shortCode' => $this->shortCode
    ));
    return $flows->collection;
  }

  public function initiateFlow($flow_id, $phone_number) {
    $payload = new StdClass();
    $payload->msisdns = array($phone_number);
    $payload->mobileFlow = $flow_id;
    Waterfall::Api()->post('messaging/sendContent', $payload);
  }
}
