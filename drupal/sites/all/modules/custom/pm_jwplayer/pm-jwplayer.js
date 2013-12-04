(function ($, Drupal, window, document, undefined) {

  Drupal.pm_jwplayer = {
    setup: function(element_id) {
      if (element_id in Drupal.settings.pm_jwplayer) {
        var settings = Drupal.settings.pm_jwplayer[element_id];
        var element = $('#' + element_id);
        if (!element) { return; }
        var attribute = element.attr('data-allowed-regions');
        var regions = attribute ? attribute.split(',') : [];
        if (regions.length > 0) {
          var blockVideo = function() {
            element.addClass('blocked').removeClass('loading');
          };
          var handleResponse = function(response) {
            if (!response.country || !response.country.iso_code) {
              element.addClass('blocked').removeClass('loading');
              return false;
            }
            var code = response.country.iso_code.toLowerCase();
            if ($.inArray(code, regions) < 0) {
              element.addClass('blocked').removeClass('loading');
            }
            else {
              element.removeClass('loading');
              var player = jwplayer(element_id);
              if ('setup' in player) { player.setup(settings); }
            }
          };
          geoip2.country(handleResponse, blockVideo);
        }
        else {
          var player = jwplayer(element_id);
          if ('setup' in player) { player.setup(settings); }
        }
      }
    }
  }
})(jQuery, Drupal, this, this.document);
