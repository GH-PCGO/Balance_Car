#ifndef _BSP_USART_H
#define _BSP_USART_H

#include "gd32f4xx.h"
#include "systick.h"

//���ص��Խӿ�
#define BSP_USART_TX_RCU  	RCU_GPIOA        // ����0TX�Ķ˿�ʱ��
#define BSP_USART_RX_RCU 	RCU_GPIOA        // ����0RX�Ķ˿�ʱ��
#define BSP_USART_RCU     	RCU_USART0       // ����0��ʱ��

#define BSP_USART_TX_PORT 	GPIOA		     // ����TX�Ķ˿�
#define BSP_USART_RX_PORT 	GPIOA			 // ����RX�Ķ˿�
#define BSP_USART_AF 		GPIO_AF_7  		 // ����0�ĸ��ù���
#define BSP_USART_TX_PIN  	GPIO_PIN_9   	 // ����0TX������
#define BSP_USART_RX_PIN  	GPIO_PIN_10 	 // ����0RX������

#define BSP_USART 			USART0      	 // ����0
#define BSP_USART_IRQ     		USART0_IRQn 								// ����0�ж�
#define BSP_USART_IRQHandler  USART0_IRQHandler						// ����0�жϷ�����

//�������ӽӿ�
#define BSP_UART6_TX_RCU  	RCU_GPIOF        // ����6TX�Ķ˿�ʱ��
#define BSP_UART6_RX_RCU 	RCU_GPIOF        // ����6RX�Ķ˿�ʱ��
#define BSP_UART6_RCU     	RCU_UART6        // ����6��ʱ��

#define BSP_UART6_TX_PORT 	GPIOF		     // ����TX�Ķ˿�
#define BSP_UART6_RX_PORT 	GPIOF			 // ����RX�Ķ˿�
#define BSP_UART6_AF 		GPIO_AF_8  		 // ����6�ĸ��ù���
#define BSP_UART6_TX_PIN  	GPIO_PIN_7   	 // ����6TX������
#define BSP_UART6_RX_PIN  	GPIO_PIN_6 	 	 // ����6RX������

#define BSP_UART6 				UART6      	 	 // ����6
#define BSP_UART6_IRQ     		UART6_IRQn 		 // ����6�ж�
#define BSP_UART6_IRQHandler  	UART6_IRQHandler // ����6�жϷ�����

/* ���ڻ����������ݳ��� */
#define USART_RECEIVE_LENGTH  4096

extern uint8_t  g_recv_buff[USART_RECEIVE_LENGTH]; // ���ջ�����
extern uint16_t g_recv_length;					   // �������ݳ���
extern uint8_t  g_recv_complete_flag; 			   // ������ɱ�־λ

void usart_gpio_config(uint32_t band_rate);  // ���ô���0
void usart_send_data(uint8_t ucch);          // ����һ���ַ�
void usart_send_string(uint8_t *ucstr);      // ����һ���ַ���

void uart6_gpio_config(uint32_t band_rate);	 // ���ô���6

#endif  /* BSP_USART_H */

