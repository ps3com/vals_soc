<?php
module_load_include('inc', 'vals_soc', 'includes/install/vals_soc.roles');
/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
function getRoles(){
    global $user;
    
    if (isset($user)){
        return $user->roles;
    } else {
        return array();
    }
}

function getRole(){
    $roles = getRoles();
    if ($roles) { 
        foreach ($roles as $rid => $name){
            if ($rid == _ANONYMOUS_ROLE ){
                return 'anonymous user';
            } elseif ($rid !== _USER_ROLE) {
                return $name;
            }
        }
        return 'authenticated user';
    }
}
$role = getRole();
echo ' Ik ben nu een '.$role;
echo "nu gaan we de current stage bepalen. Het is: ".getCurrentStage();
echo "we kijken nu naar de reminders<hr>";
print_r( getReminders(1));

function getReminders($stage_id=1){
	/*
    $x = db_select('soc_reminder_schedule', 'sch');
    $x->join('soc_reminder_text', 'text', "sch.reminder_id = text.reminder_id");
    $x->fields('sch', array('stage_id', 'user_type'))
        ->fields('text', array('reminder_id', 'reminder_user_type', 'reminder_subject', 'reminder_text'))
        ->condition('stage_id', $stage_id);

    $result = $x->execute()->fetchAll();
    return $result;
    */
	return 'getreminders';
}

function getCurrentStage(){
	/*
    $today_str = date('y-m-d');
    $result = db_query("SELECT stage FROM {soc_timeline} WHERE start_date <= '$today_str' AND end_date >= '$today_str'");
    
    $result2 = $result->fetchAll();
    if ($result2){
        return $result2[0]->stage;
    }
    */
    return '';
}