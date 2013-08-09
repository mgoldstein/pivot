<?php
/**
 * @file
 * pivot_dl_file.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function pivot_dl_file_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-download-body'
  $field_instances['node-download-body'] = array(
    'bundle' => 'download',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'promo' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'promo_alt' => array(
	'label' => 'above',
	'settings' => array(),
	'type' => 'hidden',
	'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'display_summary' => 1,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'node-download-field_download_file'
  $field_instances['node-download-field_download_file'] = array(
    'bundle' => 'download',
    'deleted' => 0,
    'description' => 'Upload the file for users to download.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 2,
      ),
      'promo' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'promo_alt' => array(
	'label' => 'above',
	'settings' => array(),
	'type' => 'hidden',
	'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_download_file',
    'label' => 'Downloadable File',
    'required' => 1,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'downloadable_content',
      'file_extensions' => 'jpg jpeg pdf mp3 zip',
      'filefield_paths' => array(
	'active_updating' => 0,
	'file_name' => array(
	  'options' => array(
	    'pathauto' => 0,
	    'transliterate' => 0,
	  ),
	  'value' => '[file:ffp-name-only-original].[file:ffp-extension-original]',
	),
	'file_path' => array(
	  'options' => array(
	    'pathauto' => 0,
	    'transliterate' => 0,
	  ),
	  'value' => '',
	),
	'retroactive_update' => 0,
      ),
      'filefield_paths_enabled' => 1,
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
	'file_entity_inline' => 0,
        'file_entity_inline_fields' => array(),
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'plupload' => 0,
            'reference' => 0,
            'remote' => 0,
            'upload' => 'upload',
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'progress_indicator' => 'bar',
      ),
      'type' => 'file_generic',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'node-download-field_section_ref'
  $field_instances['node-download-field_section_ref'] = array(
    'bundle' => 'download',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'What Pivot.tv section is this downloadable file related to?',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
      'promo' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'promo_alt' => array(
	'label' => 'above',
	'settings' => array(),
	'type' => 'hidden',
	'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_section_ref',
    'label' => 'Section Reference',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 32,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Description');
  t('Downloadable File');
  t('Section Reference');
  t('Upload the file for users to download.');
  t('What Pivot.tv section is this downloadable file related to?');

  return $field_instances;
}
