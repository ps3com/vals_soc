<?php 

/**
 * Returns the module version as defined in the .info file for this module
 * @return unknown
 */
function get_vals_version(){
	$info_data = system_get_info('module', 'vals_soc');
	return $info_data['version'];
}

/**
 * This was originally in .module - but is never called - we should remove if not used
 * Custom content function.
 *
 * Set beginning and end dates, retrieve posts from database
 * saved in that time period.
 *
 * @return
 *   A result set of the targeted posts.
 */
function vals_soc_contents(){
	//Get today's date.
	//  $today = getdate();
	//  //Calculate the date a week ago.
	//  $start_time = mktime(0, 0, 0,$today['mon'],($today['mday'] - 7), $today['year']);
	//  //Get all posts from one week ago to the present.
	//  $end_time = time();
	//  //Use Database API to retrieve current posts.
	//  $query = db_select('node', 'n')
	//    ->fields('n', array('nid', 'title', 'created'))
	//    ->condition('status', 1) //Published.
	//    ->condition('created', array($start_time, $end_time), 'BETWEEN')
	//    ->orderBy('created', 'DESC') //Most recent first.
	//    ->execute();
	return array();
}