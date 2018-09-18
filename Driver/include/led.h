/*
Decription	:
Author		:Alan Zhang
Date		:2018-09-16 17:48:13
Version		:1.0.0
*/
#ifndef _LED_H_
#define _LED_H_

#include "gpio.h"

typedef enum
{
    LedOff = 0 ,
    LedOn ,        
}LedState ;

typedef struct
{
    unsigned char index ;
    unsigned char size ;
    GPIO* gpio ;
    LedState state ;
}Led;

#ifdef __cplusplus
extern C{
#endif

void ledSet(Led* obj,LedState state);

#ifdef __cplusplus
}
#endif
#endif
