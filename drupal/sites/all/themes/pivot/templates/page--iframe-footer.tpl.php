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

    Drupal.behaviors.resizeFooter = {
      attach: function() {
        var pxH = $('#footer-inner').height();
        setTimeout(function(){parent.kpiFrameSize(pxH);}, 1500);
      }
    };
  })(jQuery, Drupal, this, this.document);",
  array('type' => 'inline', 'scope' => 'footer'));
print render($page['footer']); ?>
