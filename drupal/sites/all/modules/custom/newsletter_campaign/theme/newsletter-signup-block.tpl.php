<section id="<?php print $variables['response_id']; ?>" class="subscribe">
    <h4 class="headline"><?php print $variables['body']; ?></h4>
    <?php print drupal_render($variables['form']); ?>
    <p class="terms-link"><?php print $variables['tos_link']; ?></p>
</section>