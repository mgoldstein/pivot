<?php

/**
 * Implements hook_block_info().
 */
function pivot_global_block_info() {
    $blocks = array();

    $blocks['find_pivot_sidebar'] = array(
        'info' => t('Find Pivot in Your Area Block'),
    );

    $blocks['pivot_twitter_widget'] = array(
        'info' => t('Pivot Twitter Widget Block'),
    );

    return $blocks;
}

/**
 * Implements hook_block_view().
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
    }

    return $block;    
}
