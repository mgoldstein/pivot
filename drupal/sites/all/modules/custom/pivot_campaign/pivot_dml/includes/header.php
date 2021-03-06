<?php
include_once(DIRNAME(__FILE__) . '/twitter/get-tweets.php');

# Load JSON
$json_string = file_get_contents(DIRNAME(__FILE__) . '/../public/data/header.json');
# Parse data
$headerData = json_decode($json_string);

?>


<link rel="stylesheet" href="/<?php echo pivot_dml_get_path('css'); ?>/dml.css">

<div id="fb-root"></div>


		<div class="dml-header">

			<div class="logo"><a href="/pivot"><img src="/<?php echo pivot_dml_get_path('images'); ?>/<?=$headerData->logo?>" width="172" height="42" alt="Nav Logo"></a></div>
			<nav>
				<ul>
					<li class="<?php if ($dmlPage == "Home") echo "current"; ?>"><a href="<?php echo url('dml', array('absolute' => TRUE)); ?>">home</a></li>
					<li class="<?php if ($dmlPage == "Quiz") echo "current"; ?>"><a href="<?php echo url('dml', array('absolute' => TRUE)); ?>/quiz">quiz</a></li>
					<li class="<?php if ($dmlPage == "Ad Policy") echo "current"; ?>"><a href="<?php echo url('dml', array('absolute' => TRUE)); ?>/ad">ad policy</a></li>
					<li class="<?php if ($dmlPage == "News Hub") echo "current"; ?>"><a href="<?php echo url('dml', array('absolute' => TRUE)); ?>/news">news hub</a></li>
					<li class="last <?php if ($dmlPage == "About") echo "current"; ?>"><a href="<?php echo url('dml', array('absolute' => TRUE)); ?>/about">about</a></li>
				</ul>

			</nav>
			<div class="social">
				<a target="_blank" href="https://twitter.com/intent/user?screen_name=<?=$headerData->social->twitter?>" class="twitter">Twitter</a>
				<a target="_blank" href="http://facebook.com/<?=$headerData->social->facebook?>" class="fb">Facebook</a>
				<a target="_blank" href="http://instagram.com/<?=$headerData->social->instagram?>" class="instagram">Instagram</a>
				<a target="_blank" href="http://<?=$headerData->social->tumblr?>.tumblr.com" class="tumblr">Tumblr</a>
			</div>
		</div><!-- /.dml-header -->
