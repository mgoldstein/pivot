(function (window, $, undefined) {

var $body = $('body');

// Drupal tab stuff
$('.tabs-toolbar').remove().find('li').appendTo('.toolbar-shortcuts ul');

// Delegates
$body
	// Skip link tabbing fix for Webkit
	.delegate('.skip-link a', 'click', function() {
		$($(this).attr('href')).attr('tabIndex', '-1').focus();
	})
	;

$(function() {

	// Pretty selects
	$('.find-pivot select').tpselect();

	// Homepage
	if ($('body').hasClass('front')) {

		// Slideshow
		var vp_width = $(window).width();
		var vp_height = $(window).height();
		var $slide_wrapper = $('.slide-wrapper');
		var $slides = $slide_wrapper.find('.slide');
		var $images = $('.slide-wrapper .video-image');
		var $topslide = $('#topslide');
		var $current = $slides.first();
		var $video;
		var $image;

		$images.each(function() {
			var $this = $(this);
			if ( this.complete || this.readyState === 4 ) {
				$this.addClass('loaded');
			} else {
				$this
					.bind('load', function() {
						$this.addClass('loaded');
					});
			}
		});

		$slides.each(function() {
			var $player = $('.video-player', this);
			var video_width = $player.width();
			var video_height = $player.height();
			var video_ar = video_width / video_height;

			$player.data({
				video_width: video_width,
				video_height: video_height,
				video_ar: video_ar
			})
		});

		var updateslidernav = function($curr) {
			$curr = $curr || $current;
			$topslide.addClass($curr.data('token'));
			$topslide.find('li').removeClass('active');
			var $newnav = $topslide.find('.slide-nav .' + $curr.data('token')).addClass('active');
			$('.active-selector').css({left: $newnav.offset().left});
		}

		var onafter = function($curr) {
			$slides.not($curr).removeClass('active');
			$curr.addClass('active');

			if ( $current ) $topslide.removeClass($current.data('token'));
			if ( $video ) {
				$video[0].pause();
				$video[0].currentTime = 0;
			}
			$current = $curr;
			$video = $current.find('.video-player');
			$image = $current.find('.video-image');

			$video
				.animate({opacity: 1}, 'fast', function() {
					$video[0].play();
				});

		};

		var onslide = function($curr) {
			if ( !$curr || $curr === $current ) return;
			updateslidernav($curr);
			$video = $current.find('.video-player');
			$video[0].pause();
		}

		var adjust = function() {
			vp_width = $(window).width();
			vp_height = $(window).height();
			var viewportAspectRatio = vp_width / vp_height;
			$slide_wrapper.css({width: vp_width});
			$slide_wrapper.css({height: vp_height});
			$slides.css({width: vp_width});
			$slides.css({height: vp_height});
			updateslidernav();

			$slides.each(function() {
				var $player = $('.video-player, .video-image', this);
				var video_width = $player.data('video_width');
				var video_height = $player.data('video_height');
				var videoAspectRatio = video_width / video_height;

				//$slide_wrapper.css({height: vp_height});
				if ( viewportAspectRatio < videoAspectRatio ) {
					var width = vp_height / video_height * video_width;

					$player.css({
						height: vp_height + 'px',
						width: 'auto',
						left: -1 * ((width - vp_width) / 2) + 'px'
					});
				} else {
					$player.css({
						height: (vp_width/video_width * video_height) + 'px',
						width: vp_width + 'px',
						left: 0
					});
				}
			});
		};

		$('.slide-nav a').bind('click', function(e) {
			e.preventDefault();

			$slide_wrapper.tpslide_to(this.href.replace(/^[^#]*/, ''));
		});

		adjust();

		$slide_wrapper.tpslide({onslide: onslide, onafter: onafter});

		$(window).resize(function(){ adjust(); });
	}
});


})(window, jQuery);