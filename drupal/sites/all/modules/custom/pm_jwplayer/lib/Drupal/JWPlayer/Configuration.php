<?php

class JWPlayerConfiguration {

  protected $_settings;

  public static function valueLabels() {
    return array(
      'promo' => array(
        'image' => t('Image'),
        'title' => t('Title'),
        'displaytitle' => t('Display Title'),
      ),
      'layout' => array(
        'controls' => t('Controls'),
        'responsive' => t('Responsive'),
        'aspectratio' => t('Aspect Ratio'),
        'width' => t('Width'),
        'height' => t('Height'),
        'skin' => t('Skin'),
        'stretching' => t('Stretching'),
      ),
      'playback' => array(
        'autostart' => t('Auto Start'),
        'fallback' => t('Fallback'),
        'mute' => t('Mute'),
        'primary' => t('Primary'),
        'repeat' => t('Repeat'),
      ),
      'region_limits' => array(
        'allowed_regions' => t('Allowed Regions'),
      ),
      'listbar' => array(
        'position' => t('Position'),
        'size' => t('Size'),
        'layout' => t('Layout'),
      ),
      'sharing' => array(
        'link' => t('Link'),
        'code' => t('Code'),
        'heading' => t('Heading'),
      ),
      'related' => array(
        'file' => t('File'),
        'onclick' => t('On Click'),
        'oncomplete' => t('On Complete'),
        'heading' => t('Heading'),
        'dimensions' => t('Dimensions'),
      ),
      'advertising' => array(
        'client' => t('Client'),
        'tag' => t('Tag'),
      ),
      'jwplayer_analytics' => array(
        'enabled' => t('Enabled'),
      ),
      'google_analytics' => array(
        'idstring' => t('ID String'),
        'trackingobject' => t('Tracking Object'),
      ),
      'sitecatalyst' => array(
        'mediaName' => t('Media Name'),
        'playerName' => t('Player Name'),
      ),
    );
  }

  public function __construct($settings) {
    if (is_null($settings)) { $settings = array(); }
    $this->_settings = $settings;
  }

  public static function replaceTokens($type, $entity, $langcode, $settings) {
    foreach ($settings as $key => $item) {
      if (is_array($item)) {
        $settings[$key] = self::replaceTokens($type, $entity, $langcode, $item);
      }
      else {
        $settings[$key] = token_replace($item, array($type => $entity), array(
          'clear' => TRUE,
          'sanitize' => FALSE,
        ));
      }
    }
    return $settings;
  }

  public static function booleanValue($value) {
    return $value ? TRUE : FALSE;
  }

  public static function intValue($value) {
    return (int) $value;
  }

  public function allowedRegions() {
    $regions = array();
    if (isset($this->_settings['region_limits']['allowed_regions'])) {
      $t = explode(' ', $this->_settings['region_limits']['allowed_regions']);
      $i = array_map('trim', $t);
      $d = array_filter($i, 'strlen');
      $y = array_map('strtolower', $d);
      $regions = $y;
    }
    return $regions;
  }

  protected function contentSettings($uri) {
    $scheme = file_uri_scheme($uri);
    $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
    $url = $wrapper->getExternalUrl();
    if ($scheme === 'jwplatform-channel' || $scheme === 'jwplatform-video') {
      return array('playlist' => $url);
    }
    return array('file' => $url);
  }

  protected function promoSettings() {
    $values = array();
    $settings = $this->_settings['promo'];
    if (!empty($settings['image'])) {
      $values['image'] = $settings['image'];
    }
    if (!empty($settings['title'])) {
      $values['title'] = $settings['title'];
    }
    if (!empty($settings['displaytitle'])) {
      $values['displaytitle'] = self::booleanValue($settings['displaytitle']);
    }
    return $values;
  }

  protected function layoutSettings() {
    $values = array();
    $settings = $this->_settings['layout'];
    if (!empty($settings['controls'])) {
      $values['controls'] = self::booleanValue($settings['controls']);
    }
    if (!empty($settings['skin'])) {
      $values['skin'] = $settings['skin'];
    }
    if (!empty($settings['stretching'])) {
      $values['stretching'] = $settings['stretching'];
    }
    if ($settings['responsive']) {
      $values['width'] = '100%';
      if (!empty($settings['aspectratio'])) {
        $values['aspectratio'] = $settings['aspectratio'];
      }
    }
    else {
      if (!empty($settings['width'])) {
        $values['width'] = self::intValue($settings['width']);
      }
      if (!empty($settings['height'])) {
        $values['height'] = self::intValue($settings['height']);
      }
    }
    return $values;
  }

