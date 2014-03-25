<?php 
//require_once('vals_soc.helper.inc');
module_load_include('inc', 'vals_soc', 'includes/install/vals_soc.roles');

/**
 * Form to edit the programme email messages
 * @param unknown $form
 * @param unknown $form_state
 */
function vals_soc_admin_messages_form($form, $form_state){
	$accepted_orgs_prev_input = variable_get('vals_accepted_organizations_message',
			array('value'=>'Complete this section', 'format' => 'full_html'));
	$form['vals_accepted_organizations_message'] = array(
		'#type' => 'text_format',
		'#base_type' => 'textarea',
		'#title' => t('Accepted organizations message'),		
		'#default_value' => $accepted_orgs_prev_input['value'],
		'#suffix' => '<p></p>',
	);
	
	$rejected_orgs_prev_input = variable_get('vals_rejected_organizations_message',
			array('value'=>'Complete this section', 'format' => 'full_html'));
	$form['vals_rejected_organizations_message'] = array(
		'#type' => 'text_format',
		'#base_type' => 'textarea',
		'#title' => t('Rejected organizations message'),
		'#default_value' => $rejected_orgs_prev_input['value'],
		'#suffix' => '<p></p>',
	);
	
	$mentor_welcome_prev_input = variable_get('vals_mentor_welcome_message',
			array('value'=>'Complete this section', 'format' => 'full_html'));
	$form['vals_mentor_welcome_message'] = array(
		'#type' => 'text_format',
		'#base_type' => 'textarea',
		'#title' => t('Mentor welcome message'),
		'#default_value' => $mentor_welcome_prev_input['value'],
		'#suffix' => '<p></p>',
	);
	
	$student_welcome_prev_input = variable_get('vals_student_welcome_message',
			array('value'=>'Complete this section', 'format' => 'full_html'));
	$form['vals_student_welcome_message'] = array(
		'#type' => 'text_format',
		'#base_type' => 'textarea',
		'#title' => t('Student welcome message'),
		'#default_value' => $student_welcome_prev_input['value'],
		'#suffix' => '<p></p>',
	);
	
	$accepted_students_prev_input = variable_get('vals_accepted_students_message',
			array('value'=>'Complete this section', 'format' => 'full_html'));
	$form['vals_accepted_students_message'] = array(
		'#type' => 'text_format',
		'#base_type' => 'textarea',
		'#title' => t('Accepted students message'),
		'#default_value' => $accepted_students_prev_input['value'],
		'#suffix' => '<p></p>',
	);
	
	$rejected_students_prev_input = variable_get('vals_rejected_students_message',
			array('value'=>'Complete this section', 'format' => 'full_html'));
	$form['vals_rejected_students_message'] = array(
		'#type' => 'text_format',
		'#base_type' => 'textarea',
		'#title' => t('Rejected students message'),
		'#default_value' => $rejected_students_prev_input['value'],
		'#suffix' => '<p></p>',
	);
	
	$form['vals_messages_test_email'] = array(
		'#type' => 'textfield',
		'#title' => t('Test email address'),
		'#default_value' => '', // dont store this
		'#size' => 60,
		'#maxlength' => 128,
		'#required' => FALSE,
		'#prefix' => '',
		'#suffix' => '<div>' .t('Email address to which test messages must be sent. If provided, a test email is sent for each of the messages on this page to the given address').'.</div>',		
	);
	
	$form['#validate'][] = 'vals_soc_admin_messages_form_validate';
	$form['#submit'][] = 'vals_soc_admin_messages_form_submit';
	return system_settings_form($form);
}


/**
 * A validation routine for the admin messages form which checks that if
 * an email address was entered, it is parsed and checked to try to ascertain
 * if it is valid or not.
 * @param unknown $form
 * @param unknown $form_state
 */
function vals_soc_admin_messages_form_validate($form, $form_state) {
	if (!empty($form_state['values']['vals_messages_test_email'])){
		$mail = $form_state['values']['vals_messages_test_email'];
		if (!valid_email_address($mail)) {
			form_set_error('vals_messages_test_email', t('Please Enter a valid email address or leave blank'));
		}
	}
}

/**
 * Function to call the test email function on form submission
 * @param unknown $form
 * @param unknown $form_state
 */
function vals_soc_admin_messages_form_submit($form, $form_state) {
	// fire off our test email handler
	if (!empty($form_state['values']['vals_messages_test_email'])){
		drupal_set_message(t('Sending test emails to ').  $form_state['values']['vals_messages_test_email'] ."");
		module_load_include('inc', 'vals_soc', 'includes/module/vals_soc.mail');
		vals_soc_handle_test_emails($form_state['values']['vals_messages_test_email']);
	}
}


