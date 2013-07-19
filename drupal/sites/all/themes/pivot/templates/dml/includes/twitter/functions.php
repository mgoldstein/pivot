<?php

function getConnectionWithAccessToken($cons_key, $cons_secret, $oauth_token, $oauth_token_secret) {
  $connection = new TwitterOAuth($cons_key, $cons_secret, $oauth_token, $oauth_token_secret);
  return $connection;
}

function makeAPICall() {
	$connection = getConnectionWithAccessToken(CONSUMERKEY, CONSUMERSECRET, ACCESSTOKEN, ACCESSTOKENSECRET);
	$tweets = $connection->get("https://api.twitter.com/1.1/statuses/user_timeline.json?screen_name=".TWITTER_USER."&count=".NUM_TWEETS."&exclude_replies=true");
	return $tweets;
}


# test the if the cache file has expired
function cache_test_time() {
	# Make Sure Cache Location is set
	if (CACHE_PATH == null) throw new Exception('You must set an cache path before initializing.');

	# File Name      
	$file_name = CACHE_PATH . TWITTER_USER . "-tweets.apicache";

	# Test For File
	if (file_exists($file_name) == false) return false;

	# Current Time
	$current_time = time();

	# File Mod Time
	$file_mod_time = filectime($file_name);

	# Age of file
	$file_age = ($current_time - $file_mod_time);

	# Remove File
	if ($file_age > CACHE_DURATION) {        
	 # Test Failed
	 return false;        
	}

	# Test Passed      
	return true;
}


# create feed cache
function create_cache() {
	
	$tweets = makeAPICall();
	
	//Check twitter response for errors.
	if ( isset( $tweets->errors[0]->code )) {
	    // If errors exist, print the first error for a simple notification.
	    echo "Error encountered: ".$tweets->errors[0]->message." Response code:" .$tweets->errors[0]->code;
	} else {
	    // No errors exist. Write tweets to json/txt file.
	    $file = CACHE_PATH . TWITTER_USER . "-tweets.apicache";
	    $fh = fopen($file, 'w') or die("can't open file");
	    fwrite($fh, json_encode($tweets));
	    fclose($fh);

	    if (file_exists($file)) {
	       global $feedResults;
		   $feedResults = json_decode(file_get_contents(CACHE_PATH . TWITTER_USER . "-tweets.apicache"));
	    } else {
	       // echo "Error encountered. File could not be written.";
	    }
	}
	
	
}


# Make Twitter Links Clickable 
function make_twitter_links_clickable($text) {
  # Process Text
  $text = preg_replace("/@(\w+)/", "<a href=\"http://www.twitter.com/\\1\" target=\"_blank\">@\\1</a>",             $text);
  $text = preg_replace("/#(\w+)/", "<a href=\"http://twitter.com/search?q=%23\\1\" target=\"_blank\">#\\1</a>", $text);
  
  # Return Text
  return $text;
}


# Make Links Clickable 
function make_links_clickable($text) {
  # Process Text
  $text = preg_replace("#(^|[\n ])([\w]+?://[\w]+[^ \"\n\r\t< ]*)#", "\\1<a href=\"\\2\" target=\"_blank\">\\2</a>",        $text);
  $text = preg_replace("#(^|[\n ])((www|ftp)\.[^ \"\t\n\r< ]*)#",    "\\1<a href=\"http://\\2\" target=\"_blank\">\\2</a>", $text);
  
  # Return Text
  return $text;
}









?>