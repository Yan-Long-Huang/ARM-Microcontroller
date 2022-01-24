#include "usart.h"
#include "uart_driver.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "flash.h"
/*
************************************************************
*	�������ƣ�	Usart2_Init
*
*	�������ܣ�	����2��ʼ��
*
*	��ڲ�����	baud���趨�Ĳ�����
*
*	���ز�����	��
*
*	˵����		TX-PA2		RX-PA3
************************************************************
*/
void Usart2_Init(unsigned int baud)
{
  GPIO_InitPara  GPIO_InitStructure;
	USART_InitPara  USART_InitStructure;
	NVIC_InitPara nvicInitStruct;
  /* Enable GPIOA clock */
	RCC_APB2PeriphClock_Enable( RCC_APB2PERIPH_GPIOA  , ENABLE );
	
	/* Enable USART2 APB clock */
	RCC_APB1PeriphClock_Enable( RCC_APB1PERIPH_USART2  , ENABLE );
	/* USART2 Pins configuration **************************************************/
	
	/* Configure the GPIO ports */
 
	GPIO_InitStructure.GPIO_Pin     = GPIO_PIN_2 ;
	GPIO_InitStructure.GPIO_Mode    = GPIO_MODE_AF_PP;
	GPIO_InitStructure.GPIO_Speed   = GPIO_SPEED_50MHZ;
	GPIO_Init( GPIOA , &GPIO_InitStructure); 
	GPIO_InitStructure.GPIO_Pin     = GPIO_PIN_3;
	GPIO_InitStructure.GPIO_Mode    = GPIO_MODE_IN_FLOATING;;
	GPIO_Init( GPIOA , &GPIO_InitStructure); 


	
	
	USART_DeInit( USART2 );        
	USART_InitStructure.USART_BRR                 = baud;
	USART_InitStructure.USART_WL                  = USART_WL_8B;
	USART_InitStructure.USART_STBits              = USART_STBITS_1;
	USART_InitStructure.USART_Parity              = USART_PARITY_RESET;
	USART_InitStructure.USART_HardwareFlowControl = USART_HARDWAREFLOWCONTROL_NONE;
	USART_InitStructure.USART_RxorTx              = USART_RXORTX_RX | USART_RXORTX_TX;
	USART_Init(USART2, &USART_InitStructure);


	/* USART enable */
	USART_Enable(USART2, ENABLE);
	//USART_ITConfig(USART1, USART_IT_IDLE, ENABLE);	
	USART_INT_Set(USART2, USART_INT_RBNE, ENABLE);	//ʹ�ܽ����ж�
	//USART_INT_Set(USART2,USART_INT_IDLEF,ENABLE);//ʹ�ܿ����ж�
	
	nvicInitStruct.NVIC_IRQ = USART2_IRQn;										//usart1�жϺ�
	nvicInitStruct.NVIC_IRQEnable = ENABLE;											//�ж�ͨ��ʹ��
	nvicInitStruct.NVIC_IRQPreemptPriority = 0;						//��ռ�ж����ȼ�(ֵԽС���ȼ�Խ��)
	nvicInitStruct.NVIC_IRQSubPriority = 1;									//���ж����ȼ�(ֵԽС���ȼ�Խ��)
	NVIC_Init(&nvicInitStruct);																			//��ʼ��NVIC
	
	//USART_GetIntBitState(USART2, USART_FLAG_TC);

}

