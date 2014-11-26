<?php
/**
 * @file
 *
 */
 
/* Blocks
** ----------------------------------------------------------------*/
function gc_block_info() {
  $blocks['pane_converter'] = array( 'info' => t('PANE: Converter'), 'cache' => DRUPAL_NO_CACHE );
  return $blocks;
}

function gc_block_view($delta = '') {
  $block = array();

  switch ($delta) {
    case 'pane_converter':
      $block['subject'] = t('Currency Converter');
      $block['content'] = gc_pane_converter();
      break; 	  
  }

  return $block;
}

function gc_pane_converter() {
	
	$output = '<div class="btn-group btn-group-justified">';
	  $output .= '<a href="#" class="btn btn-default">Regional</a>';
	  $output .= '<a href="#" class="btn btn-default">Associate</a>';
	  $output .= '<a href="#" class="btn btn-default">Both</a>';
	$output .= '</div>';

	return $output;
	
}

function gc_block_sidebar_search() {
	$form = drupal_get_form('gc_sidebar_search_form');
	return drupal_render($form);
}

/**
 * A simple form that displays a select box and submit button.
 */
function gc_sidebar_search_form($form, &$form_state) {
  $form['ig'] = array( '#prefix' => '<div class="input-group">', '#suffix' => '</div>' );

  $form['ig']['src'] = array(
    '#type' => 'textfield',
    // '#title' => t('Search'),
  );
  $form['ig']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Go'),
	'#prefix' => '<span class="input-group-btn">', 
	'#suffix' => '</span>'
  );
  return $form;
}

function gc_sidebar_search_form_submit($form, &$form_state) {
  drupal_set_message(t('You entered %input', array('%input' => $form_state['values']['src'])));
}
