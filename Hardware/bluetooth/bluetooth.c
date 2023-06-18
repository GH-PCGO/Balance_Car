#include "bluetooth.h"

/************************************************
函数名称 ： uart6_send_data
功    能 ： 串口重发送一个字节
参    数 ： ucch：要发送的字节
返 回 值 ： 
作    者 ： LC
*************************************************/
void uart6_send_data(uint8_t ucch)
{
	usart_data_transmit(BSP_UART6,(uint8_t)ucch);			   // 发送数据
	while(RESET == usart_flag_get(BSP_UART6,USART_FLAG_TBE));  // 等待发送数据缓冲区标志置位
}

/************************************************
函数名称 ： uart6_send_String
功    能 ： 串口发送字符串
参    数 ： ucstr:要发送的字符串
返 回 值 ： 
作    者 ： LC
*************************************************/
void uart6_send_string(uint8_t *ucstr)
{
	while(ucstr && *ucstr)        // 地址为空或者值为空跳出
	{
	  uart6_send_data(*ucstr++);  // 发送单个字符
	}
}

/*************************************************
函数功能：蓝牙2.0 HC05 AT指令测试
入口参数：无
返回  值：无
**************************************************/
void HC05_Bluetooth2_0_config(void)
{
	/* 使能时钟 */
	rcu_periph_clock_enable(HC05_EN_RCU);
	/* 配置为输出模式 浮空模式 */
	gpio_mode_set(PORT_HC05_EN,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,HC05_EN_PIN);
	/* 配置为推挽输出 50MHZ */
	gpio_output_options_set(PORT_HC05_EN,GPIO_OTYPE_PP,GPIO_OSPEED_50MHZ,HC05_EN_PIN);
	gpio_bit_write(PORT_HC05_EN,HC05_EN_PIN,RESET);
	
	/* 使能时钟 */
	rcu_periph_clock_enable(HC05_STATE_RCU);
	/* 配置为输入模式 浮空模式 */
	gpio_mode_set(PORT_HC05_STATE,GPIO_MODE_INPUT,GPIO_PUPD_NONE,HC05_STATE_PIN);
	
	EN=1;		//PA4引脚输出高电平，即EN引脚为高电平，进入AT指令模式
	delay_1us(1000000);
#if 0 
	usart_send_string( UART6, "AT+ORGL\r\n");//恢复出厂配置
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
	EN=0;		//PA4引脚输出低电平，即EN引脚为低电平，退出AT指令模式
	delay_1us(1000000);	
}
