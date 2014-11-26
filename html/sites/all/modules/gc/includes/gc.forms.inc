<?php
/**
 * @file
 *
 */
 
  
/*  [FORM] Converter
** ----------------------------------------------------------------*/
function gc_currency_convert_form($form, &$form_state) {
  $form['ig'] = array( '#prefix' => '<div class="input-group row">', '#suffix' => '</div>' );
  $json = file_get_contents('sites/all/modules/gc/includes/resources/currency-codes.json');
  $obj = drupal_json_decode($json);
  $form['ig']['amount'] = array(
    '#type' => 'textfield',
    '#title' => t('Amount'),
    '#default_value' => '1',
    '#prefix' => '<div class="col-md-12">', 
    '#suffix' => '</div>'
  );
  $form['ig']['from'] = array(
    '#type' => 'select',
    '#title' => t('From'),
    '#options' => $obj,
    '#prefix' => '<div class="col-md-12">', 
    '#suffix' => '</div>'
  );
  $form['ig']['to'] = array(
    '#type' => 'select',
    '#title' => t('To'),
    '#options' => $obj,
    '#prefix' => '<div class="col-md-12">', 
    '#suffix' => '</div>'
  );
  $form['ig']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Convert'),
	  '#prefix' => '<div class="col-md-6">', 
    '#suffix' => '</div>'
  );
  return $form;
}

function gc_currency_convert_form_validate($form, &$form_state) {
  if (!($form_state['values']['amount'] > 0)){
    form_set_error('Amount', t('Amount must be a greater than 0.'));
  }
}

function gc_currency_convert_form_submit($form, &$form_state) {
  $from = drupal_strtolower($form_state['values']['from']);
  $to = drupal_strtolower($form_state['values']['to']);
  $amount = $form_state['values']['amount'];
  $form_state['redirect'] = array(
    'convert/'.$from.'/'.$to,
    array(
      'query' => array(
        'amount' => $amount
      )
    ),
  );
}


function gc_currency_location_form($form, &$form_state) {
  drupal_add_js('https://maps.googleapis.com/maps/api/js?key=AIzaSyCMsb6rzofh-UmaSsa6yCmNkMn7SAqbBvs');
  drupal_add_js(drupal_get_path('module', 'gc') .'/includes/resources/maps.js');
  $form['loc'] = array( '#prefix' => '<div class="row">', '#suffix' => '</div>' );
  $form['loc']['amount'] = array(
    '#type' => 'textfield',
    '#title' => t('ENTER CITY/ZICODE'),
    '#default_value' => '',
    '#prefix' => '<div class="col-md-9">', 
    '#suffix' => '</div>'
  );
  $form['loc']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('GO'),
    '#prefix' => '<div class="col-md-2 formSubmit">', 
    '#suffix' => '</div>'
  );
  $form['some_text'] = array(
  '#markup' => '<div id="map-canvas"></div>'
  );
  return $form;
}