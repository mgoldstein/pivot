<?php
/**
 * @file
 * pivot_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function pivot_permissions_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 6,
  );

  // Exported role: contributor.
  $roles['contributor'] = array(
    'name' => 'contributor',
    'weight' => 2,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 3,
  );

  // Exported role: layout editor.
  $roles['layout editor'] = array(
    'name' => 'layout editor',
    'weight' => 5,
  );

  // Exported role: supervising editor.
  $roles['supervising editor'] = array(
    'name' => 'supervising editor',
    'weight' => 4,
  );

  return $roles;
}
