<?php

// Plugin definition
$plugin = array(
  'title' => t('Bootstrap Columns 3'),
  'category' => t('Bootstrap'),
  'icon' => 'bs_cols3.png',
  'theme' => 'bs-cols3',
  'css' => 'bs_cols3.css',
  'regions' => array(
    'top' => t('Top Full'),
    'top_left' => t('Top Left'),
    'top_middle' => t('Top Middle'),
    'top_right' => t('Top Right'),
	'middle' => t('Middle Full'),
    'bottom_left' => t('Bottom Left'),
    'bottom_middle' => t('Bottom Middle'),
    'bottom_right' => t('Bottom Right'),
    'bottom' => t('Bottom Full')
  ),
);
