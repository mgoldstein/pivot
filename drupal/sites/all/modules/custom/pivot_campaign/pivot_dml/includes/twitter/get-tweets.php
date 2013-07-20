<?php
//session_start();
require_once(DIRNAME(__FILE__) . "/twitteroauth.php"); //Path to twitteroauth library
require_once(DIRNAME(__FILE__) . "/constants.php");
require_once(DIRNAME(__FILE__) . "/functions.php");

if (cache_test_time() == true) {
	// read cache
	//global $feedResults;
	//$feedResults = json_decode(file_get_contents(CACHE_PATH . TWITTER_USER . "-tweets.apicache"));
    // do nothing
} else {
	create_cache();
}





?>
