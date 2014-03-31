<?php

class Timeline {

	private static $instance;
	private $cached_program_active;
	private $cached_program_start_date;
	private $cached_program_end_date;
	private $cached_org_signup_start_date;
	private $cached_org_signup_end_date;
	private $cached_accepted_org_announced_date;
	private $cached_student_signup_start_date;
	private $cached_student_signup_end_date;
	private $cached_org_review_student_applications_date;
	private $cached_students_matched_to_mentors_deadline_date;
	private $cached_accepted_students_announced_deadline_date;
	private $cached_students_start_submit_forms_date;

	private function __construct(){
		$this->fetchDatesFromDB();
	}

	public static function getInstance(){
		if (is_null ( self::$instance )){
			self::$instance = new self ();
		}
		return self::$instance;
	}

	private function fetchDatesFromDB(){
		$this->cached_program_active = variable_get('vals_timeline_program_active', 0);
		$this->sanityCheck($this->cached_program_start_date, variable_get('vals_timeline_program_start_date'));
		$this->sanityCheck($this->cached_program_end_date, variable_get('vals_timeline_program_end_date'));
		$this->sanityCheck($this->cached_org_signup_start_date, variable_get('vals_timeline_org_app_start_date')); 
		$this->sanityCheck($this->cached_org_signup_end_date, variable_get('vals_timeline_org_app_end_date'));
		$this->sanityCheck($this->cached_accepted_org_announced_date, variable_get('vals_timeline_accepted_org_announced_date'));
		$this->sanityCheck($this->cached_student_signup_start_date, variable_get('vals_timeline_student_signup_start_date'));
		$this->sanityCheck($this->cached_student_signup_end_date, variable_get('vals_timeline_student_signup_end_date'));
		$this->sanityCheck($this->cached_org_review_student_applications_date, variable_get('vals_timeline_org_review_student_applications_date'));
		$this->sanityCheck($this->cached_students_matched_to_mentors_deadline_date, variable_get('vals_timeline_students_matched_to_mentors_deadline_date'));
		$this->sanityCheck($this->cached_accepted_students_announced_deadline_date, variable_get('vals_timeline_accepted_students_announced_deadline_date'));
		$this->sanityCheck($this->cached_students_start_submit_forms_date, variable_get('vals_timeline_students_start_submit_forms_date'));
	}

	private function sanityCheck(&$localCache, $value){
		if(isset($value) && $this->validateDate($value)){
			$localCache = new DateTime($value);
		}
		else{
			// TODO - what do we do when these are not set.
			//for now we'll just drop NOW in there.
			$localCache = new DateTime();
		}
	}
	
	
	private function validateDate($date){
		$d = DateTime::createFromFormat('Y-m-d H:i', $date);
		return $d && $d->format('Y-m-d H:i') == $date;
	}
	
	public function getOrgsSignupStartDate(){
		return $this->cached_org_signup_start_date;
	}
	
	public function getOrgsSignupEndDate(){
		return $this->cached_org_signup_end_date;
	}
	
	public function getStudentsSignupStartDate(){
		return $this->cached_student_signup_start_date;
	}
	
	public function getStudentsSignupEndDate(){
		return $this->cached_student_signup_end_date;
	}
	
	public function isProgramActive(){
		return $this->cached_program_active;
	}
	
	public function getOrgsAnnouncedDate(){
		return $this->cached_accepted_org_announced_date;
	}
	
	public function isOrganisationSignupPeriod(){
		$now = new DateTime();
		if($this->cached_org_signup_start_date < $now && $this->cached_org_signup_end_date > $now){
			return true;
		}
		return false;
	}

	public function isStudentsSignupPeriod(){
		$now = new DateTime();
		if($this->cached_student_signup_start_date < $now && $this->cached_student_signup_end_date > $now){
			return true;
		}
		return false;
	}
	
	public function hasProgramStarted(){
		if($this->cached_program_start_date < new DateTime()){
			return true;
		}
		return false;
	}
	
	public function hasProgramFinished(){
		if($this->cached_program_end_date > new DateTime()){
			return true;
		}
		return false;
	}
	
	public function getProgramStartDate(){
		return $this->cached_program_start_date;
	}
	

	public function resetCache(){
		$this->fetchDatesFromDB();
	}

	function __destruct() {}
}