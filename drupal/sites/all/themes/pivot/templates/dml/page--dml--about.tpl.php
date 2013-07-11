<div id="page">
  <?php
    $header = render($page['header']);
    if ($header):
  ?>
  <header id="header" role="banner">
    <?php print $header; ?>
  </header>
  <?php endif; ?>
  <main id="main">
    <div id="content" class="site-wrapper">



    <!-- CONTENT GOES HERE -->
    <h1>About Page</h1>




    </div>
  </main><!-- /#main -->
  <?php // footer will always render ?>
  <?php print render($page['footer']); ?>
</div><!-- /#page -->
