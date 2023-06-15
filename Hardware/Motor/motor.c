#include "motor.h"
#include "gd32f4xx.h"
/* PA0 PA1 PA2 PA3*/
void motor_gpio_init(){
	// 开启时钟线
	rcu_periph_clock_enable(RCU_GPIOA);
	// 配置端口复用
	gpio_af_set(GPIOA,GPIO_AF_2,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
	// 配置输出模式
	gpio_mode_set(GPIOA,GPIO_MODE_AF,GPIO_PUPD_NONE,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
	gpio_output_options_set(GPIOA,GPIO_OTYPE_PP,GPIO_OSPEED_50MHZ,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
}

/* 
PA0 TIMER4_CH0  TIMER4_CH1

*/
void motor_timer_init(){
	// 开启时钟线
	rcu_timer_clock_prescaler_config(RCU_TIMER_PSC_MUL4);
	rcu_periph_clock_enable(RCU_TIMER4);
	// 开启定时器配置
	timer_parameter_struct timer_param;
	timer_struct_para_init(&timer_param);
	timer_param.prescaler = 200 - 1;
	timer_param.period = 7200 - 1;
	
	timer_deinit(TIMER4);
	timer_init(TIMER4,&timer_param);
	
	// 开启输出配置
	timer_oc_parameter_struct timer_oc_param;
	timer_channel_output_struct_para_init(&timer_oc_param);
	timer_oc_param.outputstate = TIMER_CCX_ENABLE;
	
	timer_channel_output_config(TIMER4,TIMER_CH_0,&timer_oc_param);
	timer_channel_output_config(TIMER4,TIMER_CH_1,&timer_oc_param);
	
	timer_channel_output_config(TIMER4,TIMER_CH_2,&timer_oc_param);
	timer_channel_output_config(TIMER4,TIMER_CH_3,&timer_oc_param);
	
	// 初始占空比
	timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_0,0);
	timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_1,0);
	
	timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_2,0);
	timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_3,0);
	
	// pwm的模式
	timer_channel_output_mode_config(TIMER4,TIMER_CH_0,TIMER_OC_MODE_PWM0);
	timer_channel_output_mode_config(TIMER4,TIMER_CH_1,TIMER_OC_MODE_PWM0);
	timer_channel_output_mode_config(TIMER4,TIMER_CH_2,TIMER_OC_MODE_PWM0);
	timer_channel_output_mode_config(TIMER4,TIMER_CH_3,TIMER_OC_MODE_PWM0);
	
	// 配置定时器输出,并使能定时器
	timer_primary_output_config(TIMER4,ENABLE);
	timer_enable(TIMER4);
}

void motor_init(){
	// gpio初始化
	motor_gpio_init();
	// timer初始化
	motor_timer_init();
}


void motor_set_pwm(int pwm){
	/* 快衰减
	if(pwm > 0){
		timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_0,pwm);
		timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_1,0);
	}else{
		timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_0,0);
		timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_1,-pwm);
	}*/
	// 慢衰减
	if(pwm > 0){
		timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_0,7200 - pwm);
		timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_1,7200);
	}else{
		timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_0,7200);
		timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_1,7200 + pwm);
	}
}

void motor_set_pwm1(int pwm){
	
	if(pwm > 7100) pwm = 7100;
	if(pwm < -7100) pwm = -7100;
	
	if(pwm > 0){
		timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_0,7200 - pwm);
		timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_1,7200);
	}else{
		timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_0,7200);
		timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_1,7200 + pwm);
	}
}


void motor_set_pwm2(int pwm){
	
	if(pwm > 7100) pwm = 7100;
	if(pwm < -7100) pwm = -7100;
	
	if(pwm > 0){
		timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_2,7200 );
		timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_3,7200- pwm);
	}else{
		timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_2,7200+ pwm);
		timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_3,7200 );
	}

}





#include "systick.h"
void motor_test(){
	motor_init();
	//motor_set_pwm(0);
	
	int pwm = 7200;
	
	while(1){
		motor_set_pwm(pwm);
		
		pwm -= 1000;
		if(pwm < -7200){
			pwm = 7200;
		}
		delay_1ms(500);
	}
}
