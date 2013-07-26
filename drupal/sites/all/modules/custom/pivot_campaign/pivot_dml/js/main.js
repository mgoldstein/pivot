(function ($, Drupal, window, document, undefined) {

	function getInternetExplorerVersion()
	{
		// Returns the version of Internet Explorer or a -1
		// (indicating the use of another browser).
	  var rv = -1; // Return value assumes failure.
	  if (navigator.appName == 'Microsoft Internet Explorer')
	  {
	    var ua = navigator.userAgent;
	    var re  = new RegExp("MSIE ([0-9]{1,}[\.0-9]{0,})");
	    if (re.exec(ua) != null)
	      rv = parseFloat( RegExp.$1 );
	  }
	  return rv;
	}

	function getURLParameter(name) {
	    return decodeURI(
		(RegExp(name + '=' + '(.+?)(&|$)').exec(location.search)||[,null])[1]
	    );
	}

	function popupwindow(url, title, w, h) {
		  var left = (screen.width/2)-(w/2);
		  var top = (screen.height/2)-(h/2);
		  return window.open(url, title, 'toolbar=no, location=no, directories=no, status=no, menubar=no, scrollbars=no, resizable=no, copyhistory=no, width='+w+', height='+h+', top='+top+', left='+left);
	}

	function postToFBFeed(link, image, name, caption, description) {

		// calling the API ...
		var obj = {
			method: 		'feed',
			display: 		'popup',
			link:  			link,
			picture:  		image,
			name: 			name,
			caption:  		caption,
			description: 	description
		};

	    function callback(response) {
	      //document.getElementById('msg').innerHTML = "Post ID: " + response['post_id'];
	    }

	    FB.ui(obj, callback);
	}

	function socialShare() {
		$('a.share.fb').click(function(e){
			e.preventDefault();
			trackingEvents('fb','');
			var link = $(this).data('link');
			var image = $(this).data('image');
			var name = $(this).data('name');
			var caption = $(this).data('caption');
			var description = $(this).data('description');
			postToFBFeed(link, image, name, caption, description);
		});
		$('a.share.twitter').click(function(e){
			trackingEvents('twitter', '');
		});
		$('a.share.gplus').click(function(e){
			e.preventDefault();
			trackingEvents('gplus','');
			var href = $(this).attr('href');
			popupwindow(href, 'Share on Facebook', 500, 500);
		});
		$('a.share.email').click(function(e){
			trackingEvents('email', '');
		});
	}


	// process triggers and fire tracking events
	function trackingEvents(trigger, message) {

		var s = window.s;

		if (s) {
			switch(trigger) {
				case "fb":
					s.linkTrackVars = 'prop68,eVar27,eVar30,events';
					s.linkTrackEvents = 'event25,event86';
					s.events = 'event25,event86';
					s.eVar27 = 'Facebook';
					s.eVar30 = s.pageName;
					s.tl(true, 'o', 'Shares Content');
					break;
				case "twitter":
					s.linkTrackVars = 'prop68,eVar27,eVar30,events';
					s.linkTrackEvents = 'event25,event86';
					s.events = 'event25,event86';
					s.eVar27 = 'Twitter';
					s.eVar30 = s.pageName;
					s.tl(true, 'o', 'Shares Content');
					break;
				case "gplus":
					s.linkTrackVars = 'prop68,eVar27,eVar30,events';
					s.linkTrackEvents = 'event25,event86';
					s.events = 'event25,event86';
					s.eVar27 = 'GooglePlus';
					s.eVar30 = s.pageName;
					s.tl(true, 'o', 'Shares Content');
					break;
				case "email":
					s.linkTrackVars = 'prop68,eVar27,eVar30,events';
					s.linkTrackEvents = 'event25,event86';
					s.events = 'event25,event86';
					s.eVar27 = 'Email';
					s.eVar30 = s.pageName;
					s.tl(true, 'o', 'Shares Content');
					break;
				case "infographic":
					s.linkTrackVars = 'prop68,eVar30,eVar45,events';
					s.linkTrackEvents = 'event45,event87';
					s.events = 'event45,event87';
					s.eVar45 = message;
					s.eVar30 = s.pageName;
					s.tl(true, 'o', 'Clicks to View Infographic');
					break;
				default:
					// do nothing
			}
		}
	}

	// process quiz callback triggers and fire tracking events
	function quizCallbacks(trigger, message) {
		var messageObj = JSON.parse(message);
		var s = window.s;

		if (s) {
			switch (trigger) {
				case "quiz start":
					s.linkTrackVars = 'prop68,eVar30,events';
					s.linkTrackEvents = 'event79';
					s.events = 'event79';
					s.eVar30 = s.pageName;
					s.prop68 = 'Quiz Start';
					s.tl(true, 'o', 'Quiz Start');
					break;
				case "question loaded":
					var qNum = (parseInt(messageObj.index) +1);
					qNum = qNum.toString();
					s.linkTrackVars = 'prop68,eVar30,eVar68,events';
					s.linkTrackEvents = 'event81';
					s.events = 'event81';
					s.eVar68 = qNum + '. '+ messageObj.message;
					s.eVar30 = s.pageName;
					s.prop68 = 'Clicks to View Quiz Question';
					s.tl(true, 'o', 'Clicks to View Quiz Question');
					break;
				case "response":
					var qNum = (parseInt(messageObj.index) +1);
					qNum = qNum.toString();
					if (messageObj.response == 'correct') {
						s.linkTrackVars = 'prop68,eVar30,eVar68,events';
						s.linkTrackEvents = 'event82,event83';
						s.events = 'event82,event83';
						s.eVar68 = messageObj.message;
						s.eVar30 = s.pageName;
						s.tl(true, 'o', 'Quiz Answer: Right');
					} else {
						s.linkTrackVars= 'prop68,eVar30,eVar68,events';
						s.linkTrackEvents = 'event82,event84';
						s.events = 'event82,event84';
						s.eVar68 = messageObj.message;
						s.eVar30 = s.pageName;
						s.tl(true, 'o', 'Quiz Answer: Wrong');
					}
					break;
				case "quiz completed":
					s.linkTrackVars = 'prop69,eVar30,events';
					s.linkTrackEvents = 'event85';
					s.events = 'event85';
					s.eVar68 = messageObj.score;
					s.eVar30 = s.pageName;
					s.tl(true, 'o', 'Finishes Quiz');
					break;
				default:
					// do nothing
			}
		}
	}


	// page specific init methods

	function init_home() {

		socialShare();

		// initialize tweet rotator
		$('div.tweets ul').bxSlider({
			mode: 			'vertical',
			easing: 		'ease-out',
			infiniteLoop: 	true,
			pager: 			false,
			controls: 		false,
			auto: 			true,
			pause: 			6000,
			startSlide: 	0,
			autoHover: 		true,
			onSliderLoad: function() {
				$('div.tweets ul').removeClass('start');
			}
		});

		// initialize lightbox
		var infoName = $('a[rel="lightbox"] img').data('name');
		$('a[rel="lightbox"]').magnificPopup({
			type:'image',
			image: {
				verticalFit: false
			},
			disableOn: function() {
			  if( $(window).width() < 480 ) {
			    return false;
			  }
			  return true;
			},
			closeOnContentClick: true,
			callbacks: {
			    open: function() {
			      //console.log('image loaded');
				  trackingEvents('infographic',infoName);
			    }
			  }
		});

		// check URL and load lightbox
		var useCookie = false;
		if (useCookie == true) {
			if (getURLParameter('share') == 'infographic') {
				// check cookie and load lightbox
				if (document.cookie.indexOf('visited=true') === -1) {
				    var expires = new Date();
				    expires.setDate(expires.getDate()+1); //expire after 1 day
				    document.cookie = "visited=true; expires="+expires.toUTCString();
				    $('a[rel="lightbox"]').magnificPopup('open');
				}
			}
		} else {
			if (getURLParameter('share') == 'infographic') {
				$('a[rel="lightbox"]').magnificPopup('open');
			}
		}

	}

	function init_quiz() {

		socialShare();
		var fileURL = $('#quiz-container').data('file');
		$.getJSON(fileURL, function(data) { createQuiz(data); });
		function createQuiz(data) {
			$('#quiz-container').slickQuiz({
				json: data,
				singleResponseMessaging: true,
				preventUnanswered: true,
				animationCallback: function(trigger, message) {
					if (trigger == 'response') {
						var messageObj = JSON.parse(message);
						console.log('response: ' + messageObj.response + '\nindex: ' + messageObj.index + '\nmessage: ' + messageObj.message);
						$('div.icons div').eq(messageObj.index).addClass(messageObj.response);
						quizCallbacks(trigger, message);
					} else if (trigger == 'question loaded') {
						var messageObj = JSON.parse(message);
						console.log("trigger: "+trigger+'\nindex: ' + messageObj.index + '\nmessage: ' + messageObj.message);
						var index = parseInt(messageObj.index);
						$('#quiz-container div.content').attr('class','content q'+ (index +1));
						$('#quiz-container div.icons').attr('class','icons q'+ (index +1));
						quizCallbacks(trigger, message);
					} else if (trigger == 'quiz completed') {
						$('#quiz-container div.content').attr('class','content results');
						$('#quiz-container div.icons').attr('class','icons');
						var messageObj = JSON.parse(message);
						console.log("trigger: "+trigger+'\nscore: ' + messageObj.score );
					} else {
						console.log('trigger: ' + trigger + '\nmessage: ' + message);
					}

				}
			});
			$('div.quizResults div.share a').click(function(e){
				e.preventDefault();
				$('div#quiz-container div.quizResults').hide();
				$('div#quiz-container div.content').addClass('share');
				$('div#quiz-container div.social-share').fadeIn(500);
				$('div.social-share div.back').fadeIn(500);

			});
			$('div.social-share div.back a').click(function(e){
				e.preventDefault();
				$('div#quiz-container div.social-share').hide();
				$('div#quiz-container div.content').removeClass('share');
				$('div#quiz-container div.quizResults').fadeIn(500);

			});
		}
	}



	Drupal.behaviors.setupDML = {
		attach: function () {

			var $body = $('body');

			// set current class on dml menu li
			$('a.active').parent().addClass('current');

			// add IE 10 Class
			if (getInternetExplorerVersion() == 10) {
				$('html').addClass("ie10");
			}

			// Page specific
			if ( $body.is('.page-dml-home')) {
				init_home();
			} // end .home
			if ( $body.is('.page-dml-quiz')) {
				init_quiz();
			}
		}
	};

})(jQuery, Drupal, this, this.document);
