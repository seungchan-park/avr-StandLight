#include "Button.h"

void Button_init(button_t *btn, volatile uint8_t *ddr, uint8_t *pin ,uint8_t pinNum)
{
	btn->DDR = ddr;
	btn->PIN = pin;
	btn->pinNum = pinNum;
	btn->prevState = RELEASED;
	GPIO_initPin(btn->DDR, btn->pinNum, INPUT);
}

uint8_t Button_getState(button_t *btn)
{
	uint8_t curState = GPIO_readPin(btn->PIN,btn->pinNum);
	if ((curState == PUSHED)&&(btn->prevState == RELEASED))
	{
		_delay_ms(10); // bouncing 방지
		btn->prevState = PUSHED;
		return ACT_PUSHED;
	}
	else if ((curState != PUSHED)&&(btn->prevState == PUSHED))
	{
		_delay_ms(10);
		btn->prevState = RELEASED;
		return ACT_RELEASED;
	}
	return ACT_NONE;
}