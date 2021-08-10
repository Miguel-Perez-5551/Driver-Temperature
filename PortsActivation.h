/*
 * PortsActivation.h
 *
 *  Created on: 22 jun. 2021
 *      Author: danov
 */

#ifndef PORTSACTIVATION_H_
#define PORTSACTIVATION_H_

extern void PinMode(char Port_1, int pin_number_1, int GPIO_1);
extern void DigitalWrite(char Port_2, int pin_number_2, int GPIO_2);
extern int DigitalRead(char Port_3, int pin_number_3);

//#define A			0
//#define B			1
//#define C			2
//#define D			3
//#define E			4

//#define INPUT	    0
//#define OUTPUT	1

#define OFF	0
#define ON	1

#endif /* PORTSACTIVATION_H_ */
