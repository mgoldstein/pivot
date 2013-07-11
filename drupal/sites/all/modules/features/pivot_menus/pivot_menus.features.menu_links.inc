<?php
/**
 * @file
 * pivot_menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function pivot_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-follow-us:http://instagram.com/pivottv
  $menu_links['menu-follow-us:http://instagram.com/pivottv'] = array(
    'menu_name' => 'menu-follow-us',
    'link_path' => 'http://instagram.com/pivottv',
    'router_path' => '',
    'link_title' => 'Instagram',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'instagram',
        ),
        'target' => '_blank',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: menu-get-our-app:http://store.apple.com
  $menu_links['menu-get-our-app:http://store.apple.com'] = array(
    'menu_name' => 'menu-get-our-app',
    'link_path' => 'http://store.apple.com',
    'router_path' => '',
    'link_title' => 'iOS',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'ios-app',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: menu-get-our-app:http://www.android.com/apps
  $menu_links['menu-get-our-app:http://www.android.com/apps'] = array(
    'menu_name' => 'menu-get-our-app',
    'link_path' => 'http://www.android.com/apps',
    'router_path' => '',
    'link_title' => 'Android',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'android-app',
        ),
        'target' => '_blank',
      ),
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
  );
  // Exported menu link: menu-participant-media:http://pivot.tv
  $menu_links['menu-participant-media:http://pivot.tv'] = array(
    'menu_name' => 'menu-participant-media',
    'link_path' => 'http://pivot.tv',
    'router_path' => '',
    'link_title' => 'Pivot',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'pivot',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
  );
  // Exported menu link: menu-participant-media:http://www.participantmedia.com
  $menu_links['menu-participant-media:http://www.participantmedia.com'] = array(
    'menu_name' => 'menu-participant-media',
    'link_path' => 'http://www.participantmedia.com',
    'router_path' => '',
    'link_title' => 'Participant Media',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'participant-media',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: menu-participant-media:http://www.takepart.com
  $menu_links['menu-participant-media:http://www.takepart.com'] = array(
    'menu_name' => 'menu-participant-media',
    'link_path' => 'http://www.takepart.com',
    'router_path' => '',
    'link_title' => 'TakePart',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'takepart',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
  );
  // Exported menu link: menu-pivot-footer:node/11
  $menu_links['menu-pivot-footer:node/11'] = array(
    'menu_name' => 'menu-pivot-footer',
    'link_path' => 'node/11',
    'router_path' => 'node/%',
    'link_title' => 'About Pivot',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: menu-pivot-footer:node/12
  $menu_links['menu-pivot-footer:node/12'] = array(
    'menu_name' => 'menu-pivot-footer',
    'link_path' => 'node/12',
    'router_path' => 'node/%',
    'link_title' => 'Advertise With Us',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
  );
  // Exported menu link: menu-pivot-footer:node/13
  $menu_links['menu-pivot-footer:node/13'] = array(
    'menu_name' => 'menu-pivot-footer',
    'link_path' => 'node/13',
    'router_path' => 'node/%',
    'link_title' => 'Contact Us',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
  );
  // Exported menu link: menu-pivot-footer:node/14
  $menu_links['menu-pivot-footer:node/14'] = array(
    'menu_name' => 'menu-pivot-footer',
    'link_path' => 'node/14',
    'router_path' => 'node/%',
    'link_title' => 'Privacy Policy',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
  );
  // Exported menu link: menu-pivot-footer:node/15
  $menu_links['menu-pivot-footer:node/15'] = array(
    'menu_name' => 'menu-pivot-footer',
    'link_path' => 'node/15',
    'router_path' => 'node/%',
    'link_title' => 'Digital Media Literacy',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
  );
  // Exported menu link: menu-pivot-footer:node/16
  $menu_links['menu-pivot-footer:node/16'] = array(
    'menu_name' => 'menu-pivot-footer',
    'link_path' => 'node/16',
    'router_path' => 'node/%',
    'link_title' => 'FAQ',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: menu-pivot-footer:node/17
  $menu_links['menu-pivot-footer:node/17'] = array(
    'menu_name' => 'menu-pivot-footer',
    'link_path' => 'node/17',
    'router_path' => 'node/%',
    'link_title' => 'Terms of Use',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: menu-primary:http://schedule.pivot.tv
  $menu_links['menu-primary:http://schedule.pivot.tv'] = array(
    'menu_name' => 'menu-primary',
    'link_path' => 'http://schedule.pivot.tv',
    'router_path' => '',
    'link_title' => 'Schedule',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
  );
  // Exported menu link: menu-secondary:<front>
  $menu_links['menu-secondary:<front>'] = array(
    'menu_name' => 'menu-secondary',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Digital Media & Literacy',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: menu-watch-live:http://watch.pivot.tv
  $menu_links['menu-watch-live:http://watch.pivot.tv'] = array(
    'menu_name' => 'menu-watch-live',
    'link_path' => 'http://watch.pivot.tv',
    'router_path' => '',
    'link_title' => 'Watch Pivot Live >>',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'watch-pivot-live',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About Pivot');
  t('Advertise With Us');
  t('Android');
  t('Contact Us');
  t('Digital Media & Literacy');
  t('Digital Media Literacy');
  t('FAQ');
  t('Instagram');
  t('Participant Media');
  t('Pivot');
  t('Privacy Policy');
  t('Schedule');
  t('TakePart');
  t('Terms of Use');
  t('Watch Pivot Live >>');
  t('iOS');


  return $menu_links;
}