  protected function playbackSettings() {
    $values = array();
    $settings = $this->_settings['playback'];
    if (!empty($settings['autostart'])) {
      $values['autostart'] = self::booleanValue($settings['autostart']);
    }
    if (!empty($settings['fallback'])) {
      $values['fallback'] = self::booleanValue($settings['fallback']);
    }
    if (!empty($settings['mute'])) {
      $values['mute'] = self::booleanValue($settings['mute']);
    }
    if (!empty($settings['primary'])) {
      $values['primary'] = $settings['primary'];
    }
    if (!empty($settings['repeat'])) {
      $values['repeat'] = self::booleanValue($settings['repeat']);
    }
    return $values;
  }

  protected function listbarSettings() {
    $values = array();
    $settings = $this->_settings['listbar'];
    if (!empty($settings['position'])) {
      $values['position'] = $settings['position'];
    }
    if (!empty($settings['size'])) {
      $values['size'] = self::intValue($settings['size']);
    }
    if (!empty($settings['layout'])) {
      $values['layout'] = $settings['layout'];
    }
    return count($values) > 0 ? array('listbar' => $values) : $values;
  }

  protected function sharingSettings() {
    $values = array();
    $settings = $this->_settings['sharing'];
    if (!empty($settings['link'])) {
      $values['link'] = $settings['link'];
    }
    if (!empty($settings['code'])) {
      $values['code'] = urlencode($settings['code']);
    }
    if (!empty($settings['heading'])) {
      $values['heading'] = $settings['heading'];
    }
    return count($values) > 0 ? array('sharing' => $values) : $values;
  }

  protected function relatedSettings() {
    $values = array();
    $settings = $this->_settings['related'];
    if (!empty($settings['file'])) {
      $values['file'] = $settings['file'];
    }
    if (!empty($settings['onclick'])) {
      $values['onclick'] = $settings['onclick'];
    }
    if (!empty($settings['oncomplete'])) {
      $values['oncomplete'] = self::booleanValue($settings['oncomplete']);
    }
    if (!empty($settings['heading'])) {
      $values['heading'] = $settings['heading'];
    }
    if (!empty($settings['dimensions'])) {
      $values['dimensions'] = $settings['dimensions'];
    }
    return count($values) > 0 ? array('related' => $values) : $values;
  }

  protected function advertisingSettings() {
    $values = array();
    $settings = $this->_settings['advertising'];
    if (!empty($settings['client'])) {
      $values['client'] = $settings['client'];
    }
    if (!empty($settings['tag'])) {
      $values['tag'] = $settings['tag'];
    }
    return count($values) > 0 ? array('advertising' => $values) : $values;
  }

  protected function jwplayerAnalyticsSettings() {
    $values = array();
    $settings = $this->_settings['jwplayer_analytics'];
    if (!empty($settings['enabled'])) {
      $values['enabled'] = self::booleanValue($settings['enabled']);
    }
    return count($values) > 0 ? array('analytics' => $values) : $values;
  }

  protected function googleAnalyticsSettings() {
    $values = array();
    $settings = $this->_settings['google_analytics'];
    if (!empty($settings['idstring'])) {
      $values['idstring'] = $settings['idstring'];
    }
    if (!empty($settings['trackingobject'])) {
      $values['trackingobject'] = $settings['trackingobject'];
    }
    return count($values) > 0 ? array('ga' => $values) : $values;
  }

  protected function siteCatalystSettings() {
    $values = array();
    $settings = $this->_settings['sitecatalyst'];
    if (!empty($settings['mediaName'])) {
      $values['mediaName'] = $settings['mediaName'];
    }
    if (!empty($settings['playerName'])) {
      $values['playerName'] = $settings['playerName'];
    }
    return count($values) > 0 ? array('sitecatalyst' => $values) : $values;
  }

  public function setupHash($uri) {
    return array_merge(
      $this->contentSettings($uri),
      $this->promoSettings(),
      $this->layoutSettings(),
      $this->playbackSettings(),
      $this->listbarSettings(),
      $this->sharingSettings(),
      $this->relatedSettings(),
      $this->advertisingSettings(),
      $this->jwplayerAnalyticsSettings(),
      $this->googleAnalyticsSettings(),
      $this->siteCatalystSettings()
    );
  }
}
