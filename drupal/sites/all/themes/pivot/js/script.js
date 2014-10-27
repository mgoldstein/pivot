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

	Drupal.settings.touchEnabled = ( 'ontouchend' in document.documentElement ) ? true : false;

	// define global settings for tpsocial
	var tp_social_config = {
		services: {
			facebook: {
				name: 'facebook',
				url: '{current}'
			},
			twitter: {
				name: 'twitter',
				text: '{{title}}',
				via: 'pivot_tv',
				url: '{current}'
			},
			googleplus: {
				name: 'googleplus',
				url: '{current}'
			},
			// pinterest: {
			// 	name: 'pinterest',
			// 	url: '{current}',
			// 	media: first_image,
			// 	description: first_description
			// },
			// tumblr: {
			// 	name: 'tumblr',
			// 	url: '{current}',
			// 	source: first_image,
			// 	caption: first_description
			// },
			email: {
				name: 'email',
				url: '{current}'
			}
		}
	};

	var more_services = {
		pinterest: {
			name: 'pinterest',
			// media: main_image // define this per share type
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

	Drupal.behaviors.globalNavigationResponsive = {
		attach: function() {
			// Responsive nav
			var primaryNav = '#site-header .primary',
				$primaryNav = $(primaryNav),
				secondaryNav = '#site-header .secondary',
				$secondaryNav = $(secondaryNav),
				$body = $('body.not-front');

			var click = 'click';
			var is_touchmove = false;
			if ( 'ontouchend' in document.documentElement ) click = 'touchend';

			$body
			     .delegate(primaryNav, 'touchmove', function () {
				   is_touchmove = true;
			     })
			     .delegate(primaryNav, click, function () {
				   if ( click == 'touchend' && is_touchmove ) {
					is_touchmove = false;
					return true;
				   }

				   if ( $primaryNav.is('.clickedon') ) {
					$primaryNav.removeClass('clickedon');
				   } else {
					$primaryNav.addClass('clickedon');
				   }
			     })
			     .delegate(primaryNav + ' a', click, function (e) {
				   e.stopPropagation();
			     })
			     .delegate(primaryNav, 'focusin', function (e) {
				   $body.addClass('clickedon');
			     })
			     .delegate(primaryNav, 'focusout', function (e) {
				   $body.removeClass('clickedon');
			     })
			     .delegate(primaryNav, 'touchmove', function () {
				   is_touchmove = true;
			     })
			     .delegate(secondaryNav, click, function () {
				   if ( click == 'touchend' && is_touchmove ) {
					is_touchmove = false;
					return true;
				   }

				   if ( $secondaryNav.is('.clickedon') ) {
					$secondaryNav.removeClass('clickedon');
				   } else {
					$secondaryNav.addClass('clickedon');
				   }
			     })
			     .delegate(secondaryNav + ' a, ' + secondaryNav + ' input', click, function (e) {
				   e.stopPropagation();
			     })
			     .delegate(secondaryNav, 'focusin', function (e) {
				   $body.addClass('clickedon');
			     })
			     .delegate(secondaryNav, 'focusout', function (e) {
				   $body.removeClass('clickedon');
			     })
			;
		}
	};

	Drupal.behaviors.superfishTouch = {
		attach: function() {

			if (Drupal.settings.touchEnabled) {
				$('ul.nice-menu')
					.find('li.menuparent > a')
						.on('touchend', function(e) {
							var $this = $(this);
							e.preventDefault();
							$this.toggleClass('clickedon');
							if ($this.hasClass('clickedon')) {
								$this.focus();
							} else {
								$this.blur();
							}
						})
				;
			}
		}
	};

	Drupal.behaviors.initializeFacebookComments = {
		attach: function() {
			var $article_comments = $('#article-comments');

			// bail early
			if (!$article_comments.length) return;

			var $comments = $article_comments.find('.fb_comments'),
				width = $comments.data('width'),
				loadFacebookTimeout = false,
				initFB = function() {
						clearTimeout('loadFacebookTimeout');
					if (!!window.FB) {
						FB.XFBML.parse();
					} else {
						setTimeout(initFB, 250);
					}
				};

			$article_comments
				.find('.comment-count')
				.empty()
				.html('<fb:comments-count href="' + window.location.href + '"></fb:comments-count>')
			;

			$comments
				.empty()
				.html('<fb:comments href="' + window.location.href + '" width="' + width + '"></fb:comments>')
			;

			loadFacebookTimeout = window.setTimeout(initFB, 500);
		}
	};

	Drupal.behaviors.populateSocialShareButtons = {
		attach: function() {

			var $body = $('body');

			if (
				$body.is('.node-type-article') ||
				$body.is('.page-shows') ||
				$body.is('.node-type-gallery') ||
				$body.is('.node-type-video')
			) {
				// Social share buttons

				$('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config);

				// setup main image

				if ($body.is('.node-type-article')) {
					var main_image = $('.field-name-field-main-image img').attr('src');
				} else if ($body.is('.page-shows')) {
					var main_image = $('.show-hero .image img').attr('src');
				} else if ($body.is('.node-type-gallery')) {
					var main_image = false; // TODO add a gallery image
				}

				if ( !main_image ) {
					delete more_services.pinterest;
				} else {
					more_services.pinterest.media = main_image;
				}

				$('.article-more-shares p').tpsocial({
					services: more_services
				});

				// Sticky social nav on article page
				$('.article-sidebar .social').tpsticky({
					offsetNode: '.article-content'
				});

				// Sticky social nav on other page page
				$('.show-sidebar .social').tpsticky({
					offsetNode: '.view-content-content'
				});

				// TODO: Restore analytics when someone explains them to me
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

	Drupal.behaviors.gallerySetup = {
		attach: function() {
			var $body = $('body'),
				$window = $(window);

			if ($body.is('.page-node.node-type-gallery')) {

				// For html5 history, change this to the number the sub-dir index of your root photo gallery url
				// Example http://participant-static.local/pivot/pages/show_photos.php = 3
				var gallery_root_index = window.location.pathname.substr(1).split('/').length;

				// Now we have the number of components in our path. But if
				// Drupal.settings.gallery.slideToken is set, the final component
				// should NOT count towrad gallery_root_index
				if (Drupal.settings.gallery && Drupal.settings.gallery.slideToken) {
					gallery_root_index = gallery_root_index - 1;
				}

				// Tracking for "Next gallery" clicks
				// $body
				// 	.delegate('#next-gallery a, .forward-to-gallery a', 'click', function() {
				// 		takepart.analytics.track('gallery-next-gallery-click', {
				// 			headline: next_gallery_headline,
				// 			topic: next_gallery_topic,
				// 			a: this
				// 		});
				// 	});

				var $gallery_main = $('#gallery-main');
				var $slides = $('#gallery-content > ul');
				var base_url = document.location.href.split(/\/|#/).slice(0,gallery_root_index + 3).join('/');
				var $fb_comment = $('.fb_comments');
				var $fb_comment_count = $('.comment-count');

				var $first_slide = $slides.find('> li:first-child');
				var first_image = $first_slide.find('img').attr('src');
				var gallery_description = $gallery_main.find('.field-name-field-description').text().trim();
				var first_description = $first_slide.find('.photo-caption').text().replace(/^\s+|\s+$/g, '').replace(/[\ |\t]+/g, ' ').replace(/[\n]+/g, "\n");
				var skip_next_pageview = false;

				var update_to = null;
				var update_page = function(token) {
					clearTimeout(update_to);

					// TODO: Restore gallery analytics when I understand the requirements
					// if ( !skip_next_pageview ) {
					// 	setTimeout((function(token, skip_next_pageview) {
					// 		return function() {
					// 			takepart.analytics.track('gallery-track-slide', {
					// 				token: token,
					// 				skip_pageview: skip_next_pageview,
					// 				next_gallery_headline: next_gallery_headline,
					// 				next_gallery_topic: next_gallery_topic
					// 			});
					// 		}
					// 	})(token, skip_next_pageview), 500);
					// } else {
					// 	skip_next_pageview = false;
					// }

					update_to = setTimeout(function() {
						var token = get_curtoken();

						refreshGalleryBehaviors(token);

						if ( window.googletag != undefined ) {
							window.googletag.pubads().refresh();
						}
					}, 500);
				};

				// TODO: Restore gallery analytics when I understand the requirements
				// prevent 2 email calls from firing
				// takepart.analytics.skip_addthis = true;

				/**
				 * Refersh social shares and Facebook Comments
				 * on gallery initialize and slide nav
				 * @param  {string} token the hash
				 */
				var refreshGalleryBehaviors = function(token) {
					if (!token) return; // bail early
					var $slide = $slides.find('[data-token=' + token + ']');
					var slideURL = base_url + '/' + token;
					var slideTitle = $slide.find('.field-name-field-image-title').text().trim();
					var slideDescription = $slide.find('.field-name-field-image-description').text().trim();
					var slideImageSRC = $slide.find('img').attr('src');

					// clean up the some of these values
					// get rid of http queries on the slideImageSRC string
					slideImageSRC = slideImageSRC.replace(/\?.*$/, '');
					// use the gallery description if the slide doesn't have one
					if (slideDescription == '') slideDescription = gallery_description;

					// redo the facebook stuff
					$fb_comment
						.empty()
						.html('<fb:comments href="' + slideURL + '" width="600"></fb:comments>')
					;
					$fb_comment_count
						.empty()
						.html('<fb:comments-count href="' + slideURL + '"></fb:comments-count>')
					;
					FB.XFBML.parse();

					// reset social services
					tp_social_config.services.facebook.url = slideURL;
					tp_social_config.services.facebook.image = slideImageSRC;
					tp_social_config.services.facebook.title = slideTitle;
					tp_social_config.services.facebook.description = slideDescription;

					tp_social_config.services.twitter.text = slideTitle;

					more_services.pinterest = {
						name: 'pinterest',
						media: slideImageSRC
					};

					$('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config);
					$('.article-more-shares p').tpsocial({
						services: more_services
					});
				}

				// Get current "token" from last folder of URL
				var get_curtoken = function() {
					return document.location.href.split(/\/|#/).slice(gallery_root_index + 3,gallery_root_index + 4) + '';
				};

				// Update slideshow based on url
				var goto_slide = function(token) {
					token = token || get_curtoken();
					var $slide = $slides.find('[data-token="' + token + '"]');
					$slides.tpslide_to($slide);
				};

				// Return history functionality in browser
				var has_history = function() {
					return (typeof history != 'undefined');
				};

				// Update html5 history if token is new
				var hpush = function(token, title, replace) {
					var curtoken = get_curtoken();
					var replace = replace || false;
					if ( curtoken == token ) return;
					update_page(token);

					if ( !has_history() ) return;
					if ( replace ) {
						history.replaceState(null, title, base_url + '/' + token);
					} else {
						history.pushState(null, title, base_url + '/' + token);
					}
				};

				// Callback for slideshow sliding a slide
				var $current_slide = null;
				var slide_callback = function($current) {
					var old_token = ( $current_slide ) ? $current_slide.data('token') : null;
					$current_slide = $current;

					if ( !$current_slide.prev().length ) {
						$gallery_main.addClass('on-first');
					} else {
						$gallery_main.removeClass('on-first');
					}

					if ( !$current_slide.next().length ) {
						$gallery_main.addClass('on-last');
					} else {
						$gallery_main.removeClass('on-last');
					}

					var current_image = $current_slide.find('img').attr('src');
					// more_services.pinterest.media = current_image;
					// tp_social_config.services.tumblr.source = current_image;

					var current_description = $current_slide.find('.photo-caption').text().replace(/^\s+|\s+$/g, '').replace(/[\ |\t]+/g, ' ').replace(/[\n]+/g, "\n");
					// more_services.pinterest.description = current_description;
					// tp_social_config.services.tumblr.caption = current_description;

					var token = $current.data('token');
					if ( token == 'next-gallery' ) {
						$('#gallery-header-main .social').css({visibility: 'hidden', display: 'none'});
					} else {
						$('#gallery-header-main .social').css({visibility: 'visible', display: 'block'});
					}

					$slides.height($current_slide.height());

					if ( !gallery_showing ) return;
					hpush(token, $current.find('.headline').text());
				}

				var gallery_showing = false;
				var show_gallery = function(replace) {
					if ( gallery_showing ) return;
					gallery_showing = true;
					$gallery_main.removeClass('hide_gallery').addClass('show_gallery');
					hpush($current_slide.data('token'), $current_slide.find('.headline').text(), replace);
				};

				var hide_gallery = function() {
					$gallery_cover.show();
					$gallery_main.removeClass('show_gallery').addClass('hide_gallery');

					var current_image = $gallery_cover.find('img').attr('src');
					tp_social_config.services.pinterest.media = current_image;
					// tp_social_config.services.tumblr.source = current_image;

					var current_description = $gallery_cover.find('.headline').text();
					tp_social_config.services.pinterest.description = current_description;
					// tp_social_config.services.tumblr.caption = current_description;

					gallery_showing = false;
				};

				// Make slideshow
				$slides.tpslide({
					onslide: slide_callback,
					threshold: 75,
					swipeTarget: 'img'
				});

				// Make img clicks forward gallery
				$slides
					.delegate('.gallery-slide img, .image-content-wrapper', 'mouseover', function() {
						$gallery_main.addClass('image-hover');
					})
					.delegate('.gallery-slide img, .image-content-wrapper', 'mouseout', function() {
						$gallery_main.removeClass('image-hover');
					})
					.delegate('.gallery-slide img', 'click', function() {
						$slides.tpslide_next(false);
					})
					;

				// Fix heights for responsive
				$window.bind('resize', function () {
					$slides.height($current_slide.height());
				});

				// Event for fake back button to go to cover page
				$('.back-to-cover a').bind('click', function(e) {
					e.preventDefault();
					if ( !gallery_showing ) return;
					hide_gallery();
					hpush('', $('#gallery-cover-main').find('.headline').text());
				});

				// Initialize page based on URL
				var firstToken;
				if (Drupal.settings.gallery && Drupal.settings.gallery.slideToken) {
					firstToken = Drupal.settings.gallery.slideToken;
					delete Drupal.settings.gallery;
				} else {
					firstToken = get_curtoken();
				}
				if ( firstToken && firstToken != 'first-slide' ) {
					goto_slide(firstToken);
					show_gallery();
				} else if ( get_curtoken() == 'first-slide' ) {
					skip_next_pageview = true;
					show_gallery(true);
				} else {
					skip_next_pageview = true;
					show_gallery(true);
				}

				var first_pop = true;
				// Listen for html5 history updates/back button
				window.addEventListener('popstate', function(e) {
					if ( first_pop ) {
						first_pop = false;
						return;
					}

					var token = get_curtoken();

					if ( token ) {
						goto_slide();
						show_gallery();
					}

					update_page(token);
				});
			}
		}
	};

	Drupal.behaviors.ieAddClass = {
		attach: function() {
			if ( $.browser.msie && +$.browser.version === 8 ) {
				$('body').addClass('ie8');
			}
		}
	};

        Drupal.behaviors.geoLimiting = {
          attach: function() {
            $('.geo-limited-video').once('initialized', function(index, element) {
              var player = element;
              var showBlocked = function() {
              	$('.video-loading', player).hide();
              	$('.video-blocked', player).show();
              };
              var handleRegion = function(response) {
                if (!response.country || !response.country.iso_code) { showBlocked(); return false; }
                var code = response.country.iso_code.toLowerCase();
                var regions = $(player).attr('data-allowed-regions').split(',');
                if ($.inArray(code, regions) < 0) { showBlocked(); return false; }
                var url = "http://video.takepart.com/players/"
                  + $(player).attr('data-botr-id') + ".js";
                $.getScript(url).fail(showBlocked);
              };
              geoip2.country(handleRegion, showBlocked);
            });
          }
        };

  Drupal.behaviors.homepageSlider = {
    attach: function() {

      $(document).ready(function(){
        $('.bxslider').bxSlider({
          nextSelector: '.next-slide',
          prevSelector: '.prev-slide',
          nextText: '',
          prevText: '',
          mode: 'fade',
          infiniteLoop: false,
          hideControlOnEnd: true,
          onSlideAfter: function(){
            jwplayer().stop();
          }
        });
      });

    }
  };

  Drupal.behaviors.pivotNavigation = {
    attach: function(){
      var snapper = new Snap({
        element: document.getElementById('page'),
        disable: 'right',
        touchToDrag: false
      });

//      $('body').click(function(){
//        snapper.open('left');
//      });
    }
  };

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