/*
************************************************************
*	�������ƣ�	Usart3_Init
*
*	�������ܣ�	����1��ʼ��
*
*	��ڲ�����	baud���趨�Ĳ�����
*
*	���ز�����	��
*
*	˵����		TX-PB10		RX-PB11
************************************************************
*/
void Usart3_Init(unsigned int baud)
{

	GPIO_InitPara gpioInitStruct;
	USART_InitPara usartInitStruct;
	NVIC_InitPara nvicInitStruct;
	
	RCC_APB2PeriphClock_Enable(RCC_APB2PERIPH_GPIOB, ENABLE);
	RCC_APB1PeriphClock_Enable(RCC_APB1PERIPH_USART3, ENABLE);
	
	//PB10	TXD
	gpioInitStruct.GPIO_Mode = GPIO_MODE_AF_PP;
	gpioInitStruct.GPIO_Pin = GPIO_PIN_10;
	gpioInitStruct.GPIO_Speed = GPIO_SPEED_50MHZ;
	GPIO_Init(GPIOB, &gpioInitStruct);
	
	//PB11	RXD
	gpioInitStruct.GPIO_Mode = GPIO_MODE_IN_FLOATING;
	gpioInitStruct.GPIO_Pin = GPIO_PIN_11;
	gpioInitStruct.GPIO_Speed = GPIO_SPEED_50MHZ;
	GPIO_Init(GPIOB, &gpioInitStruct);
	
	USART_DeInit( USART3 ); 
	
	usartInitStruct.USART_BRR                 = baud;
	usartInitStruct.USART_WL                  = USART_WL_8B;
	usartInitStruct.USART_STBits              = USART_STBITS_1;
	usartInitStruct.USART_Parity              = USART_PARITY_RESET;
	usartInitStruct.USART_HardwareFlowControl = USART_HARDWAREFLOWCONTROL_NONE;
	usartInitStruct.USART_RxorTx              = USART_RXORTX_RX | USART_RXORTX_TX;											//8λ����λ
	USART_Init(USART3, &usartInitStruct);
	USART_Enable(USART3, ENABLE);																										//ʹ�ܴ���
	
	
	USART_INT_Set(USART3, USART_INT_RBNE, ENABLE);	//ʹ�ܽ����ж�
	//USART_INT_Set(USART3,USART_INT_IDLEF,ENABLE);//ʹ�ܿ����ж�																//ʹ�ܽ����ж�
	
	nvicInitStruct.NVIC_IRQ = USART3_IRQn;										//usart3�жϺ�
	nvicInitStruct.NVIC_IRQEnable = ENABLE;											//�ж�ͨ��ʹ��
	nvicInitStruct.NVIC_IRQPreemptPriority = 0;						//��ռ�ж����ȼ�(ֵԽС���ȼ�Խ��)
	nvicInitStruct.NVIC_IRQSubPriority = 2;									//���ж����ȼ�(ֵԽС���ȼ�Խ��)
	NVIC_Init(&nvicInitStruct);																			//��ʼ��NVIC

	NVIC_Init(&nvicInitStruct);
	
	
	//USART_GetIntBitState(USART3, USART_FLAG_TC);
	

}
/*
************************************************************
*	�������ƣ�	Usart1_Init
*
*	�������ܣ�	����1��ʼ��
*
*	��ڲ�����	baud���趨�Ĳ�����
*
*	���ز�����	��
*
*	˵����		TX-PA9		RX-PA10
************************************************************
*/
void Usart1_Init(unsigned int baud)  
{  
	GPIO_InitPara gpioInitStruct;
	USART_InitPara usartInitStruct;
	NVIC_InitPara nvicInitStruct;
	
	RCC_APB2PeriphClock_Enable(RCC_APB2PERIPH_GPIOA, ENABLE);
	RCC_APB2PeriphClock_Enable(RCC_APB2PERIPH_USART1, ENABLE);
	
	//PA9	TXD
	gpioInitStruct.GPIO_Mode = GPIO_MODE_AF_PP;
	gpioInitStruct.GPIO_Pin = GPIO_PIN_9;
	gpioInitStruct.GPIO_Speed = GPIO_SPEED_50MHZ;
	GPIO_Init(GPIOA, &gpioInitStruct);
	
	//PA10	RXD
	gpioInitStruct.GPIO_Mode = GPIO_MODE_IN_FLOATING;
	gpioInitStruct.GPIO_Pin = GPIO_PIN_10;
	gpioInitStruct.GPIO_Speed = GPIO_SPEED_50MHZ;
	GPIO_Init(GPIOA, &gpioInitStruct);
	
	USART_DeInit( USART1 ); 
	
	usartInitStruct.USART_BRR                 = baud;
	usartInitStruct.USART_WL                  = USART_WL_8B;
	usartInitStruct.USART_STBits              = USART_STBITS_1;
	usartInitStruct.USART_Parity              = USART_PARITY_RESET;
	usartInitStruct.USART_HardwareFlowControl = USART_HARDWAREFLOWCONTROL_NONE;
	usartInitStruct.USART_RxorTx              = USART_RXORTX_RX | USART_RXORTX_TX;											//8λ����λ
	USART_Init(USART1, &usartInitStruct);
	USART_Enable(USART1, ENABLE);																										//ʹ�ܴ���
	
//	
//	//USART_INT_Set(USART1, USART_INT_RBNE, ENABLE);	//ʹ�ܽ����ж�
//	//USART_INT_Set(USART1,USART_INT_IDLEF,ENABLE);//ʹ�ܿ����ж�																//ʹ�ܽ����ж�
//	
//	nvicInitStruct.NVIC_IRQ = USART1_IRQn;										//usart3�жϺ�
//	nvicInitStruct.NVIC_IRQEnable = ENABLE;											//�ж�ͨ��ʹ��
//	nvicInitStruct.NVIC_IRQPreemptPriority = 0;						//��ռ�ж����ȼ�(ֵԽС���ȼ�Խ��)
//	nvicInitStruct.NVIC_IRQSubPriority = 3;									//���ж����ȼ�(ֵԽС���ȼ�Խ��)
//	NVIC_Init(&nvicInitStruct);																			//��ʼ��NVIC

//	NVIC_Init(&nvicInitStruct);
//	
//	
//	//USART_GetIntBitState(USART1, USART_FLAG_TC);
}  

