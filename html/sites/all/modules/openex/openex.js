(function ($) {
    $(document).ready(function () {
        $('.input-daterange').datepicker({
            startDate: '1999-01-01',
            format: "yyyy-mm-dd"
        });


        $('.get-rates-button').click(function () {
            $("#alert").hide();
            $.post("openex_retrieve", {
                start: $("#start-date").val(),
                end: $("#end-date").val(),
                base: $("#base-currency").val(),
                symbol: $("#symbol-currency").val()
            }).success(function (data) {
                data = JSON.parse(data);

                //console.log(data)


                data_array = []
                var currency_key;
                for (var key in data.rates) {
                    if (data.rates.hasOwnProperty(key)) {
                        var firstProp;
                        jsonObj = data.rates[key];
                        for (var key in jsonObj) {
                            if (jsonObj.hasOwnProperty(key)) {
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

                if (!data.error) {
                    //console.log(data.start_date);
                    //console.log(Date.UTC(parseInt(data.start_date.split('-')[0]), parseInt(data.start_date.split('-')[1]), parseInt(data.start_date.split('-')[2])))
                    $('#container').highcharts({
                        chart: {
                            zoomType: 'x'
                        },
                        title: {
                            text: data.base + ' to ' + currency_key + ' exchange rate'
                        },
                        subtitle: {
                            text: "From " + data.start_date + " to " + data.end_date
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
                                    linearGradient: {
                                        x1: 0,
                                        y1: 0,
                                        x2: 0,
                                        y2: 1
                                    },
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
                            pointStart: Date.UTC(parseInt(data.start_date.split('-')[0]), parseInt(data.start_date.split('-')[1] - 1), parseInt(data.start_date.split('-')[2])),
                            data: data_array
                        }]
                    });
                    $(".data-display #container").show();
                } else {
                    $(".data-display #container").hide();
                    $("#alert").show();
                    $("#alert span.description").html(data.description);

                }
            });

        });
    });
})(jQuery);
