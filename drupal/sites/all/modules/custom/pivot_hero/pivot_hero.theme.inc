<?php

function theme_pivot_hero_format($variables) {
  $poster = file_create_url($variables['entity_data']->field_hs_bg_image['und'][0]['uri']);
  $output = '<video class="video-player" poster="'. $poster. '" width="960" height="540" loop="loop">';
  $video = file_create_url($variables['items'][0]['uri']);
  $output .= '<source src="'. $video. '" type="'. $variables['items'][0]['filemime']. '" />';
  $output .= '<object type="application/x-shockwave-flash" data="/other/flashfox.swf" width="960" height="540" style="position:relative;">
    <param name="movie" value="/other/flashfox.swf" />
    <param name="allowFullScreen" value="true" />
    <param name="flashVars" value="autoplay=true&amp;controls=false&amp;fullScreenEnabled=false&amp;posterOnEnd=true&amp;loop=true&amp;poster=/files/PVT_FTG_Friday_1.jpg&amp;src=http://article-redesign.dev.takepart.com/files/PVT_FTG_Friday_1.m4v" />
    <embed src="http://article-redesign.dev.takepart.com/other/flashfox.swf" width="960" height="540" style="position:relative;"  flashVars="autoplay=true&amp;controls=false&amp;fullScreenEnabled=false&amp;posterOnEnd=true&amp;loop=true&amp;poster=/files/PVT_FTG_Friday_1.jpg&amp;src=http://article-redesign.dev.takepart.com/files/PVT_FTG_Friday_1.m4v"  allowFullScreen="true" wmode="transparent" type="application/x-shockwave-flash" pluginspage="http://www.adobe.com/go/getflashplayer_en" />
  </object>';
  $output .= '</video>';
  return $output;
}

