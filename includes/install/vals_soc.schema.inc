<?php 

function vals_soc_schema_handler() {
	// NOTE: {variable} needs to be created before all other tables, as
	// some database drivers, e.g. Oracle and DB2, will require variable_get()
	// and variable_set() for overcoming some database specific limitations.

	$schema['soc_projects'] = array(
			'description' => 'The table of the projects',
			'fields' => array(
					'pid' => array(
							'description' => 'Project id.',
							'type' => 'varchar',
							'length' => 255,
							'not null' => TRUE,
							'default' => '',
					),
					'title' => array(
							'description' => 'The title of the project.',
							'type' => 'varchar',
							'length' => 255,
							'not null' => TRUE,
							'default' => '',
					),
					'description' => array(
							'description' => 'The description of the project.',
							'type' => 'varchar',
							'length' => 255, // TODO perhaps change this to another data type
							'not null' => FALSE,
							'default' => '',
					),
					'selected' => array(
							'description' => 'Whether the project is chosen by a student',
							'type' => 'int',
							'size' => 'tiny',
							'not null' => TRUE,
							'default' => 0,
					),
			),
			'primary key' => array('pid'),
	);
	$schema['soc_codes'] = array(
			'description' => 'Create some random codes so that not just anybody can register.',
			'fields' => array(
					'type' => array(
							'description' => 'The type of user.',
							'type' => 'varchar',
							'length' => 128,
							'not null' => TRUE,
							'default' => '',
					),
					'code' => array(
							'description' => 'The code to enter at registration.',
							'type' => 'varchar',
							'length' => 10,
							'not null' => TRUE,
							'default' => '',
					),
			),
			'primary key' => array('type'),
	);

	return $schema;
}