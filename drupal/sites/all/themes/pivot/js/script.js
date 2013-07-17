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

})(jQuery, Drupal, this, this.document);

document.domain = "pivot.tv";

function kpiCFheightV2(ht) {
	//toggle the div visibility
	var frameFoo = document.getElementById('kpiFrameV2');
	var divFoo = document.getElementById('kpiDivV2');
	divFoo.style.height = ht;
	frameFoo.style.height = ht;
}

(function($) {
  $(document).ready(function() {
		var isIE8 = $.browser.msie && +$.browser.version === 8;
		if ( isIE8 ) {
  		$('body').addClass('ie8');
		}
		else{
		}
 });
})(jQuery);