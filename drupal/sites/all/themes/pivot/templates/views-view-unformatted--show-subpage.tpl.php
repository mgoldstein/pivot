<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */

?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
  <div class="show-sidebar">
    <aside class="social tpsticky_main above"><div class="inner">
      <div class="tp-social"></div>
      <div id="article-social-more" class="article-social-more">
        <h4 class="trigger"><a href="#article-more-shares">More</a></h4>
        <section id="article-more-shares" class="article-more-shares">
          <h5 class="headline">Share with your friends</h5>
          <p></p>
        </section>
      </div>
    </div></aside>
  </div>
  <div class="view-content-content">
  <?php foreach ($rows as $id => $row): ?>
    <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
      <?php print $row; ?>
    </div>
  <?php endforeach; ?>
  </div>
