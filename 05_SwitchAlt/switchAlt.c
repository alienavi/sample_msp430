/*
 *  MSP430 Read Switch
 *  Description: Read the value of on-board switch (SW2)
 *               connected to P1.3 and toggle between Red
 *               and Green led
 *  Rahul Sharma
 *  Hatchnhack Solutios Pvt Ltd
 *  Built with CCS v9
 */
#include <msp430.h> 

//Constant
#define SW BIT3
#define RED BIT0
#define GREEN BIT6

/*
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watch dog timer
	
	// Setting P1.0 & P1.6 as output
	P1DIR |= RED + GREEN;   // P1DIR = 0bX1XX_XXX1
	
	// Setting P1.3 as input
	P1DIR &= ~SW;  // P1DIR = 0bXXXX_0XX1
	
	// Enabling Pull up/down for P1.3
	P1REN |= SW;   // P1REN = 0b0000_1000
	
	// Using Pull up resistor
	P1OUT |= SW;   // P1OUT?? slau114j page 329

	volatile unsigned int state = 0;
	while(1){   // loop
		//Read Switch
		if(!(P1IN & SW)){
			__delay_cycles(20000);	//Delay for debouncing
			if(!(P1IN & SW)){	// Switch is pressed
				while(!(P1IN & SW));	//switch is still pressed
				state = !state;
			}
		}
		if(state){
			P1OUT |= RED; //RED is on
			P1OUT &= ~GREEN; //GREEN is off
		} else {
			P1OUT |= GREEN; //GREEN is on
			P1OUT &= ~RED; //RED is off
		}
	}
	
	return 0;
}
