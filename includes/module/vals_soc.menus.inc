<?php 

function vals_soc_menu_handler(){
	$items['admin/config/vals_soc'] = array(
			'title' => 'VALS Summer of code',
			'type' => MENU_NORMAL_ITEM,
			'page callback' => 'vals_soc_timeline_admin_overview_page',
			'access arguments' => array('access administration pages'),
			'description' => 'Allow Administration on the summer of code module',
			'file' => 'vals_soc.pages.inc',
			'file path' => drupal_get_path('module', 'vals_soc') . '/includes/module/',
	);
	
	$items['admin/config/vals_soc/program_settings'] = array(
			'title' => 'Program Settings',
			'type' => MENU_NORMAL_ITEM,
			'page callback' => 'vals_soc_timeline_admin_program_page',
			'access arguments' => array('access administration pages'),
			'description' => 'Allow Administration on the summer of code module',
			'file' => 'vals_soc.pages.inc',
			'file path' => drupal_get_path('module', 'vals_soc') . '/includes/module/',
	);
	
	$items['admin/config/vals_soc/program_settings/timeline'] = array(
			'title' => 'Edit Timeline',
			'type' => MENU_NORMAL_ITEM,
			'page callback' => 'drupal_get_form',
			'page arguments' => array('vals_soc_admin_timeline_form'),
			'access arguments' => array('access administration pages'),
			'description' => 'Edit the timeline and other settings.',
			'file' => 'vals_soc.forms.inc',
			'file path' => drupal_get_path('module', 'vals_soc') . '/includes/module/',
	);
	
	$items['admin/config/vals_soc/program_settings/messages'] = array(
			'title' => 'Edit Messages',
			'type' => MENU_NORMAL_ITEM,
			'page callback' => 'drupal_get_form',
			'page arguments' => array('vals_soc_admin_messages_form'),
			'access arguments' => array('access administration pages'),
			'description' => 'Edit the email messages that are sent to users.',
			'file' => 'vals_soc.forms.inc',
			'file path' => drupal_get_path('module', 'vals_soc') . '/includes/module/',
	);
	
	return $items;
}