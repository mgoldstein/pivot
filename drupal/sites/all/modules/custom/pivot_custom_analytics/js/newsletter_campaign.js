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
      }
    );
  });
})(jQuery);
