<?php
/**
 * @file
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Locations - Search'),
  'description' => t('Search currency locations'),
  'category' => t('Custom Panes'),
  'edit form' => 'gc_pane_locations_search',
  'render callback' => 'gc_pane_locations_search_render',
  'admin info' => 'gc_pane_locations_search_info',
  'defaults' => array(),
  'all contexts' => TRUE,
);

/**
 * Edit form.
 */
function gc_pane_locations_search($form, &$form_state) {
 $conf = $form_state['conf'];

 $form['term'] = array(
   '#type' => 'textfield',
   '#title' => t('Term ID'),
   '#description' => t('The term, from which the root term will be displayed'),
   '#default_value' => $conf['term'],
 );

  $entity_info = entity_get_info('taxonomy_term');

  $options = array();
  if (!empty($entity_info['view modes'])) {
    foreach ($entity_info['view modes'] as $mode => $settings) {
      $options[$mode] = $settings['label'];
    }
  }

 $form['view_mode'] = array(
   '#type' => 'select',
   '#options' => $options,
   '#title' => t('View mode'),
   '#default_value' => $conf['view_mode'],
 );

 return $form;
}



/**
 * Edit form submit function.
 */
function gc_pane_locations_search_submit($form, &$form_state) {
  $form_state['conf']['term'] = $form_state['values']['term'];
  $form_state['conf']['view_mode'] = $form_state['values']['view_mode'];
}

/**
 * Render the panel.
 */
function gc_pane_locations_search_render($subtype, $conf, $args, $contexts) {
  module_load_include('inc','gc','includes/gc.forms');
  $map = '<div id="map-canvas"></div>';
  $block = new stdClass;
  $block->content = drupal_get_form('gc_currency_location_form');
  return $block;
}


/**
 * Admin info.
 */
function gc_pane_locations_search_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $content = '<p><b>Term ID:</b> ' . $conf['term'] . '</p>';
    $content = '<p><b>View mode:</b> ' . $conf['view_mode'] . '</p>';

    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';
    $block->content = $content;
    return $block;
  }
}
