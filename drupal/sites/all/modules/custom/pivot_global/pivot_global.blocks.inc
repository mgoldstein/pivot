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

        // find pivot in your area sidebar widget
        case 'find_pivot_sidebar':
            $block['subject'] = ''; // no title
            $block['content'] = '<img src="http://placehold.it/300x97&text=Find+Pivot" alt>';
        break;

        case 'pivot_twitter_widget':
            $block['subject'] = ''; // no title
            $block['content'] = '<a class="twitter-timeline" data-dnt="true" href="https://twitter.com/pivot_tv" data-widget-id="349311679672221697">Tweets by @pivot_tv</a>';
            $block['content'] .= '<script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?"http":"https";if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src=p+"://platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>';
        break;

        case 'pivot_global_footer':
            $block['subject'] = ''; // no title
            $block['content'] = '<nav class="nav footer-main-nav"><h2 class="headline">More on Pivot</h2>' . drupal_render(menu_tree('menu-pivot-footer')) . '</nav>';
            $block['content'] .= '<div class="secondary">';
            $block['content'] .= '<section class="nav footer-follow-nav"><h3 class="headline">Follow</h3>' . drupal_render(menu_tree('menu-follow-us')) . '</section>';
            $block['content'] .= '<section class="nav footer-apps-nav"><h3 class="headline">Apps</h3>' . drupal_render(menu_tree('menu-get-our-app')) . '</section>';
            $block['content'] .= '<section class="nav footer-participant-nav"><h3 class="headline">Pivot is part of Participant Media:</h3>' . drupal_render(menu_tree('menu-participant-media')) . '</section>';
            $block['content'] .= '</div><!-- /.secondary -->';
            $block['content'] .= '<div id="copyright"><p>&copy; 2013 Pivot TV, all rights reserved.</p></div>';
        break;

    }

    return $block;    
}
