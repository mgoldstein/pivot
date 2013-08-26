<?php
/**
 * @file
 * Show schedule listing block.
 *
 * $headline - Block headline.
 * $show_times - Array of show times objects that fall within primetime.
 *    $show_time->start - The start time of the show as a Unix timestamp.
 *    $show_time->show_title - Title of the show
 *    $show_time->show_path - (Optional) path to the show's page.
 * $count - The maximum number of show times to show.
 * $timezone - Timezone used for finding next unaired show times.
 */
?>
<section class="page schedule">
  <?php print $messages; ?>
  <?php foreach($list as $entity): ?>

    <div class="row">
      <div class="time"><?php print date('h:ia', $entity[0]->broadcast_start_time); ?></div>
      <div class="info">
        <div class="rating"><?php print $entity[0]->fcc_rating_v_chip_codes; ?></div>
        <?php if(strtolower($entity[0]->element_name) == 'movie'): ?>
          <div class="title"><?php print ($entity['reference'] != NULL ? l($entity[0]->title_name, 'node/'. $entity['reference']) : $entity[0]->title_name); ?></div>
          <div class="episode"></div>
        <?php else: ?>
          <div class="title"><?php print $entity[0]->element_name; ?> </div>
          <div class="episode">"<?php print $entity[0]->title_name; ?>"</div>
        <?php endif; ?>
        <div class="description"><?php print $entity[0]->title_synopsis; ?></div>
      </div>
      <?php if(isset($entity[0]->title_premiere_indicator_current_schedule) && $entity[0]->title_premiere_indicator_current_schedule == 1): ?>
        <div class="premier"><div class="icon">New</div></div>
      <?php endif; ?>
    </div>
  <?php endforeach; ?>
</section>












