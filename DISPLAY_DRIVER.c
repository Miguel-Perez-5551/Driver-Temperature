/*
 * DISPLAY_DRIVER.c
 *
 *  Created on: 22 jun. 2021
 *      Author: danov
 */


#include "PortsActivation.h"
#include "MKL25Z4.h"
#include "DISPLAY_DRIVER.h"
#include "ADC.h"


void DPY_vfnDriverInit (void);
void DPY_bfnWriteMsg(uint8_t *bpMsgSrc, uint8_t bMsgSize);
/*
uint_8 DPY_bfnClearScreen (void);
uint_8 DPY_bfnWriteMsg (uint_8 *bpMsgSrc, uint_8 bMsgSize);
*/
void InitVar(void);
void Paso1Clear(void);
void Paso2ReturnHome(void);
void Paso3EnteryModeSet(void);
void Paso4DisplayON(void);
void Paso4DisplayOFF(void);
void Paso5Cursor(void);
void Paso6Set(void);
void WriteDatatoRam(void);
void Delay(long n);
//////////////////////////////////////////
void cero(void);
void uno(void);
void dos(void);
void tres(void);
void cuatro(void);
void cinco(void);
void seis(void);
void siete(void);
void ocho(void);
void nueve(void);
void LetraC(void);
void signogrados(void);

void DPY_vfnDriverInit (void)
{
	char i = 0;


	InitVar();
	Paso4DisplayOFF();
	Paso1Clear();
	Paso4DisplayON();
	Paso2ReturnHome();
	Paso6Set();
	//WriteDatatoRam();
	//Paso1Clear();
	//Paso4DisplayOFF();


	i++;//Para aqui
}

void DPY_bfnWriteMsg (uint8_t *bpMsgSrc, uint8_t bMsgSize)
{
	Paso1Clear();
	Paso4DisplayOFF();

	unsigned short X = 0;
		unsigned char Division = 0;
		unsigned char Modulo = 0;
		unsigned char VAR[3] = {0,0,0,0};
		unsigned char count = 0;
		void (*Num[])(void) = {cero, uno, dos, tres, cuatro, cinco, seis, siete, ocho, nueve, signogrados, LetraC};

		X = *bpMsgSrc;

	        Division = 1;

			while(Division != 0)
			{
			Modulo = X % 10;
			Division = X / 10;
			X /= 10;
			VAR[count] = Modulo;
			count++;
			}
			while(count != 0)
			{
			count--;
			(*Num[VAR[count]])();
			}

			(*Num[10])();
			(*Num[11])();

	Delay(0xFFFFF);
}
/*
uint_8 DPY_bfnClearScreen (void)
{


}
uint_8 DPY_bfnWriteMsg (uint_8 *bpMsgSrc, uint_8 bMsgSize)
{


}
*/
void InitVar()
{
	PinMode('C',11,1);//Rs
	PinMode('C',10,1);//Rw
	PinMode('C',6,1);//E
	PinMode('D',7,1);//D0
	PinMode('D',6,1);//D1
	PinMode('A',17,1);//D2
	PinMode('A',16,1);//D3
	PinMode('C',17,1);//D4
	PinMode('C',16,1);//D5
	PinMode('C',13,1);//D6
	PinMode('C',12,1);//D7
    Delay(0xFFFF);
}
void Paso1Clear()
{
	DigitalWrite('C',11,0);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E
	DigitalWrite('D', 7, 1);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7
	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 0);//D0
	Delay(0xFFFF);

}

void Paso2ReturnHome()
{
	DigitalWrite('C',11,0);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E
	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 1);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7
	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 6, 0);//D1
	Delay(0xFFFF);

}

void Paso3EnteryModeSet()
{




}

void Paso4DisplayON()
{
	DigitalWrite('C',6,1);//E
	DigitalWrite('C',11,0);//Rs LOW
	DigitalWrite('C',10,0);//Rw LOW
	DigitalWrite('C',6,1);//E
	DigitalWrite('D', 7, 1);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 1);//D2
	DigitalWrite('A', 16, 1);//D3
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7
	DigitalWrite('C',6,0);//E
	DigitalWrite('D',7,0);//D0 LOW
	DigitalWrite('A',17,0);//D2 LOW
	DigitalWrite('A',16,0);//D3 LOW
	Delay(0xFFFF);

}
void Paso4DisplayOFF()
{
	DigitalWrite('C',6,1);//E
	DigitalWrite('C',11,0);//Rs LOW
	DigitalWrite('C',10,0);//Rw LOW
	DigitalWrite('C',6,1);//E
	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 1);//D2
	DigitalWrite('A', 16, 1);//D3
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7
	DigitalWrite('C',6,0);//E
	DigitalWrite('A',17,0);//D2 LOW
	DigitalWrite('A',16,0);//D3 LOW
	Delay(0xFFFF);

}

