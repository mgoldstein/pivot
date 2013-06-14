(function (window, $, undefined) {

// Drupal tab stuff
$('.tabs-toolbar').remove().find('li').appendTo('.toolbar-shortcuts ul');

// Delegates
$body
	// Skip link tabbing fix for Webkit
	.delegate('.skip-link a', 'click', function() {
		$($(this).attr('href')).attr('tabIndex', '-1').focus();
	})
	;



})(window, jQuery);