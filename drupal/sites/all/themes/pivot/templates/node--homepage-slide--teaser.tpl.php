<?php
/**
 * @file
 * Returns the HTML for a Homepage Slide Node Teaser.
 * hook_preprocess_node() in pivot_hpslider.module
 *
 */
?>
<?php if ($title_prefix || $title_suffix || $display_submitted || $unpublished || !$page && $title): ?>
	<header>
		<?php print render($title_prefix); ?>
		<?php print render($title_suffix); ?>
	</header>
<?php endif; ?>
<div class="media <?php print $variables['media_type']; ?>">
	<?php print $variables['media']; //Coming soon?>
</div>
<div class="slider-content">
	<div class="slider-title">
		<?php print $title; ?>
	</div>
	<div class="slider-text">
		<?php print drupal_render($content['field_hs_slider_text']); ?>
	</div>
	<div class="slider-cta">
		<?php print $variables['more_link']; ?>
	</div>
</div>