/*
************************************************************
*	�������ƣ�	Usart_SendStr
*
*	�������ܣ�	�������ݷ���һ���ֽ�
*
*	��ڲ�����	USARTx��������
*				str��Ҫ���͵�����
*				len�����ݳ���
*
*	���ز�����	��
*
*	˵����		
************************************************************
*/
void Usart_SendStr(USART_TypeDef *USARTx, unsigned char str)
{
		USART_DataSend(USARTx, str);																	//��������
		while(USART_GetBitState(USARTx, USART_FLAG_TBE) == RESET);		//�ȴ��������

}

/*
************************************************************
*	�������ƣ�	Usart_SendString
*
*	�������ܣ�	�������ݷ���
*
*	��ڲ�����	USARTx��������
*				str��Ҫ���͵�����
*				len�����ݳ���
*
*	���ز�����	��
*
*	˵����		
************************************************************
*/
void Usart_SendString(USART_TypeDef *USARTx, unsigned char *str, unsigned short len)
{
	unsigned short count = 0;
	for(; count < len; count++)
	{
		USART_DataSend(USARTx, *str++);									//��������
		while(USART_GetBitState(USARTx, USART_FLAG_TBE) == RESET);		//�ȴ��������
	}
}

/*
************************************************************
*	�������ƣ�	UsartPrintf
*
*	�������ܣ�	��ʽ����ӡ
*
*	��ڲ�����	USARTx��������
*				fmt����������
*
*	���ز�����	��
*
*	˵����		
************************************************************
*/
void UsartPrintf(USART_TypeDef *USARTx, char *fmt,...)
{

	unsigned char UsartPrintfBuf[296];
	va_list ap;
	unsigned char *pStr = UsartPrintfBuf;
	
	va_start(ap, fmt);
	vsprintf((char *)UsartPrintfBuf, fmt, ap);
	va_end(ap);
	
	while(*pStr != 0)
	{
		USART_DataSend(USARTx, *pStr++);
		while(USART_GetBitState(USARTx, USART_FLAG_TBE) == RESET);
	}

}


/*
************************************************************
*	�������ƣ�	USART1_IRQHandler
*
*	�������ܣ�	����1�շ��ж�
*
*	��ڲ�����	��
*
*	���ز�����	��
*
*	˵����		
************************************************************
*/


void USART1_IRQHandler(void)                	//����1�жϷ������
{
	
	if ( USART_GetIntBitState( USART1, USART_INT_RBNE ) != RESET )
	{
		
		USART_ClearIntBitState(USART1, USART_INT_RBNE);	
	  Uart1RxBuffer[Uart1RxCount] = USART_DataReceive(USART1);
		Uart1RxCount++;
		if (Uart1RxCount >= (USART1_RX_BUFFER_SIZE - 2))
		{
			Uart1RxCount = 0;
		}
			
		
	}
}


