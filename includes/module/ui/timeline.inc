<?php 
echo '<hr/>';
module_load_include('php', 'vals_soc', 'includes/classes/Timeline');
drupal_add_js(drupal_get_path('module', 'vals_soc') .'/includes/js/countdown/jquery.plugin.js');
drupal_add_js(drupal_get_path('module', 'vals_soc') .'/includes/js/countdown/jquery.countdown.js');
drupal_add_css(drupal_get_path('module', 'vals_soc') . '/includes/vals_soc.css');

function generateCountdown($dTime){
	if(!empty($dTime)){
	return '
		<script>
			jQuery(document).ready(function($){
			var austDay = new Date();
			// note month in js is oddly 0-11 based rather than 1-12
			austDay = new Date('.$dTime->format('Y,m-1,d,H,i,s').');
			$("#vals-timeline-countdown").countdown({until: austDay});
			});
		</script>
		<div id="vals-timeline-countdown"></div>
		<div id="vals-timeline-countdown-footer">Remaining</div>';
	}
	return '';
}


function getLayout($timeline_period_header, $timeline_period, $timeline_deadline, $timeline_clock){
	return '
	<div id="vals-timeline-wrapper">
		<div id="vals-timeline-header">'
			.t('Timeline').
		'</div>
		<div id="vals-timeline-body">
			<div id="vals-timeline-period-header">'.$timeline_period_header.'</div>
			<div id="vals-timeline-period">'.$timeline_period.'</div>
			<div id="vals-timeline-icon"></div>
			<div id="vals-timeline-deadline">'.$timeline_deadline.'</div>
			<div id="vals-timeline-clock">'.
				generateCountdown($timeline_clock).
			'</div>
		</div>
	</div>';
}

function generateTimelineOutput(){
	$now = new DateTime();
	$timeline_period_header = "";
	$timeline_period = "";
	$timeline_deadline = "";
	$timeline_clock = null;
	// Is there is an active program
	if(Timeline::getInstance()->isProgramActive()){
		// has it started?
		if(Timeline::getInstance()->hasProgramStarted()){
			// its started so where are we?
			if(Timeline::getInstance()->getOrgsSignupStartDate() > $now){
				// programme is running but orgs cant register yet
				$timeline_period_header = t('Organisation applications soon');
				$timeline_period = Timeline::getInstance()->getOrgsSignupStartDate()->format('F j, Y');
				$timeline_period .= ' - ';
				$timeline_period .= Timeline::getInstance()->getOrgsSignupEndDate()->format('F j, Y');
				$timeline_deadline = t('Org Application opens:'). '<br/>' . Timeline::getInstance()->getOrgsSignupStartDate()->format('F j, Y, g:i a');
				$timeline_clock = Timeline::getInstance()->getOrgsSignupStartDate();
			}
			else if(Timeline::getInstance()->isOrganisationSignupPeriod()){
				// programme is running orgs can now register 
				$timeline_period_header = t('Organisation applications');
				$timeline_period = Timeline::getInstance()->getOrgsSignupStartDate()->format('F j, Y');
				$timeline_period .= ' - ';
				$timeline_period .= Timeline::getInstance()->getOrgsSignupEndDate()->format('F j, Y');
				$timeline_deadline = t('Org Application closes:'). '<br/>' . Timeline::getInstance()->getOrgsSignupEndDate()->format('F j, Y, g:i a');
				$timeline_clock = Timeline::getInstance()->getOrgsSignupEndDate();
			}
			else if(Timeline::getInstance()->getStudentsSignupStartDate() > $now){
				// before student applications start
				$timeline_period_header = t('Student applications soon');
				$timeline_period = Timeline::getInstance()->getStudentsSignupStartDate()->format('F j, Y');
				$timeline_period .= ' - ';
				$timeline_period .= Timeline::getInstance()->getOrgsSignupEndDate()->format('F j, Y');
				$timeline_deadline = t('Student Application opens:'). '<br/>' . Timeline::getInstance()->getStudentsSignupStartDate()->format('F j, Y, g:i a');
				$timeline_clock = Timeline::getInstance()->getStudentsSignupStartDate();
			}
			else if(Timeline::getInstance()->isStudentsSignupPeriod()){
				// student registration period
				$timeline_period_header = t('Student applications');
				$timeline_period = Timeline::getInstance()->getStudentsSignupStartDate()->format('F j, Y');
				$timeline_period .= ' - ';
				$timeline_period .= Timeline::getInstance()->getStudentsSignupEndDate()->format('F j, Y');
				$timeline_deadline = t('Student Application closes:'). '<br/>' . Timeline::getInstance()->getStudentsSignupEndDate()->format('F j, Y, g:i a');
				$timeline_clock = Timeline::getInstance()->getStudentsSignupEndDate();
			}
			else{$timeline_period_header = t('TODO - finish other timeline events.'). ' NOW= '. $now->format('Y,m,d,H,i,s');}
			echo getLayout($timeline_period_header, $timeline_period, $timeline_deadline, $timeline_clock);
		}
		else{
			echo t('Programme starts ' . Timeline::getInstance()->getProgramStartDate()->format('F j, Y, g:i a'));
		}
	}
	else{
		echo t('There are currently no active programmes');
	}

}

//Build!
generateTimelineOutput();