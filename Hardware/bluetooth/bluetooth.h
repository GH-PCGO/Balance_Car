#ifndef __BLUETOOTH_H
#define __BLUETOOTH_H

#include "gd32f4xx.h"
#include "systick.h"
#include "sys.h"
#include "bsp_usart.h"
#include "stdio.h"

#define HC05_EN_RCU  		RCU_GPIOF   	// GPIOF��ʱ��
#define PORT_HC05_EN 		GPIOF			// GPIOF�Ķ˿�
#define HC05_EN_PIN 		GPIO_PIN_10  	// GPIOF������

#define HC05_STATE_RCU  	RCU_GPIOF   	// GPIOF��ʱ��
#define PORT_HC05_STATE 	GPIOF			// GPIOF�Ķ˿�
#define HC05_STATE_PIN 		GPIO_PIN_9  	// GPIOF������

#define EN 		PFout(10)
#define STATE	PFin(9)

void HC05_Bluetooth2_0_config(void);

#endif
