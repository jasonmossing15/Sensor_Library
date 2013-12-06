/*
 * RobotSensors.c
 *
 *  Created on: Dec 5, 2013
 *      Author: C15Jason.Mossing
 */

#include "RobotSensors.h"

void initializeADC10(){
	//enable interrupts
	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE;
	//divide the clock cycles in order to prevent loading
	ADC10CTL1 = ADC10DIV_7;
	//set the individual pins for interrupts
	ADC10AE0 |= BIT3|BIT4|BIT5;
	//select SMCLK
	ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;
}

unsigned int getLeftSensorValue(){
	//clear ENC and INCH bits in order to change the settings
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 &= ~(INCH3|INCH2|INCH1|INCH0);
	ADC10CTL1 |= INCH_3; //set the input to be A3

	//sample and conversion
	ADC10CTL0 |= ENC + ADC10SC;
	__bis_SR_register(CPUOFF + GIE);

	return ADC10MEM;
}

unsigned int getRightSensorValue(){
	//clear ENC and INCH bits in order to change the settings
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 &= ~(INCH3|INCH2|INCH1|INCH0);
	ADC10CTL1 |= INCH_4; //set the input to be A4

	//sample and conversion
	ADC10CTL0 |= ENC + ADC10SC;
	__bis_SR_register(CPUOFF + GIE);

	return ADC10MEM;
}

unsigned int getCenterSensorValue(){
	//clear ENC and INCH bits in order to change the settings
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 &= ~(INCH3|INCH2|INCH1|INCH0);
	ADC10CTL1 |= INCH_5; //set the input to be A5

	//sample and conversion
	ADC10CTL0 |= ENC + ADC10SC;
	__bis_SR_register(CPUOFF + GIE);

	return ADC10MEM;
}


