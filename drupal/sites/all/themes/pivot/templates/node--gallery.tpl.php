<article id="gallery-main" class="node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <div id="gallery-photos">
      <header class="primary-header"><div class="headline-wrapper">
          <?php print render($title_prefix); ?>
          <h1<?php print $title_attributes; ?>><?php print $title; ?></h1>
          <?php print render($title_suffix); ?>
          <?php print render($content['field_article_subtitle']); ?>
            <?php if ($byline = render($content['field_person_ref'])) : ?>
            <address class="authors">
              <span class="by">By</span>
              <?php print $byline; ?>
            </address>
            <?php endif; ?>
          <p class="pubdate">
            <?php print date("F j, Y" ,$published_at); ?>
          </p>
          <!-- <p class="comment"><a href="#article-comments">Comment</a></p> -->
        </div>

        <aside class="social above">
          <div class="tp-social"></div>
          <div id="article-social-more" class="article-social-more">
            <h4 class="trigger"><a href="#article-more-shares">More</a></h4>
            <section id="article-more-shares" class="article-more-shares">
              <h5 class="headline">Share with your friends</h5>
              <p></p>
            </section>
          </div>
        </aside>
      </header>
      <?php print render($content['field_gallery_images']); ?>
  </div>
  <div id="gallery-related" class="primary with-sidebar">
    <?php print render($content); ?>

    <section id="article-comments">
      <h3 class="headline">Comments <span class="comment-count"></span></h3>
      <div class="fb_comments" data-width="600"></div>
    </section>

  </div>
</article><!-- /.node -->
