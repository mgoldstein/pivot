<?php
include_once(drupal_get_path('module', 'pivot_dml'). '/includes/twitter/get-tweets.php');

# Load JSON
$json_string = file_get_contents(drupal_get_path('module', 'pivot_dml'). '/data/header.json');
# Parse data
$headerData = json_decode($json_string);
$path = variable_get('pivot_dml_path', '');
global $base_url;
?>

<div id="fb-root"></div>


		<div class="dml-header">


			<div class="logo"><?php print l('<img src="'. $base_url. '/'. drupal_get_path('module', 'pivot_dml'). '/images/nav-logo.png" width="172" height="42" alt="Nav Logo">', '<front>', array('html' => true)); ?></div>
			<nav>
				<ul>
					<li class=""><?php print l('home', drupal_lookup_path('source', $path)); ?></li>
					<li class=""><?php print l('quiz', $path. '/quiz'); ?></li>
					<li class=""><?php print l('ad policy', drupal_lookup_path('source', $path. '/ad_policy')); ?></li>
					<li class=""><?php print l('about', drupal_lookup_path('source', $path. '/about')); ?></li>


				</ul>

			</nav>
			<div class="social">
				<a target="_blank" href="https://twitter.com/intent/user?screen_name=<?=$headerData->social->twitter?>" class="twitter">Twitter</a>
				<a target="_blank" href="http://facebook.com/<?=$headerData->social->facebook?>" class="fb">Facebook</a>
				<a target="_blank" href="http://instagram.com/<?=$headerData->social->instagram?>" class="instagram">Instagram</a>
				<a target="_blank" href="http://<?=$headerData->social->tumblr?>.tumblr.com" class="tumblr">Tumblr</a>
			</div>
		</div><!-- /.dml-header -->
