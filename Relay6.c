/*
 * relay6.c:
 *	Test Control 6 Relays
 *
 * Copyright (c) 2012-2013 Gordon Henderson. <projects@drogon.net>
 ***********************************************************************
 * This file is part of wiringPi:
 *	https://projects.drogon.net/raspberry-pi/wiringpi/
 *
 *    wiringPi is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    wiringPi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public License
 *    along with wiringPi.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************
 */

#include <stdio.h>
#include <wiringPi.h>

#define	relay0 6
#define	relay1 0
#define	relay2 2
#define	relay3 3
#define	relay4 4
#define	relay5 5

int main (void)
{
  int speed = 1000;

  printf ("Raspberry Pi Nwazet's Pecan Pi Relay Tester\n");

  wiringPiSetup ();

  pinMode (relay0, OUTPUT);
  pinMode (relay1, OUTPUT);
  pinMode (relay2, OUTPUT);
  pinMode (relay3, OUTPUT);
  pinMode (relay4, OUTPUT);
  pinMode (relay5, OUTPUT);

  for (;;)
  {
      digitalWrite (relay0, 1) ;
      delay (speed) ;

      digitalWrite (relay1, 1) ;
      delay (speed) ;

      digitalWrite (relay2, 1) ;
      delay (speed) ;

      digitalWrite (relay3, 1) ;
      delay (speed) ;

      digitalWrite (relay4, 1) ;
      delay (speed) ;

      digitalWrite (relay5, 1) ;
      delay (speed) ;

      digitalWrite (relay0, 0) ;
      delay (speed) ;

      digitalWrite (relay1, 0) ;
      delay (speed) ;

      digitalWrite (relay2, 0) ;
      delay (speed) ;

      digitalWrite (relay3, 0) ;
      delay (speed) ;

      digitalWrite (relay4, 0) ;
      delay (speed) ;

      digitalWrite (relay5, 0) ;
      delay (speed) ;
  }
}
