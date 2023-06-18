#ifndef _LED_H
#define _LED_H

#include "gd32f4xx.h"
#include "systick.h"
#include "systick.h"

//GPIOD的时钟
#define LED2_RCU RCU_GPIOD
//led2的GPIO类型（A/B/C/D...）
#define LED2_GPIO GPIOD
//led2的引脚号
#define LED2_PIN GPIO_PIN_7
void led_control();

//右车灯PG7
#define LEDR_RCU RCU_GPIOG
#define LEDR_GPIO GPIOG
#define LEDR_PIN GPIO_PIN_7

//左车灯PA12
#define LEDL_RCU RCU_GPIOA
#define LEDL_GPIO GPIOA
#define LEDL_PIN GPIO_PIN_12
#endif