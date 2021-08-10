/*
 * ADC.c
 *
 *  Created on: 22 jun. 2021
 *      Author: danov
 */


#include "MKL25Z4.h"
#include "DISPLAY_DRIVER.h"

void ADC0_init8b(void);
void ADC_read8b(unsigned char channelNumber);
//void Delay(long n);

void ADC0_init8b(void)
{
	SIM->SCGC6 = 0x8000000; //RELOJ ADC0

	SIM->SCGC5 = 0x3E00; //ACTIVO TODOS LOS PUERTOS DE RELOJ POR SI ACASO

	PORTB->PCR[0] |= PORT_PCR_MUX(0);// PORTB0

	ADC0->CFG1 = 0x70; // 8 BITS (0x76 10 BITS)

	ADC0->CFG1 |= (ADC_CFG1_ADLPC(1)); //Configuración ADLPC (Low power confuguration)

	ADC0->SC1[0] = ADC_SC1_ADCH(31);//ADC connections/channel assignment
}
void ADC_read8b(unsigned char channelNumber){//temperature


	unsigned short I;

	ADC0->SC1[0] = channelNumber & ADC_SC1_ADCH_MASK;

	while(ADC0->SC2 & ADC_SC2_ADACT_MASK);
	while(!(ADC0->SC1[0] & ADC_SC1_COCO_MASK));// Conversion complete flag
	I = ADC0->R[0];
Delay(0xFFFF);

}
