<?php 

/**
 * Returns the module version as defined in the .info file for this module
 * @return unknown
 */
function get_vals_version(){
	$info_data = system_get_info('module', 'vals_soc');
	return $info_data['version'];
}

function vals_soc_handle_test_emails($to){

	$message = drupal_mail('vals_soc', 'vals_soc_email_accepted_organization', $to, language_default());
	if (!empty($message['result'])) {
		drupal_set_message("Mail sent!");
	}
	$message = drupal_mail('vals_soc', 'vals_soc_email_rejected_organization', $to, language_default());
	if (!empty($message['result'])) {
		drupal_set_message("Mail sent!");
	}
	$message = drupal_mail('vals_soc', 'vals_soc_email_mentor_welcome', $to, language_default());
	if (!empty($message['result'])) {
		drupal_set_message("Mail sent!");
	}
	$message = drupal_mail('vals_soc', 'vals_soc_email_student_welcome', $to, language_default());
	if (!empty($message['result'])) {
		drupal_set_message("Mail sent!");
	}
	$message = drupal_mail('vals_soc', 'vals_soc_accepted_students', $to, language_default());
	if (!empty($message['result'])) {
		drupal_set_message("Mail sent!");
	}
	$message = drupal_mail('vals_soc', 'vals_soc_rejected_students', $to, language_default());
	if (!empty($message['result'])) {
		drupal_set_message("Mail sent!");
	}
}