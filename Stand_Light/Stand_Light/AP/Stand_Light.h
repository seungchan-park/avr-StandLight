#ifndef STAND_LIGHT_H_
#define STAND_LIGHT_H_
#include <avr/io.h>
#include <util/delay.h>
#include "../Driver/Button/Button.h"
#include "../Driver/LED/LED.h"

button_t btnGo, btnBack;


void stand_light_init();
void stand_light_excute(volatile uint8_t *PORT);

#endif /* STAND_LIGHT_H_ */