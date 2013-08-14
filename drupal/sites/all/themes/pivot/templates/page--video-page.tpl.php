<div id="page">
  <header id="site-header" role="banner" class="header">
    <?php print render($page['header']); ?>
  </header>

  <main id="main">
    <div id="content" class="site-wrapper">
      <a id="main-content"></a>

      <?php print render($page['preface']); ?>

      <div style="clear:both;">
        <?php print $messages; ?>
        <?php print render($tabs); ?>
        <?php print render($page['help']); ?>
        <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>
      </div>
      <?php print render($page['content']); ?>

      <?php print render($page['right_sidebar']); ?>

      <?php print render($page['suffix']); ?>

    </div><!-- /#content -->
  </main><!-- /#main -->

  <?php print render($page['footer']); ?>

</div><!-- /#page -->