void Paso5Cursor()
{




}

void Paso6Set()
{
	DigitalWrite('C',11,0);//Rs LOW
	DigitalWrite('C',10,0);//Rw LOW
	DigitalWrite('C',6,1);//E
	DigitalWrite('D',7,0);//D0 Indiferente
	DigitalWrite('D',6,0);//D1 Indiferente
	DigitalWrite('A',17,0);//D2 HIGH = cuadricula de 5x11 LOW = cuadricula de 5x8
	DigitalWrite('A',16,1);//D3 HIGH = 2-Line LOW = 1-Line
	DigitalWrite('C',17,1);//D4 HIGH = 8-Bits LOW = 4-Bits
	DigitalWrite('C',16,1);//D5 Set
	DigitalWrite('C',13,0);//D6 LOW
	DigitalWrite('C',12,0);//D7 LOW
	DigitalWrite('C',6,0);//E HIGH (Se requiere darle alrededor de 3 segundos para que el display recibe el Paso)
	DigitalWrite('A',16,0);//D3 HIGH = 2-Line LOW = 1-Line
	DigitalWrite('C',17,0);//D4 HIGH = 8-Bits LOW = 4-Bits
	DigitalWrite('C',16,0);//D5 Set
	Delay(0xFFFF);

}



/*void WriteDatatoRam(void){

	void (*Num[])(void) = {cero, uno, dos, tres, cuatro, cinco, seis, siete, ocho, nueve, signogrados, LetraC};
         (*Num[0])();

}/*

/* aqui tenemos una function de retard en milisegun
	dos*/
void Delay(long n){
	while(n--);
	return;
	}

void cero(void)
{
	DigitalWrite('C',11,1);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E

	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 1);//D4
	DigitalWrite('C', 16, 1);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7

	DigitalWrite('C',6,0);//E
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5

	Delay(0xFFFF);
}

void uno(void)
{
	DigitalWrite('C',11,1);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E

	DigitalWrite('D', 7, 1);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 1);//D4
	DigitalWrite('C', 16, 1);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7

	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5

	Delay(0xFFFF);
}
void dos(void)
{
	DigitalWrite('C',11,1);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E

	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 1);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 1);//D4
	DigitalWrite('C', 16, 1);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7

	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5

	Delay(0xFFFF);
}
void tres(void)
{
	DigitalWrite('C',11,1);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E

	DigitalWrite('D', 7, 1);//D0
	DigitalWrite('D', 6, 1);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 1);//D4
	DigitalWrite('C', 16, 1);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7

	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5

	Delay(0xFFFF);
}
void cuatro(void)
{
	DigitalWrite('C',11,1);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E

	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 1);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 1);//D4
	DigitalWrite('C', 16, 1);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7

	DigitalWrite('C',6,0);//E
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5

	Delay(0xFFFF);
}
void cinco(void)
{
	DigitalWrite('C',11,1);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E

	DigitalWrite('D', 7, 1);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 1);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 1);//D4
	DigitalWrite('C', 16, 1);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7

	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5

	Delay(0xFFFF);
}
void seis(void)
{
	DigitalWrite('C',11,1);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E

	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 1);//D1
	DigitalWrite('A', 17, 1);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 1);//D4
	DigitalWrite('C', 16, 1);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7

	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5

	Delay(0xFFFF);
}
void siete(void)
{
	DigitalWrite('C',11,1);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E

	DigitalWrite('D', 7, 1);//D0
	DigitalWrite('D', 6, 1);//D1
	DigitalWrite('A', 17, 1);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 1);//D4
	DigitalWrite('C', 16, 1);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7

	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5

	Delay(0xFFFF);
}

