/*
	Filename : RelayOFF.c
	
	Description : Turn OFF all 6 Relays on the Nwazet's Pecan Pi Rev 1.1

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

#define	relay0	6	// Pin Setup for Relay 1
#define	relay1	0	// Pin Setup for Relay 2
#define	relay2	2	// Pin Setup for Relay 3
#define	relay3	3	// Pin Setup for Relay 4
#define	relay4	4	// Pin Setup for Relay 5
#define	relay5	5	// Pin Setup for Relay 6

int main (void)
{
	wiringPiSetup();		// WiringPi Setup

	pinMode (relay0, OUTPUT);	// Setup Output Mode for Relay 1
	pinMode (relay1, OUTPUT);	// Setup Output Mode for Relay 2
	pinMode (relay2, OUTPUT);	// Setup Output Mode for Relay 3
	pinMode (relay3, OUTPUT);	// Setup Output Mode for Relay 4
	pinMode (relay4, OUTPUT);	// Setup Output Mode for Relay 5
	pinMode (relay5, OUTPUT);	// Setup Output Mode for Relay 6

	printf ("MrRetupmoc's Raspberry Pi - Nwazet's Pecan Pi Relay OFF(er)\n");

	digitalWrite (relay0, 0);	// Relay 0 OFF
	digitalWrite (relay1, 0);	// Relay 1 OFF
	digitalWrite (relay2, 0);	// Relay 2 OFF
	digitalWrite (relay3, 0);	// Relay 3 OFF
	digitalWrite (relay4, 0);	// Relay 4 OFF
	digitalWrite (relay5, 0);	// Relay 5 OFF

	return 0;
}