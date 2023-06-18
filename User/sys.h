#ifndef _SYS_H
#define _SYS_H

#include "gd32f4xx.h"
#include "systick.h"

#define BIT_ADDR(byte_offset,bit_number) (volatile unsigned long*)(0x42000000 +(byte_offset << 5)+(bit_number << 2))   // λ���������ĵ�ַ
	
#define GPIOA_OCTL_OFFSET ((GPIOA + 0x14) - 0x40000000) 	// ƫ����
#define GPIOB_OCTL_OFFSET ((GPIOB + 0x14) - 0x40000000) 	// ƫ����
#define GPIOC_OCTL_OFFSET ((GPIOC + 0x14) - 0x40000000) 	// ƫ����
#define GPIOD_OCTL_OFFSET ((GPIOD + 0x14) - 0x40000000) 	// ƫ����
#define GPIOE_OCTL_OFFSET ((GPIOE + 0x14) - 0x40000000) 	// ƫ����
#define GPIOF_OCTL_OFFSET ((GPIOF + 0x14) - 0x40000000) 	// ƫ����
#define GPIOG_OCTL_OFFSET ((GPIOG + 0x14) - 0x40000000) 	// ƫ����
#define GPIOH_OCTL_OFFSET ((GPIOH + 0x14) - 0x40000000) 	// ƫ����

#define GPIOA_ISTAT_OFFSET ((GPIOA + 0x10) - 0x40000000) 	// ƫ����
#define GPIOB_ISTAT_OFFSET ((GPIOB + 0x10) - 0x40000000) 	// ƫ����
#define GPIOC_ISTAT_OFFSET ((GPIOC + 0x10) - 0x40000000) 	// ƫ����
#define GPIOD_ISTAT_OFFSET ((GPIOD + 0x10) - 0x40000000) 	// ƫ����
#define GPIOE_ISTAT_OFFSET ((GPIOE + 0x10) - 0x40000000) 	// ƫ����
#define GPIOF_ISTAT_OFFSET ((GPIOF + 0x10) - 0x40000000) 	// ƫ����
#define GPIOG_ISTAT_OFFSET ((GPIOG + 0x10) - 0x40000000) 	// ƫ����
#define GPIOH_ISTAT_OFFSET ((GPIOH + 0x10) - 0x40000000) 	// ƫ����

#define PAout(n)  *(BIT_ADDR(GPIOA_OCTL_OFFSET,n))   		  // PA�����
#define PBout(n)  *(BIT_ADDR(GPIOB_OCTL_OFFSET,n))   		  // PB�����
#define PCout(n)  *(BIT_ADDR(GPIOC_OCTL_OFFSET,n))   		  // PC�����
#define PDout(n)  *(BIT_ADDR(GPIOD_OCTL_OFFSET,n))   		  // PD�����
#define PEout(n)  *(BIT_ADDR(GPIOE_OCTL_OFFSET,n))   		  // PE�����
#define PFout(n)  *(BIT_ADDR(GPIOF_OCTL_OFFSET,n))   		  // PF�����
#define PGout(n)  *(BIT_ADDR(GPIOG_OCTL_OFFSET,n))   		  // PG�����
#define PHout(n)  *(BIT_ADDR(GPIOH_OCTL_OFFSET,n))   		  // PH�����

#define PAin(n)   *(BIT_ADDR(GPIOA_ISTAT_OFFSET,n))   		  // PA������
#define PBin(n)   *(BIT_ADDR(GPIOB_ISTAT_OFFSET,n))   		  // PB������
#define PCin(n)   *(BIT_ADDR(GPIOC_ISTAT_OFFSET,n))   		  // PC������
#define PDin(n)   *(BIT_ADDR(GPIOD_ISTAT_OFFSET,n))   		  // PD������
#define PEin(n)   *(BIT_ADDR(GPIOE_ISTAT_OFFSET,n))   		  // PE������
#define PFin(n)   *(BIT_ADDR(GPIOF_ISTAT_OFFSET,n))   		  // PF������
#define PGin(n)   *(BIT_ADDR(GPIOG_ISTAT_OFFSET,n))   		  // PG������
#define PHin(n)   *(BIT_ADDR(GPIOH_ISTAT_OFFSET,n))   		  // PH������

#endif  /* SYS_H */
