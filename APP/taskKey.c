/*
Decription	:
Author		:Alan Zhang
Date		:2018-10-05 12:53:12
Version		:1.0.0
*/
#include "taskKey.h"
#include "FreeRTOS.h"
#include "Queue.h"
#include "taskLed.h"
#include "task.h"
#include "key.h"

static TaskHandle_t taskKeyHandle ;

static void taskKey(void *para)
{
    para = para ;
    LedModule writeData ;
    unsigned short keyValue = 0 ;
    while(1)
    {
        keyValue = getKey();
        if(keyValue & key1)
        {
            writeData.index = 0 ;
            writeData.mode = (LedMode)1 ;
            taskLedSet(writeData);
        }else{
            writeData.index = 0 ;
            writeData.mode =(LedMode) 0 ;
            taskLedSet(writeData);
        }
        vTaskDelay(100);
    }
}

void taskKeyInit(void)
{
    xTaskCreate(taskKey,"",20,(void*)0,1,&taskKeyHandle);
}

