(function($) {
  $.fn.analytics_ncs = function(errors) {
    if(errors == null) {
	s.linkTrackVars = "eVar22,eVar23,eVar30,events";
        s.linkTrackEvents = "event39";
        s.events = "event39";
        s.eVar22 = "Right Rail Signup";
	s.tl(this, "o", s.eVar27);
	_gaq.push(['_trackEvent', 'Social Shares', 'Click', s.eVar22]);
    }
  };
})(jQuery);
