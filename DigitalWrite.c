/*
 * DigitalWrite.c
 *
 *  Created on: 27 may. 2021
 *      Author: danov
 */

#include "PinSetting.h"
#include "MKL25Z4.h"

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
