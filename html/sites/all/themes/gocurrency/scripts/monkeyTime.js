jQuery(document).ready(function($) {

      //Historical Data API -- Open Exchange & Highcharts
      //$('.input-daterange').datepicker({
        //        startDate: '1999-01-01',
          //      format: "yyyy-mm-dd"
            ///});

            //$('.get-rates-button').click(function(){
                function openexCurrentRates(){
                    var file='latest.json';
                    var base=$('.views-field-field-currency-code .field-content').text();
                    var symbol="USD";
                    $.post( "/openexchange/openex-latest.php", {file: file, base: base, symbol: symbol }).success(function(data){
                        data = JSON.parse(data);
                        data_array = []
                                var currency_key;
                                for (var key in data.rates) {
                                  if (data.rates.hasOwnProperty(key)) {
                                    var firstProp;
                                    jsonObj = data.rates[key];
                                    for(var key in jsonObj) {
                                        if(jsonObj.hasOwnProperty(key)) {
                                            currency_key = key;
                                            firstProp = jsonObj[key];
                                            break;
                                        }
                                    }
                                    data_array.push(firstProp);// console.log(key + " -> " + data.rates[key]);
                                  }
                                }
                                //console.log(key + " -> " + data.rates[key]);
                                var currentRate = data.rates[key];
                                $('.currency-title').append(' <span id="currency-rate">1 '+data.base+' = ' +currentRate+ ' USD</span>');
                     });
                }
                openexCurrentRates();

  /**
   * Commented by Eduard - functions move to currency_tabs module
   *
                function openexHistorical(){
                    $("#alert").hide();

                    //$.post( "/openexchange/openex.php", { start: $("#start-date").val(), end: $("#end-date").val(), base:$("#base-currency").val(), symbol:$("#symbol-currency").val() }).success(function(data) {

                    //get todays date
                    var today = new Date();
                    var dd = today.getDate();
                    var mm = today.getMonth()+1; //January is 0!
                    var yyyy = today.getFullYear();
                    if(dd<10) {
                        dd='0'+dd
                    }
                    if(mm<10) {
                        mm='0'+mm
                    }
                    mm2=mm-'1';
                    today = yyyy+'-'+mm+'-'+dd;
                    monthago = yyyy+'-'+mm2+'-'+dd;

                    var start=monthago;
                    var file='time-series.json';
                    var end=today;
                    var base=$('.views-field-field-currency-code .field-content').text();
                    var symbol="USD";
                    //$.post( "/openexchange/"+base+".json", { start: start, end: end, base: base, symbol: symbol }).success(function(data) {
                    $.post( "/openexchange/openex.php", {file: file, start: start, end: end, base: base, symbol: symbol }).success(function(data) {

                                data = JSON.parse(data);

                                //console.log(data)

                                data_array = []
                                var currency_key;
                                for (var key in data.rates) {
                                  if (data.rates.hasOwnProperty(key)) {
                                    var firstProp;
                                    jsonObj = data.rates[key];
                                    for(var key in jsonObj) {
                                        if(jsonObj.hasOwnProperty(key)) {
                                            currency_key = key;
                                            firstProp = jsonObj[key];
                                            break;
                                        }
                                    }
                                    data_array.push(firstProp);// console.log(key + " -> " + data.rates[key]);
                                  }
                                }

                                //console.log(data_array);

                                daydiff = parseInt((new Date(data.end_date) - new Date(data.start_date)) / (1000 * 60 * 60 * 24));

                                if(!data.error) {
                                        //console.log(data.start_date);
                                        //console.log(Date.UTC(parseInt(data.start_date.split('-')[0]), parseInt(data.start_date.split('-')[1]), parseInt(data.start_date.split('-')[2])))
                                         $('#container').highcharts({
                                                        chart: {
                                                            zoomType: 'x'
                                                        },
                                                        title: {
                                                            text: '1 '+data.base+' to '+currency_key+' exchange rate'
                                                        },
                                                        subtitle: {
                                                            text: "From "+data.start_date+" to "+data.end_date
                                                        },
                                                        xAxis: {
                                                            type: 'datetime',
                                                            minRange: daydiff * 24 * 3600000
                                                        },
                                                        yAxis: {
                                                            title: {
                                                                text: 'Exchange rate'
                                                            }
                                                        },
                                                        legend: {
                                                            enabled: false
                                                        },
                                                        plotOptions: {
                                                            area: {
                                                                fillColor: {
                                                                    linearGradient: { x1: 0, y1: 0, x2: 0, y2: 1},
                                                                    stops: [
                                                                        [0, Highcharts.getOptions().colors[0]],
                                                                        [1, Highcharts.Color(Highcharts.getOptions().colors[0]).setOpacity(0).get('rgba')]
                                                                    ]
                                                                },
                                                                marker: {
                                                                    radius: 2
                                                                },
                                                                lineWidth: 1,
                                                                states: {
                                                                    hover: {
                                                                        lineWidth: 1
                                                                    }
                                                                },
                                                                threshold: null
                                                            }
                                                        },

                                                        series: [{
                                                            type: 'area',
                                                            name: 'rate',
                                                            pointInterval: 24 * 3600 * 1000,
                                                            pointStart: Date.UTC(parseInt(data.start_date.split('-')[0]), parseInt(data.start_date.split('-')[1]-1), parseInt(data.start_date.split('-')[2])),
                                                            data: data_array
                                                        }]
                                                    });
                                    } else {
                                        $("#alert").show();
                                        $("#alert span.description").html(data.description);

                                    }
                            });
                        }
               // });
                openexHistorical();
                // Bootstrap Tabs
                $('#currencyTab a').click(function (e) {
                  e.preventDefault()
                  $(this).tab('show')
                })

  */

                //country flag
                function showFlag(){
                    var countryName = $('.views-field-field-country-name .field-content').text();
                    $('.currency-title').prepend(' <img id="country-flag" src="/sites/default/files/flags/standard/png/64x64/Flag_of_'+countryName+'.png" />');
                }
                if ($('body').hasClass('page-currencies')){
                    showFlag();
                }
                else{}

$( ".mailchimp-signup-subscribe-form .form-checkbox" ).prop( "checked", true );
$( ".mailchimp-signup-subscribe-form .form-type-checkbox" ).hide();

    // end jquery
});