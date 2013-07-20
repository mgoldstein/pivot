/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - http://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

	/**
	 * Add the Facebook JS SDK to the page.
	 */
	window.fbAsyncInit = function() {
		// init the FB JS SDK
		FB.init({
			appId      : '247137505296280',                    // App ID from the app dashboard
			channelUrl : '//gallery-redesign.dev.takepart.com/facebook/channel', // Channel file for x-domain comms
			status     : true,                                 // Check Facebook Login status
			cookie     : true,
			xfbml      : true                                  // Look for social plugins on the page
		});

		// Additional initialization code such as adding Event Listeners goes here
  };

	// Load the SDK asynchronously
	(function(d, s, id){
		var js, fjs = d.getElementsByTagName(s)[0];
		if (d.getElementById(id)) {return;}
		js = d.createElement(s); js.id = id;
		js.src = "//connect.facebook.net/en_US/all.js";
		fjs.parentNode.insertBefore(js, fjs);
	 }(document, 'script', 'facebook-jssdk'));


	Drupal.behaviors.globalNavigationResponsive = {
		attach: function() {
			$('body').delegate('#site-header .primary', 'click', function(event) {
				if($(event.target).is("a,input") || $(event.target).parents().is("a,input")) {
					return;
				}
				$(this).toggleClass('open');
			});
		}
	};

	Drupal.behaviors.articleSocialShareButtons = {
		attach: function() {

			var $body = $('body');

			if ($body.is('.node-type-article')) {
				// Social share buttons
				var tp_social_config = {
					services: [
						{name: 'facebook'},
						{
							name: 'twitter',
							text: '{{title}}',
							via: 'PivotTV'
						},
						{name: 'googleplus'},
						//{name: 'reddit'},
						{name: 'email'}
					]
				};

				$('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config);

				var main_image = $('.field-name-field-main-image img').attr('src');
				var more_services = {
					pinterest: {
						name: 'pinterest',
						media: main_image
					},
					tumblr_link: {name: 'tumblr_link'},
					gmail: {name: 'gmail'},
					hotmail: {name: 'hotmail'},
					yahoomail: {name: 'yahoomail'},
					aolmail: {name: 'aolmail'},

					//{name: 'myspace'},
					//{name: 'delicious'},
					linkedin: {name: 'linkedin'},
					//{name: 'myaol'},
					//{name: 'live'},
					digg: {name: 'digg'},
					stumbleupon: {name: 'stumbleupon'},
					//{name: 'hyves'}
				};

				if ( !main_image ) delete more_services.pinterest;

				$('.article-more-shares p').tpsocial({
					services: more_services
				});

				// Sticky social nav on article page
				$('.article-sidebar .social').tpsticky({
					offsetNode: '.article-content'
				});

				//takepart.analytics.skip_addthis = true;

				// Social more box
				var social_more_close = function() {
					$article_social_more.removeClass('focusin');
					$body.unbind('click', social_more_close);
				};

				var $article_social_more = $('#article-social-more')
					.bind('focusin', function() {
						$article_social_more.addClass('focusin');
					})
					.bind('focusout', function() {
						$article_social_more.removeClass('focusin');
					})
					.bind('click', function(e) {
						if ( !$article_social_more.is('.focusin') ) {
							$article_social_more.addClass('focusin');
							setTimeout(function() {
								$body.bind('click', social_more_close);
							}, 100);
						}
						e.preventDefault();
					})
					;
			}
		}
	};

	Drupal.behaviors.ieAddClass = {
		attach: function() {
			if ( $.browser.msie && +$.browser.version === 8 ) {
				$('body').addClass('ie8');
			}
		}
	}

})(jQuery, Drupal, this, this.document);


/**
 * Script for the "Find Pivot" iframe widget
 */
document.domain = "pivot.tv";

function kpiCFheightV2(ht) {
	//toggle the div visibility
	var frameFoo = document.getElementById('kpiFrameV2');
	var divFoo = document.getElementById('kpiDivV2');
	divFoo.style.height = ht;
	frameFoo.style.height = ht;
}
