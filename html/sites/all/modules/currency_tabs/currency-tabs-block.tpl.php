<?php
/**
 * @var $currency array
 * @var $history array
 * @var $alerts array
 */
?>

<div role="tabpanel" id="currencyTab">
  <!-- Nav tabs -->
  <ul class="nav nav-tabs" id="currencyTab" role="tablist">
    <li role="presentation" class="active">
      <a href="#current" aria-controls="home" role="tab" data-toggle="tab">Currency</a>
    </li>
    <li role="presentation">
      <a href="#history" aria-controls="profile" role="tab" data-toggle="tab">History</a>
    </li>
    <li role="presentation">
      <a href="#messages" aria-controls="messages" role="tab" data-toggle="tab">Alerts</a>
    </li>
  </ul>

  <!-- Tab panes -->
  <div class="tab-content">
    <div role="tabpanel" class="tab-pane active table-responsive" id="current">
      <?php echo render($currency); ?>

    </div>
    <div role="tabpanel" class="tab-pane" id="history">
      <?php echo render($history); ?>
      <div id="alert" style="display:none;" class="alert alert-warning alert-dismissible" role="alert">
        <button style="display: none;" type="button" class="close" data-dismiss="alert">
          <span aria-hidden="true">&times;</span><span class="sr-only">Close</span>
        </button>
        <span class="description">Warning! </span>
      </div>
    </div>
    <div role="tabpanel" class="tab-pane" id="messages">...</div>
  </div>

</div>