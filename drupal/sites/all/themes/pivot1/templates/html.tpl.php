<!doctype html>
<html lang="<?=$language->language ?>" dir="<?=$language->dir ?>">
<head profile="<?=$grddl_profile ?>">
  <title><?=$head_title ?></title>
  <?=$head ?>
  <meta name="viewport" content="width=device-width">
  <?=$styles ?>
  <!--[if lt IE 9]>
      <? // TODO: move this to the new theme ?>
      <script src="/sites/all/themes/participant_core/js/lib/html5shiv.js"></script>
  <![endif]-->
</head>
<body class="<?=$classes ?>" <?=$attributes ?>>
  <? if (isset($page_top)): ?>
      <?=$page_top ?>
  <? endif ?>

  <? if (isset($page)): ?>
      <?=$page ?>
  <? endif ?>      


  <? if (isset($custom)): ?>
      <?=$custom ?>
  <? endif ?>        


  <? if (isset($page_bottom)): ?>
      <?=$page_bottom ?>
  <? endif ?>

  <? if (isset($tp_sysinfo_comment_tags)): ?>
      <?=$tp_sysinfo_comment_tags ?>
  <? endif ?>

  <?=$scripts ?>
</body>
</html>