<?php
/**
 * This template used as container for hotels items
 *
 * @var $items array of rendered hotels (see ean-api-hotel.tpl.php)
 * @var $location string Location name that used for API call
 * @var $node object Current node
 */
?>

<div class="hotelHeader">Hotels in <?php echo check_plain($location); ?></div>

<table class="table table-striped table-bordered table-condensed">
	<th class="hotel-item">Hotels</th><th class="hotel-rating">Ratings</th>
  <?php foreach ($items as $item): ?>
      <?php echo $item; ?>	
  <?php endforeach; ?>
</table>
