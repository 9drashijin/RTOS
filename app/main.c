#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "LED.h"
#include "Task.h"
#include "main.h"

void testFunc();
void schedular();

int taskSwitch(int value){
	return value *3;
}

void initSysTick(){
	if(SysTick_Config(SystemCoreClock / 100)){
		while(1);
	}
}

int main(void)
{
	initSysTick();
	//testFunc();
	//schedular();
	initTcb();
	//taskOne();

	//TaskBlock tb1, tb2, tb3, tb4;
	//initTaskBlock(&tb1);
	//initTaskBlock(&tb2);
	//initTaskBlock(&tb3);
	//initTaskBlock(&tb4);

	//initControl();
	//initLED1();
	//initLED2();
	//initLED3();
	//initLED4();

	while(1)
		{
			//blink_LED1();
			//blink_LED2();
			//blink_LED3();

			//blink_LED1_yield(&tb1);
			//blink_LED2_yield(&tb2);
			//blink_LED3_yield(&tb3);
			//blink_4_LEDs(&tb4);
		}
}


