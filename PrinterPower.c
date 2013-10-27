#include <stdio.h>
#include <stdlib.h>
#include <poll.h>
#include <wiringPi.h>

#ifndef	TRUE
#  define TRUE  (1==1)
#  define FALSE (!TRUE)
#endif

static int keypressed (void)
{
  struct pollfd polls ;

  polls.fd     = fileno (stdin) ;
  polls.events = POLLIN ;

  return poll (&polls, 1, 0) != 0 ;
}

static void clearKeypressed (void)
{
  while (keypressed ())
    (void)getchar () ;
}

#define	PowerRelay	6

int main (void)
{
	printf ("Raspberry Pi Megatronics Power Controller\n") ;
	wiringPiSetup () ;
	pinMode (PowerRelay, OUTPUT) ;
	
	for (;;)
	{
		if (keypressed ()) digitalWrite (PowerRelay, HIGH) ;
		else digitalWrite (PowerRelay, LOW) ;
		clearKeypressed () ;
		delay (500) ;
	}

  return 0 ;
}
