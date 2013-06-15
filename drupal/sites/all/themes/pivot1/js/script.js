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
	var $player_wrapper = $('#video');
	var $player = $player_wrapper.find('video, img');
	/*var $video = $player_wrapper.find('video');
	var $img = $player_wrapper.find('img');

	$img.bind('load', function() {
		$img.fadeIn();
	});

	$video.bind('canplaythrough', function() {
		$video.fadeIn();
		$video[0].play();
	});*/

	// Set this variable when the page first loads
	var videoAspectRatio;
	var video_width = $player.width();
	var video_height = $player.height();
	var videoAspectRatio = video_width / video_height;

	function adjust() {
		var viewportWidth = $(window).width();
		var viewportHeight = $(window).height();
		var viewportAspectRatio = viewportWidth / viewportHeight;

		$player_wrapper.css({height: viewportHeight});

		if ( viewportAspectRatio < videoAspectRatio ) {
			var width = viewportHeight / video_height * video_width;
			$player.css({
				height: viewportHeight + 'px',
				width: 'auto',
				left: -1 * ((width - viewportWidth) / 2) + 'px'
			});
		} else {
			$player.css({
				height: (viewportWidth/video_width * video_height) + 'px',
				width: viewportWidth + 'px',
				left: 0
			});
		}
	}

	// Get the aspect ratio of the video
	adjust();



	// Homepage
	if ( $body.is('.front') ) {
		var vp_width = $(window).width();
		var vp_height = $(window).height();
		var $slide_wrapper = $('.slide-wrapper');
		var $slides = $slide_wrapper.find('.slide');
		var $images = $('.slide-wrapper .video-image');
		var $current;
		var $video;
		var $image;

		$images.bind('load', function() {
			$(this).fadeIn();
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

		var onafter = function($curr) {
			if ( $video ) {
				$video[0].pause(); 
				$video[0].currentTime = 0;
			}
			$current = $curr;
			$video = $current.find('.video-player');
			$image = $current.find('.video-image');
			$image.show();
			$video.fadeIn('fast', function() {
				$video[0].play();
			});
			//video = $current.find('.video-player')[0];
		};

		var adjust = function() {
			vp_width = $(window).width();
			vp_height = $(window).height();
			var viewportAspectRatio = vp_width / vp_height;

			$slide_wrapper.width(vp_width);
			$slide_wrapper.height(vp_height);
			$slides.width(vp_width);
			$slides.height(vp_height);

			$slides.each(function() {
				var $player = $('.video-player, .video-image', this);
				var video_width = $player.data('video_width');
				var video_height = $player.data('video_height');
				var videoAspectRatio = video_width / video_height;

				$player_wrapper.css({height: vp_height});

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

		adjust();

		$slide_wrapper.tpslide({onafter: onafter});

		$(window).resize(function(){ adjust(); });
	}
});


})(window, jQuery);