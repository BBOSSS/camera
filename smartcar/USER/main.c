#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "pwm.h"
#include "bsp_sccb.h"


u8 val1 = 0;
int main(void)
{ 

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//…Ë÷√œµÕ≥÷–∂œ”≈œ»º∂∑÷◊È2
	delay_init(168);                               //≥ı ºªØ—” ±∫Ø ˝
	uart_init(115200);														 //≥ı ºªØ¥Æø⁄≤®Ãÿ¬ Œ™115200
	LED_Init();                                    //LED
 	TIM14_PWM_Init(500-1,84-1);                    //84M/84=1Mhz÷ÿ◊∞‘ÿ÷µ500£1M/500=2Khz.  
  SCCB_Init();                                   //SCCB
	printf("Test\n\n");
	while(1)
	{
    LED_ON;
		delay_ms(1000);
		val1 = SCCB_RD_Reg(0x0b);
		printf("Reg Val = 0x%x\n\n",val1);
		LED_OFF;
		delay_ms(1000);
	}

}
