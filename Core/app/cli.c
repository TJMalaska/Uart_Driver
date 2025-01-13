#include "cli.h"
#include <stdbool.h>

void echo(USART_TypeDef *USARTx){
    static circle_array arr;
    static bool is_init = false;
    //uart_send_char(USARTx, 'a');

    if (is_init == false){
        is_init = true;
        circle_array_init(&arr);
    } 

    uint8_t letter = uart_receive(USARTx);
    arr.add(&arr, letter);
    if(letter == '\n'){
        while (arr.read_index != arr.write_index){
            uart_send_char(USARTx, arr.pop(&arr));
        }
    }
}