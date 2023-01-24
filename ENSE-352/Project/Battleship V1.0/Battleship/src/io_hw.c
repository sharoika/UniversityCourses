#include <stdbool.h>
#include "stm32f10x.h"
#include "../include/io_hw.h"

// this function turns on the required clocks for my battlesip game
void turnOnClocks(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN;
}

// this function is configuring the ports required for the battleship game
void configurePorts(void)
{
	GPIOA->CRL |= GPIO_CRL_MODE0_1 | GPIO_CRL_MODE0_0 | 													// port a0 mode 11 // led A
								GPIO_CRL_MODE1_1 | GPIO_CRL_MODE1_0 | 													// port a1 mode 11 // led B
								GPIO_CRL_MODE4_1 | GPIO_CRL_MODE4_0 |														// port a4 mode 11 // led C
								GPIO_CRL_MODE6_1 | GPIO_CRL_MODE6_0	|														// port a6 mode 11 // led D
								GPIO_CRL_MODE7_1 | GPIO_CRL_MODE7_0;  													// port a7 mode 11 // led E
	
	GPIOA->CRL &=   ~GPIO_CRL_CNF0_1 &~ GPIO_CRL_CNF0_0 													// port a0 cnf 00 // led A
								&~ GPIO_CRL_CNF1_1 &~ GPIO_CRL_CNF1_0 													// port a1 cnf 00 // led B
								&~ GPIO_CRL_CNF4_1 &~ GPIO_CRL_CNF4_0														// port a4 cnf 00 // led C
								&~ GPIO_CRL_CNF6_1 &~ GPIO_CRL_CNF6_0 													// port a6 cnf 00 // led D
								&~ GPIO_CRL_CNF7_1 &~ GPIO_CRL_CNF7_0;													// port a7 cnf 00 // led E
	
	GPIOA->CRH |= GPIO_CRH_MODE8_1 | GPIO_CRH_MODE8_0;														// port a8 mode 11 // led F
	
	GPIOA->CRH &=  ~GPIO_CRH_CNF8_1 &~ GPIO_CRH_CNF8_0; 													// port a8 cnf 00 // led F
	
	GPIOB->CRL |= GPIO_CRL_MODE0_1 | GPIO_CRL_MODE0_0 | 													// port b0 mode 11 // led G
								GPIO_CRL_CNF4_0 |																								// port b4 cnf #1 // switch 0
								GPIO_CRL_CNF6_0;																								// port b6 cnf #1 // switch 1
	
	
	GPIOB->CRL &=   ~GPIO_CRL_CNF0_1 &~ GPIO_CRL_CNF0_0 													// port b0 cnf 00 // led G
								&~ GPIO_CRL_CNF4_1 &~ GPIO_CRL_MODE4_1 &~ GPIO_CRL_MODE4_0			// port b4 cnf 0# AND mode 00 // switch 0
								&~ GPIO_CRL_CNF6_1 &~ GPIO_CRL_MODE6_1 &~ GPIO_CRL_MODE6_0;			// port b6 cnf 0# AND mode 00 // switch 1
	
	GPIOB->CRH |= GPIO_CRH_CNF8_0 | 																							// port b8 cnf #1 // switch 2
								GPIO_CRH_CNF9_0;																								// port b9 cnf #1 // switch 3
	
	GPIOB->CRH &= ~GPIO_CRH_CNF8_1 &~ GPIO_CRH_MODE8_1 &~ GPIO_CRH_MODE8_0				// port b8 cnf 0# AND mode 00 // switch 2
								&~ GPIO_CRH_CNF9_1 &~ GPIO_CRH_MODE9_1 &~ GPIO_CRH_MODE9_0;			// port b9 cnf 0# AND mode 00 // switch 3
								
	GPIOC->CRH |= GPIO_CRH_CNF13_0;  																							// port c13 cnf #1 // switch blue
	
	GPIOC->CRH &= ~GPIO_CRH_CNF13_1 &~ GPIO_CRH_MODE13_1 &~ GPIO_CRH_MODE13_0;		// port c13 cnf 0# AND mode 00 // switch blue
	
	GPIOA->CRL |= GPIO_CRL_MODE5_0 | GPIO_CRL_MODE5_1;														// port a5 mode 11 // led green
	GPIOA->CRL &= ~GPIO_CRL_CNF5_0 &~ GPIO_CRL_CNF5_1; 														// configuring green LED
}

