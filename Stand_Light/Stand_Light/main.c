#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "AP/Stand_Light.h"

int main(void)
{
	stand_light_init();
	
	    while (1) 
    {
		stand_light_excute(&PORTD);
    }
}

