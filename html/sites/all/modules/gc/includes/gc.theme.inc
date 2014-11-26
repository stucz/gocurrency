<?php
/**
 * @file
 *
 */
 
/**
 * Format a node stripe legend
 */
function theme_iiusa_solr_item($vars) {
  if (empty($vars) || !$type = $vars['type']) { return ''; }

  $d = $vars['data'];
  
  switch ($vars['type']) {
	
	case 'company':
	case 'person':
	  
	  $temp = 'NA';
	  
	  $addr = array(
	    'city' => $d['sm_field_member_address_city'][0],	
	    'state' => $d['sm_field_member_address_state'][0],	
	    'zip' => $d['sm_field_member_address_zip'][0],	
	  );
	  
	  $f = array();
	  $f[] = array( 'value' => $d['sm_field_member_address_street'][0]);
	  $f[] = array( 'value' => implode(' ', $addr), 'break' => TRUE);
	  
	  $f[] = array( 'label' => t('E-Mail'), 'value' => $d['sm_field_member_email'][0]);
	  $f[] = array( 'label' => t('Phone'), 'value' => $d['sm_field_member_phone'][0], 'break' => TRUE);  
	  
	  $f[] = array( 'label' => t('Member Since'), 'value' => $temp); 
	  $f[] = array( 'label' => t('States Served'), 'value' => $d['sm_field_member_states'][0], 'break' => TRUE); 
	  
	  $f[] = array( 'label' => t('Website'), 'value' => $d['sm_field_member_website'][0]); 
	  $f[] = array( 'label' => t('I-526 Approval'), 'value' => $temp); 
	  $f[] = array( 'label' => t('I-829 Approval'), 'value' => $temp, 'break' => TRUE); 
	  
	  $f[] = array( 'label' => t('Approved Geography'), 'value' => $temp, 'break' => TRUE); 
	  
	  $f[] = array( 'label' => t('NAICS Codes / Approved Industries'), 'value' => $d['sm_field_member_industry_code'][0]); 
	  $f[] = array( 'value' => $d['sm_field_member_industry_name'][0], 'break' => TRUE); 
	  
	  $f[] = array( 'label' => t('Approved Economic Model'), 'value' => $d['sm_field_member_models'][0]); 
	  $f[] = array( 'label' => t('Parent Company'), 'value' => $temp); 
	  
	  $title = l($vars['title'], $vars['data']['path']);
	  $content = theme('iiusa_solr_item_fields', array( 'items' => $f ));
	
	break;
	
	default:
	  $title = l($vars['title'], $vars['data']['path']);
	  $content = $vars['snippet'];
	break;	
	
  }
  
  
  
  $output = '<div class="result-item result-'. $vars['data']['bundle'] .'">';
    $output .= '<h3 class="result-title">'. $title .'</h3>';
    $output .= $content; 
  $output .= '</div>';
  
  return $output;
  
} 

/**
 * Format a node stripe legend 
 */
function theme_iiusa_solr_item_fields($vars) {

  if (empty($vars) || !count($vars['items'])) { return ''; }

  $output = '';
  
  foreach ($vars['items'] as $item) {
	if ( !empty($item['label']) || !empty($item['value']) ) {
	  $class = isset($item['break']) ? 'fld fld-break' : 'fld';
	  $output .= '<div class="'. $class .'">';
	    if (!empty($item['label'])) { 
			$output .= '<span class="fld-label">'. $item['label'] .': </span>'; 
		}
	    if (!empty($item['value']) && $item['value'] != '') { 
			$output .= '<span class="fld-value">'. $item['value'] .'</span>'; 
		}
	  $output .= '</div>';
	}
  }

  return $output;
} 