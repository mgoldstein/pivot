(function ($, Drupal, window, document, undefined) {

    Drupal.behaviors.interstitialChannelFinder = {
        attach: function() {

            if (Drupal.settings.touchEnabled) {
                $('.interstitial')
                    .find('.interstitial-cta')
                    .on('touchend', function(e) {
                        var $this = $(this);
                        e.preventDefault();
                        $('.channel-finder-widget').toggleClass('expose');
                    })
                ;
            }else{
            $('.interstitial')
            .find('.interstitial-cta')
                    .on('click', function(e) {
                        var $this = $(this);
                        e.preventDefault();
                        $('.channel-finder-widget').toggleClass('expose');
                    })
            }
        }
    };
})(jQuery, Drupal, this, this.document);