<div role="tabpanel" id="currencyTab">
        <!-- Nav tabs -->
        <ul class="nav nav-tabs" id="currencyTab" role="tablist">
          <li role="presentation" class="active"><a href="#current" aria-controls="home" role="tab" data-toggle="tab">Currency</a></li>
          <li role="presentation"><a href="#history" aria-controls="profile" role="tab" data-toggle="tab">History</a></li>
          <li role="presentation"><a href="#messages" aria-controls="messages" role="tab" data-toggle="tab">Alerts</a></li>
        </ul>

        <!-- Tab panes -->
        <div class="tab-content">
          <div role="tabpanel" class="tab-pane active" id="current"><table class="table"><tr><td></td><td>AUD</td><td>CAD</td><td>EUR</td><td>GBP</td><td>JPY</td><td>USD</td><tr><td>1 AUD=</td><td>'.$convertaud_aud.'</td><td>'.$convertcad_aud.'</td><td>'.$converteur_aud.'</td><td>'.$convertgbp_aud.'</td><td>'.$convertjpy_aud.'</td><td>'.$convertusd_aud.'</td></tr><tr><td>1 CAD=</td><td>'.$convertaud_cad.'</td><td>'.$convertcad_cad.'</td><td>'.$converteur_cad.'</td><td>'.$convertgbp_cad.'</td><td>'.$convertjpy_cad.'</td><td>'.$convertusd_cad.'</td></tr><tr><td>1 EUR=</td><td>'.$convertaud_eur.'</td><td>'.$convertcad_eur.'</td><td>'.$converteur_eur.'</td><td>'.$convertgbp_eur.'</td><td>'.$convertjpy_eur.'</td><td>'.$convertusd_eur.'</td></tr><tr><td>1 GPB=</td><td>'.$convertaud_gbp.'</td><td>'.$convertcad_gbp.'</td><td>'.$converteur_gbp.'</td><td>'.$convertgbp_gbp.'</td><td>'.$convertjpy_gbp.'</td><td>'.$convertusd_gbp.'</td></tr><tr><td>1 JPY=</td><td>'.$convertaud_jpy.'</td><td>'.$convertcad_jpy.'</td><td>'.$converteur_jpy.'</td><td>'.$convertgbp_jpy.'</td><td>'.$convertjpy_jpy.'</td><td>'.$convertusd_jpy.'</td></tr><tr><td>1 USD=</td><td>'.$aud_round.'</td><td>'.$cad_round.'</td><td>'.$eur_round.'</td><td>'.$gbp_round.'</td><td>'.$jpy_round.'</td><td>'.json_encode($exchangeRates->rates->USD).'</td></tr></table></div>
          <div role="tabpanel" class="tab-pane" id="history"><div id="container" style="height: 400px; margin: 0 auto"></div>
                      <div id="alert" style="display:none;" class="alert alert-warning alert-dismissible" role="alert">
                          <button style="display: none;" type="button" class="close" data-dismiss="alert">
                          <span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>
                          <span class="description">Warning! </span>
                      </div></div>
          <div role="tabpanel" class="tab-pane" id="messages">...</div>
        </div>

      </div>