(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.pivotCollab = {
    attach: function (context, settings) {
      $(document).ready(function() {
        window.init_pivot_collab_block();

        $(window).smartresize(function() {
          window.init_pivot_collab_block();
        });
      });
      $('.megamenu-wrapper #megamenu li').hover(
        function(){
          $(this).addClass('pivot-hover');  //TODO: adjust the CSS to reflect the 'pivot' change
        },
        function(){
          $(this).removeClass('pivot-hover');
        }
      );
    }
  };

  /**
   *  @function:
   *    This is a window function to init the custom block
   */
  window.init_pivot_collab_block = function() {
    var small = 401;
    var large = 701;

    //does for each collab block
    $('.pivot-collab-block').each(function(i, v) {  //TODO: sync this to the class in the output
      $(this).unbind('mouseenter mouseleave');

      //anything smaller than desktop
      if ($(window).width() < large) {
        //binds click to the div
        $(this).bind('click', function() {
          $('.normal-state', this).hide();
          $('.focus-state', this).show();
        });

        //additional code to handle the mousedown and touch for mobile
        $("body").bind('touchstart mousedown', function(event) {
          if (!$(event.target).hasClass('focus-state-link')) {
            $('.normal-state', this).show();
            $('.focus-state', this).hide();
          }
        });
      }
      else {
        //desktop
        $(this).hover(function() {
          $('.normal-state', this).hide();
          $('.focus-state', this).show();
        }, function() {
          $('.normal-state', this).show();
          $('.focus-state', this).hide();
        });
      }
    });
  }

})(jQuery, Drupal, this, this.document);