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
    'weight' => 0,
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
    'weight' => 0,
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
  // Exported menu link: menu-primary:movies
  $menu_links['menu-primary:movies'] = array(
    'menu_name' => 'menu-primary',
    'link_path' => 'movies',
    'router_path' => 'movies',
    'link_title' => 'Movies',
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
  // Exported menu link: menu-primary:shows
  $menu_links['menu-primary:shows'] = array(
    'menu_name' => 'menu-primary',
    'link_path' => 'shows',
    'router_path' => 'shows',
    'link_title' => 'Shows',
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
  // Exported menu link: menu-primary:videos
  $menu_links['menu-primary:videos'] = array(
    'menu_name' => 'menu-primary',
    'link_path' => 'videos',
    'router_path' => 'videos',
    'link_title' => 'Videos',
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
  // Exported menu link: menu-secondary:movies
  $menu_links['menu-secondary:movies'] = array(
    'menu_name' => 'menu-secondary',
    'link_path' => 'movies',
    'router_path' => 'movies',
    'link_title' => 'Our Blog',
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
  // Exported menu link: menu-secondary:shows
  $menu_links['menu-secondary:shows'] = array(
    'menu_name' => 'menu-secondary',
    'link_path' => 'shows',
    'router_path' => 'shows',
    'link_title' => 'Do I have Pivot on my TV?',
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
  t('Android');
  t('Digital Media & Literacy');
  t('Do I have Pivot on my TV?');
  t('Facebook');
  t('Movies');
  t('Our Blog');
  t('Participant Media');
  t('Pivot');
  t('Schedule');
  t('Shows');
  t('TakePart');
  t('Twitter');
  t('Videos');
  t('Watch Pivot Live >>');
  t('YouTube');
  t('iOS');


  return $menu_links;
}
