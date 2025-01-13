#include "circle_array.h"



void add(circle_array * self, uint8_t letter){
    self->arr[self->write_index] = letter;
    if (self->write_index >= sizeof(self->arr) -1 ){
        self->write_index = 0;
    }
    else self->write_index++;
}

uint8_t pop(circle_array * self){
    uint8_t letter = self->arr[self->read_index];
    if (self->read_index >= sizeof(self->arr) -1 ){
        self->read_index = 0;
    }
    else self->read_index++;
    return letter;
}

void circle_array_init(circle_array * self){
    self->read_index =0;
    self->write_index= 0;
    self->add = add;
    self->pop = pop;
}