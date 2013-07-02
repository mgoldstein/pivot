(function($) {
  var tabsSwiper = new Swiper('.swiper-container',{
    // onlyExternal : true,
    height:200px,
    speed:500
  })
  $(".tabs a").on('touchstart mousedown',function(e){
    e.preventDefault()
    $(".tabs .active").removeClass('active')
    $(this).addClass('active')
    tabsSwiper.swipeTo( $(this).index() )
  })
  $(".tabs a").click(function(e){
    e.preventDefault()
  })
})(jQuery);