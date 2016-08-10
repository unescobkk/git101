<?php

/**
 * @file
 * Theme implementation for displaying flexpaper formatter.
 */
?>
<div class="flexpaper-container">
  <?php if ($file_link): ?>
  <div class="flexpaper-link-container">
    <?php print $file_link ?>
  </div>
  <?php endif; ?>
  <?php if ($show_flexpaper): ?>
  <div class="flexpaper-viewer-container">
    <div class="flexpaper-viewer"><?php print t("File is downloading..."); ?></div>
  </div>
  <?php endif; ?>
</div>
