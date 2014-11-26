<?php

$appId = '8c0ead44445346f4b3b5588270304af2';

if($_SERVER['REQUEST_METHOD'] === 'POST') {

	$file = $_POST['file'];
    $base = $_POST['base'];
    $symbols = $_POST['symbol'];


$ch = curl_init("http://openexchangerates.org/api/{$file}?app_id={$appId}&base={$base}&symbols={$symbols}");
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);

$json = curl_exec($ch);
curl_close($ch);

print_r($json);
}

?>
