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
<section class="show-sched section">
  <h3 class="headline"><?php echo $headline ?></h3>
  <ul class="schedule">
    <?php foreach ($show_times as $show_time): ?>
    <li class="item"><?php echo $show_time->start->format('l, M j @ g:ia/\E\T'); ?></li>
    <?php endforeach ?>
  </ul>
</section>
