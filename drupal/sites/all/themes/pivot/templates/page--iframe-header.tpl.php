<?php
  drupal_add_js('document.domain = "pivot.tv";
  ', 'inline');

  drupal_add_js('
  (function ($, Drupal, window, document, undefined) {
    Drupal.behaviors.iframeLinks = {
      attach: function () {
        $("a").attr("target", "_top");
      }
    };
    Drupal.behaviors.resizeFrameOnClick = {
      attach: function() {
        var $siteHeader = $("#site-header"),
            click = "click",
            isTouchmove = false;

        if ( "ontouchend" in document.documentElement ) click = "touchend";

        parent.pivotHeaderHeight($siteHeader.height() + " px");

        $siteHeader
          .on("touchmove", function() {
            isTouchmove = true;
          })
          .on(click, function() {
            if (click == "touchend" && isTouchmove) {
              isTouchmove = false;
              return true;
            } else {
              setTimeout(function() {parent.pivotHeaderHeight($("#site-header").height() + " px");}, 550);              
            }
        });
      }
    };
  })(jQuery, Drupal, this, this.document);',
  'inline');
?>
<header id="site-header" role="banner" class="header">
  <?php
  unset($page['header']['dfp_pivot_ros_leaderboard_728x90']);
  print render($page['header']);
  ?>
</header>
