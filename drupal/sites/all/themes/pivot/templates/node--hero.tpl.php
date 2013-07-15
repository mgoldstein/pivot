<?php print render(field_view_field('node', $node, 'field_hs_bg_video', 'default')); ?>
<?php
  $poster = file_create_url($variables['field_hs_bg_image']['und'][0]['uri']);
  $output = '<img class="video-image" src="'. $poster. '" width="960" height="540" />';
  $image_path = file_create_url($variables['field_hs_slider_image'][0]['uri']);
  $more_link = '&nbsp;';
  if (isset($variables['field_hs_link'][0]['title']) && isset($variables['field_hs_link'][0]['url'])) {
    $more_link = l($variables['field_hs_link'][0]['title'], $variables['field_hs_link'][0]['url'], array('attributes' => array('class' => 'important')));
  }
  $output .= '<div class="video-content">
          <div class="video-content-inner">
            <div class="secondary promo">
                <img alt="PEOPLE" height="445" src="'. $image_path. '" width="793" />
            </div><!--
            --><div class="primary">
              <h3 class="headline">'. $title. '</h3>
              <p class="description">'. $variables['field_hs_slider_text'][0]['value']. '</p>
              <p class="more">' . (isset($more_link) ? $more_link : ''). '</p>  
            </div>
          </div>
        </div>';

  print $output;
?>

