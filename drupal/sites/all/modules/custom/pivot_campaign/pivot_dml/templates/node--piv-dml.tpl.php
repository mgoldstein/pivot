<div id="page">
  <?php
    $header = render($page['header']);
    if ($header):
  ?>
  <header id="header" role="banner">
    <?php print $header; ?>
  </header>
  <?php endif; ?>
  <main id="main">
    <div id="content" class="site-wrapper home">



    <!-- CONTENT GOES HERE -->


	<?php
	ini_set('display_errors', 1); error_reporting(E_ALL);
	$dmlPage = "Home";
	require_once('includes/header.php');


	# Load JSON
	$json_string = file_get_contents(DIRNAME(__FILE__) . '/public/data/home.json');
	# Parse data
	$homeData = json_decode($json_string);


	?>

	       <div class="row two-column main">
	       		<div class="left">
	       			<div class="row hero">
						<div class="hero-single">
							<a href="/<?php echo pivot_dml_get_path('templates');?>/<? echo $homeData->infographic->imgLarge; ?>" rel="lightbox"><img itemprop="image" src="/<?php echo pivot_dml_get_path('templates');?>/<? echo $homeData->infographic->img; ?>" width="540" height="733" alt="Hero Fpo"></a>
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
							<a href="https://www.facebook.com/sharer/sharer.php?u=<?php echo url('dml', array('absolute' => TRUE)).$homeData->infographic->share->facebook->data_link; ?>" class="share fb"
								data-link="<?php echo url('dml', array('absolute' => TRUE)).$homeData->infographic->share->facebook->data_link; ?>"
								data-image="<?php echo url('<front>', array('absolute' => TRUE)).pivot_dml_get_path('templates').$homeData->infographic->share->facebook->data_image; ?>"
								data-name="<?php echo $homeData->infographic->share->facebook->data_name; ?>"
								data-caption="<?php echo $homeData->infographic->share->facebook->data_caption; ?>"
								data-description="<?php echo $homeData->infographic->share->facebook->data_description; ?>"></a>
							<a href="https://twitter.com/intent/tweet?url=<?php echo url('dml', array('absolute' => TRUE)).$homeData->infographic->share->twitter->link; ?>" class="twitter"></a>
							<a href="https://plus.google.com/share?url=<?php echo url('dml', array('absolute' => TRUE)).$homeData->infographic->share->gplus->link; ?>" class="share gplus"></a>
							<a href="mailto:?subject=<?php echo $homeData->infographic->share->email->subject; ?>&amp;body=<?php echo $homeData->infographic->share->email->body; ?> <?php echo url('dml', array('absolute' => TRUE)).$homeData->infographic->share->email->link; ?>." target="_blank" class="email"></a>
						</div>
					</div>
					<div class="row bottom">
						<div class="cta-quiz">

							<a href="<?php echo url('dml', array('absolute' => TRUE)); ?>/quiz" class="btn">ultimate test</a>
						</div>
					</div>
	       		</div>
				<div class="right">
					<div class="row video">
						<div id="video-one">
							<script type="text/javascript" src="http://video.takepart.com/players/<?php echo $homeData->videos->video_one->video_code; ?>-n2uhTYdH.js"></script>
						</div>
					</div>
					<div class="row cta">
						<div class="left">
							<h3>Hot Headlines</h3>
							<span>NewsTrust: “A Story Can Cause You to Do Something Stupid”</span>
							<p>Are you indulging in the “sweets and calories” entertainment news of The Daily Show, and neglecting your PBS News Hour “broccoli”?</p>
							<a href="<?php echo url('dml', array('absolute' => TRUE)); ?>/news" class="btn">get the whole story</a>
						</div>
						<div class="right">
							<p class="first">transparency</p>
							<span>is the best</span>
							<p class="last">ad<br>policy</p>
							<a href="<?php echo url('dml', array('absolute' => TRUE)); ?>/ad" class="btn">get all the deets here</a>
						</div>
					</div>
					<div class="row video">
						<div id="video-two">
							<script type="text/javascript" src="http://video.takepart.com/players/<?php echo $homeData->videos->video_two->video_code; ?>-n2uhTYdH.js"></script>
						</div>
					</div>
					<div class="row bottom">
						<div class="twitter-feed">
							<div class="header">
								<h3>all a twitter</h3>
								<a href="https://twitter.com/intent/user?screen_name=<?php if (TWITTER_USER != null) echo TWITTER_USER; ?>" class="btn follow">follow us</a>
							</div>
							<div class="tweets">
							<ul class="start">
							<?php include_once('includes/create-twitter-feed.php'); ?>
							</ul>
							</div>
						</div>
					</div>
				</div>
	       </div>


	<?php require_once('includes/footer.php'); ?>


	<!-- END CONTENT -->
    </div>
  </main><!-- /#main -->
  <?php // footer will always render ?>
  <?php print render($page['footer']); ?>
</div><!-- /#page -->
