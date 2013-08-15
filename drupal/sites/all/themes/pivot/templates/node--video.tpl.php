<article id="video-main" class="node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <div id="video-content" class="<?php print ($variables['field_video_type']['und'][0]['value'] == 1 ? 'single' : 'list') ?>">
      <header class="primary-header"><div class="headline-wrapper">
          <?php print render($title_prefix); ?>
          <h1<?php print $title_attributes; ?>><?php print $title; ?></h1>
          <?php print render($title_suffix); ?>
          <p class="pubdate">
            <?php print date("F j, Y" ,$published_at); ?>
          </p>
          <p class="comment"><a href="#article-comments">Comment</a></p>
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
      <?php
      if(isset($content['field_video_youtube_media'])){
        print render($content['field_video_youtube_media']);
      }
      elseif(isset($content['field_video_longtail_video_id'])){
        print render($content['field_video_longtail_video_id']);
      }
      ?>
  </div>
  <div id="video-related" class="primary with-sidebar">
    <?php print l(t('Watch full episodes right here, right now'), 'http://watch.pivot.tv/pivottv/', array('attributes' => array('target' => '_blank', 'class' => array('important')))); ?>
    <?php print render($content); ?>

    <section id="article-comments">
      <h3 class="headline">Comments <span class="comment-count"></span></h3>
      <div class="fb_comments" data-width="600"></div>
    </section>

  </div>
</article><!-- /.node -->
