/*
	Filename : PololuStepper.c
	
	Description : Testing Output to a Bi-Polar Stepper Using a Pololu Stepstick Connected to GPIO on RPi

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

#include <stdio.h>
#include <wiringPi.h>

#define	direction 0	// Pin Setup for Direction
#define	step 1		// Pin Setup for Step
#define	ms1 2		// Pin Setup for MS1
#define	ms2 3		// Pin Setup for MS2
#define	ms3 4		// Pin Setup for MS3

int main (void)
{
	int i, j;		// Define Integer(s)
	int speed = 10;		// Set Sleep Speed
	
	printf ("MrRetupmoc's Raspberry Pi - Bi-Polar Stepper\n");
	
	wiringPiSetup();		// WiringPi Setup
	
	pinMode (direction, OUTPUT);	// Setup Output Mode for Direction
	pinMode (step, OUTPUT);		// Setup Output Mode for Step
	pinMode (ms1, OUTPUT);		// Setup Output Mode for MS1
	pinMode (ms2, OUTPUT);		// Setup Output Mode for MS2
	pinMode (ms3, OUTPUT);		// Setup Output Mode for MS3

	for (;;)				// For - ever or untill Control C
	{
		digitalWrite (ms1, 0);			// Set MS1 to LOW for Full Step Mode
		digitalWrite (ms2, 0);			// Set MS2 to LOW for Full Step Mode
		digitalWrite (ms3, 0);			// Set MS3 to LOW for Full Step Mode

		for (j = 1; j < 10; j++)			// Loop For 9 Times or J, Forward First
		{
			digitalWrite (direction, 0);		// Turn Direction OFF Counter-Clock Wise
		
			for (i = 0; i < (100 / j); i++)		// Loop For 100 Divided by J
			{
				digitalWrite (step, 1);		// Turn Step ON or 1
				delay (speed);			// Sleep
				digitalWrite (step, 0);		// Turn Step OFF or 0
				delay (speed);			// Sleep
			}
		
			digitalWrite (direction, 1);		// Turn Direction ON Clock Wise
		
			for (i = 0; i < (100 / j); i++)		// Loop For 100 Divided by J
			{
				digitalWrite (step, 1);		// Turn Step ON or 1
				delay (speed);			// Sleep
				digitalWrite (step, 0);		// Turn Step OFF or 0
				delay (speed);			// Sleep
			}
		}

		for (j = 1; j < 10; j++)			// Loop For 9 Times or J, Forward First
		{
			digitalWrite (direction, 1);		// Turn Direction ON Clock Wise
		
			for (i = 0; i < (100 / j); i++)		// Loop For 100 Divided by J
			{
				digitalWrite (step, 1);		// Turn Step ON or 1
				delay (speed);			// Sleep
				digitalWrite (step, 0);		// Turn Step OFF or 0
				delay (speed);			// Sleep
			}
		
			digitalWrite (direction, 0);		// Turn Direction OFF Counter-Clock Wise
		
			for (i = 0; i < (100 / j); i++)		// Loop For 100 Divided by J
			{
				digitalWrite (step, 1);		// Turn Step ON or 1
				delay (speed);			// Sleep
				digitalWrite (step, 0);		// Turn Step OFF or 0
				delay (speed);			// Sleep
			}
		}
	}
}