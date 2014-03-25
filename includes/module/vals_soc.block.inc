<?php 

function vals_soc_block_info_handler() {
	$blocks['soc'] = array(
			// The name that will appear in the block list.
			'info' => t('Semester of Code'),
			// Default setting.
			'cache' => DRUPAL_CACHE_PER_ROLE,
	);
	return $blocks;
}

function vals_soc_projects(){
	return array();
	$result = db_select('soc_projects');
}

function vals_soc_block_view_handler($delta = '') {
	switch ($delta) {
		case 'soc':
			$block['subject'] = t('Het inner blok');
			if (user_access('access content')) {
				// Use our custom function to retrieve data.

				//Rol uitvinden van de user die is ingelogd

				$result = vals_soc_projects();
				// Array to contain items for the block to render.
				$items = array();
				// Iterate over the resultset and format as links.
				if ($result){
					//include('includes/classes/Projects.php');
					module_load_include('php', 'vals_soc', 'includes/classes/Projects');
					$project_obj = new Project();
					foreach ($result as $project) {
						$items[] = array(
								'data' => $project_obj->show_project($project),
						);
					}
				}
				$block['content'] = '<h2>Current available projects</h2>';
				// No content in the last week.
				if (empty($items)) {
					$block['content'] .= t('No projects available yet.');
				}
				else {
					// Pass data through theme function.
					$block['content'] = theme('item_list', array('items' => $items));
				}
				ob_start();
				//include(__DIR__.'/includes/index.php');
				module_load_include('php', 'vals_soc', 'includes/module/index');
				$soc_content = ob_get_clean();
				$block['content'] = t('Here comes the content'). $soc_content;
			}
			return $block;
	}
}