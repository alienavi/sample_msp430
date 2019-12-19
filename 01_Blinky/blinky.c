/*
 *  MSP430 Blink Led Code
 *  Description; Toggle P1.0 by xor'ing P1.0 inside of a software loop.
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

	while(1){   // loop
	    //  Toggle P1.0 Output using X-OR
	    P1OUT = P1OUT ^ BIT0;   // P1OUT = 0bXXXX_XXX1 ^ 0b0000_0001
	    volatile unsigned int delay = 10000;
	    while(delay--){
	        ;   // SW defined blank loop for delay
	    }
	}
	
	return 0;
}

