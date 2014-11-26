<?php

$file = 'time-series.json';
$appId = '8c0ead44445346f4b3b5588270304af2';

$ch = curl_init("http://openexchangerates.org/api/currencies.json");
                    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
                    $json = curl_exec($ch);

                    $obj = json_decode($json, TRUE);
                    foreach($obj as $key => $value) {                      
	                    $symbols = "USD";

	                    //get todays date
		              	$today = date("Y-m-d");
		              	$monthago = date('Y-m-d', strtotime('-30 days'));
	                    $start = $monthago;
					    $end = $today;
					    $base = $key;

						$ch2 = curl_init("http://openexchangerates.org/api/{$file}?app_id={$appId}&start={$start}&end={$end}&base={$base}&symbols={$symbols}");
						curl_setopt($ch2, CURLOPT_RETURNTRANSFER, 1);

						$json2 = curl_exec($ch2);
						curl_close($ch2);

						file_put_contents($base.".json",json_encode($json2));
                    }
                    curl_close($ch);

//print_r($json);

?>
