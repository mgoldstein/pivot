<?php
  drupal_add_js('document.domain = "pivot.tv";
  ', 'inline');

  drupal_add_js('
  (function ($, Drupal, undefined) {
    Drupal.behaviors.iframeLinks = {
      attach: function () {
        $("a").attr("target", "_top");
      }
    };
    Drupal.behaviors.resizeFrameOnClick = {
      attach: function() {
        var click = "click",
            isTouchmove = false,
            resizing = false,
            lastHeight = $("#site-header").height(),
            resizeHeader = function() {
              var h = $("#site-header").height();
              if (h == lastHeight) {
                clearTimeout(resizing);
              }
              else {
                parent.pivotHeaderHeight(h + "px");
                lastHeight = h;
                setTimeout(resizeHeader, 25);
              }
            };

        if ( "ontouchend" in document.documentElement ) click = "touchend";

        setTimeout(resizeHeader, 1000);

        $("#site-header")
          .on("touchmove", function() {
            isTouchmove = true;
          })
          .on(click, function() {
            if (click == "touchend" && isTouchmove) {
              isTouchmove = false;
              return true;
            } else {
              resizing = setTimeout(resizeHeader, 25);
            }
        });
      }
    };

  })(jQuery, Drupal);',
  'inline');
?>
<header id="site-header" role="banner" class="header">
  <?php
  unset($page['header']['dfp_pivot_ros_leaderboard_728x90']);
  print render($page['header']);
  ?>
</header>
