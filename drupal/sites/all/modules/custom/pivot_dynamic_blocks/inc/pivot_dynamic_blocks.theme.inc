<?php

/**
 *  @function:
 *    Theme function that is used to dynamically generate the output of the blocks
 */
function theme_pivot_dynamic_block_render($variables) {
  $output = '';
  
  //dynamically create the keys
  foreach ($variables as $key => $value) {
    ${$key} = $value;
  }
  
  $file = file_load($image);

  //ensures that the image exist
  if (!empty($file)) {
    //creates the link to the image
    $image = theme('image', array(
      'path' => $file->uri,
      'attributes' => array(
        'style' => 'width: 100%;'
      )
    ));
  
    //only adds the image url if its not empty
    $attributes = array();
    
    //wrap a url if neccessary
    if (!empty($image_url)) {
      $image = l($image, $image_url, array('attributes' => $attributes, 'html' => TRUE));
    }
    
    //creates the wrapper
    $output = theme('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#value' => $image,
      '#attributes' => array(
        'class' => 'dynamic-block-wrapper',
    ))));
  }
  
  return $output;
}