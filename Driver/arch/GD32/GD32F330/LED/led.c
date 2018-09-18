/*
Decription	:
Author		:Alan Zhang
Date		:2018-09-16 17:48:13
Version		:1.0.0
*/
#include "led.h"
#include "GD32F3x0.h"
#include "gd32f3x0_libopt.h"

void ledSet(Led * obj, LedState state)
{
    unsigned char i = 0 ;
    obj->state = state ;
    for(;i<obj->size;i++)
    {
        state==LedOn?gpio_bit_set(obj->gpio[i].port, obj->gpio[i].pin):gpio_bit_reset(obj->gpio[i].port, obj->gpio[i].pin) ; 
    }
}

