<?php 
define('_SITE_ADMIN_ROLE', 7);
define('_TUTOR_ROLE', 6);
define('_MENTOR_ROLE', 5);
define('_STUDENT_ROLE', 4);
define('_ADMIN_ROLE', 3);
define('_USER_ROLE', 2);
define('_ANONYMOUS_ROLE', 1);

/**
 * Function to create the custom roles needed in drupal for the summer of code programme.
 */
function create_roles(){
	$roles = get_default_roles();
	// Call the array with your default roles.
	foreach ($roles as $value) {
		// Check that a role is not already returned.
		if (!user_role_load_by_name($value)) {
			$role = new stdClass(); // create your Class
			// Match values to the role Class.
			$role->name = $value['name'];
			$role->weight = $value['weight'];
			// Save the Role using Drupal's API.
			user_role_save($role);
		}
	}
}


/**
 * Create codes
 */
function create_codes(){
	$roles = get_default_roles();
	// Call the array with your default roles.
	foreach ($roles as $key=> $value) {
		// Check that a role is not already returned.
		if ($key !== 'Organization Administrator') {
			db_insert('soc_codes')
			->fields(array(
			'type' => $value['name'],
			'code' => $value['code'],
			))->execute();
		}
	}
}


/**
 * Function which defines a set of roles and returns them in an array.
 * @return multitype:multitype:string
 */
function get_default_roles() {
	$roles = array();
	$roles['Organization Administrator'] = array(
			'name' => 'Organization Administrator',
			'weight' => '3',
			'code' => 'AHGLL765OW'
	);
	$roles['Academic Supervisor'] = array(
			'name' => 'Academic Supervisor',
			'weight' => '4',
			'code' => 'MNUFD783SF'
	);
	$roles['Mentor'] = array(
			'name' => 'Mentor',
			'weight' => '5',
			'code' => 'QTU8TR44KJ'
	);
	$roles['Student'] = array(
			'name' => 'Student',
			'weight' => '6',
			'code' => 'PGI99OPAQW'
	);
	return $roles;
}

/*
 * TODO - REFINE ROLES and ACCESS per role instance
*
* THIS IS HOW TO SET PERMISSIONS ON A ROLE
*
// Role to grant the permissions to
$editor_role = user_role_load_by_name('editor');
$editor_rid = $editor_role->rid;
// Define our 'editor' role permissions
$editor_permissions = array(
		'administer blocks' => TRUE, // Grant permission
		'access dashboard' => FALSE, // Revoke permission
		..., // more permissions' name
);
// Grant permissions to our 'editor' role
user_role_change_permissions($editor_rid, $editor_permissions);
*/