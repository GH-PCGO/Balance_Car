
#include "inv_mpu.h"
#include "data_show.h"
#include "bluetooth.h"
#include "Ultrasonic.h"


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
    float distance;
    while(1) {
        Ultrasonic_get_distance(&distance);
			printf("distance:%fm\r\n",distance);
				delay_1ms(1000);
    }
}
