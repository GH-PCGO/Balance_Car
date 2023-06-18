#include "Ultrasonic.h"
#include "led.h"

int32_t distance = 0;

int main(void)
{
    /* configure systick */
    systick_config();
    // 初始化串口打印
    usart_gpio_dma_config(115200);
    
//    motor_init();
//    motor_set_pwm2(6000);//0
//    motor_set_pwm1(-6000);//-7200
		Ultrasonic_init();
    while(1) {
				led_control();
//        Ultrasonic_get_distance(&distance);
			distance = get_distance();
				printf("distance:%dmm\r\n",distance);
				delay_1ms(1000);
    }
}
