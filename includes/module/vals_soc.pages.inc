<?php 
module_load_include('inc', 'vals_soc', 'includes/vals_soc.helper');

/**
 * Callback for the admin overview page
 * @return string
 */
function vals_soc_timeline_admin_overview_page() {
	return '<p>'.get_vals_version().'@<a href="./vals_soc/program_settings">Program settings</a></p>';
}

/**
 * Callback for the Program settings page
 * @return string
 */
function vals_soc_timeline_admin_program_page() {
	$txt = '<p>'.get_vals_version().'@<a href="./program_settings/timeline">Edit Timeline</a></p>';
	$txt .= '<p>'.get_vals_version().'@<a href="./program_settings/messages">Edit Messages</a></p>';
	return $txt;
}
