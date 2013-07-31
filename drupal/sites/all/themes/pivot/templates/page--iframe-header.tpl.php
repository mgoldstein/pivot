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
  <?php print render($page['header']); ?>
</header>
