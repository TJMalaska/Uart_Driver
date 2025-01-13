#include "uart_driver.h"


void uart_init(USART_TypeDef *USARTx){

    //nvic enable copied from nick
    NVIC_SetPriorityGrouping(0);
    NVIC_SetPriority(USART2_IRQn, NVIC_EncodePriority(0, 6, 0));
    NVIC_EnableIRQ(USART2_IRQn);



    if (USARTx == USART2){
        RCC->APB1ENR1 |= RCC_APB1ENR1_USART2EN;
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
        GPIOA->MODER &= ~(GPIO_MODER_MODE2_Msk | GPIO_MODER_MODE3_Msk);
        GPIOA->MODER |= GPIO_MODER_MODE2_1 | GPIO_MODER_MODE3_1;
        GPIOA->AFR[0] |= 7 << GPIO_AFRL_AFSEL2_Pos | 7 << GPIO_AFRL_AFSEL3_Pos;
    }

    USARTx->CR1 |= USART_CR1_RXNEIE;
    

    uint16_t uartdiv = SystemCoreClock/9600;
    USARTx->BRR = (((uartdiv / 16) << USART_BRR_DIV_MANTISSA_Pos)
                | ((uartdiv % 16) << USART_BRR_DIV_FRACTION_Pos));


    USARTx->CR1 |= USART_CR1_TE;
    USARTx->CR1 |= USART_CR1_RE;

    USARTx->CR1 |= USART_CR1_UE;
}
void uart_send_char(USART_TypeDef *USARTx, uint8_t letter){
    while (!(USARTx->ISR & USART_ISR_TXE));
    USARTx->TDR = letter;
    while(! (USARTx -> ISR & USART_ISR_TC));
}

void uart_send_buffer(USART_TypeDef *USARTx, uint8_t buf[], uint32_t size){
    for(uint32_t i = 0; i < size; i++){
        uart_send_char(USARTx, buf[i]);
    }
}

uint8_t uart_receive(USART_TypeDef *USARTx){
    //static uint8_t str[10];
    uint8_t letter = USARTx->RDR;
    return letter;
    //uart_send_char(USARTx, letter);
}



