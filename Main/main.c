/*
Decription	:
Author		:Alan Zhang
Date		:2018-09-16 00:38:18
Version		:1.0.0
*/
#include "main.h"
#include "gd32f3x0.h"

/*
GPIO ledsGpio[] = {{GPIOF,GPIO_PIN_6},{GPIOF,GPIO_PIN_7},};

Led leds = {0,2,ledsGpio,LedOff};
static unsigned char counter = 0 ;


static TaskHandle_t testQueueHandle ;
static void testQueueTask(void* para)
{
    para = para ;
    unsigned char counter = 0 ;
    LedModule writeModule ;
    while(1)
    {
        switch(counter)
        {
            case 0:
            {
                writeModule.index = 0 ;
                writeModule.mode = 1 ;
                counter ++ ;
                break ;
            }
            case 1:
            {
                writeModule.index = 0 ;
                writeModule.mode = 0 ;
                counter ++ ;
                break ;
            }
            case 2:
            {
                writeModule.index = 1 ;
                writeModule.mode = 1 ;
                counter ++ ;
                break ;
            }
            case 3:
            {
                writeModule.index = 1 ;
                writeModule.mode = 0 ;
                counter = 0 ;
                break ;
            }
        }
        taskLedSet(writeModule);
        vTaskDelay(1000);
    }
}
*/

int main(void)
{
    SystemInit();
    systick_config();
    bspInit();
    
    taskLedInit();
    taskKeyInit();
    //xTaskCreate(testQueueTask,"",50,(void*)0,2,&testQueueHandle);
    vTaskStartScheduler();
    while(1)
    {
    }
}

