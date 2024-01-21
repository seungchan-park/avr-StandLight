#include "GPIO.h"

void GPIO_initPort(volatile uint8_t *DDR, uint8_t dir) // DDR 전체 초기화
{
	if (dir == OUTPUT)
	{
		*DDR = 0xff;
	}
	else
	{
		*DDR = 0x00;
	}
}

void GPIO_initPin(volatile uint8_t *DDR, uint8_t pinNum, uint8_t dir) // DDR 부분 초기화
{
	if (dir == OUTPUT)
	{
		*DDR |= (1<<pinNum);
	}
	else
	{
		*DDR &= ~(1<<pinNum);
	}
}

void GPIO_writePort(volatile uint8_t *PORT, uint8_t data) // 전체 출력
{
	*PORT = data;
}

void GPIO_writePin(volatile uint8_t *PORT, uint8_t pinNum, uint8_t state) // 부분 출력
{
	if (state == GPIO_PIN_SET)
	{
		*PORT |= (1<<pinNum);
	}
	else
	{
		*PORT &= ~(1<<pinNum);
	}
	
}

uint8_t GPIO_readPort(volatile uint8_t *PIN) // 전체 입력
{
	return *PIN;
}

uint8_t GPIO_readPin(volatile uint8_t *PIN, uint8_t pinNum) // 부분 입력
{
	return ((*PIN & 1<<pinNum) != 0); // 예를들어 버튼이0b000x0000이면 0인지 아닌지 비교
}