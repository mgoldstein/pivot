<?php
/**
 * @file
 * Zen theme's implementation to display a region.
 *
 * Available variables:
 * - $content: The content for this region, typically blocks.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - region: The current template type, i.e., "theming hook".
 *   - region-[name]: The name of the region with underscores replaced with
 *     dashes. For example, the page_top region would have a region-page-top class.
 * - $region: The name of the region variable as defined in the theme's .info file.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 *
 * @see template_preprocess()
 * @see template_preprocess_region()
 * @see zen_preprocess_region()
 * @see template_process()
 */
?>
<?php if ($content): ?>
  <footer id="site-footer" class="<?php print $classes; ?>">
    <div id="footer-inner" class="site-wrapper">
      <?php print $content; ?>
		  <!-- tribal fusion -->
      <?php if($is_front == TRUE): ?>
		  <img src='http://a.tribalfusion.com/i.cid?c=555033&d=30' width='1' height='1' border='0'>
      <!-- adotube -->
		  <img border="0" width="1" height="1" src="http://stats.adotube.com/pixel/pixel.php?c=432818b92ff417b5b54da6b48dbea696&t=ret&s_id=0&e=30&o=i" />
    <?php endif; ?>
	 </div>
  </footer><!-- /.footer -->
<?php endif; ?>
