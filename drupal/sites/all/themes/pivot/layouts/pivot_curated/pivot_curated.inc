<?php

// Plugin definition
$plugin = array(
  'title' => t('Pivot Curated'),
  'category' => t('Pivot Layouts'),
  'icon' => 'pivot_curated.png',
  'theme' => 'panels_pivot_curated',
  'css' => 'pivot_curated.css',
  'regions' => array(
    'top' => t('Top'),
    'left' => t('Left side'),
    'right' => t('Right side'),
  ),
);
