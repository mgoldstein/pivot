<?php

function pivot1_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $element['#localized_options']['absolute'] = TRUE;

  // Put the link classes on the li
  $element['#attributes']['class'] = @array_merge(@$element['#localized_options']['attributes']['class'], @$element['#attributes']['class']);

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

function pivot1_preprocess_node(&$vars) {
  if ( $vars['view_mode'] == 'full' && drupal_is_front_page() ) {
    $vars['theme_hook_suggestions'][] = 'node__landing_page__home';
  }
} 