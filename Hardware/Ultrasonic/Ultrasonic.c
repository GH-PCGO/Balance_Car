#include "Ultrasonic.h"

//ECHO ���ղ���źţ�����Ϊ��������ģʽ��ECHO��Ĭ��Ϊ�͵�ƽ��
//TRIG ������࣬����Ϊ���ģʽ

void Ultrasonic_init() {
	//����GPIOD�Ķ˿�ʱ��
	rcu_periph_clock_enable(ULTRASONIC_RCU);
	gpio_mode_set(ULTRASONIC_PORT,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,ULTRASONIC_TRIG_PIN);
	gpio_output_options_set(ULTRASONIC_PORT,GPIO_OTYPE_PP,GPIO_OSPEED_50MHZ,ULTRASONIC_TRIG_PIN);
	gpio_bit_write(ULTRASONIC_PORT,ULTRASONIC_TRIG_PIN,RESET);
	
	gpio_mode_set(ULTRASONIC_PORT,GPIO_MODE_INPUT,GPIO_PUPD_PULLDOWN,ULTRASONIC_ECHO_PIN);
	
	
}

//����������
int32_t get_distance()
{
	uint32_t t = 0;
	int32_t d = 0;
	
	Trig = 1;
	delay_1us(20);
	Trig = 0;
	
	t = 0;
	while(Echo==0)
	{
		delay_1us(1);
		t++;
		if(t > 1000000)
			return -1;//��Ӧ��ʱ
			
	}
	t = 0;
	while(Echo){
		delay_1us(9);
		t++;
		
		if(t > 1000000)
			return -2;//������Χ
	}
	
	d = t*3/2;
	
	return d;
	
	
}


////��
//uint8_t Ultrasonic_get_distance(float* distance) {
//	uint16_t cnt = 0;
//	gpio_bit_write(ULTRASONIC_PORT,ULTRASONIC_TRIG_PIN,SET);//ULTRASONIC_TRIG = 1;
//	delay_1ms(1);
//	gpio_bit_write(ULTRASONIC_PORT,ULTRASONIC_TRIG_PIN,RESET);//ULTRASONIC_TRIG = 0;
//	// ����ߵ�ƽ��ʱ��
//	do {
//		cnt++;
//		if(gpio_input_bit_get(ULTRASONIC_PORT,ULTRASONIC_ECHO_PIN) == 1 || cnt > 25) break;
//		delay_1us(10);//Delay10us();
//	} while(gpio_input_bit_get(ULTRASONIC_PORT,ULTRASONIC_ECHO_PIN) == 0);
//	
//	if(cnt > 25) {
//		return 0;
//	}
//	// �ȴ���Ϊ�͵�ƽ
//	cnt = 0;
//	do {
//		// 340 m/s  4 == ? s
//		cnt++;
//		if(gpio_input_bit_get(ULTRASONIC_PORT,ULTRASONIC_ECHO_PIN) == 0 || cnt > 2400) break;
//		delay_1us(10);
//	} while(gpio_input_bit_get(ULTRASONIC_PORT,ULTRASONIC_ECHO_PIN) == 1);
//	
//	if(cnt > 2400 || cnt < 12) {
//		return 0;
//	}
//	// 340 m/s
//	// 340 m/ 1000000 us
//	//   ?m /cnt * 10  us
//	// ? = 340 * cnt * 10 / 1000000 / 2
//	*distance = 34.0 * cnt / 10000 / 2;
//	return 1;
//}
