#include "gd32f10x.h"
#include "gd32f10x_rcu.h"
#include "gd32f10x_gpio.h"

#include <stdbool.h>
void delay(int a);

int main(void){
// Enable clock for GPIOA
	//rcu_periph_clock_enable(RCU_GPIOA);
	// Configure GPIO input pin as in-floating input
	gpio_init(GPIOC,GPIO_MODE_IPD,GPIO_OSPEED_50MHZ,GPIO_PIN_13);
	// Enable clock for GPIOC
	rcu_periph_clock_enable(RCU_GPIOC);
	// Configure GPIO output pin as push-pull output
	gpio_init(GPIOC,GPIO_MODE_OUT_PP,GPIO_OSPEED_50MHZ,GPIO_PIN_0);
	
	bool buttonState= true, booleanState= false; //true:按鈕最後已放,false:按鈕最後未放
	
  while (1)
 {
	 if (gpio_input_bit_get (GPIOC, GPIO_PIN_13) == true && buttonState == true) { //按鈕目前是按下的且按鈕最後是放開的
    booleanState = !booleanState;
		gpio_bit_write(GPIOC, GPIO_PIN_0,(bit_status)booleanState);
		buttonState = false; //按鈕最後狀態改為"不是放開"
  }
  else if (gpio_input_bit_get (GPIOC, GPIO_PIN_13) == false && buttonState == false) { //按鈕目前是放開的且按鈕最後是不是放開的
    buttonState = true; //按鈕最後狀態改為"放開"
  }
 }
}
