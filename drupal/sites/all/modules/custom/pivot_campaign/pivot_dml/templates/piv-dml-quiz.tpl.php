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
    <div id="content" class="site-wrapper">



    <!-- CONTENT GOES HERE -->

	<?php
	$dmlPage = "Quiz";
	require_once(DIRNAME(__FILE__) . '/includes/header.php');
	# Load JSON
	$json_string = file_get_contents(DIRNAME(__FILE__) . '/public/data/quiz-data.json');
	# Parse data
	$quizData = json_decode($json_string);
	?>

	       <div class="row main">

				<div id="quiz-container" data-file="/<?php echo pivot_dml_get_path('templates'); ?>/public/data/quiz-data.json">
			       <div class="content-wrapper">
					<div class="content">
					<h1 class="quizName"><!-- where the quiz name goes --></h1>

			        <div class="quizArea">
			            <div class="quizHeader">
			                <!-- where the quiz main copy goes -->

			                <a class="startQuiz" href="#">take the quiz</a>
			            </div>

			            <!-- where the quiz gets built -->
			        </div>

			        <div class="quizResults">
			            <h3 class="quizScore">SCORE: <span><!-- where the quiz score goes --></span></h3>

			            <h3 class="quizLevel"><!-- where the quiz ranking level goes --></h3>

			            <div class="quizResultsCopy">
			                <!-- where the quiz result copy goes -->
							<h4>get there with these resources:</h4>
							<ul>

							</ul>
							<div class="share"><a href="#">share<br>quiz</a></div>
						</div>
			       </div><!-- /.quizResults -->
					<div class="social-share">
						<h2>are your friends media &amp; privacy savvy?</h2>
						<span>share this quiz and find out!</span>
						<ul>
							<li>
									<a href="https://www.facebook.com/sharer/sharer.php?u=<?php echo url('dml', array('absolute' => TRUE)).$quizData->share->facebook->data_link; ?>" class="share fb"
										data-link="<?php echo url('dml', array('absolute' => TRUE)).$quizData->share->facebook->data_link; ?>"
										data-image="<?php echo url('<front>', array('absolute' => TRUE)).pivot_dml_get_path('templates').$quizData->share->facebook->data_image; ?>"
										data-name="<?php echo $quizData->share->facebook->data_name; ?>"
										data-caption="<?php echo $quizData->share->facebook->data_caption; ?>"
										data-description="<?php echo $quizData->share->facebook->data_description; ?>"></a>
							</li>
							<li>
								<a href="https://twitter.com/intent/tweet?url=<?php echo url('dml', array('absolute' => TRUE)).$quizData->share->twitter->link; ?>" class="twitter"></a>
							</li>
							<li>
								<a href="https://plus.google.com/share?url=<?php echo url('dml', array('absolute' => TRUE)).$quizData->share->gplus->link; ?>" class="share gplus"></a>
							</li>
						 	<li>
								<a href="mailto:?subject=<?php echo urlencode($quizData->share->email->subject); ?>&amp;body=<?php echo urlencode($quizData->share->email->body); ?> <?php echo url('dml', array('absolute' => TRUE)).$quizData->share->email->link; ?>." target="_blank" class="email"></a>
							</li>
						</ul>
						<div class="back"><a href="#">back to<br>results</a></div>
					</div>
				</div><!-- /.content -->
				</div><!-- /.content-wrapper -->
				<div class="icons">
					<div class="email">&#xe00a;<span class="correct">&#xe008;</span><span class="incorrect">&#xe006;</span></div>
					<div class="news">&#xe007;<span class="correct">&#xe008;</span><span class="incorrect">&#xe006;</span></div>
					<div class="social">&#xe004;<span class="correct">&#xe008;</span><span class="incorrect">&#xe006;</span></div>
					<div class="lock">&#xe005;<span class="correct">&#xe008;</span><span class="incorrect">&#xe006;</span></div>
					<div class="computer">&#xe00b;<span class="correct">&#xe008;</span><span class="incorrect">&#xe006;</span></div>
					<div class="gov">&#xe009;<span class="correct">&#xe008;</span><span class="incorrect">&#xe006;</span></div>
					<div class="tv">&#xe003;<span class="correct">&#xe008;</span><span class="incorrect">&#xe006;</span></div>
					<div class="user-info">&#xe002;<span class="correct">&#xe008;</span><span class="incorrect">&#xe006;</span></div>
					<div class="users">&#xe001;<span class="correct">&#xe008;</span><span class="incorrect">&#xe006;</span></div>
					<div class="user">&#xe000;<span class="correct">&#xe008;</span><span class="incorrect">&#xe006;</span></div>
				</div>
				</div><!-- /#quiz-container -->
				<div class="newsletter-signup">
					<div class="title">
						<h2>sign up for <span>email</span> updates</h2>
					</div>
					<p>We know your time and information is valuable, so we won't spam you or share your data with marketers without your consent. But we'd love to stay in touch and share with you updates, web exclusives, special events and more.</p>
					<form>
						<div>
							<input type="text" placeholder="Your email" />
								<input type="image" src="/<?php echo pivot_dml_get_path('templates'); ?>/public/images/quiz/newsletter-submit.png"/>
						</div>
					</form>
				<div class="tos">	By submitting your email address above, you agree to our <a href="#" target="_blank">Terms of Use</a> and <a href="#" target="_blank">Privacy Policy</a>.</div>
				</div>
	       </div>


	<?php require_once('includes/footer.php'); ?>



	<!-- END CONTENT -->
    </div>
  </main><!-- /#main -->
  <?php // footer will always render ?>
  <?php print render($page['footer']); ?>
</div><!-- /#page -->
