<?php
/**
 * @file
 * https://ohthehugemanatee.org/blog/2014/01/03/how-to-create-a-custom-panels-pane/
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Ad Placeholder'),
  'description' => t('Placeholder for advertising spaces'),
  'category' => t('Custom Panes'),
  'edit form' => 'gc_pane_ad_placeholder',
  'render callback' => 'gc_pane_ad_placeholder_render',
  'admin info' => 'gc_pane_ad_placeholder_info',
  'defaults' => array(),
  'all contexts' => TRUE,
);

/**
 * Edit form.
 */
function gc_pane_ad_placeholder($form, &$form_state) {

	$conf = $form_state['conf'];
	
	$items = image_styles();
	
	$options = array();
	foreach ($items as $k => $v) { $options[$k] = $v['label']; }  

	$form['size'] = array(
		'#type' => 'select',
		'#options' => $options,
		'#title' => t('Size'),
		'#default_value' => $conf['size'],
	);

 	return $form;
}



/**
 * Edit form submit function.
 */
function gc_pane_ad_placeholder_submit($form, &$form_state) {
  $form_state['conf']['size'] = $form_state['values']['size'];
}

/**
 * Render the panel.
 */
function gc_pane_ad_placeholder_render($subtype, $conf, $args, $contexts) {

  $size = $conf['size'];
  
  $block = new stdClass();
  $block->module = 'entity';
  
  $alt = t('Advertisement');
  $image = array( 'style_name' => $size, 'path' => 'ad_placeholder.png', 'alt' => $alt, 'title' => $alt );

  $block->delta = 'ad_placeholder-' . str_replace('-', '_', $conf['size']);
  $block->content = theme('image_style', $image);
  return $block;  

}


/**
 * Admin info.
 */
function gc_pane_ad_placeholder_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $content = '<p><b>Size:</b> ' . $conf['size'] . '</p>';

    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';
    $block->content = $content;
    return $block;
  }
}
