<?php
/**
 * @file
 * Schedule primetime listing block.
 *
 * $headline_text - Block headline text.
 * $headline_link - Block headline link href.
 * $show_times - Array of show times objects that fall within primetime.
 *    $show_time->start - The start time of the show as a Unix timestamp.
 *    $show_time->show_title - Title of the show
 *    $show_time->show_path - (Optional) path to the show's page.
 * $full_schedule_text - Full schedule link text.
 * $full_schedule_link - Full schedule link href.
 * $start_time - Start time of primetime.
 * $end_time - End time of primetime.
 * $timezone - Timezone of start and end times.
 */
?>
<nav class="upcoming">
  <div class="inner">
    <h1 class="headline"><a href="<?php echo $headline_link ?>"><?php echo $headline_text ?></a></h1>
    <div id="upcoming-times" class="times">
      <div class="inner">
        <ul class="list">
          <?php foreach ($show_times as $show_time): ?>
          <li class="item">
            <div class="item-inner">
              <span class="time"><?php echo $show_time->start->format('g:ia/\E\T'); ?></span>
              <wbr>
              <?php if (isset($show_time->show_path)): ?>
              <span class="show"><a href="<?php echo $show_time->show_path; ?>"><?php echo $show_time->show_title ?></a></span>
              <?php else: ?>
              <span class="show"><?php echo $show_time->show_title; ?></span>
              <?php endif ?>
            </div>
          </li>
          <?php endforeach ?>
      </div>
    </div>
    <p class="full-schedule">
      <a href="<?php echo $full_schedule_link ?>" class="important"><?php echo $full_schedule_text ?></a>
    </p>
  </div>
</nav>