// turn on light or turns it off (LED A)
void toggleLight0(bool on)
{
	// if passed with true, turn it on - otherwise make it false
	if (on == true)
	{
		GPIOA->ODR |= GPIO_ODR_ODR0;
	}
	else
	{
		GPIOA->ODR &= (unsigned)~GPIO_ODR_ODR0;
	}
}

// turn on light or turns it off (LED B)
void toggleLight1(bool on)
{
	// if passed with true, turn it on - otherwise make it false
	if (on == true)
	{
		GPIOA->ODR |= GPIO_ODR_ODR1;
	}
	else
	{
		GPIOA->ODR &= (unsigned)~GPIO_ODR_ODR1;
	}
}

// turn on light or turns it off (LED C)
void toggleLight2(bool on)
{
	// if passed with true, turn it on - otherwise make it false
	if (on == true)
	{
		GPIOA->ODR |= GPIO_ODR_ODR4;
	}
	else
	{
		GPIOA->ODR &= (unsigned)~GPIO_ODR_ODR4;
	}
}

// turn on light or turns it off (LED D)
void toggleLight3(bool on)
{
	// if passed with true, turn it on - otherwise make it false
	if (on == true)
	{
		GPIOA->ODR |= GPIO_ODR_ODR6;
	}
	else
	{
		GPIOA->ODR &= (unsigned)~GPIO_ODR_ODR6;
	}
}

// turn on light or turns it off (LED E)
void toggleLight4(bool on)
{
	// if passed with true, turn it on - otherwise make it false
	if (on == true)
	{
		GPIOA->ODR |= GPIO_ODR_ODR7;
	}
	else
	{
		GPIOA->ODR &= (unsigned)~GPIO_ODR_ODR7;
	}
}

// turn on light or turns it off (LED F)
void toggleLight5(bool on)
{
	// if passed with true, turn it on - otherwise make it false
	if (on == true)
	{
		GPIOA->ODR |= GPIO_ODR_ODR8;
	}
	else
	{
		GPIOA->ODR &= (unsigned)~GPIO_ODR_ODR8;
	}
}

// turn on light or turns it off (LED G)
void toggleLight6(bool on)
{
	// if passed with true, turn it on - otherwise make it false
	if (on == true)
	{
		GPIOB->ODR |= GPIO_ODR_ODR0;
	}
	else
	{
		GPIOB->ODR &= (unsigned)~GPIO_ODR_ODR0;
	}
}

// this listens to if the blue switch is triggered (this switch is considered active low)
bool listenBlueSwitch(void)
{
	int val = (GPIOC->IDR & 0x00002000); 
	if (val == 0x00002000)
		return false;
	else 
		return true;
}

// return a value [0, 15] from the switches 
int listenSwitches(void)
{
	// value declared above that will hold inputed from switch as an integer
	int val;
	// this will hold the third bit from the switch acting as a value of 8
	int bit3 = (GPIOB->IDR & 0x00000200); 
	if (bit3 == 0x00000200)
		{
			bit3 = 8; 
		}
	else
		{
			bit3 = 0;
		}
	// this will hold the third bit from the switch acting as a value of 4
	int bit2 = (GPIOB->IDR & 0x00000100); 
	if (bit2 == 0x00000100)
		{
			bit2 = 4; 
		}
		else
		{
			bit2 = 0;
		}
	// this will hold the third bit from the switch acting as a value of 2
	int bit1 = (GPIOB->IDR & 0x00000040); 
	if (bit1 == 0x00000040)
		{
			bit1 = 2; 
		}
	else
		{
			bit1 = 0;
		}
	// this will hold the third bit from the switch acting as a value of 1
	int bit0 = (GPIOB->IDR & 0x00000010); 
	if (bit0 == 0x00000010)
		{
			bit0 = 1; 
		}
		else
		{
			bit0 = 0;
		}
	// adding all of our bits and thier worths into value
	val = bit3 + bit2 + bit1 + bit0; 
	// return that value, basically reading the switches integer count
	return val; 
}

// a function that will either turn on or off the embeded green LED from a parameter
void greenLED(bool on)
{
	// if its true turn it on, otherwise make it false
	if (on == true)
	{
		GPIOA->ODR |= GPIO_ODR_ODR5; 
	}
	else
	{
		GPIOA->ODR &= (uint32_t) ~GPIO_ODR_ODR5;
	}
}