/*

************************************************************
*	�������ƣ�	USART2_IRQHandler
*
*	�������ܣ�	����2�շ��ж�---ID��
*
*	��ڲ�����	��
*
*	���ز�����	��
*
*	˵����		
************************************************************
*/
void USART2_IRQHandler(void)
{
	
	if(USART_GetIntBitState(USART2,USART_INT_RBNE) != RESET)		//���ָ����USART�жϷ������
	{
		USART_ClearIntBitState(USART2, USART_INT_RBNE);
		Uart2RxBuffer[Uart2RxCount] = USART_DataReceive(USART2);
		Uart2RxCount++;
		if (Uart2RxCount >= (USART2_RX_BUFFER_SIZE - 2))
		{
			Uart2RxCount = 0;
		}
		// Reset Data Receive Timer
		
		
	}
}

/*
************************************************************
*	�������ƣ�	USART1_IRQHandler
*
*	�������ܣ�	����1�շ��ж�
*
*	��ڲ�����	��
*
*	���ز�����	��
*
*	˵����		
************************************************************
*/


void USART3_IRQHandler(void)                	//����1�жϷ������
{
	
	if ( USART_GetIntBitState( USART3, USART_INT_RBNE ) != RESET )
	{
		
		USART_ClearIntBitState(USART3, USART_INT_RBNE);	
	  Uart3RxBuffer[Uart3RxCount] = USART_DataReceive(USART3);
		Uart3RxCount++;
		if (Uart3RxCount >= (USART3_RX_BUFFER_SIZE - 2))
		{
			Uart3RxCount = 0;
		}	
		
	}
}

///*
//************************************************************
//*	�������ƣ�	Asc2Hex
//*
//*	�������ܣ�	ASCII��תHEX
//*
//*	��ڲ�����	��
//*
//*	���ز�����	��
//*
//*	˵����		
//************************************************************
//*/
//unsigned char Asc2Hex(char *str)
//{
//	unsigned char hex = 0;
//	if      ((str[0] > 0x2F) && (str[0] < 0x3A))
//		hex = (str[0] << 4);
//	else if ((str[0] > 0x40) && (str[0] < 0x47))
//		hex = ((str[0]-0x37) << 4);

//	if      ((str[1] > 0x2F) && (str[1] < 0x3A))
//		hex |= (str[1] & 0x0F);
//	else if ((str[1] > 0x40) && (str[1] < 0x47))
//		hex |= (str[1]-0x37);
//	return hex;
//}



///*
//************************************************************
//*	�������ƣ�	Empty_Usart_buf
//*
//*	�������ܣ�	�������
//*
//*	��ڲ�����	��
//*
//*	���ز�����	��
//*
//*	˵����		
//************************************************************
//*/
//void Empty_Usart_buf(void)
//{
//	
//}
////����ָ��
//u8 DeviceParameterLen[MSG_DEVICE_MAXNUM] = {
//  0,
//  6,   //����ʱ��
//  20,  //�ͺ�
//  8,   //��������汾
//  8,   //����Ӳ���汾
//  8,   //ģ������汾
//  8,   //ģ��Ӳ���汾
//  16,  //WIFIģ��MAC
//  20,  //·����SSID
//  15,  //2Gģ��IMEI
//  15,  //2Gģ��IMSI
//  2,   //2Gģ��MNC
//  2,   //2Gģ��MCC
//  1,   //��վ����
//  5,   //��վ1
//  5,   //��վ2
//  5,   //��վ3
//  5,   //��վ4
//  5,   //��վ5
//  5,   //��վ6
//  50,  //ģ�� OTA URL
//  50,  //MCU OTA URL
//	50,  //product key
//	50   //product Secret 
//};
//DeviceParameterT gDeviceParameter = 
//{
//  {0,0,0,0,0,0},
//  "SeaGull_GD",
//  "1.0.7",
//  "1.0.0",
//  "1.0.2",
//  "1.0.0",
////  "B0F89315BF4C0000",  //WIFI MAC string
////  {0xB0,0xF8,0x93,0x15,0xBF,0x4C,0x00,0x00},  //WIFI MAC Hex SN
//	"B0F8933BE5F90000",    
//  {0xB0,0xF8,0x93,0x3B,0xE5,0xF5,0x00,0x00},
//  "Canature", //SSID
//  "001020304050607",
//  {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07},
//  "0102030405060708",
//  0,
//  0,
//  0,
//  {0,0,0},
//  {0,0,0},
//  {0,0,0},
//  {0,0,0},
//  {0,0,0},
//  {0,0,0},
//  "www.canature.com",
//  "www.canature.com",
//  "a1W00QYyJY1",  //WIFI
////	"a1NRXrQiNne", //2G
//  "VrPAotqslHUi2u8U"
//};

