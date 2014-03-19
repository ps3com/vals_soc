<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
class Project {
    private $title = 'Dummy project title';
    
    public function showProject($project='', $echo=TRUE){
        $s = '';
        if (!$project) {
            $s = $this->title;
        }
    }
}
