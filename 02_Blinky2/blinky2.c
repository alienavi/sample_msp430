/*
 *  MSP430 Blink2
 *  Description: Alternating between P1.0(red) and P1.6(green)
 *               by xor'ing P1 port inside of a software loop.
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

	// Setting P1.0 and P1.6 as output
	P1DIR = P1DIR | (BIT0 + BIT6);   // P1DIR = 0bX1XX_XXX1

	// P1.0 High
	P1OUT = P1OUT | BIT0;   // P1OUT OR 0b0000_0001 => P1 = 0bXXXX_XXX1
	// P1.6 Low
	P1OUT = P1OUT & ~BIT6;   // P1OUT AND 0b1011_1111 => P1 = 0bX0XX_XXX1

	while(1){   // loop
	    //  Toggle P1.0 & P1.6 Output using X-OR
	    P1OUT = P1OUT ^ (BIT0 + BIT6);   // P1OUT = 0bX0XX_XXX1 ^ 0b0100_0001 => 0bX1XX_XXX0 ....
	    volatile unsigned int delay = 10000;
	    while(delay--){
	        ;   // SW defined blank loop for delay
	    }
	}
	
	return 0;
}
