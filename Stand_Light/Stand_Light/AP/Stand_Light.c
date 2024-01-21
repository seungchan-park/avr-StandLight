#include "Stand_Light.h"

uint8_t ledstate=0;

void stand_light_init()
{
	LED_init(&DDRD);
	Button_init(&btnGo, &DDRA, &PINA, 0);
	Button_init(&btnBack, &DDRA, &PINA, 1);
}

void stand_light_excute(volatile uint8_t *PORT)
{
	switch(ledstate)
	{
		case 0:
		if (Button_getState(&btnGo)==ACT_PUSHED)
		{
			LED_writeData(PORT, 0x00);
			ledstate = 1;
		}
		else if (Button_getState(&btnBack)==ACT_RELEASED)
		{
			LED_writeData(PORT, 0x00);
			ledstate = 0;
		}
		break;
		case 1:
		if (Button_getState(&btnGo)==ACT_PUSHED)
		{
			LED_writeData(PORT, (1<<0)|(1<<1));
			ledstate = 2;
		}
		else if (Button_getState(&btnBack)==ACT_RELEASED)
		{
			LED_writeData(PORT, 0x00);
			ledstate = 0;
		}
		break;
		case 2:
		if (Button_getState(&btnGo)==ACT_PUSHED)
		{
			LED_writeData(PORT, (1<<0)|(1<<1)|(1<<2)|(1<<3));
			ledstate = 3;
		}
		else if (Button_getState(&btnBack)==ACT_RELEASED)
		{
			LED_writeData(PORT, 0x00);
			ledstate = 0;
		}
		break;
		case 3:
		if (Button_getState(&btnGo)==ACT_PUSHED)
		{
			LED_writeData(PORT, (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5));
			ledstate = 4;
		}
		else if (Button_getState(&btnBack)==ACT_RELEASED)
		{
			LED_writeData(PORT, 0x00);
			ledstate = 0;
		}
		break;
		case 4:
		if (Button_getState(&btnGo)==ACT_PUSHED)
		{
			LED_writeData(PORT, (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7));
			ledstate = 0;
		}
		else if (Button_getState(&btnBack)==ACT_RELEASED)
		{
			LED_writeData(PORT, 0x00);
			ledstate = 0;
		}
		break;
	}
}