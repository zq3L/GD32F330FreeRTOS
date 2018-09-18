/*
Decription	:
Author		:Alan Zhang
Date		:2018-09-16 00:38:18
Version		:1.0.0
*/
#include "main.h"
#include "gd32f3x0.h"

GPIO ledsGpio[] = {{GPIOF,GPIO_PIN_6},{GPIOF,GPIO_PIN_7},};

Led leds = {0,2,ledsGpio,LedOff};

static unsigned char couter = 0 ;
static void ledTask(void* para)
{
    para = para ;
    while(1)
    {
        if(couter)
        {
            ledSet(&leds, LedOn);
            couter = 0 ;
        }else{
            ledSet(&leds, LedOff);
            couter = 1 ;
        }
        vTaskDelay(1000);
    }
}

int main(void)
{
    SystemInit();
    systick_config();
    bspInit();
    xTaskCreate(ledTask, "", 10, NULL, 4, NULL);
    vTaskStartScheduler();
    while(1)
    {
    }
}

