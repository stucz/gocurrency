jQuery(function ($) {
  $('#currencyTab').find('a').click(function (e) {
    e.preventDefault();
    $(this).tab('show');
  });

  if (Drupal && Drupal.settings && Drupal.settings.currency_history) {
    var history = Drupal.settings.currency_history;

    $('#currency-tabs-history-chart').highcharts({
      chart: {
        zoomType: 'x'
      },
      title: {
        text: '1 ' + history.base + ' to ' + history.code + ' exchange rate'
      },
      subtitle: {
        text: "From " + history.start_date + " to " + history.end_date
      },
      xAxis: {
        type: 'datetime',
        minRange: parseInt(new Date(history.end_date) - new Date(history.start_date))
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
            linearGradient: {x1: 0, y1: 0, x2: 0, y2: 1},
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

      series: [
        {
          type: 'area',
          name: 'rate',
          pointInterval: 24 * 3600 * 1000,
          pointStart: Date.UTC(parseInt(history.start_date.split('-')[0]), parseInt(history.start_date.split('-')[1] - 1), parseInt(history.start_date.split('-')[2])),
          data: history.rates
        }
      ]
    });
  }

});

