/*
Raspberry Pi driving the Max7219 / AS1100
to compile : make -lwiringPi -lwiringPiDev ./8LED
*/
 
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// define our pins :

#define DATA        12 // GPIO 17 (WiringPi pin num 0)  header pin 11
#define CLOCK       14 // GPIO 22 (WiringPi pin num 3)   header pin 15
#define LOAD        10 // GPIO 23 (WiringPi pin num 4)   header pin 16

// The Max7219 Registers :

#define DECODE_MODE   0x09                       
#define INTENSITY     0x0a                        
#define SCAN_LIMIT    0x0b                        
#define SHUTDOWN      0x0c                        
#define DISPLAY_TEST  0x0f                         

static void Send16bits (unsigned short output)
{
	unsigned char i;
	
	for (i=16; i>0; i--) 
	{
		unsigned short mask = 1 << (i - 1); // calculate bitmask
		
		digitalWrite(CLOCK, 0);  // set clock to 0
		
		// Send one bit on the data pin
		
		if (output & mask) digitalWrite(DATA, 1);
		else digitalWrite(DATA, 0);
		
		digitalWrite(CLOCK, 1);  // set clock to 1	 
	}
}


// Take a reg numer and data and send to the max7219

static void MAX7219Send (unsigned char reg_number, unsigned char dataout)
{
	digitalWrite(LOAD, 1);  // set LOAD 1 to start
	Send16bits((reg_number << 8) + dataout);   // send 16 bits ( reg number + dataout )
	digitalWrite(LOAD, 0);  // LOAD 0 to latch
	digitalWrite(LOAD, 1);  // set LOAD 1 to finish
}

int main (void)
{
	int i;
	int j;
	int k;
	
	printf ("\n\nRaspberry Pi Max7219 Test using WiringPi\n\n");
	
	if (wiringPiSetup () == -1) exit (1) ;
	
	//We need 3 output pins to control the Max7219: Data, Clock and Load
	
	pinMode(DATA, OUTPUT);  
	pinMode(CLOCK, OUTPUT);
	pinMode(LOAD, OUTPUT);  
		
	MAX7219Send(SCAN_LIMIT, 16);
	
	// BCD decode mode off : data bits correspond to the segments (A-G and DP) of the seven segment display.
	// BCD mode on :  0 to 15 =  0 to 9, -, E, H, L, P, and ' '
	
	MAX7219Send(DECODE_MODE, 0);   // Set BCD decode mode on
	MAX7219Send(DISPLAY_TEST, 0);  // Disable test mode
	MAX7219Send(INTENSITY, 15);     // set brightness 0 to 15
	MAX7219Send(SHUTDOWN, 1);      // come out of shutdown mode	/ turn on the digits
	
	for(i = 200; i > 0; i--)
	{
		for(j = 1; j < 255; j++)
		{
			//for(k = 1; k < 2; k++)
			//{
				printf ("Sending %i \n", j);
				MAX7219Send(1,j); 		 // displays the number 6 on digit 1
				delay(i);
			//}
		}
		i = i - 149;
	}

	delay(500);

	printf ("Printing FOIL \n");
	MAX7219Send(1,5); 		 // displays the number 6 on digit 1
	delay(400);
	MAX7219Send(1,9); 		 // displays the number 6 on digit 1
	delay(400);
	MAX7219Send(1,6); 		 // displays the number 6 on digit 1
	delay(400);
	MAX7219Send(1,10); 		 // displays the number 6 on digit 1
	delay(400);

	delay(500);
	
	MAX7219Send(SHUTDOWN, 0);      // turn off the LED's
	delay(200);
	
	return 0;
}