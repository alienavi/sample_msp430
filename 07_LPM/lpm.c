/*
 *  MSP430 Read Switch
 *  Description: Read the value of on-board switch (SW2)
 *               connected to P1.3 and reflect output on
 *               P1.0 red led and set MSP to Low Power Mode
 *
 *  Rahul Sharma
 *  Hatchnhack Solutios Pvt Ltd
 *  Built with CCS v9
 */
#include <msp430.h> 

//Constants
#define SW BIT3
#define RED BIT0

/*
 * main.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watch dog timer
	// Setting P1.0 as output
	P1DIR |= RED;   // P1DIR = 0bXXXX_XXX1
	// Setting P1.3 as input
	P1DIR &= ~SW;  // P1DIR = 0bXXXX_0XX1
	// Enabling Pull up/down for P1.3
	P1REN |= SW;   // P1REN = 0b0000_1000
	// Using Pull up resistor
	P1OUT |= SW; 
	// Set and Enable Interrupts
	P1IES |= SW;
	P1IE |= SW;
	// Enable Global Interrupt and LPM
	__bits_SR_register(GIE + LPM4_bits); //LPM4_bits ?????
}

#pragma vector = PORT1_VECTOR
__interrupt void Port_1(void){
	P1OUT ^= RED;	//Toggle LED
	P1IFG &= ~SW;	//Clear Interrupt
}
