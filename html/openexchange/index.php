<!DOCTYPE html>
<html>
<head lang="en">
    <meta charset="UTF-8">
    <title>OpenEX Graph</title>

    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.0/css/bootstrap.min.css">
    <link rel="stylesheet" href="style.css">
    <link rel="stylesheet" href="//cdnjs.cloudflare.com/ajax/libs/bootstrap-datepicker/1.3.0/css/datepicker.min.css">


</head>
<body>
<div class="row">
    <div class="col-md-4"></div>
    <div class="col-md-4">

        <div class="col-md-12 date-selector-block">
            <div class="input-daterange input-group" id="datepicker">
                <input id="start-date" type="text" class="input-sm form-control" name="start" />
                <span class="input-group-addon">to</span>
                <input id="end-date" type="text" class="input-sm form-control" name="end" />
            </div>
        </div>


        <div class="col-md-6">
            <select id="base-currency" class="form-control">
                <?php 
                    $ch = curl_init("http://openexchangerates.org/api/currencies.json");
                    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
                    $json = curl_exec($ch);

                    $obj = json_decode($json, TRUE);
                    foreach($obj as $key => $value) {
                       echo "<option>".$key."</option>";
                    }
                    curl_close($ch);
                ?>
            </select>
        </div>
        <div class="col-md-6">
            <select id="symbol-currency" class="form-control">
                <?php 
                    foreach($obj as $key => $value) {
                           echo "<option>".$key."</option>";
                    }
                ?>
            </select>
        </div>

        <div class="col-md-12">
            <button type="button" class="get-rates-button btn btn-block btn-default">Get rates</button>
        </div>


        
    </div>
    <div class="col-md-4"></div>
</div>

    <div class="row data-display">
        <div class="col-md-2"></div>
        <div class="col-md-8">
            <div id="container" style="height: 400px; margin: 0 auto"></div>
        
                <div id="alert" style="display:none;" class="alert alert-warning alert-dismissible" role="alert">
                    <button style="display: none;" type="button" class="close" data-dismiss="alert">
                    <span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>
                    <span class="description">Warning! </span>
                </div>

          

        </div>
        <div class="col-md-2"></div>
    </div>

    
    <script src="https://code.jquery.com/jquery-1.11.1.min.js"></script>
    <script src="https://code.highcharts.com/highcharts.js"></script>
    <script src="http://code.highcharts.com/modules/exporting.js"></script>
    <script src="//cdnjs.cloudflare.com/ajax/libs/bootstrap-datepicker/1.3.0/js/bootstrap-datepicker.min.js"></script>

    <script>
        $(document).ready(function(){
            $('.input-daterange').datepicker({
                startDate: '1999-01-01',
                format: "yyyy-mm-dd"
            });
            
          


            $('.get-rates-button').click(function(){
                $("#alert").hide();
                $.post( "openex.php", { start: $("#start-date").val(), end: $("#end-date").val(), base:$("#base-currency").val(), symbol:$("#symbol-currency").val() }).success(function(data) {
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
                                                        text: data.base+' to '+currency_key+' exchange rate'
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
                        
                });
            });
    </script>

</body>
</html>