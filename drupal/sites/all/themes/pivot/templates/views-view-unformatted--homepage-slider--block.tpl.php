<section id="topslide">
    <div id="home-header">

    <div class="pivot-headline">
      <h1 class="headline">Pivot</h1>
      <p class="tagline">It's your turn</p>
    </div>

    <div class="secondary">
      <div class="social">
        <ul>
          <li class="item facebook"><a href="#">Facebook</a></li>
          <li class="item twitter"><a href="#">Twitter</a></li>
          <li class="item googleplus"><a href="#">Google Plus</a></li>
        </ul>
      </div>
      <div class="find">
        <a href="#" class="important">
          Find <span class="pivot">Pivot</span> in your area
        </a>
      </div>
    </div>
  </div>
  <nav class="tabs slide-nav">
    <h2 class="headline">Explore Pivot</h2>
    <ul class="list">
      <?php foreach ($view->result as $id => $tab): ?>
        <?php $node = node_load($tab->nid); ?>
        <?php $tab = $node->title; ?>
        <?php $title = str_replace(' ', '_', strtolower($tab)); ?>
        <?php $title = str_replace('!', '', $title); ?>
        <?php $color = (isset($node->field_hs_logo_color['und'][0]['value']) ? $node->field_hs_logo_color['und'][0]['value'] : ''); ?>
         <li class="item <?php print $title; ?>">
            <a class="item-link" color="<?php print $color; ?>" href='#<?php print $title; ?>'>
              <span class="item-title">
                <?php print $tab; ?></a>
              </span>
          </li>
      <?php endforeach; ?>
    </ul>
    <div class="active-selector"></div>
  </nav>
  <span class="tpslide_wrapper">
    <div class="swiper-wrapper slide-wrapper">
      <?php foreach ($rows as $id => $row):
      $nid = $view->result[$id]->nid;
      $node_tab = node_load($nid);
      $title_tab = $node_tab->title;
      $title_tab = str_replace(' ', '_', strtolower($title_tab));
      $title_tab = str_replace('/!/', '', $title_tab);
      ?><!--
      --><article id="<?php print $title_tab; ?>" class="slide" data-token="<?php print $title_tab; ?>">

            <?php print $row; ?>

        </article><!--
        --><?php endforeach; ?>
    </div>
  </span>
</section>