    <!-- CONTENT GOES HERE -->
	<?php
	# Load JSON
	$json_string = file_get_contents(drupal_get_path('module', 'pivot_dml'). '/data/home.json');

	# Parse data
	$homeData = json_decode($json_string);
	$path = variable_get('pivot_dml_path', '');
	global $base_url;
	?>

<div class="row two-column main">
		<div class="left">
			<div class="row hero">
	<div class="hero-single">

		<a href="/<?php echo drupal_get_path('module', 'pivot_dml');?>/images/infographic-full-9-3.png" rel="lightbox"><img itemprop="image" src="/<?php echo drupal_get_path('module', 'pivot_dml');?>/images/infographic-thumb.png" width="540" height="733" alt="Hero Fpo"></a>
	</div>
	<!-- <div class="hero-one">
						<h3>lorem ipsum</h3>
						<span>Lorem ipsum dolor sit amet, consectetuer adipiscing elit</span>
						<p>Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat.</p>
						<img src="public/images/fpo-1.jpg" width="277" height="159" >
						<a href="#" class="btn">learn more</a>
					</div>
					<div class="hero-two">
						<h3>lorem ipsum</h3>
						<span>Lorem ipsum dolor sit amet, consectetuer adipiscing elit</span>
						<div class="images">
							<img src="public/images/fpo-1.jpg" width="217" height="142">
							<img src="public/images/fpo-2.jpg" width="217" height="142">
						</div>
						<p>Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat.</p>

						<a href="#" class="btn">learn more</a>
					</div> -->
	<div class="share">
		<span>share this:</span>
		<a href="#" class="share fb"
			data-link="<?php echo url($path, array('absolute' => TRUE)).$homeData->infographic->share->facebook->data_link; ?>"
			data-image="<?php echo url('<front>', array('absolute' => TRUE)).drupal_get_path('module', 'pivot_dml').$homeData->infographic->share->facebook->data_image; ?>"
			data-name="<?php echo $homeData->infographic->share->facebook->data_name; ?>"
			data-caption="<?php echo $homeData->infographic->share->facebook->data_caption; ?>"
			data-description="<?php echo $homeData->infographic->share->facebook->data_description; ?>">&#xe00d;</a>
		<a href="#" data-url="https://twitter.com/intent/tweet?url=<?php echo url($path, array('absolute' => TRUE)).$homeData->infographic->share->twitter->link; ?>&text=<?php echo rawurlencode($homeData->infographic->share->twitter->share_copy); ?>" class="share twitter">&#xe00c;</a>
		<a href="#" data-url="https://plus.google.com/share?url=<?php echo url($path, array('absolute' => TRUE)).$homeData->infographic->share->gplus->link; ?>" class="share gplus">&#xe00e;</a>
		<a href="#" data-url="mailto:?subject=<?php echo rawurlencode($homeData->infographic->share->email->subject); ?>&amp;body=<?php echo rawurlencode($homeData->infographic->share->email->body); ?> <?php echo url($path, array('absolute' => TRUE)).$homeData->infographic->share->email->link; ?>."  class="share email" >&#xe00a;</a>
	</div>
</div>
<div class="row bottom">
	<div class="cta-quiz">

		<a href="<?php echo url($path, array('absolute' => TRUE)); ?>/quiz" class="btn">ultimate test</a>
	</div>
</div>
		</div>
<div class="right">
<div class="row video">
	<div id="video-one">
		<script type="text/javascript" src="http://video.takepart.com/players/<?php echo $homeData->videos->video_one->video_code; ?>-sbVGJbeW.js"></script>
	</div>
</div>
<div class="row cta">
	<div class="left">
		<?php print l('<img src="'. $base_url. '/'. drupal_get_path('module', 'pivot_dml'). '/images/you-are-media.jpg" alt="You are Media"', 'http://takeaction.takepart.com/actions?browse=pivot&cmpid=pivot-on-air&tags=eyes+wide+open&filtered=true&sort=recent', array('html' => TRUE, 'attributes' => array('target' => '_blank'))); ?>
	</div>
	<div class="right">
		<a href="http://takeaction.takepart.com/actions?browse=pivot&cmpid=pivot-on-air&tags=terms+and+conditions+may+apply&filtered=true&sort=recent" target="_blank"><img src="/<?php print drupal_get_path('module', 'pivot_dml'); ?>/images/tacma.jpg" style="float:right; height:100%;"></a>
	</div>
</div>
<!-- <div class="row video">
	<div id="video-two">
		<script type="text/javascript" src="http://video.takepart.com/players/<?php echo $homeData->videos->video_two->video_code; ?>-n2uhTYdH.js"></script>
	</div>
</div> -->
<div class="row bottom">
	<div class="twitter-feed">
		<div class="header">
			<h3>all a twitter</h3>
			<a href="https://twitter.com/intent/user?screen_name=<?php if (TWITTER_USER != null) echo TWITTER_USER; ?>" class="btn follow">follow us</a>
		</div>
		<div class="tweets">
		<ul class="start">
		<?php include_once(drupal_get_path('module', 'pivot_dml'). '/includes/create-twitter-feed.php'); ?>
		</ul>
		</div>
	</div>
</div>
</div>
</div>









