<?php

global $feedResults;
$feedResults = json_decode(file_get_contents(CACHE_PATH . TWITTER_USER . "-tweets.apicache"));

if (isset($feedResults)) {
	
	foreach ($feedResults as $post) {

	    # Gather Info
	    $user_full_name   = $post->user->name;
	    $user_screen_name = $post->user->screen_name;
		$user_profile_url = "http://twitter.com/".$user_screen_name;
	    $user_image_path  = $post->user->profile_image_url;
	    $body             = $post->text;
	    $datestamp        = $post->created_at;
	    $link             = "http://www.twitter.com/".$user_screen_name."/status/".$post->id_str;
		$intentReply 	  = "https://twitter.com/intent/tweet?in_reply_to=".$post->id_str;
		$intentRetweet 	  = "https://twitter.com/intent/retweet?tweet_id=".$post->id_str;
		$intentFavorite   = "https://twitter.com/intent/favorite?tweet_id=".$post->id_str;

	    # Change User image if this is a retweet
	    if (isset($post->retweeted_status)) {
		  $user_full_name   = $post->retweeted_status->user->name;
		  $user_screen_name = $post->retweeted_status->user->screen_name;
		  $user_profile_url = "http://twitter.com/".$post->retweeted_status->user->screen_name;
		  $user_image_path  = $post->retweeted_status->user->profile_image_url;
	    }         

	    # Process $body
	    $body = make_links_clickable($body);
	    $body = make_twitter_links_clickable($body);

	?>


	<li>
		<a href="<?php echo $user_profile_url; ?>"><img class="avatar" src="<?php echo $user_image_path; ?>" width="42" height="42"></a>
		<div class="content">
			<div class="user">
				<span class="name"><?php echo $user_full_name; ?></span>
				<a href="<?php echo $user_profile_url; ?>">@<?php echo $user_screen_name; ?></a>
			</div>
			<div class="intents">
				<a href="<?php echo $intentReply; ?>" class="reply">reply</a>
				<a href="<?php echo $intentRetweet; ?>" class="retweet">retweet</a>
				<a href="<?php echo $intentFavorite; ?>" class="favorite">favorite</a>
			</div>
			<p><?php echo $body; ?></p>
			<?php if (isset($post->retweeted_status)) { ?>
				<span class="retweet-status">Retweeted by <a href="<?php echo $link; ?>"><?php echo $post->user->name; ?></a></span>
			<?php } ?>
		</div>
	</li>



	<?php

	}
	
	
	
}

?>
















