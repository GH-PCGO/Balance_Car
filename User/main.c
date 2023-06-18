#include "Ultrasonic.h"
#include "led.h"
#include "bsp_usart.h"
#include "bluetooth.h"

int32_t distance = 0;	//超声波测距
extern uint8_t 		g_recv_buff[USART_RECEIVE_LENGTH];   // 接收缓冲区
extern uint16_t 	g_recv_length;						 // 接收数据长度
extern uint8_t		g_recv_complete_flag; 				 // 接收数据完成标志位

uint16_t speed=40;

int main(void)
{
    /* configure systick */
    systick_config();
    // 初始化串口打印
	usart_gpio_config(115200);
	uart6_gpio_config(9600U);
	
	
	while(1){
			/* 等待数据传输完成 */
			if(g_recv_complete_flag)  									// 数据接收完成
			{ 
				g_recv_complete_flag = 0;                   			// 等待下次接收
				printf("g_recv_length:%d ",g_recv_length);  			// 打印接收的数据长度
				printf("g_recv_buff:%s\r\n",g_recv_buff);				// 打印接收的数据
				
				switch(g_recv_buff[0]){
					case 1:
						printf("1");
						break;
					case 2:
						printf("2");//右转
						break;
					case 3:
						printf("3");//左转
						break;
					case 4:
						printf("4");//停止
						break;
					case 5:
						printf("5");//后退
						break;
					case 6:
						printf("6"); //开灯
						break;
					case 7:
						printf("7");//关灯
						break;
					case 8:
						printf("8");//慢速
						break;
					case 9:
						printf("9");//中速
						break;
					case 10:
						printf("10");//快速
						break;
					default:
//						printf("指令错误！！！\r\n");
						break;
				}
					
				memset(g_recv_buff,0,g_recv_length);					// 清空数组
				g_recv_length = 0;										// 清空长度
			}
	}
	
    
//    motor_init();
//    motor_set_pwm2(6000);//0
//    motor_set_pwm1(-6000);//-7200
//		Ultrasonic_init();
//    while(1) {
//				led_control();
////        Ultrasonic_get_distance(&distance);
//			distance = get_distance();
//				printf("distance:%dmm\r\n",distance);
//				delay_1ms(1000);
//    }
}
