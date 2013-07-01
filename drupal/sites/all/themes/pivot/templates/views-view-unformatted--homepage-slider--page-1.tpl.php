<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<div class="swiper-container">
  <div class="swiper-wrapper">
    <?php foreach ($rows as $id => $row): ?>
      <div class="<?php print $classes_array[$id]; ?>">
        <?php print $row; ?>
      </div>
    <?php endforeach; ?>
  </div>
  <div class="tabs">
    <?php foreach ($view->result as $id => $tab): ?>
      <?php $node = node_load($tab->nid); ?>
      <?php $tab = $node->title; ?>
      <a href='#'><?php print $tab; ?></a>
    <?php endforeach; ?>
  </div>
</div>
  <?php drupal_add_js(drupal_get_path('module', 'pivot_hero1'). '/js/idangerous.swiper-2.0.min.js'); ?>
  <?php drupal_add_css(drupal_get_path('module', 'pivot_hero1'). '/css/idangerous.swiper.css'); ?>

<script>
  (function($) {
    $(document).ready(function() {

      var mySwiper = $('.swiper-container').swiper({
        //Your options here:
        mode:'horizontal',
        loop: true,
        height: '200px'
        //etc..
      });
      $(".tabs a").on('touchstart mousedown',function(e){
        e.preventDefault()
        $(".tabs .active").removeClass('active')
        $(this).addClass('active')
        tabsSwiper.swipeTo( $(this).index() )
      })
      $(".tabs a").click(function(e){
        e.preventDefault()
      })






    });
  })(jQuery);
</script>