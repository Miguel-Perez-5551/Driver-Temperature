/*
 * Ports_Activation.c
 *
 *  Created on: 22 jun. 2021
 *      Author: danov
 */


#include "PortsActivation.h"
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
//////////////////////////////////////////////////////////////////////////////////////////

void DigitalWrite(char Port_2, int pin_number_2, int GPIO_2){


	if(Port_2 == 'A'){
		if(GPIO_2 == 1){
		GPIOA->PDOR |= 1<<pin_number_2;
		}else if(GPIO_2 == 0){
		GPIOA->PDOR &= ~(1<<pin_number_2);
		}
	}else if(Port_2 == 'B'){
		if(GPIO_2 == 1){
		GPIOB->PDOR |= 1<<pin_number_2;
	    }else if(GPIO_2 == 0){
		GPIOB->PDOR &= ~(1<<pin_number_2);
		}
	}else if(Port_2 == 'C'){
		if(GPIO_2 == 1){
		GPIOC->PDOR |= 1<<pin_number_2;
		}else if(GPIO_2 == 0){
		GPIOC->PDOR &= ~(1<<pin_number_2);
		}
	}else if(Port_2 == 'D'){
		if(GPIO_2 == 1){
		GPIOD->PDOR |= 1<<pin_number_2;
		}else if(GPIO_2 == 0){
		GPIOD->PDOR &= ~(1<<pin_number_2);
		}
	}else if(Port_2 == 'E'){
		if(GPIO_2 == 1){
		GPIOE->PDOR |= 1<<pin_number_2;
		}else if(GPIO_2 == 0){
		GPIOE->PDOR &= ~(1<<pin_number_2);
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////

int DigitalRead(char Port_3, int pin_number_3){

	int r=0;

	if(Port_3 == 'A'){
  r  =	 (GPIOA->PDIR & (1<<pin_number_3));
	}else if(Port_3 == 'B'){
  r  =	 (GPIOB->PDIR & (1<<pin_number_3));
    }else if(Port_3 == 'C'){
  r  =	 (GPIOC->PDIR & (1<<pin_number_3));
	}else if(Port_3 == 'D'){
  r  =	 (GPIOD->PDIR & (1<<pin_number_3));
    }else if(Port_3 == 'E'){
  r  =	 (GPIOE->PDIR & (1<<pin_number_3));
	}

	return r;

}
