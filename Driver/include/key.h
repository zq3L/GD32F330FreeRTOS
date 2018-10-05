/*
Decription	:
Author		:Alan Zhang
Date		:2018-09-16 17:48:21
Version		:1.0.0
*/
#ifndef _KEY_H_
#define _KEY_H_

#ifdef GD32F330
typedef enum
{
    keyNone = 0 ,
    key1 = (0x0001<<0) ,
    key2 = (0x0001<<1) ,
}Key;
#endif

#ifdef __cplusplus
extern C{
#endif

void keyInit(void);
Key getKey(void);


#ifdef __cplusplus
}
#endif
#endif
