#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "pwm.h"
#include "bsp_sccb.h"
#include "bsp_ov7725.h"

extern uint8_t Ov7725_vsync;

u8 val1 = 0;
int main(void)
{ 

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);                               //初始化延时函数
	uart_init(115200);														 //初始化串口波特率为115200
	LED_Init();                                    //LED
 	TIM14_PWM_Init(500-1,84-1);                    //84M/84=1Mhz重装载值500�1M/500=2Khz.  
  SCCB_Init();                                   //SCCB
	Ov7725_GPIO_Config();                          //OV7725 IO 初始化
	LED_ON;
	while(Ov7725_Init() != SUCCESS);               /* ov7725 寄存器配置初始化 */
	LED_OFF;
	VSYNC_Init();	
	Ov7725_vsync = 0;                              /* ov7725 场信号线初始化 */
	                                      
	while(1)
	{
		if( Ov7725_vsync == 2 )
		{
			LED_ON;
			FIFO_PREPARE;  			/*FIFO准备*/					
			ImagDisp();					/*采集并显示*/
			Ov7725_vsync = 0;			
			LED_OFF;
		}
	}

}