void ocho(void)
{
	DigitalWrite('C',11,1);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E

	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('A', 16, 1);//D3
	DigitalWrite('C', 17, 1);//D4
	DigitalWrite('C', 16, 1);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7

	DigitalWrite('C',6,0);//E
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5

	Delay(0xFFFF);
}
void nueve(void)
{
	DigitalWrite('C',11,1);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E

	DigitalWrite('D', 7, 1);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('A', 16, 1);//D3
	DigitalWrite('C', 17, 1);//D4
	DigitalWrite('C', 16, 1);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7

	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5

	Delay(0xFFFF);
}
void signogrados()
{
	DigitalWrite('C',11,1);//RS
		DigitalWrite('C',10,0);//RW
		DigitalWrite('C',6,1);//E

		DigitalWrite('D', 7, 0);//D0
		DigitalWrite('D', 6, 0);//D1
		DigitalWrite('A', 17, 0);//D2
		DigitalWrite('A', 16, 1);//D3
		DigitalWrite('C', 17, 1);//D4
		DigitalWrite('C', 16, 1);//D5
		DigitalWrite('C', 13, 1);//D6
		DigitalWrite('C', 12, 1);//D7
		DigitalWrite('C',6,0);//E
		DigitalWrite('A', 16, 0);//D3
		DigitalWrite('C', 17, 0);//D4
		DigitalWrite('C', 16, 0);//D5
		DigitalWrite('C', 13, 0);//D6
		DigitalWrite('C', 12, 0);//D7


		Delay(0xFFFF);

}
void LetraC()
{
	DigitalWrite('C',11,1);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E

	DigitalWrite('D', 7, 1);//D0
	DigitalWrite('D', 6, 1);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5
	DigitalWrite('C', 13, 1);//D6
	DigitalWrite('C', 12, 0);//D7

	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('C', 13, 0);//D6

	Delay(0xFFFF);
}

/*
void Delay()
{
	 unsigned char count = 0;

while(count < 30000)
{
	count ++;
}


}


void delayMs(int n);

void DPY_vfnDriverInit(void)
{
	PinMode('C',11,1);//RS
	PinMode('C',10,1);//RW
	PinMode('C',6,1);//E
	PinMode('D',7,1);//D0
	PinMode('D',6,1);//D1
	PinMode('A',17,1);//D2
	PinMode('A',16,1);//D3
	PinMode('C',17,1);//D4
	PinMode('C',16,1);//D5
	PinMode('C',13,1);//D6
	PinMode('C',12,1);//D7
	//////////////////////////////////////////////////////////
	DigitalWrite('C',11,0);//RS
		DigitalWrite('C',10,0);//RW
		DigitalWrite('C',6,0);//E
		DigitalWrite('D', 7, 0);//D0
		DigitalWrite('D', 6, 0);//D1
		DigitalWrite('A', 17, 0);//D2
		DigitalWrite('A', 16, 0);//D3
		DigitalWrite('C', 17, 0);//D4
		DigitalWrite('C', 16, 0);//D5
		DigitalWrite('C', 13, 0);//D6
		DigitalWrite('C', 12, 0);//D7
	//BIT MODE//
	DigitalWrite('C',11,0);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 1);//D4
	DigitalWrite('C', 16, 1);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7
	DigitalWrite('C',6,1);//E
	DigitalWrite('C',6,0);//E
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5
	//CLEAR DISPLAY//
	DigitalWrite('C',11,0);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 1);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7
	DigitalWrite('C',6,1);//E
	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 0);//D0
	//RETURN HOME//
	DigitalWrite('C',11,0);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 1);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7
	DigitalWrite('C',6,1);//E
	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 6, 0);//D1
	//DISPLAY ON//
	DigitalWrite('C',11,0);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 1);//D2
	DigitalWrite('A', 16, 1);//D3
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7
	DigitalWrite('C',6,1);//E
	DigitalWrite('C',6,0);//E
	//DigitalWrite('D', 7, 0);//D0
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('A', 16, 0);//D3
	//WRITE//
	DigitalWrite('C',11,1);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('A', 16, 1);//D3
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5
	DigitalWrite('C', 13, 1);//D6
	DigitalWrite('C', 12, 0);//D7
	DigitalWrite('C',6,1);//E
	DigitalWrite('C',6,0);//E
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 13, 0);//D6

	/* aqui tenemos una function de retard en milisegun
	dos*/
