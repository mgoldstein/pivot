<?php
/**
 * @file
 * pivot_menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function pivot_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-follow-us.
  $menus['menu-follow-us'] = array(
    'menu_name' => 'menu-follow-us',
    'title' => 'Follow Us',
    'description' => 'Social share icons shown in the page footer.',
  );
  // Exported menu: menu-get-our-app.
  $menus['menu-get-our-app'] = array(
    'menu_name' => 'menu-get-our-app',
    'title' => 'Get Our App',
    'description' => 'OTT app icon shown in the page footer.',
  );
  // Exported menu: menu-participant-media.
  $menus['menu-participant-media'] = array(
    'menu_name' => 'menu-participant-media',
    'title' => 'Participant Media Footer Menu',
    'description' => 'Links to other Participant Media sites shown in the page footer.',
  );
  // Exported menu: menu-pivot-footer.
  $menus['menu-pivot-footer'] = array(
    'menu_name' => 'menu-pivot-footer',
    'title' => 'Pivot Footer Menu',
    'description' => 'Links to general pages on the Pivot site shown in the page footer.',
  );
  // Exported menu: menu-primary.
  $menus['menu-primary'] = array(
    'menu_name' => 'menu-primary',
    'title' => 'Pivot Global Navigation',
    'description' => 'Pivot Global Nav for (almost) all pages on the site.',
  );
  // Exported menu: menu-secondary.
  $menus['menu-secondary'] = array(
    'menu_name' => 'menu-secondary',
    'title' => 'Secondary Menu',
    'description' => 'Second line menu links in the header.',
  );
  // Exported menu: menu-watch-live.
  $menus['menu-watch-live'] = array(
    'menu_name' => 'menu-watch-live',
    'title' => 'Watch Live Header Link',
    'description' => 'Watch Pivot Live link shown in the page header.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Follow Us');
  t('Get Our App');
  t('Links to general pages on the Pivot site shown in the page footer.');
  t('Links to other Participant Media sites shown in the page footer.');
  t('OTT app icon shown in the page footer.');
  t('Participant Media Footer Menu');
  t('Pivot Footer Menu');
  t('Pivot Global Nav for (almost) all pages on the site.');
  t('Pivot Global Navigation');
  t('Second line menu links in the header.');
  t('Secondary Menu');
  t('Social share icons shown in the page footer.');
  t('Watch Live Header Link');
  t('Watch Pivot Live link shown in the page header.');


  return $menus;
}
