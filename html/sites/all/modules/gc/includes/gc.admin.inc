<?php
/**
 * @file
 *
 *
 */

/**
 * Build iiusa_settings_form form.
 *
 * @param array $form_state
 * @return array The created form.
 */
function gc_settings_form($form_state) {
  
  	$form = array();

	$form['general'] = array(
		'#type' => 'fieldset',
		'#title' => t('Highrise API'),
		'#collapsible' => TRUE,
		'#collapsed' => FALSE,
	);
	
	$form['general']['gc_copyright'] = array(
		'#type' => 'textfield',
		'#title' => t('Copyright'),
		'#default_value' => variable_get('gc_copyright', ''),
	);

  	return system_settings_form($form);
	
}


function gc_settings_follow_form($form, &$form_state) {
	
	$networks = _gc_list_social_networks();
	$defaults = variable_get('gc_follow_links', array());
	
	$form['follow'] = array(
		'#type' => 'fieldset',
		'#title' => t('Social Media Links'),
		'#collapsible' => TRUE,
		'#collapsed' => FALSE,
		'#tree' => TRUE,
	);	
	
	foreach ($networks as $key => $info) {
		$form['follow'][$key] = array(
			'#type' => 'textfield',
			'#title' => $info['name'],
			'#default_value' => fdv($defaults[$key]),
		);		
	}
	
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => 'Submit',
	);
	
	return $form;
}


function gc_settings_follow_form_submit($form, &$form_state) {
	$v = $form_state['values'];
	variable_set('gc_follow_links', $v['follow']);
  	drupal_set_message(t('Social media links have been updated.'));
}