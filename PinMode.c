/*
 * PinMode.c
 *
 *  Created on: 25 may. 2021
 *      Author: danov
 */

#include "PinSetting.h"
#include "MKL25Z4.h"

void PinMode(char Port_1, int pin_number_1, int GPIO_1){

	SIM->SCGC5 = 0x3E00;//Activar todos los relojes


	if(Port_1 == 'A'){
		PORTA->PCR[pin_number_1] = 0x100;
		if(GPIO_1 == 1){
		GPIOA->PDDR |= 1<<pin_number_1;
		}else if(GPIO_1 == 0){
		GPIOA->PDDR &= ~(1<<pin_number_1);
		}
	}else if(Port_1 == 'B'){
		PORTB->PCR[pin_number_1] = 0x100;
		if(GPIO_1 == 1){
		GPIOB->PDDR |= 1<<pin_number_1;
	    }else if(GPIO_1 == 0){
		GPIOB->PDDR &= ~(1<<pin_number_1);
		}
	}else if(Port_1 == 'C'){
		PORTC->PCR[pin_number_1] = 0x100;
		if(GPIO_1 == 1){
		GPIOC->PDDR |= 1<<pin_number_1;
		}else if(GPIO_1 == 0){
		GPIOC->PDDR &= ~(1<<pin_number_1);
		}
	}else if(Port_1 == 'D'){
		PORTD->PCR[pin_number_1] = 0x100;
		if(GPIO_1 == 1){
		GPIOD->PDDR |= 1<<pin_number_1;
		}else if(GPIO_1 == 0){
		GPIOD->PDDR &= ~(1<<pin_number_1);
		}
	}else if(Port_1 == 'E'){
		PORTE->PCR[pin_number_1] = 0x100;
		if(GPIO_1 == 1){
		GPIOE->PDDR |= 1<<pin_number_1;
		}else if(GPIO_1 == 0){
		GPIOE->PDDR &= ~(1<<pin_number_1);
		}
	}
}





/*
	switch(Port_1){

	case: 'A'
	{
		  PORTA->PCR[pin_number_1] = 0x100;

    break;
	}

	case: 'B'
		{
			  PORTB->PCR[pin_number_1] = 0x100;

	    break;
		}
	case: 'C'
		{
			  PORTC->PCR[pin_number_1] = 0x100;

	    break;
		}

	case: 'D'
		{
			  PORTD->PCR[pin_number_1] = 0x100;

	    break;
		}

	case: 'E'
		{
			  PORTE->PCR[pin_number_1] = 0x100;

	    break;
		}
}

}


		GPIOB->PDDR = 1<<18;

		GPIOB->PDOR = 1<<18;

*/



