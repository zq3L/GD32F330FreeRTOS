/*
Decription	:
Author		:Alan Zhang
Date		:2018-09-16 16:12:38
Version		:1.0.0
*/
#include "GD32F3x0.h"
#include "gd32f3x0_libopt.h"

static void gpioInit(void);
static void rccInit(void);

void bspInit(void)
{
    rccInit();
    gpioInit();
}

static void rccInit(void)
{
    rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_GPIOF);
}

static void gpioInit(void)
{
    gpio_mode_set(GPIOA, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO_PIN_0);
    gpio_mode_set(GPIOF,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,GPIO_PIN_6|GPIO_PIN_7);
}