//u8 SendBuffer[512];
//u8 CloudSerial = 0;


//u8 CalculateChecksum(u8 * pdata, u16 datalen, u8 offset)
//{
//	u16 idx = 0;
//	u8 checksum = 0;
//	
//	for(idx = offset; idx < datalen; idx++)
//	{
//		checksum += pdata[idx];
//	}
//	// Print Out
////	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: CK(0x%02x) idx(%02d) offset(%d) len(%02d)", FmtTimeShow(),\
//		 checksum, idx, offset, datalen);
//	return checksum;
//}

//u16 data_exchange(u8 *pdata,int mode,u16 len)
//{
///*	
//  mode = SEND:
//	Before: FE 01 78 90 67 FE    BC 56 FD    78 96 FD    89 98 88 FE
//	After:  FE 01 78 90 67 FD 01 BC 56 FD 02 78 96 FD 02 89 98 88 FE

//	mode = RECEIVE:
//	Before: FE 01 78 90 67 FD 01 BC 56 FD 02 78 96 FD 02 89 98 88 FE
//	After:  FE 01 78 90 67 FE    BC 56 FD    78 96 FD    89 98 88 FE	
//*/

//	int idx = 0;
//	int jdx = 0;
//	int kdx = 0;
//	
//	// Print Out
//	//Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] Exchange: %s len(%02d)", FmtTimeShow(),\
//		 mode?"IN":"OUT", len);

//	if(mode==SEND)
//	{
//		// Send data transfer
//		//0xFD -> 0xFD 0x02
//		for(idx= 1; idx < len+kdx-1; idx++)
//		{		
//			if(pdata[idx] == 0xFD)
//			{
//				kdx++;
//				for(jdx=len+kdx-1; jdx > idx+1; jdx--)
//				{
//					pdata[jdx] = pdata[jdx-1];
//				}
//				pdata[idx+1] = 0x02;
//			}
//		}
//		//0xFE -> 0xFD 0x01
//		for(idx = 1; idx < len+kdx-1; idx++)
//		{
//			if(pdata[idx] == 0xFE)
//			{
//				kdx++;
//				for(jdx = len+kdx-1; jdx> idx+1; jdx--)
//				{
//					pdata[jdx] = pdata[jdx-1];
//				}
//				pdata[idx] = 0xFD;
//				pdata[idx+1] = 0x01;
//			}
//		}
//	}
//	else
//	{
//		//mode=1,Receive data transfer
//		//0xFD 0x01 -> 0xFE
//		for(idx = 1; idx < len-kdx-1; idx++)
//		{
//			if((pdata[idx]==0xFD) && (pdata[idx+1]==0x01))
//			{
//				kdx++;
//				for(jdx = idx+1; jdx < len-kdx-1; jdx++)
//				{
//					pdata[jdx] = pdata[jdx+1];
//				}
//				pdata[idx] = 0xFE;
//			}
//		}
//		//0xFD 0x02 -> 0xFD
//		for(idx = 1; idx < len-kdx-1; idx++)
//		{
//			if((pdata[idx]==0xFD) && (pdata[idx+1]==0x02))
//			{
//				kdx++;
//				for(jdx = idx+1; jdx<len-kdx-1 ;jdx++)
//				{
//					pdata[jdx] = pdata[jdx+1];
//				}
//				pdata[idx] = 0xFD;
//			}
//		}
//		pdata[len-kdx-1] = 0xFE;
//		pdata[len-kdx] = 0;
//	}
//	return kdx;	
//}
//void SendDeviceParameter(void)
//{
//	u8 i = 0;
//	u16 len = 0;
//	// Print Out

