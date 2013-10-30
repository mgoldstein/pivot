<section id="<?php print $variables['response_id']; ?>" class="subscribe">
  <h4 class="headline"><?php print $variables['body']; ?></h4>
  <?php print drupal_render($variables['form']); ?>
  <p class="terms-link"><?php echo $variables['tos_link']; ?></p>
</section>
<?php if ($variables['follow_us_enabled']): ?>
<section class="follow">
  <h4 class="headline"><?= t('Follow Pivot') ?></h3>
  <ul class="list social">
    <?php foreach ($variables['social_links'] as $link): ?>
    <li><?php echo render($link); ?></li>
    <?php endforeach ?>
  </ul>
</section>
<?php endif; ?>
