<?php

// Plugin definition
$plugin = array(
  'title' => t('Bootstrap Columns 2'),
  'category' => t('Bootstrap'),
  'icon' => 'bs_cols2.png',
  'theme' => 'bs-cols2',
  'css' => 'bs_cols2.css',
  'regions' => array(
    'top' => t('Top'),
    'left' => t('Left side'),
    'right' => t('Right side'),
    'bottom' => t('Bottom')
  ),
);