/*	void delayMs(int n) {
	int i;
	int j;
	for(i = 0 ; i < n; i++)
	for(j = 0 ; j < 7000; j++) { }
	}
}
	/*
//____________|paso 1|________________________//
	PinMode('C',11,1);//RS
	PinMode('C',10,1);//RW
	PinMode('C',6,1);//E
	PinMode('D',7,1);//D0
	PinMode('D',6,1);//D1
	PinMode('A',17,1);//D2
	PinMode('A',16,1);//D3
	PinMode('C',17,1);//D4
	PinMode('C',16,1);//D5
	PinMode('C',13,1);//D6
	PinMode('C',12,1);//D7
	//delay(100);
//____________|paso 2|________________________//00110000b
	DigitalWrite('C',11,0);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 0);
	DigitalWrite('D', 6, 0);
	DigitalWrite('A', 17, 1);
	DigitalWrite('A', 16, 1);
	DigitalWrite('C', 17, 0);
	DigitalWrite('C', 16, 0);
	DigitalWrite('C', 13, 0);
	DigitalWrite('C', 12, 0);
	//delay(4.1);
//____________|paso 3|________________________//00110000b
	DigitalWrite('C',11,0);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 0);
	DigitalWrite('D', 6, 0);
	DigitalWrite('A', 17, 1);
	DigitalWrite('A', 16, 1);
	DigitalWrite('C', 17, 0);
	DigitalWrite('C', 16, 0);
	DigitalWrite('C', 13, 0);
	DigitalWrite('C', 12, 0);
	//delay(0.1);
//____________|paso 4|________________________//00110000b
	DigitalWrite('C',11,0);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 0);
	DigitalWrite('D', 6, 0);
	DigitalWrite('A', 17, 1);
	DigitalWrite('A', 16, 1);
	DigitalWrite('C', 17, 0);
	DigitalWrite('C', 16, 0);
	DigitalWrite('C', 13, 0);
	DigitalWrite('C', 12, 0);
	//delay(0.1);
//____________|paso 5|________________________//00111000b
	DigitalWrite('C',11,0);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 0);
	DigitalWrite('D', 6, 0);
	DigitalWrite('A', 17, 1);
	DigitalWrite('A', 16, 1);
	DigitalWrite('C', 17, 1);
	DigitalWrite('C', 16, 0);
	DigitalWrite('C', 13, 0);
	DigitalWrite('C', 12, 0);
	//delay(0.053);
 //____________|paso 6|________________________//00001000b
	DigitalWrite('C',11,0);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,0);//E
    DigitalWrite('D', 7, 0);
    DigitalWrite('D', 6, 0);
    DigitalWrite('A', 17, 0);
    DigitalWrite('A', 16, 0);
    DigitalWrite('C', 17, 1);
    DigitalWrite('C', 16, 0);
    DigitalWrite('C', 13, 0);
    DigitalWrite('C', 12, 0);
    //delay(0.053);
 //____________|paso 7|________________________//00000001b
    DigitalWrite('C',11,0);//RS
    DigitalWrite('C',10,0);//RW
    DigitalWrite('C',6,0);//E
    DigitalWrite('D', 7, 0);
    DigitalWrite('D', 6, 0);
    DigitalWrite('A', 17, 0);
    DigitalWrite('A', 16, 0);
    DigitalWrite('C', 17, 0);
    DigitalWrite('C', 16, 0);
    DigitalWrite('C', 13, 0);
    DigitalWrite('C', 12, 1);
    //delay(3);
  //____________|paso 8|________________________//00000110b
    DigitalWrite('C',11,0);//RS
    DigitalWrite('C',10,0);//RW
    DigitalWrite('C',6,0);//E
    DigitalWrite('D', 7, 0);
    DigitalWrite('D', 6, 0);
    DigitalWrite('A', 17, 0);
    DigitalWrite('A', 16, 0);
    DigitalWrite('C', 17, 0);
    DigitalWrite('C', 16, 1);
    DigitalWrite('C', 13, 1);
    DigitalWrite('C', 12, 0);
    //delay(0.053);
  //____________|paso 9|________________________//

  //____________|paso 10|________________________// 00001100b
    DigitalWrite('C',11,0);//RS
    DigitalWrite('C',10,0);//RW
    DigitalWrite('C',6,0);//E
    DigitalWrite('D', 7, 0);
    DigitalWrite('D', 6, 0);
    DigitalWrite('A', 17, 0);
    DigitalWrite('A', 16, 0);
    DigitalWrite('C', 17, 1);
    DigitalWrite('C', 16, 1);
    DigitalWrite('C', 13, 0);
    DigitalWrite('C', 12, 0);
    //delay(0.053);

}
*/

