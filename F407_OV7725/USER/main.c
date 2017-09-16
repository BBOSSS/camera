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

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//…Ë÷√œµÕ≥÷–∂œ”≈œ»º∂∑÷◊È2
	delay_init(168);                               //≥ı ºªØ—” ±∫Ø ˝
	uart_init(115200);														 //≥ı ºªØ¥Æø⁄≤®Ãÿ¬ Œ™115200
	LED_Init();                                    //LED
 	TIM14_PWM_Init(500-1,84-1);                    //84M/84=1Mhz÷ÿ◊∞‘ÿ÷µ500£1M/500=2Khz.  
  SCCB_Init();                                   //SCCB
	Ov7725_GPIO_Config();                          //OV7725 IO ≥ı ºªØ
	LED_ON;
	while(Ov7725_Init() != SUCCESS);               /* ov7725 ºƒ¥Ê∆˜≈‰÷√≥ı ºªØ */
	LED_OFF;
	VSYNC_Init();	
	Ov7725_vsync = 0;                              /* ov7725 ≥°–≈∫≈œﬂ≥ı ºªØ */
	                                      
	while(1)
	{
		if( Ov7725_vsync == 2 )
		{
			LED_ON;
			FIFO_PREPARE;  			/*FIFO◊º±∏*/					
			ImagDisp();					/*≤…ºØ≤¢œ‘ æ*/
			Ov7725_vsync = 0;			
			LED_OFF;
		}
	}

}
