/*
 * main.c
 *
 *  Created on: 2014年7月9日
 *      Author: jin-yc10
 */

#include "stm32f10x.h"
#include "led.h"
#include "usart.h"
#include "misc.h"
#include "stm32f10x_tim.h"
#include <stdio.h>

#define SINGLE_TICK 1
uint32_t g_time = 0;

void tick_init( void );
void led_init( void );
void usart_init( void );

int main()
{
	tick_init();
	led_init();
	LEDOn(LED1);
	usart_init();
	printf("hello world\n\r");
	while(1)
	{
		switch((g_time / 250) % 4)
		{
		case 0:
			LEDToggle(LED1);
			break;
		case 1:
			LEDToggle(LED2);
			break;
		case 2:
			LEDToggle(LED3);
			break;
		case 3:
			LEDToggle(LED4);
			break;
		}
	}
}

void tick_init( void )
{
	RCC_ClocksTypeDef RCC_Clocks;
	RCC_GetClocksFreq(&RCC_Clocks);
	SysTick_Config(RCC_Clocks.HCLK_Frequency / (1000 / SINGLE_TICK));
}

void tick_1ms( void )
{
	g_time += SINGLE_TICK;
}

void led_init(void)
{
	LEDInit(LED1);
	LEDInit(LED2);
	LEDInit(LED3);
	LEDInit(LED4);
}

void usart_init( void )
{
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 38400;
	USART_InitStructure.USART_WordLength =USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;
	COMInit(COM1, &USART_InitStructure);
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
