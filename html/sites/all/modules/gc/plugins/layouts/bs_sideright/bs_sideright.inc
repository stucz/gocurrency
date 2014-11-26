<?php

// Plugin definition
$plugin = array(
  'title' => t('Bootstrap Side Right'),
  'category' => t('Bootstrap'),
  'icon' => 'bs_sideright.png',
  'theme' => 'bs-sideright',
  'css' => 'bs_sideright.css',
  'regions' => array(
    'top' => t('Top Full'),
    'top_left' => t('Top Left'),
    'top_right' => t('Top Right'),
	'middle' => t('Middle Full'),
    'bottom_left' => t('Bottom Left'),
    'bottom_right' => t('Bottom Right'),
    'bottom' => t('Bottom Full'),
	'side' => t('Side'),
  ),
);
