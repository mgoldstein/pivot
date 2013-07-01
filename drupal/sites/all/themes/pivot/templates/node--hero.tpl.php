<?php print render(field_view_field('node', $node, 'field_hs_bg_video', 'default')); ?>
<?php
  $poster = file_create_url($variables['field_hs_bg_image']['und'][0]['uri']);
  $output = '<img class="video-image" src="'. $poster. '" width="960" height="540" />';
  $image_path = $variables['field_hs_slider_image'][0]['uri'];
  $output .= '<div class="video-content">
          <div class="video-content-inner">
            <div class="primary">
              <p>
                <img alt="PEOPLE" height="445" src="'. $image_path. '" width="793" />
              </p>
            </div>
            <div class="secondary">
              <h3 class="headline">'. $title. '</h3>
              <p class="description">'. $variables['field_hs_slider_text'][0]['value']. '</p>
              <p class="more">'. l($variables['field_hs_link'][0]['title'], $variables['field_hs_link'][0]['url']). '</p>
            </div>
          </div>
        </div>';

  print $output;

?>