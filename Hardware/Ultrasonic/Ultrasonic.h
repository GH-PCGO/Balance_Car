#ifndef __ULTRASONIC_H__
#define __ULTRASONIC_H__

#include "gd32f4xx.h"
#include "systick.h"
#include "sys.h"

//³¬Éù²¨µÄÊ±ÖÓ
#define ULTRASONIC_RCU RCU_GPIOB

#define ULTRASONIC_PORT GPIOB
#define ULTRASONIC_TRIG_PIN GPIO_PIN_12
#define ULTRASONIC_ECHO_PIN GPIO_PIN_10

#define Echo  PBin(10)
#define Trig  PBout(12)

//#define ULTRASONIC_PIN_INIT() {P1M0 &= ~0x08; P1M1 &= ~0x08;P4M0 &= ~0x01; P4M1 &= ~0x01; }

void Ultrasonic_init();
//Ã×
//uint8_t Ultrasonic_get_distance(float* distance);

//mm
int32_t get_distance();


#endif