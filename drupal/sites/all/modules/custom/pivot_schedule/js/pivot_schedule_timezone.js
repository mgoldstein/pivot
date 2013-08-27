/**
 * @file
 * Determine and set user's timezone on page load.
 */
jQuery(document).ready(function () {

  // Determine timezone from browser client using jsTimezoneDetect library.
  var tz = jstz.determine();
  // Post timezone to callback url via ajax.
  jQuery.ajax({
    type: 'POST',
    url: '/pivot-ajax/timezone',
    dataType: 'json',
    data: 'timezone=' + tz.name()
  });

    // $('ul.sf-menu').superfish({
    //   delay:       1000,                            // one second delay on mouseout
    //   animation:   {opacity:'show',height:'show'},  // fade-in and slide-down animation
    //   speed:       'fast',                          // faster animation speed
    //   autoArrows:  false,                            // disable generation of arrow mark-up
    //   depth:        '-1',
    //   respect_expanded:  false
    // });


});
