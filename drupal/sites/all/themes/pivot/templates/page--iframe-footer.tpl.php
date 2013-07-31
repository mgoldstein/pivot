<?php
  drupal_add_js('
    document.domain = "pivot.tv";
    ', 'inline');
print render($page['footer']); ?>
