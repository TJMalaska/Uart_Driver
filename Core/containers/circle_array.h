#pragma once

#include "stm32l4xx.h"

typedef struct circle_array circle_array;
struct circle_array{
    uint8_t arr[50];
    uint32_t read_index;
    uint32_t write_index;
    void (*add)(circle_array * self, uint8_t letter);
    uint8_t (*pop)(circle_array * self);
};

void add(circle_array * self, uint8_t letter);
uint8_t pop(circle_array * self);
void circle_array_init(circle_array * self);
