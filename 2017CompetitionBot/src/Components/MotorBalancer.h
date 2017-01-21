/*
 * MotorBalancer.h
 *
 *  Created on: Feb 27, 2016
 *      Author: 4917
 */

#ifndef SRC_COMPONENTS_MOTORBALANCER_H_
#define SRC_COMPONENTS_MOTORBALANCER_H_

#include <PIDOutput.h>

class MotorBalancer: public frc::PIDOutput {
private:
	float difference;
public:
	MotorBalancer();
	void PIDWrite(double output);
	float GetDifference();
	void Reset();
};

#endif /* SRC_COMPONENTS_MOTORBALANCER_H_ */
