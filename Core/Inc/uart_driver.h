#ifndef uart_driver
#define uart_driver

#include "stm32l4xx.h"

void uart_init(USART_TypeDef *USARTx);
void uart_send_char(USART_TypeDef *USARTx, uint8_t letter);
void uart_send_buffer(USART_TypeDef *USARTx, uint8_t buf[], uint32_t size);
uint8_t uart_receive(USART_TypeDef *USARTx);

#endif 