//	// Clear data
//	memset(SendBuffer, 0, sizeof(SendBuffer));  
//  
//	// Fill head
//	SendBuffer[0] = 0xFE;
//	// Fill type
//	SendBuffer[3] = CloudSerial;
//	CloudSerial ++;
//	// Fill length
//	SendBuffer[4] = 0x30;
//	//command type
//	SendBuffer[5] = 0x05;	
//	//SN
//	for(i=0;i<8;i++)
//	{
//    
//      SendBuffer[6+i] = gDeviceParameter.ModemWifiMacHex[i];
//	}
//  
//	//Product Type
//  
//    SendBuffer[14] = 0x01;

//	//Data Type
//	SendBuffer[15] = 0x02;
//	len = 16;
//  
//	//Data Time
//	SendBuffer[len] = 0x01;	
//	len ++;
//	
//	//Length
//	SendBuffer[len] = 0x06;
//	len ++;
//	SendBuffer[len] = 0x15;
//	len ++;
//	SendBuffer[len] = 0x05;
//	len ++;
//	SendBuffer[len] = 0x16;
//	len ++;
//	SendBuffer[len] = 0x05;
//	len ++;
//	SendBuffer[len] = 0x05;
//	len ++;
//	SendBuffer[len] = 0x05;
//	len ++;

//	//Model Num
//	SendBuffer[len] = 0x02;
//	len ++;
//	//DeviceParameterLen[MSG_DEVICE_MODEL_NUMBER] = strlen((const char *)gDeviceParameter.ModelNum);
//	//Length
//	SendBuffer[len] = 0x15;
//	len ++;
//  
//	//Model Num String
//	for(i=0;i<0x15;i++)
//	{
//		SendBuffer[len+i] = 0;
//	}
//	
//	len = len + 0x15;
//  
//	//Board Firmware Version
//	SendBuffer[len] = 0x03;
//	len ++;
//	DeviceParameterLen[MSG_DEVICE_BORD_FIRMWARE_VERSION] = strlen((const char *)gDeviceParameter.BordFirmwareVersion);
//	//Length
//	SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_BORD_FIRMWARE_VERSION];
//	len ++;
//	//Board Firmware Version String
//	for(i=0;i<DeviceParameterLen[MSG_DEVICE_BORD_FIRMWARE_VERSION];i++)
//	{
//		SendBuffer[len+i] = gDeviceParameter.BordFirmwareVersion[i];
//	}
//	
//	len = len + DeviceParameterLen[MSG_DEVICE_BORD_FIRMWARE_VERSION];
//  
//  //Board Hardware Version
//	SendBuffer[len] = MSG_DEVICE_BORD_HARDWARE_VERSION;
//	len ++;
//	DeviceParameterLen[MSG_DEVICE_BORD_HARDWARE_VERSION] = strlen((const char *)gDeviceParameter.BordHardwareVersion);
//	//Length
//	SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_BORD_HARDWARE_VERSION];
//	len ++;
//	//Board Hardware Version String
//	for(i=0;i<DeviceParameterLen[MSG_DEVICE_BORD_HARDWARE_VERSION];i++)
//	{
//		SendBuffer[len+i] = gDeviceParameter.BordHardwareVersion[i];
//	}
//	
//	len = len + DeviceParameterLen[MSG_DEVICE_BORD_HARDWARE_VERSION];

