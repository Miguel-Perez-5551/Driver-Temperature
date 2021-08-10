/*
 * DigitalRead.c
 *
 *  Created on: 27 may. 2021
 *      Author: danov
 */


#include "PinSetting.h"
#include "MKL25Z4.h"

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
