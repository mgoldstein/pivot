<?php

/**
 *  @function:
 *    Admin configuration from for the dynamic blocks
 */
function pivot_dynamic_blocks_admin_form() {
  $form = array();
  
  //creates the first fieldset
  $form['pivot_dynamic_block_fieldset_1'] = array(
    '#type' => 'fieldset',
    '#title' => t('Custom Block Fieldset 1'),
    '#collapsible' => TRUE,
    '#tree' => TRUE
  );

  //loops through until end of blocks
  $counter = 1;
  do {
    $image = variable_get('pivot_dynamic_block_image_img_' . $counter, '');
    $image_url = variable_get('pivot_dynamic_block_image_url_' . $counter, '');
  
    $form['pivot_dynamic_block_fieldset_' . $counter] = array(
      '#type' => 'fieldset',
      '#title' => t('Pivot Promo Blocks - Block - ' . $counter),
      '#collapsible' => TRUE,
      '#collapsed' => (!empty($image)) ? TRUE : FALSE,
      '#tree' => FALSE
    );
    
    $form['pivot_dynamic_block_fieldset_' . $counter]['markup'] = array(
      '#markup' => t('Pivot Promo Blocks - Block - ' . $counter),
      '#prefix' => '<strong>Block Title: </strong>'
    );
    
    $form['pivot_dynamic_block_fieldset_' . $counter]['pivot_dynamic_block_image_img_' . $counter] = array(
      '#title' => t('Custom Block Image'),
      '#type' => 'managed_file',
      '#description' => '',
      '#default_value' => variable_get('pivot_dynamic_block_image_img_' . $counter, ''),
      '#upload_location' => 'public://pivot_dynamic_images/',
      '#required' => (empty($image)) ? FALSE : TRUE
    );
  
    $form['pivot_dynamic_block_fieldset_' . $counter]['pivot_dynamic_block_image_url_' . $counter] = array(
      '#title' => t('Custom Block Image URL'),
      '#type' => 'textfield',
      '#description' => '',
      '#default_value' => variable_get('pivot_dynamic_block_image_url_' . $counter, ''),
    );
      
    $counter++;
  } while (!empty($image));
  
  //creates a shortcut method to flush drupal cache
  $form['flush_block_cache'] = array(
    '#type' => 'select',
    '#title' => t('Rebuild Block Caches'),
    '#options' => array(
      0 => 'No',
      1 => 'Yes'
    ),
    '#default_value' => 0
  );
  
  //additional submit handler
  $form['#submit'][] = '_pivot_dynamic_blocks_admin_form_submit';
  
  return system_settings_form($form);
}

/**
 *  @function:
 *    This function is an additional submit handler for the admin form.
 */
function _pivot_dynamic_blocks_admin_form_submit(&$form, &$form_state) {
  //variable for flushing
  $flush = $form_state['values']['flush_block_cache'];

  //ensures that the blocks are perm saved
  $blocks = _pivot_dynamic_blocks_list();
  foreach($blocks as $key => $values) {
    //loads the file
    $image_file = file_load($values['image']);
    $image_file->status = FILE_STATUS_PERMANENT;
    file_save($image_file);
    file_usage_add($image_file, 'user', 'user', 1); 
  }
  
  //if true then flush the drupal cache to rebuild the new blocks
  if ($flush) {
    drupal_flush_all_caches();
    drupal_set_message('All caches has been flushed');
  }
}