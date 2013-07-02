<section id="topslide">
  <span class="tpslide_wrapper">
    <nav class="tabs slide-nav">
      <ul class="list">
        <?php foreach ($view->result as $id => $tab): ?>
          <?php $node = node_load($tab->nid); ?>
          <?php $tab = $node->title; ?>
           <li class="item <?php print $node->title; ?>">
              <?php $title = str_replace(' ', '_', strtolower($node->title)); ?>
              <a href='#<?php print $title; ?>'><?php print $tab; ?></a>
            </li>
        <?php endforeach; ?>
      </ul>
      <div class="active-selector"></div>
    </nav>
    <div class="swiper-wrapper slide-wrapper">
      <?php foreach ($rows as $id => $row): ?>
        <div class="<?php print $classes_array[$id]; ?>">
          <?php print $row; ?>
        </div>
      <?php endforeach; ?>
    </div>
  </span>
</section>