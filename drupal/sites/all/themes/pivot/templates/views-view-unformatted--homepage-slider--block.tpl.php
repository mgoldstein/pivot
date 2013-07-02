<section id="topslide">
  <span class="tpslide_wrapper">
    <nav class="tabs slide-nav">
      <ul class="list">
        <?php foreach ($view->result as $id => $tab): ?>
          <?php $node = node_load($tab->nid); ?>
          <?php $tab = $node->title; ?>
          <?php $title = str_replace(' ', '_', strtolower($tab)); ?>
           <li class="item <?php print $title; ?>">
              <a href='#<?php print $title; ?>'><?php print $tab; ?></a>
            </li>
        <?php endforeach; ?>
      </ul>
      <div class="active-selector"></div>
    </nav>
    <div class="swiper-wrapper slide-wrapper">
      <?php foreach ($rows as $id => $row):
      $nid = $view->result[$id]->nid;
      $node_tab = node_load($nid);
      $title_tab = $node_tab->title;
      $title_tab = str_replace(' ', '_', strtolower($title_tab));
      ?>
        <article id="<?php print $title_tab; ?>" class="slide" data-token="<?php print $title_tab; ?>">
          <div class="<?php print $classes_array[$id]; ?>">
            <?php print $row; ?>
          </div>
        </article>
      <?php endforeach; ?>
    </div>
  </span>
</section>