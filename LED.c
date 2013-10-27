#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <wiringPi.h>
#include <wiringPiSPI.h>

int main ()
{
	int i;
	unsigned char bit [4096];

	if (wiringPiSPISetup (0, 115200) < 0)
	{
		fprintf (stderr, "Unable to SPI to device: %s\n", strerror (errno));
		return 1;
	}

	if (wiringPiSetup () == -1)
	{
		fprintf (stdout, "Unable to start wiringPi: %s\n", strerror (errno));
		return 1;
	}

	for (i = 0; i < 4096; i++)
	    bit [i] = i & 0xFF;
	
	for(;;)
	{
		wiringPiSPIDataRW (0, bit, 4096);

		for (i = 0; i < 4096; i++)
		{
			if (bit [i] != (i & 0xFF))
			    printf ("Bit %d: %02X -> %02X\n", i , i & 0xFF, bit[i]);
		
			delay(5);
		}
	}

	return 0 ;
}
