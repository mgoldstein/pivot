<?php
/**
 * @file
 * Custom Blocks for the Pivot.tv website
 */
/**
 * Implements hook_block_info().
 *
 * Define custom blocks for the Pivot.tv website
 */
function pivot_global_block_info() {
    $blocks = array();
    $blocks['pivot_global_header_nav'] = array(
        'info' => t('Pivot Global Header Nav block'),
    );
    $blocks['find_pivot_sidebar'] = array(
        'info' => t('Find Pivot in Your Area Block'),
    );

    $blocks['pivot_twitter_widget'] = array(
        'info' => t('Pivot Twitter Widget Block'),
    );

    $blocks['pivot_global_footer'] = array(
        'info' => t('Pivot Global Footer block'),
    );

    return $blocks;
}

/**
 * Implements hook_block_view().
 *
 * Output custom blocks for the Pivot.tv website
 */
function pivot_global_block_view($block_name) {

    $block = array();

    switch ($block_name) {
        // Global Header for non-homepage pages
        case 'pivot_global_header_nav':
            $block['subject'] = ''; // no title
            $block['content'] = pivot_global_header();
        break;
        // find pivot in your area sidebar widget
        case 'find_pivot_sidebar':
            $block['subject'] = ''; // no title
	    $block['content'] = '<a id="find-pivot"></a><div id="kpiDivV2"><iframe src="http://find.pivot.tv/rrV2ZipForm.asp" id="kpiFrameV2" style="width:300px;height:100px;" frameborder="0" scrolling="no" allowTransparency="true"></iframe></div>';
        break;

        case 'pivot_twitter_widget':
            $block['subject'] = ''; // no title
            $block['content'] = '<a class="twitter-timeline" href="https://twitter.com/pivot_tv" data-widget-id="329027240346128386">Tweets by @pivot_tv</a>';
            $block['content'] .= '<script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?"http":"https";if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src=p+"://platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>';
        break;

        case 'pivot_global_footer':
            $block['subject'] = ''; // no title
	    $block['content'] = '<nav class="nav footer-main-nav"><h1 class="headline">Secondary Site Navigation</h1>' . drupal_render(menu_tree('menu-pivot-footer')) . '</nav>';
            $block['content'] .= '<div class="secondary">';
	    $block['content'] .= '<div class="nav footer-follow-nav"><h3 class="headline">Follow</h3>' . drupal_render(menu_tree('menu-follow-us')) . '</div>';
	    $block['content'] .= '<div class="nav footer-apps-nav"><h3 class="headline">Apps</h3>' . drupal_render(menu_tree('menu-get-our-app')) . '</div>';
	    // $block['content'] .= '<div class="nav footer-participant-nav"><h3 class="headline">Pivot is part of Participant Media:</h3>' . drupal_render(menu_tree('menu-participant-media')) . '</div>';
            $block['content'] .= '</div><!-- /.secondary -->';
	    $block['content'] .= '<div id="copyright"><p>&copy; ' . date("Y") . ' Participant Channel, Inc. All Rights Reserved.</p></div>';
        break;

    }

    return $block;
}

/**
 * Provide HTML for the Pivot global header.
 *
 * @return string an html string for the pivot global header
 *
 * @todo this should be in a template file
 */
function pivot_global_header() {
  $output = '<div class="primary">
    <div class="site-wrapper">
      <a class="logo" href="/"><p class="headline">Pivot</p></a>

      <nav class="nav nav-primary">
        <h1 class="headline">Site Navigation</h1>
        ' . drupal_render(menu_tree('menu-primary')) . '
      </nav>
    </div>
  </div>';

  //TODO Integrate with Druapl and Search
  $output .= '<div class="secondary">
      <nav class="nav nav-secondary site-wrapper">
          <h1 class="headline">More Site Navigation</h1>
          <div class="find-pivot">'.
            l('Find <span class="pivot">Pivot</span> in your area', 'http://find.pivot.tv', array('html' => TRUE, 'attributes' => array('class' => array('important')))).

          '</div>
          <div class="search">
            ' . drupal_render(module_invoke('search', 'block_view', 'form')) . '
          </div>
      </nav>
    </div>';

  return $output;
}

/**
 * Implements hook_form_alter().
 *
 * Add placeholder text to the search block.
 */
function pivot_global_form_alter(&$form, &$form_state, $form_id) {
  // removed per PIV-285, but left this here in case this comes back
  // if ($form_id == 'search_block_form') {
  //   // Add HTML5 placeholder attribute
  //   $form['search_block_form']['#attributes']['placeholder'] = t('Search');
  // }
}
