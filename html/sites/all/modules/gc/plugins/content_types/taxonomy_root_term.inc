<?php
/**
 * @file
 * https://ohthehugemanatee.org/blog/2014/01/03/how-to-create-a-custom-panels-pane/
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Taxonomy root term'),
  'description' => t('a Display of data from the root term of the given TID'),
  'category' => t('Custom Panes'),
  'edit form' => 'gc_taxonomy_root_term',
  'render callback' => 'gc_taxonomy_root_term_render',
  'admin info' => 'gc_taxonomy_root_term_info',
  'defaults' => array(),
  'all contexts' => TRUE,
);

/**
 * Edit form.
 */
function gc_taxonomy_root_term($form, &$form_state) {
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
function gc_taxonomy_root_term_submit($form, &$form_state) {
  $form_state['conf']['term'] = $form_state['values']['term'];
  $form_state['conf']['view_mode'] = $form_state['values']['view_mode'];
}

/**
 * Render the panel.
 */
function gc_taxonomy_root_term_render($subtype, $conf, $args, $contexts) {
  if ($context->empty) {
    return;
  }
  // Get full term object for the root term.
  $term = ctools_context_keyword_substitute($conf['term'], array(), $contexts);
  $parent_array = taxonomy_get_parents_all($term);
  $root = end($parent_array);

  // Render as a block.
  $block = new stdClass();
  $block->module = 'entity';
  $block->delta = 'taxonomy_term-' . str_replace('-', '_', $conf['view_mode']);

  $entity = entity_load_single('taxonomy_term', $root->tid);
  $block->content = entity_view('taxonomy_term', array($root), $conf['view_mode']);
  return $block;

}


/**
 * Admin info.
 */
function gc_taxonomy_root_term_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $content = '<p><b>Term ID:</b> ' . $conf['term'] . '</p>';
    $content = '<p><b>View mode:</b> ' . $conf['view_mode'] . '</p>';

    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';
    $block->content = $content;
    return $block;
  }
}