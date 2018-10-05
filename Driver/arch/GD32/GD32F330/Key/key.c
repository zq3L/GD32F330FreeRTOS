/*
Decription	:
Author		:Alan Zhang
Date		:2018-09-16 17:48:21
Version		:1.0.0
*/
#include "../../../../include/key.h"
#include "GD32F3x0.h"
#include "gd32f3x0_gpio.h"


Key getKey(void)
{
    if(gpio_input_bit_get(GPIOA, GPIO_PIN_0))
    {
        return key1 ;
    }
    return keyNone ;
}



