#ifndef SEESAW_CONFIG_H
#define SEESAW_CONFIG_H

#include "RegisterMap.h"

#define VERSION_MAJOR 0x00
#define VERSION_MINOR 0x01
#define VERSION_SUB 0x01
#define CONFIG_VERSION (uint32_t)( ( (uint32_t)VERSION_MAJOR << 16 ) | ((uint32_t)VERSION_MINOR << 8) | VERSION_SUB & 0xFF )

//* ============== POOL SIZES =================== *//
#define	EVT_SIZE_SMALL 32
#define EVT_SIZE_MEDIUM 64
#define	EVT_SIZE_LARGE 128
#define	EVT_COUNT_SMALL 8
#define	EVT_COUNT_MEDIUM 2
#define	EVT_COUNT_LARGE 1

//* ============== ADC =================== *//
#define CONFIG_ADC 0
#define CONFIG_ADC_INPUT_0 1
#define CONFIG_ADC_INPUT_0_PIN 2

#define CONFIG_ADC_INPUT_1 1
#define CONFIG_ADC_INPUT_1_PIN 3

#define CONFIG_ADC_INPUT_2 0
#define CONFIG_ADC_INPUT_2_PIN 4

#define CONFIG_ADC_INPUT_3 0
#define CONFIG_ADC_INPUT_3_PIN 5

//* ============== DAC =================== *//
#define CONFIG_DAC 0

//* ============== TIMER =================== *//
#define CONFIG_TIMER 0

#define CONFIG_TIMER_PWM_OUT0 1
#define CONFIG_TIMER_PWM_OUT0_TC TC1
#define CONFIG_TIMER_PWM_OUT0_WO 0
#define CONFIG_TIMER_PWM_OUT0_PIN 4

#define CONFIG_TIMER_PWM_OUT1 1
#define CONFIG_TIMER_PWM_OUT1_TC TC1
#define CONFIG_TIMER_PWM_OUT1_WO 1
#define CONFIG_TIMER_PWM_OUT1_PIN 5

#define CONFIG_TIMER_PWM_OUT2 0
#define CONFIG_TIMER_PWM_OUT2_TC TC2
#define CONFIG_TIMER_PWM_OUT2_WO 0
#define CONFIG_TIMER_PWM_OUT2_PIN 6

#define CONFIG_TIMER_PWM_OUT3 0
#define CONFIG_TIMER_PWM_OUT3_TC TC2
#define CONFIG_TIMER_PWM_OUT3_WO 1
#define CONFIG_TIMER_PWM_OUT3_PIN 7

//* ============== INTERRUPT =================== *//
#define CONFIG_INTERRUPT 1
#define CONFIG_INTERRUPT_PIN 4

//* ============== I2C SLAVE =================== *//
#define CONFIG_I2C_SLAVE 1

#if defined(__SAMD21G18A__)
	#define CONFIG_I2C_SLAVE_SERCOM SERCOM3
	#define CONFIG_I2C_SLAVE_HANDLER SERCOM3_Handler
	#define CONFIG_I2C_SLAVE_IRQn SERCOM3_IRQn
#else
	#define CONFIG_I2C_SLAVE_SERCOM SERCOM1
	#define CONFIG_I2C_SLAVE_HANDLER SERCOM1_Handler
	#define CONFIG_I2C_SLAVE_IRQn SERCOM1_IRQn
#endif

#define CONFIG_I2C_SLAVE_PIN_SDA 22
#define CONFIG_I2C_SLAVE_PIN_SCL 23

#define CONFIG_I2C_SLAVE_ADDR 0x49

//* ============== SERCOM =================== *//
#define CONFIG_SERCOM0 1
#define CONFIG_SERCOM1 0
#define CONFIG_SERCOM2 0

//These are only available on samd21
#define CONFIG_SERCOM3 0
#define CONFIG_SERCOM4 0
#define CONFIG_SERCOM5 0

#define CONFIG_SERCOM_UART_PIN_RX 11
#define CONfIG_SERCOM_UART_PIN_TX 10
#define CONFIG_SERCOM_UART_PAD_TX UART_TX_PAD_2
#define CONFIG_SERCOM_UART_PAD_RX SERCOM_RX_PAD_3

#define CONFIG_SERCOM_UART_BAUD_RATE 9600
#define CONFIG_SERCOM_UART_CHAR_SIZE UART_CHAR_SIZE_8_BITS

#define CONFIG_SERCOM_UART_PARITY SERCOM_NO_PARITY

#define CONFIG_SERCOM_UART_STOP_BIT SERCOM_STOP_BIT_1

#define CONFIG_NUM_AO (1 + CONFIG_ADC + CONFIG_DAC + CONFIG_TIMER + CONFIG_INTERRUPT + CONFIG_SERCOM0 + CONFIG_SERCOM1 + CONFIG_SERCOM2 + CONFIG_SERCOM3 + CONFIG_SERCOM4 + CONFIG_SERCOM5 + CONFIG_I2C_SLAVE)

#define CONFIG_OPTIONS (uint32_t)( (0x03ul) | ((uint32_t)CONFIG_DAC << SEESAW_DAC_BASE) \
			| ((uint32_t)CONFIG_ADC << SEESAW_ADC_BASE) \
			| ((uint32_t)CONFIG_TIMER << SEESAW_TIMER_BASE) \
			| ((uint32_t)CONFIG_INTERRUPT << SEESAW_INTERRUPT_BASE) \
			| ((uint32_t)CONFIG_SERCOM0 << SEESAW_SERCOM0_BASE) \
			| ((uint32_t)CONFIG_SERCOM1 << SEESAW_SERCOM1_BASE) \
			| ((uint32_t)CONFIG_SERCOM2 << SEESAW_SERCOM2_BASE) \
			| ((uint32_t)CONFIG_SERCOM3 << SEESAW_SERCOM3_BASE) \
			| ((uint32_t)CONFIG_SERCOM4 << SEESAW_SERCOM4_BASE) \
			| ((uint32_t)CONFIG_SERCOM5 << SEESAW_SERCOM5_BASE) )

#endif