<?php
/**
 * @file
 * Functions for pivot galleries
 */

/**
 * Implements hook_init();
 *
 */

function pivot_global_url_inbound_alter(&$path, $original_path, $path_language) {
  $last_path_argument = basename($original_path);
  $dirs = explode('/', $original_path);

  // find out of the string 'gallery' occurs exactly in the path
  $gallery_path_index = array_search('gallery', $dirs, true);

  // if we're viewing a node that has "gallery" as a component of the path
  // do some redirecting
  if ($gallery_path_index && arg(0) == 'node') {
    $gallery_path = '';
    for($i = 0; $i <= $gallery_path_index + 1; $i++) {
      $gallery_path .= $dirs[$i] . '/';
    }
    $gallery_path = substr($gallery_path, 0, -1);

    // if the last argument was a gallery slide name
    if (basename($gallery_path) != $last_path_argument) {
      drupal_session_start();
      _pivot_global_session_variable('slide_token', $last_path_argument);
      $path = drupal_lookup_path('source', $gallery_path);
    }
    // otherwise, if we have a slide_token session variable
    // set it in javascript so the gallery knows what to render
    else if ($slide_token = _pivot_global_session_variable('slide_token')) {
      drupal_add_js(array('gallery' => array('slideToken' => $slide_token)), 'setting');
    }
  }
}

/**
 * Implements hook_preprocess_node().
 */
function pivot_global_preprocess_node(&$variables) {
  // if we're in a gallery and the slide_token session variable is set,
  // find the relevant slide and populate the og meta tags from its values
  if ($variables['node']->type == 'gallery' && $slide_token = _pivot_global_session_variable('slide_token')) {
    // loop through the slides and test each one against the value of $slide_token
    foreach ($variables['field_gallery_images'] as $key => $slide) {
      $test_token = $slide['field_image_title'][LANGUAGE_NONE][0]['safe_value'];
      $test_token = strtolower($test_token);
      $test_token = str_replace(' ', '-', $test_token);
      if ($slide_token == $test_token) {
        $current_slide = $variables['field_gallery_images'][$key];
        break;
      }

      // set the first slide as the default in case we don't find anything.
      $current_slide = $variables['field_gallery_images'][0];
    }

    // populate the og meta tags

    $slide_url = $GLOBALS['base_url'] . request_uri() . '/' . $slide_token;
    $slide_image_url = file_create_url($current_slide['uri']);
    $slide_title = $current_slide['field_image_title'][LANGUAGE_NONE][0]['safe_value'];
    $slide_description = trim(strstr(strip_tags($current_slide['field_image_description'][LANGUAGE_NONE][0]['safe_value']), "\n", true));

    $og_tags = array(
      'slide_url' => array(
        '#tag' => 'meta',
        '#attributes' => array(
          'property' => 'og:url',
          'content' => $slide_url,
        ),
      ),
      'slide_image_url' => array(
        '#tag' => 'meta',
        '#attributes' => array(
          'property' => 'og:image',
          'content' => $slide_image_url,
        ),
      ),
      'slide_title' => array(
        '#tag' => 'meta',
        '#attributes' => array(
          'property' => 'og:title',
          'content' => $slide_title,
        ),
      ),
      'slide_description' => array(
        '#tag' => 'meta',
        '#attributes' => array(
          'property' => 'og:description',
          'content' => $slide_description,
        ),
      ),
    );

    foreach ($og_tags as $key => $tag) {
       drupal_add_html_head($tag, $key);
     }
  }
}

/**
 * Implements hook_html_head_alter().
 *
 * If there is a specific slide token set, unset metatag_og tags.
 */
function pivot_global_html_head_alter(&$head_elements) {
  if (_pivot_global_session_variable('slide_token')) {
    foreach ($head_elements as $key => $element) {
      if (
        isset($element['#id']) &&
        strstr($element['#id'], 'metatag_og') &&
        !strstr($element['#id'], 'metatag_og:site_name')
      ) {
        unset($head_elements[$key]);
      }
    }
    // we're finally good to get rid of the session variable
    _pivot_global_session_variable('slide_token', FALSE);
  }
}

/**
 * Store and retrieve session variables.
 * 
 * @param  string $key   a key to reference the session value
 * @param  mixed $value (optional) the value to store under $key, or FALSE to delete the $key
 * @return mixed        the value you are setting or retrieving
 */
function _pivot_global_session_variable($key, $value = NULL) {
  static $session_storage;

  // if we have $value, assign it to $key
  if ($value) {
    $session_storage[$key] = $value;
    $_SESSION[__FUNCTION__][$key] = $value;
  }
  // if $value is false, unset the key
  else if ($value === FALSE) {
    unset($session_storage[$key]);
    unset($_SESSION[__FUNCTION__][$key]);
  }
  // retrieve the value from $_SESSION if we don't have it in our static array
  else if (empty($session_storage[$key]) && isset($_SESSION[__FUNCTION__][$key])) {
    $session_storage[$key] = $_SESSION[__FUNCTION__][$key];
  }

  return isset($session_storage[$key]) ? $session_storage[$key] : false;
}
