/*
 * led.h
 *
 *  Created on: 2014年7月9日
 *      Author: jin-yc10
 */

#ifndef LED_H_
#define LED_H_

#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

#ifdef __cplusplus
 extern "C" {
#endif

#define LEDn                             4

#define LED1_PIN                         GPIO_Pin_1
#define LED1_GPIO_PORT                   GPIOA
#define LED1_GPIO_CLK                    RCC_APB2Periph_GPIOA

#define LED2_PIN                         GPIO_Pin_7
#define LED2_GPIO_PORT                   GPIOA
#define LED2_GPIO_CLK                    RCC_APB2Periph_GPIOA

#define LED3_PIN                         GPIO_Pin_12
#define LED3_GPIO_PORT                   GPIOB
#define LED3_GPIO_CLK                    RCC_APB2Periph_GPIOA

#define LED4_PIN                         GPIO_Pin_3
#define LED4_GPIO_PORT                   GPIOB
#define LED4_GPIO_CLK                    RCC_APB2Periph_GPIOA

typedef enum
{
  LED1 = 0,
  LED2 = 1,
  LED3 = 2,
  LED4 = 3
} Led_TypeDef;

void LEDInit(Led_TypeDef Led);
void LEDOn(Led_TypeDef Led);
void LEDOff(Led_TypeDef Led);
void LEDToggle(Led_TypeDef Led);

#endif /* LED_H_ */
