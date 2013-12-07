<article id="video-main" class="node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <div id="video-content" class="list">
      <header class="primary-header">
        <div class="headline-wrapper">
          <?php print render($title_prefix); ?>
          <h1<?php print $title_attributes; ?>><?php print $title; ?></h1>
          <?php print render($title_suffix); ?>
          <p class="pubdate">
            <?php print date("F j, Y" ,$published_at); ?>
          </p>
          <p class="comment"><a href="#article-comments">Comment</a></p>
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
        </div>


      </header>
      <?php
        print render($content['field_video_media']);
        print l(t('Watch full episodes right here, right now'), 'http://watch.pivot.tv/pivottv/', array('attributes' => array('target' => '_blank', 'class' => array('important'))));
      ?>
  </div>
  <div id="video-related" class="primary with-sidebar">
    <?php print render($content); ?>
  </div>

</article><!-- /.node -->
