#include "LED.h"

void LED_init(volatile uint8_t *DDR)
{
	GPIO_initPort(DDR,OUTPUT); // &DDR을 쓰면 매개변수의 값이 아닌 매개변수의 주소가 되버린다.
}

void LED_writeData(volatile uint8_t *PORT, uint8_t data)
{
	GPIO_writePort(PORT, data);
}

void LED_allOn(volatile uint8_t *PORT)
{
	GPIO_writePort(PORT, 0xff);
}

void LED_allOff(volatile uint8_t *PORT)
{
	GPIO_writePort(PORT, 0x00);
}