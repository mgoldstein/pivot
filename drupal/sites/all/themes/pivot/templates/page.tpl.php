<div id="page">

  <header id="header" role="banner">

    <?php if ($logo): ?>
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
    <?php endif; ?>

    <?php print render($page['header']); ?>

  </header>
  <?php print render($page['preface']); ?>
  <main id="main">
    <div class="site-wrapper">

      <?php
        $right_sidebar  = render($page['right_sidebar']);
      ?>

      <div id="content" class="primary<?php print $right_sidebar ? ' with-sidebar' : '' ?>" role="main">
        <?php print $breadcrumb; ?>
        <a id="main-content"></a>
        <?php print render($title_prefix); ?>
        <?php if ($title): ?>
          <h1 class="title" id="page-title"><?php print $title; ?></h1>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
        <?php print $messages; ?>
        <?php print render($tabs); ?>
        <?php print render($page['help']); ?>
        <?php if ($action_links): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>
        <?php print render($page['content']); ?>
      </div><!-- /#content -->

      <?php if ($right_sidebar): ?>
      <?php print $right_sidebar; ?>
      <?php endif; ?>

    </div>
  </main><!-- /#main -->
  <?php print render($page['suffix']); ?>

  <?php // footer will always render ?>
  <?php print render($page['footer']); ?>

</div><!-- /#page -->