/**
 * Form to edit the timeline
 * @param unknown $form
 * @param unknown $form_state
 */
function vals_soc_admin_timeline_form($form, &$form_state){
	$form['vals_timeline_program_active'] = array(
			'#type' => 'checkbox',
			'#title' => t('Enable program'),
			'#default_value' => variable_get('vals_timeline_program_active', 0),
	);
	
	$form['vals_timeline_program_start_date'] = array(
			'#type' => 'date_popup',
			'#date_format' => 'Y-m-d H:i',
			'#title' => t('Program start date'),
			'#default_value' => variable_get('vals_timeline_program_start_date', ''),
	);
	
	$form['vals_timeline_program_end_date'] = array(
			'#type' => 'date_popup',
			'#date_format' => 'Y-m-d H:i',
			'#title' => t('Program end date'),
			'#default_value' => variable_get('vals_timeline_program_end_date', ''),
	);
	
	$form['vals_timeline_accepted_org_announced_date'] = array(
			'#type' => 'date_popup',
			'#date_format' => 'Y-m-d H:i',
			'#title' => t('Accepted organizations announced deadline'),
			'#default_value' => variable_get('vals_timeline_accepted_org_announced_date', ''),
	);
	
	$form['vals_timeline_student_signup_start_date'] = array(
			'#type' => 'date_popup',
			'#date_format' => 'Y-m-d H:i',
			'#title' => t('Student signup start date'),
			'#default_value' => variable_get('vals_timeline_student_signup_start_date', ''),
	);
	
	$form['vals_timeline_student_signup_end_date'] = array(
			'#type' => 'date_popup',
			'#date_format' => 'Y-m-d H:i',
			'#title' => t('Student signup end date'),
			'#default_value' => variable_get('vals_timeline_student_signup_end_date', ''),
	);

	$form['vals_timeline_org_review_student_applications_date'] = array(
			'#type' => 'date_popup',
			'#date_format' => 'Y-m-d H:i',
			'#title' => t('Organizations review student applications deadline'),
			'#default_value' => variable_get('vals_timeline_org_review_student_applications_date', ''),
	);
	
	$form['vals_timeline_students_matched_to_mentors_deadline_date'] = array(
			'#type' => 'date_popup',
			'#date_format' => 'Y-m-d H:i',
			'#title' => t('Students matched to mentors deadline'),
			'#default_value' => variable_get('vals_timeline_students_matched_to_mentors_deadline_date', ''),
	);
	
	$form['vals_timeline_accepted_students_announced_deadline_date'] = array(
			'#type' => 'date_popup',
			'#date_format' => 'Y-m-d H:i',
			'#title' => t('Accepted students announced deadline'),
			'#default_value' => variable_get('vals_timeline_accepted_students_announced_deadline_date', ''),
	);

	$form['vals_timeline_students_start_submit_forms_date'] = array(
			'#type' => 'date_popup',
			'#date_format' => 'Y-m-d H:i',
			'#title' => t('Students start submitting their forms'),
			'#default_value' => variable_get('vals_timeline_students_start_submit_forms_date', ''),
	);
	
	return system_settings_form($form);
}

/**
 * Override the login form so we can add custom elements to it
 * @param unknown $form
 * @param unknown $form_state
 * @return multitype:string number NULL
 */
function vals_soc_form_user_register_form_alter_handler(&$form, &$form_state) {
	//  if (variable_get('configurable_timezones', 1)) {
	//    if (variable_get('user_default_timezone', DRUPAL_USER_TIMEZONE_DEFAULT) == DRUPAL_USER_TIMEZONE_SELECT) {
	//      system_user_timezone($form, $form_state);
	//    }
	//    else {
	$form['account']['account_type'] = array(
			"#type" => "select",
			"#title" => t("What is your role"),
			//"#default_value" => 0,//variable_get('user_default_role', _ANONYMOUS_ROLE),
			"#options" => array(
					_STUDENT_ROLE => t("Student"),
					_TUTOR_ROLE => t("Supervisor"),
					_MENTOR_ROLE => t("Mentor"),
			),
			"#description" => t("Select your role in Semester of Code."),
	);

	$form['account']['account_key'] = array(
			"#type" => "textfield",
			"#title" => t("Type the key you got from the admin"),
			"#size" => 10,
			"#description" => t("This code is different per role."),
	);

	return $form;
	// }
}
