#ifndef __MOTOR__H__
#define __MOTOR__H__
#include <stdint.h>
void motor_init();

void motor_set_pwm1(int pwm);
void motor_set_pwm2(int pwm);


void motor_test();

#endif