//  //Modem Firmware Version
//	SendBuffer[len] = MSG_DEVICE_MODEM_FIRMWARE_VERSION;
//	len ++;
//	DeviceParameterLen[MSG_DEVICE_MODEM_FIRMWARE_VERSION] = strlen((const char *)gDeviceParameter.ModemFirmwareVersion);
//	//Length
//	SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_MODEM_FIRMWARE_VERSION];
//	len ++;
//	//Modem Firmware Version String
//	for(i=0;i<DeviceParameterLen[MSG_DEVICE_MODEM_FIRMWARE_VERSION];i++)
//	{
//		SendBuffer[len+i] = gDeviceParameter.ModemFirmwareVersion[i];
//	}
//	
//	len = len + DeviceParameterLen[MSG_DEVICE_MODEM_FIRMWARE_VERSION];
//	
//  //Modem Hardware Version
//	SendBuffer[len] = MSG_DEVICE_MODEM_HARDWARE_VERSION;
//	len ++;
//	DeviceParameterLen[MSG_DEVICE_MODEM_HARDWARE_VERSION] = strlen((const char *)gDeviceParameter.ModemHardwareVersion);
//	//Length
//	SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_MODEM_HARDWARE_VERSION];
//	len ++;
//	//Modem Hardware Version String
//	for(i=0;i<DeviceParameterLen[MSG_DEVICE_MODEM_HARDWARE_VERSION];i++)
//	{
//		SendBuffer[len+i] = gDeviceParameter.ModemHardwareVersion[i];
//	}
//	
//	len = len + DeviceParameterLen[MSG_DEVICE_MODEM_HARDWARE_VERSION];
//	
//    //WIFI Module MAC
//    SendBuffer[len] = MSG_DEVICE_WIFI_MAC;
//    len ++;
//		DeviceParameterLen[MSG_DEVICE_WIFI_MAC] = strlen((const char *)gDeviceParameter.ModemWifiMac);
//    //Length
//    SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_WIFI_MAC];
//    len ++;
//    //WIFI Module MAC String
//    for(i=0;i<DeviceParameterLen[MSG_DEVICE_WIFI_MAC];i++)
//    {
//      SendBuffer[len+i] = gDeviceParameter.ModemWifiMac[i];
//    }
//    
//    len = len + DeviceParameterLen[MSG_DEVICE_WIFI_MAC];

//    //Router SSID
//    SendBuffer[len] = MSG_DEVICE_ROUTER_SSID;
//    len ++;
//		DeviceParameterLen[MSG_DEVICE_ROUTER_SSID] = strlen((const char *)gDeviceParameter.ModemRouterSsid);
//    //Length
//    SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_ROUTER_SSID];
//    len ++;
//    //Router SSID String
//    for(i=0;i<DeviceParameterLen[MSG_DEVICE_ROUTER_SSID];i++)
//    {
//      SendBuffer[len+i] = gDeviceParameter.ModemRouterSsid[i];
//    }
//    
//    len = len + DeviceParameterLen[MSG_DEVICE_ROUTER_SSID];

//    
//  
//	//Module OTA URL
//	SendBuffer[len] = MSG_DEVICE_MODEM_OTA_URL;
//	len ++;
//	DeviceParameterLen[MSG_DEVICE_MODEM_OTA_URL] = strlen((const char *)gDeviceParameter.ModemOtaUrl);
//	//Length
//	SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_MODEM_OTA_URL];
//	len ++;
//	//Module OTA URL String
//	for(i=0;i<DeviceParameterLen[MSG_DEVICE_MODEM_OTA_URL];i++)
//	{
//		SendBuffer[len+i] = gDeviceParameter.ModemOtaUrl[i];
//	}
//	
//	len = len + DeviceParameterLen[MSG_DEVICE_MODEM_OTA_URL];
//	
//	//MCU OTA URL
//	SendBuffer[len] = MSG_DEVICE_MCU_OTA_URL;
//	len ++;
//	DeviceParameterLen[MSG_DEVICE_MCU_OTA_URL] = strlen((const char *)gDeviceParameter.McuOtaUrl);
//	//Length
//	SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_MCU_OTA_URL];
//	len ++;
//	//MCU OTA URL String
//	for(i=0;i<DeviceParameterLen[MSG_DEVICE_MCU_OTA_URL];i++)
//	{
//		SendBuffer[len+i] = gDeviceParameter.McuOtaUrl[i];
//	}
//	
//	len = len + DeviceParameterLen[MSG_DEVICE_MCU_OTA_URL];
//	
//	//data length,2 Byte
//	SendBuffer[1] = (u8)(len>>8);
//	SendBuffer[2] = (u8)len;
//	//check sum
//	SendBuffer[len] = CalculateChecksum(SendBuffer,len,1);
//	len ++;
//	SendBuffer[len] = 0xFE;
//	len ++;
//	
//	//Data exchange
//	len = len + data_exchange(SendBuffer, SEND, len);
//	
//	// Send out
//	PutStrToUart2Modem(SendBuffer, len);
//}

