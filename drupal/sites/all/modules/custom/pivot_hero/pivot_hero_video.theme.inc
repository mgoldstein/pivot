<?php

function theme_pivot_hero_video_format($variables) {
  $poster = file_create_url($variables['entity_data']->field_hs_bg_image['und'][0]['uri']);
  $output = '<video class="video-player" poster="'. $poster. '" width="960" height="540" loop="loop">';
  if(isset($variables['items'][0]['uri'])) {
    $video0 = file_create_url($variables['items'][0]['uri']);
    $video1 = file_create_url($variables['items'][1]['uri']);
    $output .= '<source src="'. $video0. '" type="'. $variables['items'][0]['filemime']. '" />';
    $output .= '<source src="'. $video1. '" type="'. $variables['items'][1]['filemime']. '" />';
    $output .= '<object type="application/x-shockwave-flash" data="'. drupal_get_path('module', 'pivot_hero'). '/flashfox.swf" width="960" height="540" style="position:relative;">
      <param name="movie" value="'. drupal_get_path('module', 'pivot_hero'). '" />
      <param name="allowFullScreen" value="true" />
      <param name="flashVars" value="autoplay=true&amp;controls=false&amp;fullScreenEnabled=false&amp;posterOnEnd=true&amp;loop=true&amp;poster='. $poster. '&amp;src='. $video1. '" />
      <embed src="http://article-redesign.dev.takepart.com/other/flashfox.swf" width="960" height="540" style="position:relative;"  flashVars="autoplay=true&amp;controls=false&amp;fullScreenEnabled=false&amp;posterOnEnd=true&amp;loop=true&amp;poster='. $poster. '&amp;src='. $video1. '"  allowFullScreen="true" wmode="transparent" type="application/x-shockwave-flash" pluginspage="http://www.adobe.com/go/getflashplayer_en" />
    </object>';
  }
  $output .= '</video>';

  return $output;
}

