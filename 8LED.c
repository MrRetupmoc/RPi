/*
	Filename : 8LED.c
	
	Description : Testing Output to a 8 by 8 Led Matrix Display using an [ AS1100 / MAX77219 ] via SPI 

	Requirements : wiringPi
	
	Copyright (c) 2013 MrRetupmoc. <http://Retupmoc.ca>

	*************************************************************************************************
	*	This file is part of MrRetupmoc's RPi:							*
	*												*
	*	http;//www.Retupmoc.ca/?page_id=756							*
	*	MrRetupmoc's RPi is free software: you can redistribute it and/or modify		*
	*	it under the terms of the GNU Lesser General Public License as published by		*
	*	the Free Software Foundation, either version 3 of the License, or			*
	*	(at your option) any later version.							*
	*												*
	*	MrRetupmoc's RPi is distributed in the hope that it will be useful,			*
	*	but WITHOUT ANY WARRANTY; without even the implied warranty of				*
	*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the				*
	*	GNU Lesser General Public License for more details.					*
	*												*
	*	You should have received a copy of the GNU Lesser General Public License		*
	*	along with MrRetupmoc's RPi.  If not, see <http://www.gnu.org/licenses/>.		*
	*************************************************************************************************
 */
 
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define	DATA	12		// Pin Setup for Data
#define	CLOCK	14		// Pin Setup for Clock
#define	LOAD	10		// Pin Setup for Load

#define	DECODE_MODE	0x09	// Hex for Decode Mode
#define	INTENSITY	0x0a	// Hex for Intensity
#define	SCAN_LIMIT	0x0b	// Hex for Scan Limit
#define	SHUTDOWN	0x0c	// Hex for Shutdown
#define	DISPLAY_TEST	0x0f	// Hex for Display Test

static void Send16bits (unsigned short output)
{
	unsigned char i;
	
	for (i=16; i>0; i--) 
	{
		unsigned short mask = 1 << (i - 1);		// Calculate Bitmask
		
		digitalWrite(CLOCK, 0);				// set Clock to 0
		
		if (output & mask) digitalWrite(DATA, 1);	// Send One Bit on the DATA Pin
		else digitalWrite(DATA, 0);			// Send OFF
		
		digitalWrite(CLOCK, 1);				// set Clock to 1	 
	}
}

static void MAX7219Send (unsigned char reg_number, unsigned char dataout)
{
	digitalWrite(LOAD, 1);				// Set LOAD 1 to Start
	Send16bits((reg_number << 8) + dataout);	// Send 16 Bits ( Register # + Dataout )
	digitalWrite(LOAD, 0);				// LOAD 0 to latch
	digitalWrite(LOAD, 1);				// Set LOAD 1 to Finish
}

int main (void)
{
	int i, j;					// Define Integer(s)
	
	printf ("MrRetupmoc's Raspberry Pi - Led Martix - Count to 256\n");
	
	if (wiringPiSetup () == -1) exit (1);		// WiringPi Setup
	
	pinMode(DATA, OUTPUT);				// Setup Output Mode for Data
	pinMode(CLOCK, OUTPUT);				// Setup Output Mode for Clock 
	pinMode(LOAD, OUTPUT);				// Setup Output Mode for Load 
		
	MAX7219Send(SCAN_LIMIT, 16);			// Scan Limit
	
	// BCD decode mode off : data bits correspond to the segments (A-G and DP) of the seven segment display.
	// BCD mode on :  0 to 15 =  0 to 9, -, E, H, L, P, and ' '
	
	MAX7219Send(DECODE_MODE, 0);			// Set BCD decode mode on
	MAX7219Send(DISPLAY_TEST, 0);			// Disable test mode
	MAX7219Send(INTENSITY, 15);			// set brightness 0 to 15
	MAX7219Send(SHUTDOWN, 1);			// come out of shutdown mode	/ turn on the digits
	
	for(i = 200; i > 0; i--)			// Loop for Slow and Fast Modes
	{
		for(j = 1; j < 255; j++)		// Loop for 256 Numbers
		{
			printf ("Sending %i \n", j);	// Display on Console What is Being Sent
			MAX7219Send(1,j);		// Displays the Binary Number on the Rows of Column 1
			delay(i);			// Sleep
		}
		i = i - 149;
	}

	delay(500);					// Sleep

	printf ("Printing FOIL \n");

	MAX7219Send(1,5);				// Displays the First in FOIL
	delay(400);					// Sleep
	MAX7219Send(1,9);				// Displays the First in FOIL
	delay(400);					// Sleep
	MAX7219Send(1,6);				// Displays the First in FOIL
	delay(400);					// Sleep
	MAX7219Send(1,10);				// Displays the First in FOIL
	delay(400);					// Sleep

	delay(500);					// Sleep
	
	MAX7219Send(SHUTDOWN, 0);			// Turn OFF the LED's
	delay(200);					// Sleep
	
	return 0;
}