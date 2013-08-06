(function ($) {
  $(document).ready(function() {
    $("body").bind(
      'newsletter_social_signup', function(e, title) {

        s.linkTrackVars = "eVar22,eVar23,eVar30,events";
        s.linkTrackEvents = "event39";
        s.eVar22 = 'Right Rail Signup';
        s.eVar23 = title;
        s.eVar30 = s.pageName;
        s.events = 'event39';
        s.tl(true, 'o', 'Newsletter Signup');

        _gaq.push(['_trackEvent', 'Social Shares', 'Click', s.eVar22]);

        // Tracking pixel.
        var axel = Math.random() + "";
        var a = axel * 10000000000000;
        var $frame = $('<iframe src="http://4208400.fls.doubleclick.net/activityi;src=4208400;type=pivot139;cat=email694;ord=1;num=' + a + '?" width="1" height="1" frameborder="0" style="display:none"></iframe>');
        var $pixel = $('<img width="1" height="1" style="display:none" src="http://pixel3891.everesttech.net/3891/p?ev_transid=&ev_Email_Signup=1" />');
        $(this).append($frame).append($pixel);
      }
    );
  });
})(jQuery);
