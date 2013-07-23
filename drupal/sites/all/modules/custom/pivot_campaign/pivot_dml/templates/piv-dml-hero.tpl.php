<?php
include_once(drupal_get_path('module', 'pivot_dml'). '/includes/twitter/get-tweets.php');

# Load JSON
$json_string = file_get_contents(drupal_get_path('module', 'pivot_dml'). '/data/header.json');
# Parse data
$headerData = json_decode($json_string);
$path = variable_get('pivot_dml_path', '');
?>

<div id="fb-root"></div>


		<div class="dml-header">

			<div class="logo"><a href="/homepage"><img src="/<?php echo drupal_get_path('module', 'pivot_dml'); ?>/images/nav-logo.png" width="172" height="42" alt="Nav Logo"></a></div>
			<nav>
				<ul>
					<li class="<?php echo "current"; ?>"><a href="<?php echo url($path, array('absolute' => TRUE)); ?>">home</a></li>
					<li class=""><a href="<?php echo url($path, array('absolute' => TRUE)); ?>/quiz">quiz</a></li>
					<li class=""><a href="<?php echo url($path, array('absolute' => TRUE)); ?>/ad">ad policy</a></li>
					<li class=""><a href="<?php echo url($path, array('absolute' => TRUE)); ?>/news">news hub</a></li>
					<li class="last"><a href="<?php echo url($path, array('absolute' => TRUE)); ?>/about">about</a></li>
				</ul>

			</nav>
			<div class="social">
				<a target="_blank" href="https://twitter.com/intent/user?screen_name=<?=$headerData->social->twitter?>" class="twitter">Twitter</a>
				<a target="_blank" href="http://facebook.com/<?=$headerData->social->facebook?>" class="fb">Facebook</a>
				<a target="_blank" href="http://instagram.com/<?=$headerData->social->instagram?>" class="instagram">Instagram</a>
				<a target="_blank" href="http://<?=$headerData->social->tumblr?>.tumblr.com" class="tumblr">Tumblr</a>
			</div>
		</div><!-- /.dml-header -->
