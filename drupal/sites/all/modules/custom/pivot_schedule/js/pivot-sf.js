/**
 * @file
 * Determine and set user's timezone on page load.
 */
jQuery(document).ready(function () {

    jQuery('ul.sfw-menu').superfish({
      delay:       500,                            // one second delay on mouseout
      animation:   {opacity:'show',height:'show'},  // fade-in and slide-down animation
      speed:       'slow',                          // faster animation speed
      autoArrows:  false,                            // disable generation of arrow mark-up
      depth:        '-1',
      respect_expanded:  false
    });

    jQuery('.tz-menu ul li ul li').click(function() {
      var timezone = jQuery(this).attr("tz");
      jQuery.ajax({
        type: 'POST',
        url: '/pivot-ajax/timezone-set',
        dataType: 'json',
        data: 'timezone=' + timezone,
        complete: function(){
           location.reload();
        }
      });
    });

});
