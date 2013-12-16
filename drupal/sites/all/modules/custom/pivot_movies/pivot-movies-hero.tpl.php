<header id="movie-header" class="hero-header" data-movie-title="<?php print $node->title; ?>">
	<div class="movie-hero">
		<h1 class="headline"><?php print $headline_link; ?></h1>
		<div class="image">
			<?php print $hero_image; ?>
		</div>
	</div>
	<nav class="nav">
		<h2 class="headline">Movie Navigation</h2>
		<?php print $hero_menu; ?>
	</nav>
</header>
