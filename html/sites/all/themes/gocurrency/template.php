<?php

/**
 * @file
 * template.php
 */

function gocurrency_preprocess_html(&$vars) {
  drupal_add_css('http://fonts.googleapis.com/css?family=Droid+Sans:400,700', array('type' => 'external')); 
  drupal_add_js('https://code.highcharts.com/highcharts.js', array('type' => 'external'));
  drupal_add_js('http://code.highcharts.com/modules/exporting.js', array('type' => 'external')); 
}

/**
* Adds <span> tags around main menu items
* https://www.drupal.org/node/1118658
*/
function gocurrency_menu_link(array $variables) {
	$element = $variables['element'];
	$sub_menu = '';
	if ($element['#below']) { $sub_menu = drupal_render($element['#below']); }
	if ($element['#original_link']['menu_name'] == 'main-menu') {
		$linkText = '<span>' . $element['#title'] . '</span>';
		$element['#localized_options']['html'] = true;
	} 
	else {
		$linkText = $element['#title'];
	}
	$output = l($linkText, $element['#href'], $options = $element['#localized_options']);
	return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}
