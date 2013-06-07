<?php
/**
 * @file
 * pivot_taxonomy_show.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function pivot_taxonomy_show_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-show-field_show_banner'
  $field_instances['taxonomy_term-show-field_show_banner'] = array(
    'bundle' => 'show',
    'deleted' => 0,
    'description' => 'Menu banner image for all content belonging to the show.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_show_banner',
    'label' => 'Show Banner',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'field/show_banner',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'file_entity_inline' => 1,
        'file_entity_inline_fields' => array(),
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'taxonomy_term-show-field_show_title'
  $field_instances['taxonomy_term-show-field_show_title'] = array(
    'bundle' => 'show',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The public display title of the show.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_show_title',
    'label' => 'Show Title',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Menu banner image for all content belonging to the show.');
  t('Show Banner');
  t('Show Title');
  t('The public display title of the show.');

  return $field_instances;
}
