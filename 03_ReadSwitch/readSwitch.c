/*
 *  MSP430 Read Switch
 *  Description: Read the value of on-board switch (SW2)
 *               connected to P1.3 and reflect output on
 *               P1.0 red led
 *
 *  Rahul Sharma
 *  Hatchnhack Solutios Pvt Ltd
 *  Built with CCS v9
 */
#include <msp430.h> 

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watch dog timer

	// Setting P1.0 as output
    P1DIR = P1DIR | BIT0;   // P1DIR = 0bXXXX_XXX1
	
	// Setting P1.3 as input
	P1DIR = P1DIR & ~BIT3;  // P1DIR = 0bXXXX_0XX1
	
	// Enabling Pull up/down for P1.3
	P1REN = P1REN | BIT3;   // P1REN = 0b0000_1000
	
	// Using Pull up resistor
	P1OUT = P1OUT | BIT3;   // P1OUT?? slau114j page 329

	while(1){   // loop
	    //reading switch
	    if(P1IN & BIT3){  // P1.3 is High
	        P1OUT = P1OUT & ~BIT0;  // Switch is not pressed
	    } else {
	        P1OUT = P1OUT | BIT0;   // Switch is pressed
	    }
	}

	return 0;
}
