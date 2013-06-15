<?php
/**
 * @file
 * pivot_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function pivot_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: add wordlet.
  $permissions['add wordlet'] = array(
    'name' => 'add wordlet',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'wordlet',
  );

  // Exported permission: administer search.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'search',
  );

  // Exported permission: administer wordlet.
  $permissions['administer wordlet'] = array(
    'name' => 'administer wordlet',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'wordlet',
  );

  // Exported permission: administer wordlet page.
  $permissions['administer wordlet page'] = array(
    'name' => 'administer wordlet page',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'wordlet',
  );

  // Exported permission: delete wordlet.
  $permissions['delete wordlet'] = array(
    'name' => 'delete wordlet',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'wordlet',
  );

  // Exported permission: edit wordlet.
  $permissions['edit wordlet'] = array(
    'name' => 'edit wordlet',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'wordlet',
  );

  // Exported permission: preview wordlet page.
  $permissions['preview wordlet page'] = array(
    'name' => 'preview wordlet page',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'wordlet',
  );

  // Exported permission: search content.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: use advanced search.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: view wordlet page.
  $permissions['view wordlet page'] = array(
    'name' => 'view wordlet page',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'wordlet',
  );

  return $permissions;
}
