(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.homepageSlider = {
    attach: function() {

      $(document).ready(function(){
        $('.bxslider').bxSlider();
      });

    }
  };

})(jQuery, Drupal, this, this.document);