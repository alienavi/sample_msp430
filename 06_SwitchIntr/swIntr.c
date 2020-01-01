/*
 *  MSP430 Read Switch
 *  Description: Read the interrupt on switch (SW2)
 *               connected to P1.3 and reflect output on
 *               P1.0 red led
 *
 *  Rahul Sharma
 *  Hatchnhack Solutios Pvt Ltd
 *  Built with CCS v9
 */
#include <msp430.h> 

//Constant
#define SW BIT3
#define RED BIT0

/*
 * main.c
 */
int main(void)
{
  WDTCTL = WDTPW | WDTHOLD;	// stop watch dog timer
  
  // Setting P1.0 as output
  P1DIR |= RED;   // P1DIR = 0bXXXX_XXX1
  P1OUT &= ~RED;  // Set default value
  // Setting P1.3 as input
  P1DIR &= ~SW;  // P1DIR = 0bXXXX_0XX1
  
  // Enabling Pull up/down for P1.3
	P1REN |= SW;   // P1REN = 0b0000_1000
  
  // Using Pull up resistor
  P1OUT |= SW;   // P1OUT?? slau114j page 329
  
  // Set Interrupt type
  P1IES |= SW;
  // Enable PIN Interrupt
	while(1){   // loop	    
	}

	return 0;
}

#pragma vector = PORT1_VECTOR
__interrupt void Port_1(void){
  // How to check which pin raised interrupt??
  P1OUT ^= RED;
  P1IFG &= ~SW;
}
