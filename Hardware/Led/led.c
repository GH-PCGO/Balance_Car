#include "led.h"

void led_control(){
	//ʹ��ʱ��
	rcu_periph_clock_enable(LED2_RCU);
	//����GPIOģʽ
	gpio_mode_set(LED2_GPIO,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,LED2_PIN);
	//GPIO���ѡ������
	gpio_output_options_set(LED2_GPIO,GPIO_OTYPE_PP,GPIO_OSPEED_2MHZ,LED2_PIN);
	gpio_bit_set(LED2_GPIO,LED2_PIN);
	delay_1ms(250);
	gpio_bit_reset(LED2_GPIO,LED2_PIN);
	
	
	//�󳵵�
	//ʹ��ʱ��
	rcu_periph_clock_enable(LEDL_RCU);
	//����GPIOģʽ
	gpio_mode_set(LEDL_GPIO,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,LEDL_PIN);
	//GPIO���ѡ������
	gpio_output_options_set(LEDL_GPIO,GPIO_OTYPE_PP,GPIO_OSPEED_2MHZ,LEDL_PIN);
	
	
	//�ҳ���
	//ʹ��ʱ��
	rcu_periph_clock_enable(LEDR_RCU);
	//����GPIOģʽ
	gpio_mode_set(LEDR_GPIO,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,LEDR_PIN);
	//GPIO���ѡ������
	gpio_output_options_set(LEDR_GPIO,GPIO_OTYPE_PP,GPIO_OSPEED_2MHZ,LEDR_PIN);
	
	gpio_bit_set(LEDL_GPIO,LEDL_PIN);
	gpio_bit_set(LEDR_GPIO,LEDR_PIN);
	delay_1ms(250);
	gpio_bit_reset(LEDL_GPIO,LEDL_PIN);
	gpio_bit_reset(LEDR_GPIO,LEDR_PIN);
	delay_1ms(250);
	
	
	
}