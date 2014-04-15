<?php
module_load_include('inc', 'vals_soc', 'includes/install/vals_soc.roles');
$role = getRole();
//if (isset($_POST['op'])){
//    print_r($_POST);
//}
//echo '<BR>In admin.php: I am a '.$role;
switch ($role){
    case 'administrator':
        echo '<h2>'.t('Administer the groups, institutes and organisations').'</h2>';
        $f1 = drupal_get_form('vals_soc_organisation_form');
        print drupal_render($f1);
    break;
    case 'supervisor':
        echo '<h2>'.t('Add a group to your list of groups').'</h2>';
        $f2 = drupal_get_form('vals_soc_group_form');
        print drupal_render($f2);
    break;
    case 'institute_admin':
        echo '<h2>'.t('Add your institute').'</h2>';
        $f3 = drupal_get_form('vals_soc_institute_form');
        print drupal_render($f3);
    break; 
    case 'organisation_admin':
        echo '<h2>'.t('Add your organisation').'</h2>';
        $f4 = drupal_get_form('vals_soc_organisation_form');
        print drupal_render($f4);
    break; 
}