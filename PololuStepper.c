// Written by : Evan C. Richinson aka MrRetupmoc42
//
// Raspberry Pi connected to a Pololu Stepstick
// in turn Controlling a Bi-Polar Stepper

#include <stdio.h>
#include <wiringPi.h>

#define	direction 0
#define	step 1
#define	ms1 2
#define	ms2 3
#define	ms3 4

int main (void)
{
	int i, j;
	int speed = 10;
	
	printf ("Raspberry Pi Pololu StepStick Tester\n");
	
	wiringPiSetup ();
	
	pinMode (direction, OUTPUT);
	pinMode (step, OUTPUT);
	pinMode (ms1, OUTPUT);
	pinMode (ms2, OUTPUT);
	pinMode (ms3, OUTPUT);

	for (;;)
	{
		digitalWrite (ms1, 0) ;
		digitalWrite (ms2, 0) ;
		digitalWrite (ms3, 0) ;

		for (j = 1; j < 10; j++)
		{
			digitalWrite (direction, 0) ;
		
			for (i = 0; i < (100 / j); i++)
			{
				digitalWrite (step, 1) ;
				delay (speed) ;
				digitalWrite (step, 0) ;
				delay (speed) ;
			}
		
			digitalWrite (direction, 1) ;
		
			for (i = 0; i < (100 / j); i++)
			{
				digitalWrite (step, 1) ;
				delay (speed) ;
				digitalWrite (step, 0) ;
				delay (speed) ;
			}
		}

		for (j = 1; j < 10; j++)
		{
			digitalWrite (direction, 1) ;
		
			for (i = 0; i < (100 / j); i++)
			{
				digitalWrite (step, 1) ;
				delay (speed) ;
				digitalWrite (step, 0) ;
				delay (speed) ;
			}
		
			digitalWrite (direction, 0) ;
		
			for (i = 0; i < (100 / j); i++)
			{
				digitalWrite (step, 1) ;
				delay (speed) ;
				digitalWrite (step, 0) ;
				delay (speed) ;
			}
		}
	}
}
