/*
Decription	:
Author		:Alan Zhang
Date		:2018-10-04 22:52:31
Version		:1.0.0
*/
#include "taskLed.h"
#include "FreeRTOS.h"
#include "Queue.h"
#include "task.h"
#include "led.h"
#include "gpio.h"

#ifdef GD32F330

static GPIO ledsGpio[] = {{GPIOF,GPIO_PIN_6},{GPIOF,GPIO_PIN_7},};
static Led leds[] = 
{
    {0,1,ledsGpio,LedOff},
    {1,2,ledsGpio+1,LedOff},
};
    
#endif
    
static QueueHandle_t ledQueue ;
static TaskHandle_t ledTaskHandle ;
LedModule ledModules[] = 
{
    {0,LedModeOff},
    {1,LedModeOff}
};

static void ledTask(void * para)
{
    para = para ;
    LedModule ledModuleTmp ;
    while(1)
    {
        if(xQueueReceive(ledQueue,&ledModuleTmp,10) == pdPASS)
        {
            if(ledModules[ledModuleTmp.index].mode != ledModuleTmp.mode)
            {
                ledModules[ledModuleTmp.index].mode = ledModuleTmp.mode ;
            }
            ledSet(leds+ledModuleTmp.index,(LedState)ledModuleTmp.mode);
        }
    }
}


void taskLedInit(void)
{
    ledQueue = xQueueCreate(10, 1);
    if(NULL != ledQueue)
    {
        xTaskCreate(ledTask,"",100,(void*)0,1,&ledTaskHandle);
    }
}


void taskLedSet(LedModule mode)
{
    LedModule ledModuleTmp = mode ;
    if(ledModules[mode.index].mode != mode.mode)
    {
        xQueueSend(ledQueue, &ledModuleTmp, 0);
    }    
}




