/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
  
  this->Kpi = Kpi;
  this->Kdi = Kdi;
  this->Kii = Kii;
  this->output_lim_maxi = output_lim_maxi;
  this->output_lim_mini = output_lim_mini;
  
  this->p_error = 0.0;
  this->d_error = 0.0;
  this->i_error = 0.0;
  
  this->delta_time = 0.0;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
  
  
  
  if(this->delta_time > 0.0){
    
    this->d_error = (cte - this->p_error) / this->delta_time;
    
  } else {
    this->d_error = 0.0;

  }
  
  this->p_error = cte;
  
  this->i_error += cte * this->delta_time;
  
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
    double control = (this->Kpi*this->p_error) + (this->Kdi*this->d_error) + (this->Kii*this->i_error);
  
  	if(control > this->output_lim_maxi){
      
		return this->output_lim_maxi;
    }else if(control < this->output_lim_mini) {
		return this->output_lim_mini;
    } else {
		return control;
    }

    return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
	return this->delta_time = new_delta_time;
}