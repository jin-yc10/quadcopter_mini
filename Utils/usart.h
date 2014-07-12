/*
* usart.h
*
*  Created on: 2014年7月12日
*      Author: jin-yc10
*/

#ifndef USART_H_
#define USART_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include "stm32f10x.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"

typedef enum
{
	COM1 = 0,
	COM2 = 1
} COM_TypeDef;
#define USE_USART1 1
#define USE_USART2 1
#define USE_USART3 0

#define COMn                             2

/**
 * @brief Definition for COM port1, connected to USART2 (USART2 pins remapped on GPIOD)
 */
#define EVAL_COM0                       	USART1
#define EVAL_COM0_CLK                   	RCC_APB2Periph_USART1
#define EVAL_COM0_TX_PIN                	GPIO_Pin_9
#define EVAL_COM0_TX_GPIO_PORT          	GPIOA
#define EVAL_COM0_TX_GPIO_CLK           	RCC_APB2Periph_GPIOA
#define EVAL_COM0_RX_PIN                 	GPIO_Pin_10
#define EVAL_COM0_RX_GPIO_PORT           	GPIOA
#define EVAL_COM0_RX_GPIO_CLK            	RCC_APB2Periph_GPIOA
#define EVAL_COM0_IRQn                   	USART1_IRQn

/**
 * @brief Definition for COM port1, connected to USART2 (USART2 pins remapped on GPIOD)
 */
#define EVAL_COM1                        USART2
#define EVAL_COM1_CLK                    RCC_APB1Periph_USART2
#define EVAL_COM1_TX_PIN                 GPIO_Pin_5
#define EVAL_COM1_TX_GPIO_PORT           GPIOD
#define EVAL_COM1_TX_GPIO_CLK            RCC_APB2Periph_GPIOD
#define EVAL_COM1_RX_PIN                 GPIO_Pin_6
#define EVAL_COM1_RX_GPIO_PORT           GPIOD
#define EVAL_COM1_RX_GPIO_CLK            RCC_APB2Periph_GPIOD
#define EVAL_COM1_IRQn                   USART2_IRQn

void COMInit(COM_TypeDef COM, USART_InitTypeDef* USART_InitStruct);
void USART1_IRQHandler( void );
void USART2_IRQHandler( void );
void USART3_IRQHandler( void );

#endif /* USART_H_ */
