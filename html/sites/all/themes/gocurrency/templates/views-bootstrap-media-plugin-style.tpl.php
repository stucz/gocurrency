<div id="views-bootstrap-media-<?php print $id ?>" class="<?php print $classes ?>">
  <ul class="media-list">
    <?php foreach ($items as $key => $item): ?>
      <li class="media">
        <?php if ($item['image_field']): ?>
          <div class="pull-left">
            <?php print $item['image_field'] ?>
          </div>
        <?php endif ?>

        <div class="media-body">
          <?php if ($item['heading_field']): ?>
            <h4 class="media-heading">
              <?php print $item['heading_field'] ?>
            </h4>
          <?php endif ?>
           <?php if ($item['date_field']): ?>
            <h4 class="media-date">
              <?php print $item['date_field'] ?>
            </h4>
          <?php endif ?>

          <?php print $item['body_field'] ?>
          <?php if ($item['readmore_field']): ?>
            <h4 class="media-readmore">
              <?php print $item['readmore_field'] ?>
            </h4>
          <?php endif ?>
        </div>
      </li>
    <?php endforeach ?>
  </ul>
</div>
