#include "gd32f10x.h"
#include "gd32f10x_usart_config.h"

int main(void)
{
	usart_config(USART0,115200);
	usart_config(USART1,115200);
	printf("USART printf example\n");
	printf("123printf example\n");
	//while(RESET == usart_flag_get(USART1 ,USART_FLAG_TC));
}