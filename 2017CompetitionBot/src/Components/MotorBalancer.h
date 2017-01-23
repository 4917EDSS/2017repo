/*
 * MotorBalancer.h
 *
 *  Created on: Feb 27, 2016
 *      Author: 4917
 */

#ifndef SRC_COMPONENTS_MOTORBALANCER_H_
#define SRC_COMPONENTS_MOTORBALANCER_H_

#include <PIDOutput.h>

class MotorBalancer : public frc::PIDOutput {
private:
	double difference;
public:
	virtual ~MotorBalancer() = default;
	MotorBalancer();
	void PIDWrite(double output) override;
	double GetDifference();
	void Reset();
};

#endif /* SRC_COMPONENTS_MOTORBALANCER_H_ */
