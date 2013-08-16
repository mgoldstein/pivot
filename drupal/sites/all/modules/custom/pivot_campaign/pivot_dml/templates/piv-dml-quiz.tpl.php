    <!-- CONTENT GOES HERE -->

	<?php
	# Load JSON
	$json_string = file_get_contents(drupal_get_path('module', 'pivot_dml'). '/data/quiz-data.json');
	# Parse data
	$quizData = json_decode($json_string);
	$path = variable_get('pivot_dml_path', '');
	?>

	       <div class="row main">

				<div id="quiz-container" data-file="/<?php echo drupal_get_path('module', 'pivot_dml'); ?>/data/quiz-data.json">
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
									<a href="#" class="share fb"
										data-link="<?php echo url($path, array('absolute' => TRUE)).$quizData->share->facebook->data_link; ?>"
										data-image="<?php echo url('<front>', array('absolute' => TRUE)).drupal_get_path('module', 'pivot_dml').$quizData->share->facebook->data_image; ?>"
										data-name="<?php echo $quizData->share->facebook->data_name; ?>"
										data-caption="<?php echo $quizData->share->facebook->data_caption; ?>"
										data-description="<?php echo $quizData->share->facebook->data_description; ?>"></a>
							</li>
							<li>
								<a href="#" data-url="https://twitter.com/intent/tweet?url=<?php echo url($path, array('absolute' => TRUE)).$quizData->share->twitter->link; ?>&text=<?php echo rawurlencode($quizData->share->twitter->share_copy); ?>" class="share twitter"></a>
							</li>
							<li>
								<a href="#" data-url="https://plus.google.com/share?url=<?php echo url($path, array('absolute' => TRUE)).$quizData->share->gplus->link; ?>" class="share gplus"></a>
							</li>
						 	<li>
								<a href="#" data-url="mailto:?subject=<?php echo rawurlencode($quizData->share->email->subject); ?>&amp;body=<?php echo rawurlencode($quizData->share->email->body); ?> <?php echo url($path, array('absolute' => TRUE)).$quizData->share->email->link; ?>."  class="share email" ></a>
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
					<?php
						$block = module_invoke('newsletter_campaign', 'block_view', 2);
						print render($block['content']);
					?>
					<div class="tos">	By submitting your email address above, you agree to our <a href="<?php print $path; ?>/terms-of-use">Terms of Use</a> and <a href="<?php print $path; ?>/privacy-policy">Privacy Policy</a>.</div>
				</div>

	       </div>
	<!-- END CONTENT -->







