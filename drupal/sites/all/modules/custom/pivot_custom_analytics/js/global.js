//Share Tracking
jQuery(document).ready(function () {
  jQuery(".tp-social a,.article-more-shares a").click(function (event) {
    s.linkTrackVars = "eVar1,eVar4,eVar17,eVar27,eVar30,eVar70,events";
    s.linkTrackEvents = "event25";
    s.events = "event25";
    if (jQuery(event.target).attr("class").indexOf("tp-social-facebook") > -1) {
	 s.eVar27 = "Facebook";
    }
    if (jQuery(event.target).attr("class").indexOf("tp-social-email") > -1) {
	 s.eVar27 = "Email";
    }
    if (jQuery(event.target).attr("class").indexOf("tp-social-twitter") > -1) {
	 s.eVar27 = "Twitter";
    }
    if (jQuery(event.target).attr("class").indexOf("tp-social-googleplus") > -1) {
	 s.eVar27 = "GooglePlus";
    }
    if (jQuery(event.target).attr("class").indexOf("tp-social-tumblr") > -1) {
	 s.eVar27 = "Tumblr";
    }
    if (jQuery(event.target).attr("class").indexOf("tp-social-gmail") > -1) {
	 s.eVar27 = "Gmail";
    }
    if (jQuery(event.target).attr("class").indexOf("tp-social-hotmail") > -1) {
	 s.eVar27 = "Hotmail";
    }
    if (jQuery(event.target).attr("class").indexOf("tp-social-yahoomail") > -1) {
	 s.eVar27 = "Yahoomail";
    }
    if (jQuery(event.target).attr("class").indexOf("tp-social-aolmail") > -1) {
	 s.eVar27 = "AOLMail";
    }
    if (jQuery(event.target).attr("class").indexOf("tp-social-linkedin") > -1) {
	 s.eVar27 = "Linkedin";
    }
    if (jQuery(event.target).attr("class").indexOf("tp-social-digg") > -1) {
	 s.eVar27 = "DIGG";
    }
    if (jQuery(event.target).attr("class").indexOf("tp-social-stumbleupon") > -1) {
	 s.eVar27 = "Stumbleupon";
    }
    s.tl(this, "o", s.eVar27);
    ga('send', 'event', 'Social Shares', 'Click', s.eVar27);
  });
});
