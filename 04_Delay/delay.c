/*
 *  MSP430 Read Switch
 *  Description: Blink LED using delay function
 *
 *  Rahul Sharma
 *  Hatchnhack Solutios Pvt Ltd
 *  Built with CCS v9
 */
#include <msp430.h> 

/*
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watch dog timer

	// Setting P1.0 and P1.6 as output
  P1DIR = P1DIR | (BIT0 + BIT6);   // P1DIR = 0bX1XX_XXX1
  // Default P1OUT value
  P1OUT |= BIT0;
  P1OUT &= ~BIT6;
	while(1){   // loop
	    __delay_cycles(1000000); //delay 10000ms
      P1OUT ^= (BIT0 + BIT6);
	}
	return 0;
}
