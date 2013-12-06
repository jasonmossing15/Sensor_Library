/*
 * RobotSensors.h
 *
 *  Created on: Dec 5, 2013
 *      Author: C15Jason.Mossing
 */
#include <msp430.h>

#ifndef ROBOTSENSORS_H_
#define ROBOTSENSORS_H_

void initializeADC10();

unsigned int getLeftSensorValue();

unsigned int getRightSensorValue();

unsigned int getCenterSensorValue();


#endif /* ROBOTSENSORS_H_ */
