<?php
/**
 * @file
 * Template for a 2 column panel layout.
 *
 * This template provides a two column panel display layout, with
 * additional areas for the top and the bottom.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['top']: Content in the top row.
 *   - $content['left']: Content in the left column.
 *   - $content['right']: Content in the right column.
 *   - $content['bottom']: Content in the bottom row.
 */
?>
<div class="panel-bs-cols2 clearfix panel-display" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <?php if ($content['top']): ?>
    <div class="panel-col-top panel-panel row">
      <div class="col-sm-12">
        <div class="inside"><?php print $content['top']; ?></div>
      </div>
    </div>
  <?php endif; ?>

  <?php if ($content['left'] || $content['right']): ?>
    <div class="center-wrapper row">
      <div class="panel-col-left panel-panel col-sm-8">
        <div class="inside"><?php print $content['left']; ?></div>
      </div>
      <div class="panel-col-right panel-sidebar panel-panel col-sm-4">
        <div class="inside"><?php print $content['right']; ?></div>
      </div>
    </div>  
  <?php endif; ?>

  <?php if ($content['bottom']): ?>
    <div class="panel-col-bottom panel-panel row">
      <div class="col-sm-12">
        <div class="inside"><?php print $content['bottom']; ?></div>
      </div>
    </div>
  <?php endif; ?>
  
</div>
