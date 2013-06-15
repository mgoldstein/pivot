<header class="header" role="banner">
	<h1 class="header">Pivot</h1>
	<div class="secondary">
		<div class="share"></div>
		<div class="find">
			Find <span class="pivot">Pivot</span> in your area
		</div>
	</div>
</header>

<section id="topslide">
	<nav class="slide-nav">
		<ul>
			<li>
				<a href="#shows">Shows</a>
			</li>
			<li>
				<a href="#movies">Movies</a>
			</li>
		</ul>
	</nav>

	<div class="slide-wrapper">
		<article id="shows" class="slide" data-token="shows">
			<video class="video-player" poster="http://frontend1.dev.pivot.tv/sites/default/files/PVT_FTG_Friday_1.jpg" width="960" height="540" loop="loop">
				<source src="http://frontend1.dev.pivot.tv/sites/default/files/PVT_FTG_Friday_1.m4v" type="video/mp4" />
				<source src="http://frontend1.dev.pivot.tv/sites/default/files/PVT_FTG_Friday_1.webm" type="video/webm" />
				<!-- object type="application/x-shockwave-flash" data="http://frontend1.dev.pivot.tv/other/flashfox.swf" width="960" height="540" style="position:relative;">
					<param name="movie" value="http://frontend1.dev.pivot.tv/other/flashfox.swf" />
					<param name="allowFullScreen" value="true" />
					<param name="flashVars" value="autoplay=true&amp;controls=false&amp;fullScreenEnabled=false&amp;posterOnEnd=true&amp;loop=true&amp;poster=http://frontend1.dev.pivot.tv/sites/default/files/PVT_FTG_Friday_1.jpg&amp;src=PVT_FTG_Friday_1.m4v" />
					<embed src="http://frontend1.dev.pivot.tv/other/flashfox.swf" width="960" height="540" style="position:relative;"  flashVars="autoplay=true&amp;controls=false&amp;fullScreenEnabled=false&amp;posterOnEnd=true&amp;loop=true&amp;poster=http://frontend1.dev.pivot.tv/sites/default/files/PVT_FTG_Friday_1.jpg&amp;src=PVT_FTG_Friday_1.m4v"	allowFullScreen="true" wmode="transparent" type="application/x-shockwave-flash" pluginspage="http://www.adobe.com/go/getflashplayer_en" />
				</object -->
			</video>
			<img class="video-image" src="http://frontend1.dev.pivot.tv/sites/default/files/PVT_FTG_Friday_1.jpg" width="960" height="540" />
			<div class="video-content">
				Woo I'm some kinda content
			</div>
		</article><!--

		--><article id="movies" class="slide" data-token="movies">
			<video class="video-player" poster="http://frontend1.dev.pivot.tv/sites/default/files/PVT_FTG_Friday_1.jpg" width="960" height="540" loop="loop">
				<source src="http://frontend1.dev.pivot.tv/sites/default/files/PVT_FTG_Friday_1.m4v" type="video/mp4" />
				<source src="http://frontend1.dev.pivot.tv/sites/default/files/PVT_FTG_Friday_1.webm" type="video/webm" />
				<!-- object type="application/x-shockwave-flash" data="http://frontend1.dev.pivot.tv/other/flashfox.swf" width="960" height="540" style="position:relative;">
					<param name="movie" value="http://frontend1.dev.pivot.tv/other/flashfox.swf" />
					<param name="allowFullScreen" value="true" />
					<param name="flashVars" value="autoplay=true&amp;controls=false&amp;fullScreenEnabled=false&amp;posterOnEnd=true&amp;loop=true&amp;poster=http://frontend1.dev.pivot.tv/sites/default/files/PVT_FTG_Friday_1.jpg&amp;src=PVT_FTG_Friday_1.m4v" />
					<embed src="http://frontend1.dev.pivot.tv/other/flashfox.swf" width="960" height="540" style="position:relative;"  flashVars="autoplay=true&amp;controls=false&amp;fullScreenEnabled=false&amp;posterOnEnd=true&amp;loop=true&amp;poster=http://frontend1.dev.pivot.tv/sites/default/files/PVT_FTG_Friday_1.jpg&amp;src=PVT_FTG_Friday_1.m4v"	allowFullScreen="true" wmode="transparent" type="application/x-shockwave-flash" pluginspage="http://www.adobe.com/go/getflashplayer_en" />
				</object -->
			</video>
			<img class="video-image" src="http://frontend1.dev.pivot.tv/sites/default/files/PVT_FTG_Friday_1.jpg" width="960" height="540" />
			<div class="video-content">
				Woo I'm some kinda content
			</div>
		</article>
	</div>
</section>

<p>
	<? while ( list($key, $node) = _seach($field_section_top) ): ?>
		<a href="<?=_surl($node) ?>">
			<? if ( $taxonomy = _snode($node, 'field_show') ): ?>
				<? if ( $taxonomy->field_promo_image ): ?>
					<?=_simage($taxonomy, 'field_promo_image', 'taxonomy_term', 'square_thumbnail') ?>
				<? else: ?>
					<?=_simage($taxonomy, 'field_show_banner', 'taxonomy_term', 'square_thumbnail') ?>
				<? endif ?>
			<? endif ?>
			<?=$node->title ?>
		</a>
	<? endwhile ?>
</p>

<p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>
<p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>
<p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>
<p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>
<p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>
<p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>
<p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>
<p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>
<p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>
<p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>
<p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>
<p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>
<p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>
<p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>
<p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>
<p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>
<p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>
<p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>
<p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>
<p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>
<p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>
