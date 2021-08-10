/*
 * PinSetting.h
 *
 *  Created on: 25 may. 2021
 *      Author: danov
 */

#ifndef PINSETTING_H_
#define PINSETTING_H_

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

//#define PORTA_BASE	0x40049000u   (Para comenzar de ahi e ir pasando por todo el arreglo y por todos los puertos

//#define PORT(PORT)			unsigned int(PORTA_BASE) + (unsigned int)(PORT * 0x1000)
//#define PIN(PIN)            unsigned int(PORTA_BASE) + (unsigned int)(PIN + 0x4)




#endif /* PINSETTING_H_ */
