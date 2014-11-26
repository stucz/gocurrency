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
<div class="panel-bs-cols3 clearfix panel-display" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <?php if ($content['top']): ?>
    <div class="panel-row-top panel-panel row">
      <div class="col-sm-12">
        <div class="inside"><?php print $content['top']; ?></div>
      </div>
    </div>
  <?php endif; ?>

  <?php if ($content['top_left'] || $content['top_middle'] || $content['top_right']): ?>
    <div class="center-wrapper row">
      <div class="panel-col-left panel-panel col-sm-4">
        <div class="inside"><?php print $content['top_left']; ?></div>
      </div>
      <div class="panel-col-middle panel-panel col-sm-4">
        <div class="inside"><?php print $content['top_middle']; ?></div>
      </div>      
      <div class="panel-col-right panel-panel col-sm-4">
        <div class="inside"><?php print $content['top_right']; ?></div>
      </div>
    </div>  
  <?php endif; ?>
  
  <?php if ($content['middle']): ?>
    <div class="panel-row-middle panel-panel row">
      <div class="col-sm-12">
        <div class="inside"><?php print $content['middle']; ?></div>
      </div>
    </div>
  <?php endif; ?>  
  
  <?php if ($content['bottom_left'] || $content['bottom_middle'] || $content['bottom_right']): ?>
    <div class="center-wrapper row">
      <div class="panel-col-left panel-panel col-sm-4">
        <div class="inside"><?php print $content['bottom_left']; ?></div>
      </div>
      <div class="panel-col-middle panel-panel col-sm-4">
        <div class="inside"><?php print $content['bottom_middle']; ?></div>
      </div>      
      <div class="panel-col-right panel-panel col-sm-4">
        <div class="inside"><?php print $content['bottom_right']; ?></div>
      </div>
    </div>  
  <?php endif; ?>  
  
  <?php if ($content['bottom']): ?>
    <div class="panel-row-bottom panel-panel row">
      <div class="col-sm-12">
        <div class="inside"><?php print $content['bottom']; ?></div>
      </div>
    </div>
  <?php endif; ?>  
  
</div>
