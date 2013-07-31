<?php
  drupal_add_js('document.domain = "pivot.tv";
  ', 'inline');

  drupal_add_js("
  (function ($, Drupal, window, document, undefined) {
    Drupal.behaviors.iframeLinks = {
      attach: function () {
        $('a').attr('target', '_top');
        alert('test');
      }
    };
  })(jQuery, Drupal, this, this.document);",
  'inline');
print render($page['footer']); ?>
