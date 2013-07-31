<?php
/**
 * Sigunup handler plugin for Waterfall module.
 */

$plugin = array(
  'handler' => array(
    'class' => 'WaterfalllSignupHandler',
  ),
);

class WaterfalllSignupHandler {

  protected $plugin;
  protected $configuration;

  public function __construct($plugin, $configuration) {
    $this->plugin = $plugin;
    $this->configuration = $configuration;
  }

  protected function submitNewsletterCampaignSignup($signup) {

    $phone = $signup->getPhoneNumber('');
    if (!empty($phone)) {

      $area_code = $signup->getAreaCode();
      $is_canadian = waterfallapi_is_canadian_area_code($area_code);

      if ($is_canadian && isset($this->configuration['canada-flow-id'])) {
        waterfallapi_initiate_canada_flow(
          $this->configuration['canada-flow-id'], $phone);
      }
      elseif (isset($this->configuration['us-flow-id'])) {
        waterfallapi_initiate_us_flow(
          $this->configuration['us-flow-id'], $phone);
      }
    }
  }

  public function submit($signup) {
    if (get_class($signup) === 'NewsletterCampaignSignup') {
      $this->submitNewsletterCampaignSignup($signup);
    }
  }
}
