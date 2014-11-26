<div id="openexform">
<div class="row">
	<div class="col-md-4"></div>
	<div class="col-md-4">

		<div class="col-md-12 date-selector-block">
			<div class="input-daterange input-group" id="datepicker">
				<?php
				print render( $form['start'] );
				?>
				<span class="input-group-addon">to</span>
				<?php print render( $form['end'] ); ?>
			</div>
		</div>

		<div class="clearfix">
			<div class="col-md-6">
				<?php print render( $form['currency1'] ); ?>
			</div>
			<div class="col-md-6">
				<?php print render( $form['currency2'] ); ?>
			</div>
		</div>

		<div class="col-md-12">
			<?php print render( $form['submit'] ); ?>
		</div>
	</div>
	<div class="col-md-4"></div>
</div>
<div class="row data-display">
	<div class="col-md-2"></div>
	<div class="col-md-8">
		<div id="container"></div>

		<div id="alert" style="display:none;" class="alert alert-warning alert-dismissible" role="alert">
			<button style="display: none;" type="button" class="close" data-dismiss="alert">
				<span aria-hidden="true">&times;</span><span class="sr-only">Close</span>
			</button>
			<span class="description">Warning! </span>
		</div>


	</div>
	<div class="col-md-2"></div>
</div>
</div>
