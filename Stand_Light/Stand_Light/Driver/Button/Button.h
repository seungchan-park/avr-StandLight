#ifndef BUTTON_H_
#define BUTTON_H_
#include <avr/io.h>
#include <util/delay.h>
#include "../../Peripheral/GPIO/GPIO.h"

typedef struct _button
{
	volatile uint8_t *DDR;
	volatile uint8_t *PIN;
	uint8_t pinNum;
	uint8_t prevState;
	}button_t;

enum{PUSHED, RELEASED};
enum{ACT_NONE, ACT_PUSHED, ACT_RELEASED};
	
void Button_init(button_t *btn, volatile uint8_t *ddr, uint8_t *pin ,uint8_t pinNum);
uint8_t Button_getState(button_t *btn);

#endif