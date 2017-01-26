/*
 * MotorBalancer.cpp
 *
 *  Created on: Feb 27, 2016
 *      Author: 4917
 */

#include <Components/MotorBalancer.h>

MotorBalancer::MotorBalancer() {
	difference = 0;
}

#include <iostream>
void MotorBalancer::PIDWrite(double output) {
	difference = output;
	printf( "Motor Power = %f\n", difference );
}
double MotorBalancer::GetDifference() {
	return difference/5; //always equal to 0
}

void MotorBalancer::Reset() {
	difference = 0;
}
