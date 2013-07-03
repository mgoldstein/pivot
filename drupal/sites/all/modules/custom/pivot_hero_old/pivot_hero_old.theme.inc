<?php

function theme_pivot_hero_old_format($variables) {
  $poster = file_create_url($variables['entity_data']->field_hs_bg_image['und'][0]['uri']);
  $output = '<video class="video-player" poster="'. $poster. '" width="960" height="540" loop="loop" autoplay>';
  $video = file_create_url($variables['items'][0]['uri']);
  $output .= '<source src="'. $video. '" type="'. $variables['items'][0]['filemime']. '" />';
  $output .= '<object type="application/x-shockwave-flash" data="/other/flashfox.swf" width="960" height="540" style="position:relative;">
    <param name="movie" value="/other/flashfox.swf" />
    <param name="allowFullScreen" value="true" />
    <param name="flashVars" value="autoplay=true&amp;controls=false&amp;fullScreenEnabled=false&amp;posterOnEnd=true&amp;loop=true&amp;poster='. $poster. '&amp;src='. $video. '" />
    <embed src="http://article-redesign.dev.takepart.com/other/flashfox.swf" width="960" height="540" style="position:relative;"  flashVars="autoplay=true&amp;controls=false&amp;fullScreenEnabled=false&amp;posterOnEnd=true&amp;loop=true&amp;poster='. $poster. '&amp;src='. $poster. '"  allowFullScreen="true" wmode="transparent" type="application/x-shockwave-flash" pluginspage="http://www.adobe.com/go/getflashplayer_en" />
  </object>';
  $output .= '</video>';

  
  $output .= '<img class="video-image" src="'. $poster. '" width="960" height="540" />';

  $image_path = file_create_url($variables['entity_data']->field_hs_slider_image['und'][0]['uri']);
  $output .= '<div class="video-content">
          <div class="video-content-inner">
            <div class="primary">
              <p>
                <img alt="PEOPLE" height="445" src="'. $image_path. '" width="793" />
              </p>
            </div>
            <div class="secondary">
              <h3 class="headline">'. $variables['entity_data']->title. '</h3>
              <p class="description">'. $variables['entity_data']->field_hs_slider_text['und'][0]['value']. '</p>
              <p class="more">'. l($variables['entity_data']->field_hs_link['und'][0]['title'], $variables['entity_data']->field_hs_link['und'][0]['url']). '</p>
            </div>
          </div>
        </div>';

  return $output;
}

