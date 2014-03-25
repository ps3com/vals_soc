<?php 

/**
 * Handle mail requests
 * @param unknown $key
 * @param unknown $message
 * @param unknown $params
 */
function vals_soc_mail_handler($key, &$message, $params) {
	switch($key) {
		case 'vals_soc_email_accepted_organization':
			$message['subject'] = t('Organization application for VALS summer of code');
			$message['body'][] = variable_get('vals_accepted_organizations_message')['value'];
			if (isset($params['headers']) && is_array($params['headers'])) {
				$message['headers'] += $params['headers'];
			}
			break;

		case 'vals_soc_email_rejected_organization':
			$message['subject'] = t('Organization application for VALS summer of code');
			$message['body'][] = variable_get('vals_rejected_organizations_message')['value'];
			break;

		case 'vals_soc_email_mentor_welcome':
			$message['subject'] = t('Welcome mentor to the VALS summer of code');
			$message['body'][] = variable_get('vals_mentor_welcome_message')['value'];
			break;

		case 'vals_soc_email_student_welcome':
			$message['subject'] = t('Welcome student to the VALS summer of code');
			$message['body'][] = variable_get('vals_student_welcome_message')['value'];
			break;

		case 'vals_soc_accepted_students':
			$message['subject'] = t('Your project proposal to the VALS summer of code');
			$message['body'][] = variable_get('vals_accepted_students_message')['value'];
			break;

		case 'vals_soc_rejected_students':
			$message['subject'] = t('Your project proposal to the VALS summer of code');
			$message['body'][] = variable_get('vals_rejected_students_message')['value'];
			break;
	}
}

/**
 * Add params to a messages header
 * TODO - not quite working yet!
 * @param unknown $message
 */
function vals_soc_mail_alter_handler(&$message) {
	$headers = array(
		'MIME-Version' => '1.0',
		'Content-Type' => 'text/html; charset=iso-8859-1; format=flowed',
		'Content-Transfer-Encoding' => '8Bit',
		'X-Mailer' => 'Drupal',
	);
	foreach ($headers as $key => $value) {
		$message['headers'][$key] = $value;
	}
}

/**
 * 
 * @param $to - user email to send the test mails to
 */
function vals_soc_handle_test_emails($to){
	$mail_results='';
	$message = drupal_mail('vals_soc', 'vals_soc_email_accepted_organization', $to, language_default());
	if (!empty($message['result'])) {		
		$mail_results .= 'accepted organization mail sent<br/>';
	}
	$message = drupal_mail('vals_soc', 'vals_soc_email_rejected_organization', $to, language_default());
	if (!empty($message['result'])) {
		$mail_results .= 'rejected organization mail sent<br/>';
	}
	$message = drupal_mail('vals_soc', 'vals_soc_email_mentor_welcome', $to, language_default());
	if (!empty($message['result'])) {
		$mail_results .= 'mentor welcome mail sent<br/>';
	}
	$message = drupal_mail('vals_soc', 'vals_soc_email_student_welcome', $to, language_default());
	if (!empty($message['result'])) {
		$mail_results .= 'student welcome mail sent<br/>';
	}
	$message = drupal_mail('vals_soc', 'vals_soc_accepted_students', $to, language_default());
	if (!empty($message['result'])) {
		$mail_results .= 'accepted students mail sent<br/>';
	}
	$message = drupal_mail('vals_soc', 'vals_soc_rejected_students', $to, language_default());
	if (!empty($message['result'])) {
		$mail_results .= 'rejected students mail sent<br/>';
	}
	drupal_set_message($mail_results);
}