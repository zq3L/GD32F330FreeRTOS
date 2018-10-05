/*
Decription	:
Author		:Alan Zhang
Date		:2018-10-04 22:52:31
Version		:1.0.0
*/
#ifndef _TASKLED_H_
#define _TASKLED_H_

#include "typedef.h"

typedef enum
{
    LedModeOff = 0 ,
    LedModeOn,
}LedMode;

typedef struct
{
    unsigned char index         : 7 ;
    LedMode mode                : 1 ;
}LedModule ;

#ifdef __cplusplus
extern C{
#endif

void taskLedInit(void);
void taskLedSet(LedModule mode);


#ifdef __cplusplus
}
#endif
#endif
