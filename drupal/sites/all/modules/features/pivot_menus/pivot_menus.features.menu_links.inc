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

  // Exported menu link: menu-follow-us:http://plus.google.com
  $menu_links['menu-follow-us:http://plus.google.com'] = array(
    'menu_name' => 'menu-follow-us',
    'link_path' => 'http://plus.google.com',
    'router_path' => '',
    'link_title' => 'Google Plus',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'googleplus',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
  );
  // Exported menu link: menu-follow-us:http://www.facebook.com/takepart
  $menu_links['menu-follow-us:http://www.facebook.com/takepart'] = array(
    'menu_name' => 'menu-follow-us',
    'link_path' => 'http://www.facebook.com/takepart',
    'router_path' => '',
    'link_title' => 'Facebook',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'facebook',
        ),
        'target' => '_blank',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: menu-follow-us:http://www.twitter.com/TakePart
  $menu_links['menu-follow-us:http://www.twitter.com/TakePart'] = array(
    'menu_name' => 'menu-follow-us',
    'link_path' => 'http://www.twitter.com/TakePart',
    'router_path' => '',
    'link_title' => 'Twitter',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'twitter',
        ),
        'target' => '_blank',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
  );
  // Exported menu link: menu-follow-us:http://www.youtube.com/takepart
  $menu_links['menu-follow-us:http://www.youtube.com/takepart'] = array(
    'menu_name' => 'menu-follow-us',
    'link_path' => 'http://www.youtube.com/takepart',
    'router_path' => '',
    'link_title' => 'YouTube',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'youtube',
        ),
        'target' => '_blank',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
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
    'weight' => 0,
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
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
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
  // Exported menu link: menu-pivot-footer:http://pivot.tv/test1
  $menu_links['menu-pivot-footer:http://pivot.tv/test1'] = array(
    'menu_name' => 'menu-pivot-footer',
    'link_path' => 'http://pivot.tv/test1',
    'router_path' => '',
    'link_title' => 'About Pivot',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: menu-pivot-footer:http://pivot.tv/test2
  $menu_links['menu-pivot-footer:http://pivot.tv/test2'] = array(
    'menu_name' => 'menu-pivot-footer',
    'link_path' => 'http://pivot.tv/test2',
    'router_path' => '',
    'link_title' => 'Advertise With Us',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
  );
  // Exported menu link: menu-pivot-footer:http://pivot.tv/test3
  $menu_links['menu-pivot-footer:http://pivot.tv/test3'] = array(
    'menu_name' => 'menu-pivot-footer',
    'link_path' => 'http://pivot.tv/test3',
    'router_path' => '',
    'link_title' => 'Contact Us',
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
  // Exported menu link: menu-pivot-footer:http://pivot.tv/test4
  $menu_links['menu-pivot-footer:http://pivot.tv/test4'] = array(
    'menu_name' => 'menu-pivot-footer',
    'link_path' => 'http://pivot.tv/test4',
    'router_path' => '',
    'link_title' => 'Privacy Policy',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
  );
  // Exported menu link: menu-pivot-footer:http://pivot.tv/test5
  $menu_links['menu-pivot-footer:http://pivot.tv/test5'] = array(
    'menu_name' => 'menu-pivot-footer',
    'link_path' => 'http://pivot.tv/test5',
    'router_path' => '',
    'link_title' => 'Digital Media Literacy',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
  );
  // Exported menu link: menu-pivot-footer:http://pivot.tv/test6
  $menu_links['menu-pivot-footer:http://pivot.tv/test6'] = array(
    'menu_name' => 'menu-pivot-footer',
    'link_path' => 'http://pivot.tv/test6',
    'router_path' => '',
    'link_title' => 'FAQ',
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
  // Exported menu link: menu-pivot-footer:http://pivot.tv/test7
  $menu_links['menu-pivot-footer:http://pivot.tv/test7'] = array(
    'menu_name' => 'menu-pivot-footer',
    'link_path' => 'http://pivot.tv/test7',
    'router_path' => '',
    'link_title' => 'Terms of Use',
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
  t('Facebook');
  t('Google Plus');
  t('Participant Media');
  t('Pivot');
  t('Privacy Policy');
  t('Schedule');
  t('TakePart');
  t('Terms of Use');
  t('Twitter');
  t('Watch Pivot Live >>');
  t('YouTube');
  t('iOS');


  return $menu_links;
}
