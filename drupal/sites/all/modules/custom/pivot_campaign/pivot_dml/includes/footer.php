<script type="text/javascript" src="//platform.twitter.com/widgets.js"></script>

<script type="text/javascript">
	(function ($, Drupal, window, document, undefined) {
    Drupal.behaviors.facebookSDK = {
      attach: function () {
        window.fbAsyncInit = function() {
          FB.init({
            appId     : '545435132181638',
            status    : true,
            cookie    : true,
            version   : 'v2.6',
            xfbml     : true
      	  	});
      	};
      	// Load the SDK asynchronously
      	(function() {
      	  var e = document.createElement('script');
      	  e.async = true;
      	  e.src = document.location.protocol + '//connect.facebook.net/en_US/all.js';
      	  document.getElementById('fb-root').appendChild(e);
      	}());
      }
    };
  })(jQuery, Drupal, this, this.document);
</script>

