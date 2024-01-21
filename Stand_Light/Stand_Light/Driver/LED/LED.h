#ifndef LED_H_
#define LED_H_
#include <avr/io.h>
#include <util/delay.h>
#include "../../Peripheral/GPIO/GPIO.h"

void LED_init(volatile uint8_t *DDR);
void LED_writeData(volatile uint8_t *PORT, uint8_t data);
void LED_allOn(volatile uint8_t *PORT);
void LED_allOff(volatile uint8_t *PORT);

#endif