// light lookup table, it takes an integer value and will dispaly on the screen, follow HEX
// from 0 to 15, with H assigned to the value of 16 - if any other value is passed in our 7-seg
// will display nothing and go dark.
void lightLookup(int val)
{
	if (val == 0)
	{
		toggleLight0(true);
		toggleLight1(true);
		toggleLight2(true);
		toggleLight3(true);
		toggleLight4(true);
		toggleLight5(true);
		toggleLight6(false);
	}
	else if (val == 1)
	{
		toggleLight0(false);
		toggleLight1(true);
		toggleLight2(true);
		toggleLight3(false);
		toggleLight4(false);
		toggleLight5(false);
		toggleLight6(false);
	}
	else if (val == 2)
	{
		toggleLight0(true);
		toggleLight1(true);
		toggleLight2(false);
		toggleLight3(true);
		toggleLight4(true);
		toggleLight5(false);
		toggleLight6(true);
	}
	else if (val == 3)
	{
		toggleLight0(true);
		toggleLight1(true);
		toggleLight2(true);
		toggleLight3(true);
		toggleLight4(false);
		toggleLight5(false);
		toggleLight6(true);
	}
	else if (val == 4)
	{
		toggleLight0(false);
		toggleLight1(true);
		toggleLight2(true);
		toggleLight3(false);
		toggleLight4(false);
		toggleLight5(true);
		toggleLight6(true);
	}
	else if (val == 5)
	{
		toggleLight0(true);
		toggleLight1(false);
		toggleLight2(true);
		toggleLight3(true);
		toggleLight4(false);
		toggleLight5(true);
		toggleLight6(true);
	}
	else if (val == 6)
	{
		toggleLight0(true);
		toggleLight1(false);
		toggleLight2(true);
		toggleLight3(true);
		toggleLight4(true);
		toggleLight5(true);
		toggleLight6(true);
	}
	else if (val == 7)
	{
		toggleLight0(true);
		toggleLight1(true);
		toggleLight2(true);
		toggleLight3(false);
		toggleLight4(false);
		toggleLight5(false);
		toggleLight6(false);
	}
	else if (val == 8)
	{
		toggleLight0(true);
		toggleLight1(true);
		toggleLight2(true);
		toggleLight3(true);
		toggleLight4(true);
		toggleLight5(true);
		toggleLight6(true);
	}
	else if (val == 9)
	{
		toggleLight0(true);
		toggleLight1(true);
		toggleLight2(true);
		toggleLight3(false);
		toggleLight4(false);
		toggleLight5(true);
		toggleLight6(true);
	}
	else if (val == 10)
	{
		toggleLight0(true);
		toggleLight1(true);
		toggleLight2(true);
		toggleLight3(false);
		toggleLight4(true);
		toggleLight5(true);
		toggleLight6(true);
	}
	else if (val == 11)
	{
		toggleLight0(false);
		toggleLight1(false);
		toggleLight2(true);
		toggleLight3(true);
		toggleLight4(true);
		toggleLight5(true);
		toggleLight6(true);
	}
	else if (val == 12)
	{
		toggleLight0(true);
		toggleLight1(false);
		toggleLight2(false);
		toggleLight3(true);
		toggleLight4(true);
		toggleLight5(true);
		toggleLight6(false);
	}
	else if (val == 13)
	{
		toggleLight0(false);
		toggleLight1(true);
		toggleLight2(true);
		toggleLight3(true);
		toggleLight4(true);
		toggleLight5(false);
		toggleLight6(true);
	}
	else if (val == 14)
	{
		toggleLight0(true);
		toggleLight1(false);
		toggleLight2(false);
		toggleLight3(true);
		toggleLight4(true);
		toggleLight5(true);
		toggleLight6(true);
	}
	else if (val == 15)
	{
		toggleLight0(true);
		toggleLight1(false);
		toggleLight2(false);
		toggleLight3(false);
		toggleLight4(true);
		toggleLight5(true);
		toggleLight6(true);
	}
	else if (val == 16)
	{
		toggleLight0(false);
		toggleLight1(true);
		toggleLight2(true);
		toggleLight3(false);
		toggleLight4(true);
		toggleLight5(true);
		toggleLight6(true);
	}
	else
	{
		toggleLight0(false);
		toggleLight1(false);
		toggleLight2(false);
		toggleLight3(false);
		toggleLight4(false);
		toggleLight5(false);
		toggleLight6(false);
	}
}

// a give delay in class slowed down a little
void delay()
{
	// very long loops
	unsigned volatile int a, b; 
	for (a = 0; a < 3000; a++)
	{
		for (b = 0; b < 1500; b++)
		{}
	}
}
