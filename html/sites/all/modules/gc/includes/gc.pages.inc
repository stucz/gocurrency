<?php
/**
 * @file
 *
 */
 
  
/*  [PAGE] Tester
** ----------------------------------------------------------------*/
function gc_page_tester() {
	$output = '';
	
	
    $json = file_get_contents('http://openexchangerates.org/api/currencies.json');
    $obj = drupal_json_decode($json);
	
	$currencies = array_keys($obj);
	/*
	$copy = 'testing 123';
	
	$ret = array();
	foreach ($currencies as $from) {
		foreach ($currencies as $to) {
			$ret[] = array(
				'from' => $from,
				'to' => $to				
			);	
		}
	}	
	
	variable_set('gc_tester', $ret);
	*/
	
	/*
	$copy = t('Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.');
	
	$currencies = variable_get('gc_tester', array());
	
	$items = array_chunk($currencies, 1000);
	
	$delta = $_SESSION['gc_tester'];
	
	
	$ret = array();

	foreach ($items[$delta] as $c) {
		$ret[] = array(
			'type' => 'conversion',
			'title' => t('!fr to !to Exchange Rate', array('!fr' => $c['from'], '!to' => $c['to'])),
			'fields' => array(
				'body' => array( 'value' => $copy, 'format' => filter_default_format() ),
				'field_currency_from' => $c['from'],
				'field_currency_to' => $c['to']				
			),
			'dates' => NULL,
			'edit' => NULL
		);				
	}
	
	_gc_queue($ret, 'create_nodes');

	$_SESSION['gc_tester'] = $delta + 1;
	*/
	
	// $item = $ret[0];
	// $ret = _save_node(NULL, $item['type'], $item['title'], $item['fields'], NULL);
	
	
	// $ret = $currencies;
	
	
	/*
	$ret = array();
	foreach ($currencies as $from) {
		foreach ($currencies as $to) {
			$ret[] = array(
				'type' => 'conversion',
				'title' => t('!fr to !to Exchange Rate', array('!fr' => $from, '!to' => $to)),
				'fields' => array(
					'body' => array( 'value' => $copy, 'format' => filter_default_format() ),
					'field_currency_from' => $from,
					'field_currency_to' => $to				
				),
			);	
		}
	}
	*/
	
	
	$ret = $currencies;
	
	
	$output .= _arrayinfo($ret);
	
	return $output;
} 

function _gc_tester_make_currenciessss($items = NULL, $chunk = 0){
	if (empty($items) || empty($items[$chunk])) { return array(); }	
	
  $ret['fields'] = array(
	'field_highrise_id' => $data->id,
	'field_highrise_author_name' => $data->author_id,
	'field_description' => array( 'value' => check_markup($data->body), 'format' => filter_default_format() ),
  ); 
	
	$_SESSION['gc_tester'] = $chunk + 1;
	return $ret;
		
}



function _gc_tester_make_currencies($items = NULL, $chunk = 0){
	if (empty($items) || empty($items[$chunk])) { return array(); }	
	
	$ret = array();
	foreach ($items[$chunk] as $k => $v) {
		$fields = array( 'currency_code' => $k );
		if ($n = _update_entity(NULL, 'currency', $v, $fields)) { $ret[$n->nid] = $n->title;	}
	}
	
	$_SESSION['gc_tester'] = $chunk + 1;
	return $ret;
		
}

function gc_tester_make($items = NULL){
	if (empty($items) || !count($items)) { return array(); }	
		
	$ct = 0;
	$ret = array();
	foreach ($items as $i) {
		$fields = array( 
			'capital' => $i->capital,
			'currency_code' => $i->iso4217code,
			'currency_name' => $i->iso4217name,
			'country_code' => $i->iso3166code3
		);
		if ($n = _update_entity(NULL, 'country', $i->name, $fields)) { 
			$ret[$n->nid] = $n->title;
			$ct++;	
		}
	}
	
	return $ret;
		
}

function gc_get_yelp_results(){
	
  /*
	 location: String value of the address to serve as radius center
	 radius: int value of radius in miles to search (max of 25)
	 max_results: int value ofthe maximum number of results to retrieve (max of 20)
	 offset: offset of results
	 sort : numeric value for how to order results (0=,1=,2=)
	 categories: a comma separted list of Yelp Category keys to search
	 cc: country code to search in (US, CA or GB) default US.
	 lang: the two letter language code to search (default EN)
	 lang_filter: boolean value to restrict results to the lang (default 0)
	 term: string of text results must contain.	
  */	
	
	module_load_include('inc','yelp_api','yelp_api.pages');
	$param = array( 
		'location' => '60654', 
		'cc' => 'US', 
		'categories' => 'hotelstravel', 
		'radius' => 50,
		'max_results' => 100,
		'term' => 'currency exchange',
	);
	if ($results = yelp_api_get_results($param)){ return $results; }
	return false;
}