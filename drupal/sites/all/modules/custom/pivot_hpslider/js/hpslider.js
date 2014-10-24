(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.homepageSlider = {
    attach: function() {

      $(document).ready(function(){
        $('.bxslider').bxSlider({
          nextSelector: '.next-slide',
          prevSelector: '.prev-slide',
          nextText: '',
          prevText: '',
          mode: 'fade',
          onSlideAfter: function(){
            jwplayer().stop();
          }
        });
      });

    }
  };

})(jQuery, Drupal, this, this.document);