#ifndef _LED_H
#define _LED_H

#include "gd32f4xx.h"
#include "systick.h"
#include "systick.h"

//GPIOD��ʱ��
#define LED2_RCU RCU_GPIOD
//led2��GPIO���ͣ�A/B/C/D...��
#define LED2_GPIO GPIOD
//led2�����ź�
#define LED2_PIN GPIO_PIN_7
void led_control();

//�ҳ���PG7
#define LEDR_RCU RCU_GPIOG
#define LEDR_GPIO GPIOG
#define LEDR_PIN GPIO_PIN_7

//�󳵵�PA12
#define LEDL_RCU RCU_GPIOA
#define LEDL_GPIO GPIOA
#define LEDL_PIN GPIO_PIN_12
#endif