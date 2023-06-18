#include "bluetooth.h"

/************************************************
�������� �� uart6_send_data
��    �� �� �����ط���һ���ֽ�
��    �� �� ucch��Ҫ���͵��ֽ�
�� �� ֵ �� 
��    �� �� LC
*************************************************/
void uart6_send_data(uint8_t ucch)
{
	usart_data_transmit(BSP_UART6,(uint8_t)ucch);			   // ��������
	while(RESET == usart_flag_get(BSP_UART6,USART_FLAG_TBE));  // �ȴ��������ݻ�������־��λ
}

/************************************************
�������� �� uart6_send_String
��    �� �� ���ڷ����ַ���
��    �� �� ucstr:Ҫ���͵��ַ���
�� �� ֵ �� 
��    �� �� LC
*************************************************/
void uart6_send_string(uint8_t *ucstr)
{
	while(ucstr && *ucstr)        // ��ַΪ�ջ���ֵΪ������
	{
	  uart6_send_data(*ucstr++);  // ���͵����ַ�
	}
}

/*************************************************
�������ܣ�����2.0 HC05 ATָ�����
��ڲ�������
����  ֵ����
**************************************************/
void HC05_Bluetooth2_0_config(void)
{
	/* ʹ��ʱ�� */
	rcu_periph_clock_enable(HC05_EN_RCU);
	/* ����Ϊ���ģʽ ����ģʽ */
	gpio_mode_set(PORT_HC05_EN,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,HC05_EN_PIN);
	/* ����Ϊ������� 50MHZ */
	gpio_output_options_set(PORT_HC05_EN,GPIO_OTYPE_PP,GPIO_OSPEED_50MHZ,HC05_EN_PIN);
	gpio_bit_write(PORT_HC05_EN,HC05_EN_PIN,RESET);
	
	/* ʹ��ʱ�� */
	rcu_periph_clock_enable(HC05_STATE_RCU);
	/* ����Ϊ����ģʽ ����ģʽ */
	gpio_mode_set(PORT_HC05_STATE,GPIO_MODE_INPUT,GPIO_PUPD_NONE,HC05_STATE_PIN);
	
	EN=1;		//PA4��������ߵ�ƽ����EN����Ϊ�ߵ�ƽ������ATָ��ģʽ
	delay_1us(1000000);
#if 0 
	usart_send_string( UART6, "AT+ORGL\r\n");//�ָ���������
	delay_1us(1000000);	
	delay_1us(1000);	
#endif
#if 1
	uart6_send_string("AT\r\n");
	delay_1us(500000);	
	
	uart6_send_string("AT+NAME=Mr.Zhuo\r\n");
	delay_1us(500000);
	
	uart6_send_string("AT+NAME?\r\n");
	delay_1us(500000);
	
	uart6_send_string("AT+ADDR?\r\n");
	delay_1us(500000);
	
	uart6_send_string("AT+RESET\r\n");
	delay_1us(1000000);
	delay_1us(1000000);
#endif
	EN=0;		//PA4��������͵�ƽ����EN����Ϊ�͵�ƽ���˳�ATָ��ģʽ
	delay_1us(1000000);	
}
