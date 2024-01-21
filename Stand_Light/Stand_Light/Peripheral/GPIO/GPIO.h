#ifndef GPIO_H_
#define GPIO_H_
#include <avr/io.h>
#include <util/delay.h>

enum{INPUT, OUTPUT};
enum{GPIO_PIN_SET, GPIO_PIN_RESET};

void GPIO_initPort(volatile uint8_t *DDR, uint8_t dir); // DDR 전체 초기화
void GPIO_initPin(volatile uint8_t *DDR, uint8_t pinNum, uint8_t dir); // DDR 부분 초기화
void GPIO_writePort(volatile uint8_t *PORT, uint8_t data); // 전체 출력
void GPIO_writePin(volatile uint8_t *PORT, uint8_t pinNum, uint8_t state); // 부분 출력
uint8_t GPIO_readPort(volatile uint8_t *PIN); // 전체 입력
uint8_t GPIO_readPin(volatile uint8_t *PIN, uint8_t pinNum); // 부분 입력


#endif