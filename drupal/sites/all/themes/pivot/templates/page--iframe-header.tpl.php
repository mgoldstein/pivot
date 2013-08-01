<?php
  drupal_add_js('document.domain = "pivot.tv";
  ', 'inline');

  drupal_add_js("
  (function ($, Drupal, window, document, undefined) {
    Drupal.behaviors.iframeLinks = {
      attach: function () {
        $('a').attr('target', '_top');
      }
    };
  })(jQuery, Drupal, this, this.document);",
  'inline');
?>
<header id="site-header" role="banner" class="header">
  <?php
  unset($page['header']['pivot_ros_leaderboard_728x90']);
  print render($page['header']); ?>
</header>
