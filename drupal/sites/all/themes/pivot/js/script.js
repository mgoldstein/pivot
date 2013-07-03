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
	document.domain = "pivot.tv";

	window.kpiCFheight = function (height) {
			var frameFoo = document.getElementById('kpiFrame');
			var divFoo = document.getElementById('kpiDiv');
			divFoo.style.height = ht;
			frameFoo.style.height = ht;
	};

})(jQuery, Drupal, this, this.document);
