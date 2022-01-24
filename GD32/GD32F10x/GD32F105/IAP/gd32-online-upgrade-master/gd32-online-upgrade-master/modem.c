/*******************************************************************************
* File Name          : modem.c
* Author             : lizhifei
* Description        : This file provides all the modem functions.

* History:
* 2021/01/26 : version V1.00
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "modem.h"
//#include "ntc.h"
//#include "atcmd.h"
#include "uart_driver.h"
#include "rtcclock.h"
//#include "queue.h"
#include "initialization.h"
//#include "protocol.h"
//#include "usart.h"
#include "usrtimer.h"
#include "flash.h"
//#include "externalrtc.h"
#include "flow.h"
#include "control.h"
#include "main.h"
#include "fliter.h"
#include "systick.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
static u8 ModemATPortStatus = FALSE;
static u8 ModemTransmittingStatus = FALSE;
static u8 ModemPowerOnFlag = FALSE;
u8 ProductKeyWifi[] = "a1LPpt2Qhxc";  //���ʹ�ˮWIFI
u8 ProductKey2G[] = "a1LPpt2Qhxc";  //���ʹ�ˮ2G
//u8 ModemType = MODEM_2G;
u8 ModemType = MODEM_WIFI;
PeriodicSyncTimeT SendState = SEND_DEVICE_PARAMETER_STATE;
u8 ProduceClearFlag = 0 ;
//device parameter data len
u8 DeviceParameterLen[MSG_DEVICE_MAXNUM] = {
  0,
  6,   //����ʱ��
  20,  //�ͺ�
  8,   //��������汾
  8,   //����Ӳ���汾
  8,   //ģ������汾
  8,   //ģ��Ӳ���汾
  16,  //WIFIģ��MAC
  20,  //·����SSID
  15,  //2Gģ��IMEI
  15,  //2Gģ��IMSI
  2,   //2Gģ��MNC
  2,   //2Gģ��MCC
  1,   //��վ����
  5,   //��վ1
  5,   //��վ2
  5,   //��վ3
  5,   //��վ4
  5,   //��վ5
  5,   //��վ6
  50,  //ģ�� OTA URL
  50,  //MCU OTA URL
	50,  //product key
	50   //product Secret 
};

//device display data len
u8 DeviceDisplayLen[MSG_DISPLAY_MAXNUM] = {
  0,
  6,  //����ʱ��
  2,  //PPֵ
  2,  //C1ֵ
  2,  //ROֵ
  2,  //C2ֵ
  2,  //NFֵ
  2,  //��ˮTDS����ˮ��
  2,  //ԭˮTDS����ˮ��
  2,  //��ˮTDS
  1,  //��ˮTOC
  1,  //ԭˮTOC
  2,  //��ˮ��ʾ�¶�
  2,  //ԭˮ��ˮ�¶� 
  2,  //��ˮ�¶�
  2,  //����ˮ��
  4,  //�ܾ�ˮ��������ˮ��
  2,  //��ˮ�ܷ�ˮ�������գ�
  2,  //��ˮ�ܷ�ˮ�������գ�
  2,  //��ˮ��ˮ�������Σ�
  2,  //��ˮ��ˮ�������Σ�
  2,  //���ۼ���ˮ��
  4,  //���ۼ���ˮ��
  2,  //�ۼ���ˮʱ��
  2,  //�ۼ�����ʱ��
  2,  //�ۼ�ʹ�ô���
  1,  //��ʹ�ô���
  2,  //��ˮ����
  2,  //��ˮ����
  2,  //��ˮ����
  1,  //ˮ��1����
  1,  //ˮ��2����
  1,  //ROĤ1Ĥǰѹ��
  1,  //ROĤ2Ĥǰѹ��
  1,  //����ѹ��
  2,  //��������ʱ��
  2,  //Сʱ�ۼ���
  2,  //��ǰ����
  2,  //�����������
  2,  //�����ۼƴ���
  2,  //��������ˮ��
  2,  //ʣ��������
  2,  //��������ʱ��
  1,  //�����������
  2,  //��ϴ����ʱ��
  1,  //��ϴ�������
  1,  //ȱ����ʾ
  17, //�Ĳ�1
  17, //�Ĳ�2
  17, //�Ĳ�3
  17, //�Ĳ�4
  17, //�Ĳ�5
  17, //�Ĳ�6
  17, //�Ĳ�7
  1,  //�ź�ǿ��
  1,  //����
  5,  //����
  1,	//����״̬
  1,	//����״̬
  2,	//��ˮ������ʣ��ˮ��
  1,	//��ˮ��������־
  1,	//��ˮ��������־
  1,	//�ϵ��ˮ����
  2,	//��ˮ���ܴ���ˮ��
  2,	//��ˮ���ܴ���ˮ��
  1, 	//����ʣ��ʱ��
  2,  //UFֵ
  1,  //UV״̬
  1,  //��ѹ����״̬
  1,  //Һλ��״̬
  1,  //����ˮ
  1,  //����ˮ
  1,  //ͯ������
  1,  //��ˮ����
  1,  //��ˮ����
  1,   //���ð���
  4
};

u8 UserSetParameterLen[MSG_USER_SET_MAXNUM] = {
  0,
  6,   //����ʱ��
  1,   //���ȱ�������
  1,   //�����¶�����
  1,   //��ʱ���ػ�
  1,   //����ʱ��
  1,   //�ػ�ʱ��
  1,   //��ʱ���ȿ���
  1,   //��������ʱ��
  1,   //����ֹͣʱ��
  1,   //���䱣������
  1,   //ǿ�Ʒ���ˮʱ��
  1,   //��ʱ����
  1,   //��ʱ���俪��ʱ��
  1,   //��ʱ�������ʱ��
  1,   //��ˮģʽ
  1,   //ͯ��ģʽ
  1,   //��ˮ����
  1,   //ɱ��ʱ��
  1,   //��ʱɱ����
  1,   //LED��������
  1,   //һ���ſ�����
  1,   //����ģʽ����
  1,   //ɱ������
  1,   //ȱ����ʾ����
  1,   //�����κģ���Ч��
  2,   //Ӳ������
  2,   //��Ԥ��ˮ������
  1,   //��ˮ����
  2,   //�Զ�������ˮ��
  2,   //��������ʱ��
  1,   //�����������
  2,   //��ϴ����ʱ��
  1,   //��ϴ�������
  1,   //���������ۼ�����ϴ�
  6,   //�Ĳ�1
  6,   //�Ĳ�2
  6,   //�Ĳ�3
  6,   //�Ĳ�4
  6,   //�Ĳ�5
  6,   //�Ĳ�6
  6,   //�Ĳ�7
  1,   //����������ʱ�临λ
  1,   //��о��λ  
  1    //��ʱTOC���
};

u8 UserOperateParemeterLen[MSG_USER_OPERATE_MAXNUM] = {
  0,
  6,   //����ʱ��
  1,   //��Դ����
  1,   //���ȿ���
  1,   //���俪��
  1,   //ɱ������
  1,   //����״̬��ˮ��״̬��
  1,   //���ҿ���
  1,   //ǿ������
  1,   //ԤԼ����
  1,   //ǿ�Ƴ�ϴ
  1,   //ԤԼ��ϴ 
  1	   //�Զ�Ϩ������
};

u8 ServiceParameterLen[MSG_SERVICE_MAXNUM] = {
  0,
  6,   //����ʱ��
  2,   //PP��������
  2,   //C1��������
  2,   //RO��������
  2,   //C2��������
  2,   //NF��������
  1,   //��ˮ�����
  2,   //�ɷ�ˮ����
  2,   //ԭˮTDS����
  2,   //��ˮTDS����
  1,   //ԭˮT0C����
  1,   //��ˮTOC����
  1,   //һ���ſ�����
  2,   //�����߶�����
  1,   //�����ϴ���ֵ
  1,   //����ģʽ��ϴʱ��
  1,   //����ģʽ��ϴʱ��
  1,   //��ϴʱ��
  1,   //��ϴʱ��
  1,   //����ʱ��
  1,   //��ˮʱ��
  1,   //����Ч��
  1    //���Ź���ģʽ
};

u8 LeaseBussinessParemeterLen[MSG_LEASE_MAXNUM] = {
  0,
  6, //����ʱ��
  2, //������ˮ��ˮ�������Σ�
  2, //������ˮ��ˮ�������Σ�
  2, //�����ˮ��ˮ�������Σ�
  2, //������ˮ��ˮʱ�䣨���Σ�
  2, //������ˮ��ˮʱ�䣨���Σ�
  2, //�����ˮ��ˮʱ�䣨���Σ�
  1, //����ʣ��ʱ������
  1 //��ˮ�����
};

u8 ThirdParameterLen[MSG_THIRD_MAXNUM] = {
  0,
  6,  //����ʱ��
  1,  //����
  2,  //��������PM2.5
  2,   //�¶�
  2   //���θ߶�
};

u8 LimitLen[MSG_LIMIT_MAXNUM] = {
  0,
  6,  //����ʱ��
  1  //Ȩ��
};

u8 InternetDateTimeLen[MSG_INTERNET_MAXNUM] = {
  0,
  6  //����ʱ��
};

DeviceParam gDeviceParam =
{
	SYS_MAGIC,
	0,
	0,
	0,
	FALSE,
	FALSE,
	// SysParamT
	{TRUE,	FALSE,	TRUE,	FALSE},
	// BatterParamT
	{TRUE,	TRUE,	3500,	3400},
	// TempParamT
	{
		INITIAL,
		-100,
		0,
		{
			FALSE,
			100,//NTC_X_LIMIT_DEFAULT,	// > Xlimit (report NTC)
			200,//NTC_Y_LIMIT_DEFAULT,	// < Ylimit (report SHT)
		},
	},
	// MemsParamT
	{
		{0},
		{FALSE, 0},
		0,
		0,
		0,
	},
	// LightParamT
	{
		LIGHT_THRESHOLD,
		0,
		LIGHT_EVT_INIT_BOX
	},
	// PeriodParamT
	{
		10,//MOVE_RPT_TIME,
		10,//MOVE_RPT_TIME
	},
	// SubMcuVersion
	"",
};

ControlStateT gControlState;
DeviceParameterT gDeviceParameter = 
{
  {0,0,0,0,0,0},
  "SeaGull_GD",
  "1.0.7",
  "1.0.0",
  "00000001",
  "00000001",
//  "B0F89315BF4C0000",  //WIFI MAC string
//  {0xB0,0xF8,0x93,0x15,0xBF,0x4C,0x00,0x00},  //WIFI MAC Hex
	"B0F8933BE5F90000",    
  {0xB0,0xF8,0x93,0x3B,0xE5,0xF5,0x00,0x00},
  "Canature", //SSID
  "001020304050607",
  {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07},
  "0102030405060708",
  0,
  0,
  0,
  {0,0,0},
  {0,0,0},
  {0,0,0},
  {0,0,0},
  {0,0,0},
  {0,0,0},
  "www.canature.com",
  "www.canature.com",
  "a1W00QYyJY1",  //WIFI
//	"a1NRXrQiNne", //2G
  "VrPAotqslHUi2u8U"
};

DeviceDisplayT gDeviceDisplay;
UserSetParameterT gUserSetParameter;
UserOperateParemeterT gUserOperateParemeter;
ServiceParameterT gServiceParameter;
LeaseBussinessParemeterT gLeaseBussinessParemeter;
ThirdParameterT gThirdParameter;
LimitT gLimit;
InternetDateTimeT gInternetDateTime;
    
u8 SendBuffer[USART2_TX_BUFFER_SIZE];

void SetModemATPortStat(u8 Status)
{
	ModemATPortStatus = Status;
}

u8 GetModemATPortStat(void)
{
	return ModemATPortStatus;
}

void SetModemTransmittingStat(u8 Status)
{
	ModemTransmittingStatus = Status;
}

u8 GetModemTransmittingStat(void)
{
	return ModemTransmittingStatus;
}

u8 GetModemPoweronStat(void)
{
	return ModemPowerOnFlag;
}

void SetAllowShutdownStat(u8 Status)
{
	gDeviceParam.System.AllowShutdownFlag = Status;
}

u8 GetAllowShutdownStat(void)
{
	return gDeviceParam.System.AllowShutdownFlag;
}

void SetSysShutdownStat(u8 Status)
{
	gDeviceParam.System.ShutdownStatus = Status;
}

u8 GetSysShutdownStat(void)
{
	return gDeviceParam.System.ShutdownStatus;
}

void SetSysShutdownAction(u8 Status)
{
	gDeviceParam.System.ShutdownAction = Status;
}

u8 GetSysShutdownAction(void)
{
	return gDeviceParam.System.ShutdownAction;
}

u8 GetDeviceInstallStat(void)
{
	return FALSE;
}

void SetModemFactoryState(u8 status)
{
  gControlState.ModemFactoryState = status;
}

u8 GetModemFactoryState(void)
{
  return gControlState.ModemFactoryState;
}

void SetConnectInternetState(u8 status)
{
  gControlState.ConnectInternetState = status;
}

u8 GetConnectInternetState(void)
{
  return gControlState.ConnectInternetState;
}

void SetModemOtaState(u8 status)
{
  gControlState.OtaModemState = status;
}

u8 GetModemOtaState(void)
{
  return gControlState.OtaModemState;
}

void SetMcuOtaState(u8 status)
{
  gControlState.OtaMcuState = status;
}

u8 GetMcuOtaState(void)
{
  return gControlState.OtaMcuState;
}

void SetReportDeviceState(u8 status)
{
  gControlState.ReportDeviceState = status;
}

u8 GetReportDeviceState(void)
{
  return gControlState.ReportDeviceState;
}

void SetModemInformationState(u8 status)
{
  gControlState.ModemInformationState = status;
}

u8 GetModemInformationState(void)
{
  return gControlState.ModemInformationState;
}

void SetRepeatProductKeyState(u8 status)
{
	 gControlState.RepeatProductKey = status;
}

u8 GetRepeatProductKeyState(void)
{
	return gControlState.ModemInformationState;
}

void SetReportProduceState(u8 status)
{
	gControlState.ReportProduce = status;
}

u8 GetReportProduceState(void)
{
	return gControlState.ReportProduce;
}

void SetFactoryState(u8 status)
{
	gControlState.FactoryEnd = status;
}

u8 GetFactoryState(void)
{
	return gControlState.FactoryEnd;
}

void SetTelephoneConnectState(u8 status)
{
	gControlState.TelephoneConnect = status;
}

u8 GetTelephoneConnectState(void)
{
	return gControlState.TelephoneConnect;
}

void SetInternetLedBlinkState(u8 status)
{
	gControlState.InternetLedBlink = status;
}

u8 GetInternetLedBlinkState(void)
{
	return gControlState.InternetLedBlink;
}

void SetCurrentErrorState(u8 status)
{
	gControlState.CurrentError = status;
}

u8 GetCurrentErrorState(void)
{
	return gControlState.CurrentError;
}

void CDMAPowerEnControl(FunctionalState Status, u8 Trace)
{
	// Print Out
//Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Ctl(%d %d) Q(%d) Evt(0x%04X)",FmtTimeShow(),\
//		FmtTimeShow(), \
//		Status, Trace, \
//		GetEvtQueTotalNumer(), \
//		GetSystemEventMode());
//	// High level poweron
	if(Status == ENABLE_MODEM)
	{
		// Print Out
//		Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Poweron", FmtTimeShow());
		// Power on
		ModemResetControl(DISABLE_MODEM);
		ModemStartupControl(DISABLE_MODEM);
		// Open Power
//		HAL_GPIO_WritePin(PC2_MODEM_EN_GPIO_Port,PC2_MODEM_EN_Pin,GPIO_PIN_SET);
		// Set Flag
		ModemPowerOnFlag = TRUE;
		// Delay
		Delay_1ms(20);
		// Startup...
		ModemStartupControl(ENABLE_MODEM);
		// Delay
		Delay_1ms(2500/*1000*/);		// 01/15/2018 Change for some device cannot power on
		// Startup...
		ModemStartupControl(DISABLE_MODEM);
	}
	else if(Status == DISABLE_MODEM)
	{
		// Print Out
		Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Poweroff", FmtTimeShow());
		// Clear Flag
		ModemPowerOnFlag = FALSE;
		// Clear Status
		SetModemATPortStat(FALSE);
		// Set flag
		SetModemTransmittingStat(FALSE);
		// Modem power off
		ModemResetControl(DISABLE_MODEM);
		ModemStartupControl(DISABLE_MODEM);
		// Close power
//		HAL_GPIO_WritePin(PC2_MODEM_EN_GPIO_Port,PC2_MODEM_EN_Pin,GPIO_PIN_RESET);
	}
}

void ModemStartupControl(FunctionalState Status)
{
	// Low level startup
	if(Status == ENABLE_MODEM)
  {
//		HAL_GPIO_WritePin(PC6_GSM_PWR_KEY_GPIO_Port,PC6_GSM_PWR_KEY_Pin,GPIO_PIN_RESET);
  }
	else if(Status == DISABLE_MODEM)
  {
//		HAL_GPIO_WritePin(PC6_GSM_PWR_KEY_GPIO_Port,PC6_GSM_PWR_KEY_Pin,GPIO_PIN_SET);
  }
}

void ModemResetControl(FunctionalState Status)
{
	// Low level reset
	if(Status == ENABLE_MODEM)
  {
//		HAL_GPIO_WritePin(PC4_MODEM_RST_GPIO_Port,PC4_MODEM_RST_Pin,GPIO_PIN_RESET);
  }
	else if(Status == DISABLE_MODEM)
  {
//		HAL_GPIO_WritePin(PC4_MODEM_RST_GPIO_Port,PC4_MODEM_RST_Pin,GPIO_PIN_SET);
  }
}

u8 CalculateChecksum(u8 * pdata, u16 datalen, u8 offset)
{
	u16 idx = 0;
	u8 checksum = 0;
	
	for(idx = offset; idx < datalen; idx++)
	{
		checksum += pdata[idx];
	}
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: CK(0x%02x) idx(%02d) offset(%d) len(%02d)", FmtTimeShow(),\
		 checksum, idx, offset, datalen);
	return checksum;
}

u16 data_exchange(u8 *pdata,int mode,u16 len)
{
/*	
  mode = SEND:
	Before: FE 01 78 90 67 FE    BC 56 FD    78 96 FD    89 98 88 FE
	After:  FE 01 78 90 67 FD 01 BC 56 FD 02 78 96 FD 02 89 98 88 FE

	mode = RECEIVE:
	Before: FE 01 78 90 67 FD 01 BC 56 FD 02 78 96 FD 02 89 98 88 FE
	After:  FE 01 78 90 67 FE    BC 56 FD    78 96 FD    89 98 88 FE	
*/

	int idx = 0;
	int jdx = 0;
	int kdx = 0;
	
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] Exchange: %s len(%02d)", FmtTimeShow(),\
		 mode?"IN":"OUT", len);

	if(mode==SEND)
	{
		// Send data transfer
		//0xFD -> 0xFD 0x02
		for(idx= 1; idx < len+kdx-1; idx++)
		{		
			if(pdata[idx] == 0xFD)
			{
				kdx++;
				for(jdx=len+kdx-1; jdx > idx+1; jdx--)
				{
					pdata[jdx] = pdata[jdx-1];
				}
				pdata[idx+1] = 0x02;
			}
		}
		//0xFE -> 0xFD 0x01
		for(idx = 1; idx < len+kdx-1; idx++)
		{
			if(pdata[idx] == 0xFE)
			{
				kdx++;
				for(jdx = len+kdx-1; jdx> idx+1; jdx--)
				{
					pdata[jdx] = pdata[jdx-1];
				}
				pdata[idx] = 0xFD;
				pdata[idx+1] = 0x01;
			}
		}
	}
	else
	{
		//mode=1,Receive data transfer
		//0xFD 0x01 -> 0xFE
		for(idx = 1; idx < len-kdx-1; idx++)
		{
			if((pdata[idx]==0xFD) && (pdata[idx+1]==0x01))
			{
				kdx++;
				for(jdx = idx+1; jdx < len-kdx-1; jdx++)
				{
					pdata[jdx] = pdata[jdx+1];
				}
				pdata[idx] = 0xFE;
			}
		}
		//0xFD 0x02 -> 0xFD
		for(idx = 1; idx < len-kdx-1; idx++)
		{
			if((pdata[idx]==0xFD) && (pdata[idx+1]==0x02))
			{
				kdx++;
				for(jdx = idx+1; jdx<len-kdx-1 ;jdx++)
				{
					pdata[jdx] = pdata[jdx+1];
				}
				pdata[idx] = 0xFD;
			}
		}
		pdata[len-kdx-1] = 0xFE;
		pdata[len-kdx] = 0;
	}
	return kdx;	
}

void ReportDataToModem(u8 *pdata, u16 datalen, SYSMsgTypeT msgtype)
{
	u16 len = 0;

	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Report Data To Modem", FmtTimeShow());


	// Clear data
	memset(SendBuffer, 0, sizeof(SendBuffer));

	// Fill head
	SendBuffer[0] = SYS_SYNC_HEAD;
	len += 1;

	// Fill type
	SendBuffer[len] = msgtype;
	len += 1;
	
	// Fill length
	SendBuffer[len] = datalen;
	len += 1;

	// Fill data
	if(datalen != 0)
	{
		memcpy(SendBuffer + len, pdata, datalen);
		len += datalen;
	}

	// Chech sum
	SendBuffer[len] = CalculateChecksum(SendBuffer, len, 1);
	len += 1;

	// Msg tail
	SendBuffer[len] = SYS_SYNC_HEAD;
	len += 1;

	//Data exchange
	len = len + data_exchange(SendBuffer, SEND, len);
	
	// Send out
	PutStrToUart2Modem(SendBuffer, len);
}

u8 ControlModem(MSGMcuToModemT msgtype,u8 cmd)
{
	u16 len = 0;
  u8 i;
	u8 Serial;
  static u8 ModemSerial = 0;
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Control Modem CMD %d", FmtTimeShow(),msgtype);

	// Clear data
	memset(SendBuffer, 0, sizeof(SendBuffer));  
  
	// Fill head
	SendBuffer[0] = SYS_SYNC_HEAD;
	// Fill type
	SendBuffer[3] = ModemSerial;
	Serial = ModemSerial;
	ModemSerial ++;
	// Fill length
	SendBuffer[4] = 0x30;
	//command type
	SendBuffer[5] = COMMAND_TYPE_MCU_TO_MODEM;
	
	switch(msgtype)
	{
		case MSG_MCU_GET_MODEM_INFORMATION:
		{
			SoftwareTimerReset(&GetModemInformationTimer,GetModemInformationCallback,GET_MODEM_INFORMATION_TIMEOUT);
			SoftwareTimerStart(&GetModemInformationTimer);	 
			
			SendBuffer[6] = MSG_MCU_GET_MODEM_INFORMATION;
			len = 7;			
		}
		break;
		
		case MSG_MCU_SET_MODEM_FACTORY_MODE:
		{
			SendBuffer[6] = MSG_MCU_SET_MODEM_FACTORY_MODE;
			len = 7;
		}
		break;

		case MSG_MCU_SET_MODEM_INTERNET_MODE:
		{
			SendBuffer[6] = MSG_MCU_SET_MODEM_INTERNET_MODE;
			SendBuffer[7] = 0x01; //length
			SendBuffer[8] = cmd;//airkiss
			len = 9;
		}
		break;

		case MSG_MCU_SET_MODEM_PRODUCE_TEST_MODE:
		{
			SendBuffer[6] = MSG_MCU_SET_MODEM_PRODUCE_TEST_MODE;
			SendBuffer[7] = 0x01; //length
			SendBuffer[8] = cmd;//���⿪ʼ
			len = 9;			
		}
		break;

		case MSG_MCU_SEND_SN_TO_MODEM:
		{
			SendBuffer[6] = MSG_MCU_SEND_SN_TO_MODEM;
			SendBuffer[7] = 0x08; //length
			len = 8;
			for(i=0;i<8;i++)
			{
				if(ModemType==MODEM_WIFI)
				{
				  SendBuffer[len+i] = gDeviceParameter.ModemWifiMacHex[i];
				}
				else if(ModemType==MODEM_2G)
				{
				  SendBuffer[len+i] = gDeviceParameter.Modem2gImeiHex[i];
				}
			}
			len = len + i;
		}
		break;

		case MSG_MCU_GET_MODEM_WIFI_MAC:
		{
			SendBuffer[6] = MSG_MCU_GET_MODEM_WIFI_MAC;
			len = 7;
		}
		break;

		case MSG_MCU_GET_MODEM_ROUTER_SSID:
		{
			SendBuffer[6] = MSG_MCU_GET_MODEM_ROUTER_SSID;
			len = 7;
		}
		break;

		case MSG_MCU_GET_MODEM_2G_IMEI:
		{
			SendBuffer[6] = MSG_MCU_GET_MODEM_2G_IMEI;
			len = 7;
		}
		break;

		case MSG_MCU_GET_MODEM_2G_IMSI:
		{
			SendBuffer[6] = MSG_MCU_GET_MODEM_2G_IMSI;
			len = 7;
		}
		break;

		case MSG_MCU_GET_MODEM_2G_BASESTATION:
		{
			SendBuffer[6] = MSG_MCU_GET_MODEM_2G_BASESTATION;
			len = 7;
		}
		break;

		case MSG_MCU_SEND_UPDATA_INFORMATION_TO_MODEM:
		{
			SendBuffer[6] = MSG_MCU_SEND_UPDATA_INFORMATION_TO_MODEM;
      SendBuffer[7] = 0x01;//length
			SendBuffer[8] = cmd;
      len = 9;
			
		}
		break;

		case MSG_MCU_SEND_MODEM_OTA_URL_INFORMATION_TO_MODEM:
		{
			SendBuffer[6] = MSG_MCU_SEND_MODEM_OTA_URL_INFORMATION_TO_MODEM;
      SendBuffer[7] = DeviceParameterLen[MSG_DEVICE_MODEM_OTA_URL];
			len = 8;
      //Module OTA URL String
      for(i=0;i<DeviceParameterLen[MSG_DEVICE_MODEM_OTA_URL];i++)
      {
        SendBuffer[len+i] = gDeviceParameter.ModemOtaUrl[i];
      }
      
      len = len + DeviceParameterLen[MSG_DEVICE_MODEM_OTA_URL];
		}
		break;
    
		case MSG_MCU_SEND_MCU_OTA_URL_INFORMATION_TO_MODEM:
		{
			SendBuffer[6] = MSG_MCU_SEND_MCU_OTA_URL_INFORMATION_TO_MODEM;
      SendBuffer[7] = DeviceParameterLen[MSG_DEVICE_MCU_OTA_URL]; 
			len = 8;
      //MCU OTA URL String
      for(i=0;i<DeviceParameterLen[MSG_DEVICE_MCU_OTA_URL];i++)
      {
        SendBuffer[len+i] = gDeviceParameter.McuOtaUrl[i];
      }
      
      len = len + DeviceParameterLen[MSG_DEVICE_MCU_OTA_URL];
		}
		break;
		
		case MSG_MCU_SEND_PRODUCT_KEY:
		{
			SendBuffer[6] = MSG_MCU_SEND_PRODUCT_KEY;
			DeviceParameterLen[MSG_DEVICE_PRODUCT_KEY] = strlen((const char *)gDeviceParameter.ProductKey);
			SendBuffer[7] = DeviceParameterLen[MSG_DEVICE_PRODUCT_KEY]; 
			len = 8;
      //product key
      for(i=0;i<DeviceParameterLen[MSG_DEVICE_PRODUCT_KEY];i++)
      {
        SendBuffer[len+i] = gDeviceParameter.ProductKey[i];
      }
			
			len = len + DeviceParameterLen[MSG_DEVICE_PRODUCT_KEY];						
		}
		break;

		case MSG_MCU_GET_MODEM_FIRMWARE_VERSION:
		{
			SendBuffer[6] = MSG_MCU_GET_MODEM_FIRMWARE_VERSION;
			len = 7;
		}
		break;

		case MSG_MCU_GET_MODEM_HARDWARE_VERSION:
		{
			SendBuffer[6] = MSG_MCU_GET_MODEM_HARDWARE_VERSION;
			len = 7;
		}
		break;

		case MSG_MCU_SEND_MCU_FIRMWARE_VERSION:
		{
			SendBuffer[6] = MSG_MCU_SEND_MCU_FIRMWARE_VERSION;
			DeviceParameterLen[MSG_MCU_SEND_MCU_FIRMWARE_VERSION] = strlen((const char *)gDeviceParameter.BordFirmwareVersion);
      SendBuffer[7] = DeviceParameterLen[MSG_MCU_SEND_MCU_FIRMWARE_VERSION]; 
			len = 8;
      //product key
      for(i=0;i<DeviceParameterLen[MSG_MCU_SEND_MCU_FIRMWARE_VERSION];i++)
      {
        SendBuffer[len+i] = gDeviceParameter.BordFirmwareVersion[i];
      }
			
			len = len + DeviceParameterLen[MSG_MCU_SEND_MCU_FIRMWARE_VERSION];		
		}
		break;
		
		default:
			break;
	}
  
	//data length,2 Byte
	SendBuffer[1] = 0;
	SendBuffer[2] = len;
	//check sum
	SendBuffer[len] = CalculateChecksum(SendBuffer,len,1);
	len ++;
	SendBuffer[len] = SYS_SYNC_TAIL;
	len ++;
	
	//Data exchange
	len = len + data_exchange(SendBuffer, SEND, len);
	
	// Send out
	PutStrToUart2Modem(SendBuffer, len);
	
	//SetReportDeviceState(TRUE);//�ϴ�������ȫ������

	return Serial;
}

u8 CloudSerial = 0;
void SendGetParameterCmd(MSGGetParameterCMDT msgtype)
{
	u8 len = 0;
	u8 i;
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Send Get Parameter CMD %d", FmtTimeShow(),msgtype);

	// Clear data
	memset(SendBuffer, 0, sizeof(SendBuffer));  
  
	// Fill head
	SendBuffer[0] = SYS_SYNC_HEAD;
	// Fill type
	SendBuffer[3] = CloudSerial;
	CloudSerial ++;
	// Fill length
	SendBuffer[4] = 0x31;
	//command type
	SendBuffer[5] = COMMAND_TYPE_MCU_TO_CLOUD_TOPIC1;	
	
	for(i=0;i<8;i++)
	{
    if(ModemType==MODEM_WIFI)
    {
      SendBuffer[6+i] = gDeviceParameter.ModemWifiMacHex[i];
    }
    else if(ModemType==MODEM_2G)
    {
      SendBuffer[6+i] = gDeviceParameter.Modem2gImeiHex[i];
    }
	}
	SendBuffer[14] = PRODUCT_TYPE_COMPERCE_WATER_PURIFIER;
  
	SendBuffer[15] = DATA_TYPE_GET_PARAMETER_COMMAND;
	SendBuffer[16] = MSG_GET_PARAMETER_CMD;
	SendBuffer[17] = 0x01;  //length
	
	switch(msgtype)
	{
		case MSG_GET_PARAMETER_INTERNET_TIME:
		{
			SendBuffer[18] = MSG_GET_PARAMETER_INTERNET_TIME;
			len = 19;
		}
		break;
		
		case MSG_GET_PARAMETER_LIMITED:
		{
			SendBuffer[18] = MSG_GET_PARAMETER_LIMITED;
			len = 19;			
		}
		break;

		case MSG_GET_PARAMETER_DECICE:
		{
			SendBuffer[18] = MSG_GET_PARAMETER_DECICE;
			len = 19;					
		}
		break;

		case MSG_GET_PARAMETER_USER_SET:
		{
			SendBuffer[18] = MSG_GET_PARAMETER_USER_SET;
			len = 19;					
		}
		break;

		case MSG_GET_PARAMETER_USER_OPERATE:
		{
			SendBuffer[18] = MSG_GET_PARAMETER_USER_OPERATE;
			len = 19;					
		}
		break;

		case MSG_GET_PARAMETER_SERVICE_SET:
		{
			SendBuffer[18] = MSG_GET_PARAMETER_SERVICE_SET;
			len = 19;					
		}
		break;

		case MSG_GET_PARAMETER_LEASE_BUSSINESS:
		{
			SendBuffer[18] = MSG_GET_PARAMETER_LEASE_BUSSINESS;
			len = 19;					
		}
		break;

		case MSG_GET_PARAMETER_THIRD:
		{
			SendBuffer[18] = MSG_GET_PARAMETER_THIRD;
			len = 19;					
		}
		break;
		
		default:
			break;		
	}
	
	//data length,2 Byte
	SendBuffer[1] = 0;
	SendBuffer[2] = len;
	//check sum
	SendBuffer[len] = CalculateChecksum(SendBuffer,len,1);
	len ++;
	SendBuffer[len] = SYS_SYNC_TAIL;
	len ++;
	
	//Data exchange
	len = len + data_exchange(SendBuffer, SEND, len);
	
	// Send out
	PutStrToUart2Modem(SendBuffer, len);
}

u8 ReceiveGetParametrCmd(u8* pdata, u16 datalen)
{
	u16 len;
	
	len = 16;

  switch(pdata[len])
	{
		case MSG_GET_PARAMETER_CMD: //��ȡ��������
		{
		  len ++;
		  switch(pdata[len])
		  {
		    case MSG_GET_PARAMETER_INTERNET_TIME:  //��ȡ����ʱ��
		    {
				len ++;
		      
		    }
		    break;
		    
		    case MSG_GET_PARAMETER_LIMITED:        //��ȡ��Ȩ
		    {
				len ++;
		      
		    }
		    break;
		    
		    case MSG_GET_PARAMETER_DECICE:         //��ȡ�豸����
		    {
				len ++;
		      SendDeviceParameter(COMMAND_TYPE_MCU_TO_CLOUD_TOPIC1);
		    }
		    break;
		    
		    case MSG_GET_PARAMETER_USER_SET:       //��ȡ�û����ò���
		    {
				len ++;
		      SendUserSetParameter(COMMAND_TYPE_MCU_TO_CLOUD_TOPIC1);
		    }
		    break;
		    
		    case MSG_GET_PARAMETER_USER_OPERATE:   //��ȡ�û���������
		    {
				len ++;          
		      
		    }
		    break;
		    
		    case MSG_GET_PARAMETER_SERVICE_SET:    //��ȡ�������ò���
		    {
				len ++;
		      SendServiceParameter(COMMAND_TYPE_MCU_TO_CLOUD_TOPIC1);
		    }
		    break;
		    
		    case MSG_GET_PARAMETER_LEASE_BUSSINESS://��ȡ����/����ҵ�����
		    {
				len ++;
		      
		    }
		    break;
		    
		    case MSG_GET_PARAMETER_THIRD:         //��ȡ����������
		    {
				len ++;
		      
		    }
		    break;     

		    default:
		      break;
		  }
		}
		break;

		case MSG_GET_PARAMETER_SET: //���û�ȡ�豸��ʾ����Ƶ��    
		{
			len ++;
			//Period Report Display Timer
			SoftwareTimerReset(&PeriodReportDisplayTimer,PeriodReportDisplayCallback,PERIOD_REPORT_DISPLAY_TELEPHONE_TIMEOUT);
			SoftwareTimerStart(&PeriodReportDisplayTimer);	
			SetTelephoneConnectState(TRUE);
			gControlState.TelephoneReportCount = 0;
			len ++;
			gControlState.TelephoneReportInterval = pdata[len]; 
			len ++;
			gControlState.TelephoneReportMinute = pdata[len];
			len ++;
			// Print Out
			Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Telephone Connected", FmtTimeShow());
		}
		break;

		default:
		  break;
	}    	
	
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Receive Get Parameter Cmd", FmtTimeShow());
  
  return 1;
}

void SendDeviceParameter(CMDTypeT msgtype)
{
	u8 i = 0;
	u16 len = 0;
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Send Device Parameter", FmtTimeShow());

	// Clear data
	memset(SendBuffer, 0, sizeof(SendBuffer));  
  
	// Fill head
	SendBuffer[0] = SYS_SYNC_HEAD;
	// Fill type
	SendBuffer[3] = CloudSerial;
	CloudSerial ++;
	// Fill length
	SendBuffer[4] = 0x30;
	//command type
	SendBuffer[5] = msgtype;	
	//SN
	for(i=0;i<8;i++)
	{
    if(ModemType==MODEM_WIFI)
    {
      SendBuffer[6+i] = gDeviceParameter.ModemWifiMacHex[i];
    }
    else if(ModemType==MODEM_2G)
    {
      SendBuffer[6+i] = gDeviceParameter.Modem2gImeiHex[i];
    }
	}
  
	//Product Type
  #if defined(PRODUCT_COMPERCE_WATER_PURIFIER)
  {
    SendBuffer[14] = PRODUCT_TYPE_COMPERCE_WATER_PURIFIER;
  }
  #endif

  #if defined(PRODUCT_CATERING_MACHINE)
  {
    SendBuffer[14] = PRODUCT_TYPE_CATERING_MACHINE;
  }
  #endif

  #if defined(PRODUCT_BUBBLE_MACHINE)
  {
    SendBuffer[14] = PRODUCT_TYPE_BUBBLE_MACHINE;
  }
  #endif

  #if defined(PRODUCT_NEWMOON_MACHINE)
  {
    SendBuffer[14] = PRODUCT_TYPE_NEWMOON_MACHINE;
  }
  #endif

  #if defined(PRODUCT_RAINLOTUS_MACHINE)
  {
    SendBuffer[14] = PRODUCT_TYPE_RAINLOTUS_MACHINE;
  }
  #endif

	//Data Type
	SendBuffer[15] = DATA_TYPE_DEVICE_PARAMETER;
	len = 16;
  
	//Data Time
	SendBuffer[len] = MSG_DEVICE_DATE_TIME;	
	len ++;
	
	//Length
	SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_DATE_TIME];
	len ++;
	SendBuffer[len] = gDeviceParameter.DateTime.Year;
	len ++;
	SendBuffer[len] = gDeviceParameter.DateTime.Month;
	len ++;
	SendBuffer[len] = gDeviceParameter.DateTime.Day;
	len ++;
	SendBuffer[len] = gDeviceParameter.DateTime.Hour;
	len ++;
	SendBuffer[len] = gDeviceParameter.DateTime.Minute;
	len ++;
	SendBuffer[len] = gDeviceParameter.DateTime.Second;
	len ++;

	//Model Num
	SendBuffer[len] = MSG_DEVICE_MODEL_NUMBER;
	len ++;
	DeviceParameterLen[MSG_DEVICE_MODEL_NUMBER] = strlen((const char *)gDeviceParameter.ModelNum);
	//Length
	SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_MODEL_NUMBER];
	len ++;
  
	//Model Num String
	for(i=0;i<DeviceParameterLen[MSG_DEVICE_MODEL_NUMBER];i++)
	{
		SendBuffer[len+i] = gDeviceParameter.ModelNum[i];
	}
	
	len = len + DeviceParameterLen[MSG_DEVICE_MODEL_NUMBER];
  
	//Board Firmware Version
	SendBuffer[len] = MSG_DEVICE_BORD_FIRMWARE_VERSION;
	len ++;
	DeviceParameterLen[MSG_DEVICE_BORD_FIRMWARE_VERSION] = strlen((const char *)gDeviceParameter.BordFirmwareVersion);
	//Length
	SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_BORD_FIRMWARE_VERSION];
	len ++;
	//Board Firmware Version String
	for(i=0;i<DeviceParameterLen[MSG_DEVICE_BORD_FIRMWARE_VERSION];i++)
	{
		SendBuffer[len+i] = gDeviceParameter.BordFirmwareVersion[i];
	}
	
	len = len + DeviceParameterLen[MSG_DEVICE_BORD_FIRMWARE_VERSION];
  
  //Board Hardware Version
	SendBuffer[len] = MSG_DEVICE_BORD_HARDWARE_VERSION;
	len ++;
	DeviceParameterLen[MSG_DEVICE_BORD_HARDWARE_VERSION] = strlen((const char *)gDeviceParameter.BordHardwareVersion);
	//Length
	SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_BORD_HARDWARE_VERSION];
	len ++;
	//Board Hardware Version String
	for(i=0;i<DeviceParameterLen[MSG_DEVICE_BORD_HARDWARE_VERSION];i++)
	{
		SendBuffer[len+i] = gDeviceParameter.BordHardwareVersion[i];
	}
	
	len = len + DeviceParameterLen[MSG_DEVICE_BORD_HARDWARE_VERSION];

  //Modem Firmware Version
	SendBuffer[len] = MSG_DEVICE_MODEM_FIRMWARE_VERSION;
	len ++;
	DeviceParameterLen[MSG_DEVICE_MODEM_FIRMWARE_VERSION] = strlen((const char *)gDeviceParameter.ModemFirmwareVersion);
	//Length
	SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_MODEM_FIRMWARE_VERSION];
	len ++;
	//Modem Firmware Version String
	for(i=0;i<DeviceParameterLen[MSG_DEVICE_MODEM_FIRMWARE_VERSION];i++)
	{
		SendBuffer[len+i] = gDeviceParameter.ModemFirmwareVersion[i];
	}
	
	len = len + DeviceParameterLen[MSG_DEVICE_MODEM_FIRMWARE_VERSION];
	
  //Modem Hardware Version
	SendBuffer[len] = MSG_DEVICE_MODEM_HARDWARE_VERSION;
	len ++;
	DeviceParameterLen[MSG_DEVICE_MODEM_HARDWARE_VERSION] = strlen((const char *)gDeviceParameter.ModemHardwareVersion);
	//Length
	SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_MODEM_HARDWARE_VERSION];
	len ++;
	//Modem Hardware Version String
	for(i=0;i<DeviceParameterLen[MSG_DEVICE_MODEM_HARDWARE_VERSION];i++)
	{
		SendBuffer[len+i] = gDeviceParameter.ModemHardwareVersion[i];
	}
	
	len = len + DeviceParameterLen[MSG_DEVICE_MODEM_HARDWARE_VERSION];
	
  if(ModemType==MODEM_WIFI)
  {
    //WIFI Module MAC
    SendBuffer[len] = MSG_DEVICE_WIFI_MAC;
    len ++;
		DeviceParameterLen[MSG_DEVICE_WIFI_MAC] = strlen((const char *)gDeviceParameter.ModemWifiMac);
    //Length
    SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_WIFI_MAC];
    len ++;
    //WIFI Module MAC String
    for(i=0;i<DeviceParameterLen[MSG_DEVICE_WIFI_MAC];i++)
    {
      SendBuffer[len+i] = gDeviceParameter.ModemWifiMac[i];
    }
    
    len = len + DeviceParameterLen[MSG_DEVICE_WIFI_MAC];

    //Router SSID
    SendBuffer[len] = MSG_DEVICE_ROUTER_SSID;
    len ++;
		DeviceParameterLen[MSG_DEVICE_ROUTER_SSID] = strlen((const char *)gDeviceParameter.ModemRouterSsid);
    //Length
    SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_ROUTER_SSID];
    len ++;
    //Router SSID String
    for(i=0;i<DeviceParameterLen[MSG_DEVICE_ROUTER_SSID];i++)
    {
      SendBuffer[len+i] = gDeviceParameter.ModemRouterSsid[i];
    }
    
    len = len + DeviceParameterLen[MSG_DEVICE_ROUTER_SSID];
  }
  else if(ModemType==MODEM_2G)
  {
    //2G Module IMEI
    SendBuffer[len] = MSG_DEVICE_2G_IMEI;
    len ++;
		DeviceParameterLen[MSG_DEVICE_2G_IMEI] = strlen((const char *)gDeviceParameter.Modem2gImei);
    //Length
    SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_2G_IMEI];
    len ++;
    //2G Module IMEI String
    for(i=0;i<DeviceParameterLen[MSG_DEVICE_2G_IMEI];i++)
    {
      SendBuffer[len+i] = gDeviceParameter.Modem2gImei[i];
    }
    
    len = len + DeviceParameterLen[MSG_DEVICE_2G_IMEI];

    //2G Module IMSI
    SendBuffer[len] = MSG_DEVICE_2G_IMSI;
    len ++;
		DeviceParameterLen[MSG_DEVICE_2G_IMSI] = strlen((const char *)gDeviceParameter.Modem2gImsi);
    //Length
    SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_2G_IMSI];
    len ++;
    //2G Module IMSI String
    for(i=0;i<DeviceParameterLen[MSG_DEVICE_2G_IMSI];i++)
    {
      SendBuffer[len+i] = gDeviceParameter.Modem2gImsi[i];
    }
    
    len = len + DeviceParameterLen[MSG_DEVICE_2G_IMSI];

    //2G Module MNC
    SendBuffer[len] = MSG_DEVICE_2G_MNC;
    len ++;
    //Length
    SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_2G_MNC];
    len ++;
    //2G Module MNC 2Byte
    SendBuffer[len] = (u8)(gDeviceParameter.Modem2gMnc>>8);
    len ++;
    SendBuffer[len] = (u8)gDeviceParameter.Modem2gMnc;
    len ++;
    
    //2G Module MCC
    SendBuffer[len] = MSG_DEVICE_2G_MCC;
    len ++;
    //Length
    SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_2G_MCC];
    len ++;
    //2G Module MCC 2Byte
    SendBuffer[len] = (u8)(gDeviceParameter.Modem2gMcc>>8);
    len ++;
    SendBuffer[len] = (u8)gDeviceParameter.Modem2gMcc;
    len ++;
    
    //Basestation Num
    SendBuffer[len] = MSG_DEVICE_2G_BASESTATION_NUM;
    len ++;
    //Length
    SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_2G_BASESTATION_NUM];
    len ++;
    //Basestation Num
    SendBuffer[len] = gDeviceParameter.ModemBaseStationNum;
    len ++;
    
    //Basestation1
    SendBuffer[len] = MSG_DEVICE_2G_BASESTATION1;
    len ++;
    //length
    SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_2G_BASESTATION1];
    len ++;
    SendBuffer[len] = (u8)(gDeviceParameter.BaseStation1.Lac>>8);
    len ++;
    SendBuffer[len] = (u8)gDeviceParameter.BaseStation1.Lac;
    len ++;
    SendBuffer[len] = (u8)(gDeviceParameter.BaseStation1.Cellid>>8);
    len ++;
    SendBuffer[len] = (u8)gDeviceParameter.BaseStation1.Cellid;
    len ++;
    SendBuffer[len] = (u8)gDeviceParameter.BaseStation1.Rssi;
    len ++;
    
    //Basestation2
    SendBuffer[len] = MSG_DEVICE_2G_BASESTATION2;
    len ++;
    //Length
    SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_2G_BASESTATION2];
    len ++;
    SendBuffer[len] = (u8)(gDeviceParameter.BaseStation2.Lac>>8);
    len ++;
    SendBuffer[len] = (u8)gDeviceParameter.BaseStation2.Lac;
    len ++;
    SendBuffer[len] = (u8)(gDeviceParameter.BaseStation2.Cellid>>8);
    len ++;
    SendBuffer[len] = (u8)gDeviceParameter.BaseStation2.Cellid;
    len ++;
    SendBuffer[len] = (u8)gDeviceParameter.BaseStation2.Rssi;
    len ++;
    
    //Basestation3
    SendBuffer[len] = MSG_DEVICE_2G_BASESTATION3;
    len ++;
    //Length
    SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_2G_BASESTATION3];
    len ++;
    SendBuffer[len] = (u8)(gDeviceParameter.BaseStation3.Lac>>8);
    len ++;
    SendBuffer[len] = (u8)gDeviceParameter.BaseStation3.Lac;
    len ++;
    SendBuffer[len] = (u8)(gDeviceParameter.BaseStation3.Cellid>>8);
    len ++;
    SendBuffer[len] = (u8)gDeviceParameter.BaseStation3.Cellid;
    len ++;
    SendBuffer[len] = (u8)gDeviceParameter.BaseStation3.Rssi;
    len ++;
    
    //Basestation4
    SendBuffer[len] = MSG_DEVICE_2G_BASESTATION4;
    len ++;
    //Length
    SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_2G_BASESTATION4];
    len ++;
    SendBuffer[len] = (u8)(gDeviceParameter.BaseStation4.Lac>>8);
    len ++;
    SendBuffer[len] = (u8)gDeviceParameter.BaseStation4.Lac;
    len ++;
    SendBuffer[len] = (u8)(gDeviceParameter.BaseStation4.Cellid>>8);
    len ++;
    SendBuffer[len] = (u8)gDeviceParameter.BaseStation4.Cellid;
    len ++;
    SendBuffer[len] = (u8)gDeviceParameter.BaseStation4.Rssi;
    len ++;
    
    //Basestation5
    SendBuffer[len] = MSG_DEVICE_2G_BASESTATION5;
    len ++;
    //Length
    SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_2G_BASESTATION5];
    len ++;
    SendBuffer[len] = (u8)(gDeviceParameter.BaseStation5.Lac>>8);
    len ++;
    SendBuffer[len] = (u8)gDeviceParameter.BaseStation5.Lac;
    len ++;
    SendBuffer[len] = (u8)(gDeviceParameter.BaseStation5.Cellid>>8);
    len ++;
    SendBuffer[len] = (u8)gDeviceParameter.BaseStation5.Cellid;
    len ++;
    SendBuffer[len] = (u8)gDeviceParameter.BaseStation5.Rssi;
    len ++;
    
    //Basestation6
    SendBuffer[len] = MSG_DEVICE_2G_BASESTATION6;
    len ++;
    //Length
    SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_2G_BASESTATION6];
    len ++;
    SendBuffer[len] = (u8)(gDeviceParameter.BaseStation6.Lac>>8);
    len ++;
    SendBuffer[len] = (u8)gDeviceParameter.BaseStation6.Lac;
    len ++;
    SendBuffer[len] = (u8)(gDeviceParameter.BaseStation6.Cellid>>8);
    len ++;
    SendBuffer[len] = (u8)gDeviceParameter.BaseStation6.Cellid;
    len ++;
    SendBuffer[len] = gDeviceParameter.BaseStation6.Rssi;
    len ++;	
  }
	//Module OTA URL
	SendBuffer[len] = MSG_DEVICE_MODEM_OTA_URL;
	len ++;
	DeviceParameterLen[MSG_DEVICE_MODEM_OTA_URL] = strlen((const char *)gDeviceParameter.ModemOtaUrl);
	//Length
	SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_MODEM_OTA_URL];
	len ++;
	//Module OTA URL String
	for(i=0;i<DeviceParameterLen[MSG_DEVICE_MODEM_OTA_URL];i++)
	{
		SendBuffer[len+i] = gDeviceParameter.ModemOtaUrl[i];
	}
	
	len = len + DeviceParameterLen[MSG_DEVICE_MODEM_OTA_URL];
	
	//MCU OTA URL
	SendBuffer[len] = MSG_DEVICE_MCU_OTA_URL;
	len ++;
	DeviceParameterLen[MSG_DEVICE_MCU_OTA_URL] = strlen((const char *)gDeviceParameter.McuOtaUrl);
	//Length
	SendBuffer[len] = DeviceParameterLen[MSG_DEVICE_MCU_OTA_URL];
	len ++;
	//MCU OTA URL String
	for(i=0;i<DeviceParameterLen[MSG_DEVICE_MCU_OTA_URL];i++)
	{
		SendBuffer[len+i] = gDeviceParameter.McuOtaUrl[i];
	}
	
	len = len + DeviceParameterLen[MSG_DEVICE_MCU_OTA_URL];
	
	//data length,2 Byte
	SendBuffer[1] = (u8)(len>>8);
	SendBuffer[2] = (u8)len;
	//check sum
	SendBuffer[len] = CalculateChecksum(SendBuffer,len,1);
	len ++;
	SendBuffer[len] = SYS_SYNC_TAIL;
	len ++;
	
	//Data exchange
	len = len + data_exchange(SendBuffer, SEND, len);
	
	// Send out
	PutStrToUart2Modem(SendBuffer, len);
}

/*
success: return 1
wrong: return 0
*/
u8 ReceiveDeviceParameter(u8* pdata, u16 datalen)
{
	u16 len,length;
	u8 i;
	u8 McuVersion[9];
	u16 NewMcuVersion;
	u16 OldMcuVersion;
	
	len = 16;
	length = (pdata[1]<<8) + pdata[2];
	
	for(i=0;i<255;i++)
	{
		switch(pdata[len])
		{
			case MSG_DEVICE_DATE_TIME:
			{
				len ++;
				gDeviceParameter.DateTime.Year = pdata[len];
				len ++;
				gDeviceParameter.DateTime.Month = pdata[len];
				len ++;
				gDeviceParameter.DateTime.Day= pdata[len];
				len ++;
				gDeviceParameter.DateTime.Hour= pdata[len];
				len ++;
				gDeviceParameter.DateTime.Minute= pdata[len];
				len ++;
				gDeviceParameter.DateTime.Second= pdata[len];

				len ++;
			}
			break;

			case MSG_DEVICE_BORD_FIRMWARE_VERSION:
			{
				len ++;
				DeviceParameterLen[MSG_DEVICE_BORD_FIRMWARE_VERSION] = pdata[len];
				len ++;
				memcpy(McuVersion, &pdata[len], DeviceParameterLen[MSG_DEVICE_BORD_FIRMWARE_VERSION]);
				NewMcuVersion = NumString2Short(McuVersion,DeviceParameterLen[MSG_DEVICE_BORD_FIRMWARE_VERSION]);
				OldMcuVersion = NumString2Short(gDeviceParameter.BordFirmwareVersion,DeviceParameterLen[MSG_DEVICE_BORD_FIRMWARE_VERSION]);

				// Print Out
				Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: New MCU Firmare Version %d, Old MCU Firmare Version %d", FmtTimeShow(),\
				 NewMcuVersion ,OldMcuVersion);	
						
				if(NewMcuVersion>OldMcuVersion)
				{
					ControlModem(MSG_MCU_SEND_UPDATA_INFORMATION_TO_MODEM,MCU_UPDATE_START);//����ģ�鿪ʼ��ȡMCU�̼�
				}
				else
				{
					memcpy(gDeviceParameter.BordFirmwareVersion, &pdata[len], DeviceParameterLen[MSG_DEVICE_BORD_FIRMWARE_VERSION]);
				}
				len = len + DeviceParameterLen[MSG_DEVICE_BORD_FIRMWARE_VERSION];				
			}
			break;

			case MSG_DEVICE_MODEM_FIRMWARE_VERSION:
			{
				len ++;
				DeviceParameterLen[MSG_DEVICE_MODEM_FIRMWARE_VERSION] = pdata[len];
				len ++;
				
				memcpy(gDeviceParameter.ModemFirmwareVersion, &pdata[len], DeviceParameterLen[MSG_DEVICE_MODEM_FIRMWARE_VERSION]);
				len = len + DeviceParameterLen[MSG_DEVICE_MODEM_FIRMWARE_VERSION];					
			}
			break;

			case MSG_DEVICE_MODEM_OTA_URL:
			{
				len ++;
				DeviceParameterLen[MSG_DEVICE_MODEM_OTA_URL] = pdata[len];
				len ++;
				
				memcpy(gDeviceParameter.ModemOtaUrl, &pdata[len], DeviceParameterLen[MSG_DEVICE_MODEM_OTA_URL]);
				len = len + DeviceParameterLen[MSG_DEVICE_MODEM_OTA_URL];					
			}
			break;

			case MSG_DEVICE_MCU_OTA_URL:
			{
				len ++;
				DeviceParameterLen[MSG_DEVICE_MCU_OTA_URL] = pdata[len];
				len ++;
				
				memcpy(gDeviceParameter.McuOtaUrl, &pdata[len], DeviceParameterLen[MSG_DEVICE_MCU_OTA_URL]);
				len = len + DeviceParameterLen[MSG_DEVICE_MCU_OTA_URL];			
			}
			break;
			
			default:
				break;
		}
		
		if(len==length)
		{
			// Print Out
			Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: for break", FmtTimeShow());
			break;  //����forѭ��
		}
	}

	if(i==255)
	{
		// Print Out
		Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: ReceiveDeviceParameter Wrong", FmtTimeShow());
		return 0;
	}

	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Receive Device Parameter", FmtTimeShow());
	
	SendDeviceParameter(COMMAND_TYPE_MCU_TO_CLOUD_TOPIC1);

	return 1;

}

void SendDeviceDisplay(CMDTypeT msgtype)
{
	u8 i = 0;
	u16 len = 0;
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Send Device Display", FmtTimeShow());


	// Clear data
	memset(SendBuffer, 0, sizeof(SendBuffer));  
  
	// Fill head
	SendBuffer[0] = SYS_SYNC_HEAD;
	// Fill type
	SendBuffer[3] = CloudSerial;
	CloudSerial ++;
	// Fill length
	SendBuffer[4] = 0x30;
	//command type
	SendBuffer[5] = msgtype;	
	//SN
	for(i=0;i<8;i++)
	{
    if(ModemType==MODEM_WIFI)
    {
      SendBuffer[6+i] = gDeviceParameter.ModemWifiMacHex[i];
    }
    else if(ModemType==MODEM_2G)
    {
      SendBuffer[6+i] = gDeviceParameter.Modem2gImeiHex[i];
    }
	}
  
	//Product Type
	SendBuffer[14] = PRODUCT_TYPE_WATER_SPLIT_MACHINE;
  
	//Data Type
	SendBuffer[15] = DATA_TYPE_DEVICE_PARAMETER_DISPLAY;
	len = 16;
	//Data Time
	SendBuffer[len] = MSG_DISPLAY_DATE_TIME;	
	len ++;
	//Length
	SendBuffer[len] = DeviceDisplayLen[MSG_DISPLAY_DATE_TIME];
	len ++;
	SendBuffer[len] = gDeviceDisplay.DateTime.Year;
	len ++;
	SendBuffer[len] = gDeviceDisplay.DateTime.Month;
	len ++;
	SendBuffer[len] = gDeviceDisplay.DateTime.Day;
	len ++;
	SendBuffer[len] = gDeviceDisplay.DateTime.Hour;
	len ++;
	SendBuffer[len] = gDeviceDisplay.DateTime.Minute;
	len ++;
	SendBuffer[len] = gDeviceDisplay.DateTime.Second;
  
	len ++;
	//pp value
	SendBuffer[len] = MSG_DISPLAY_PP_VALUE;
	len ++;
	//Length
	SendBuffer[len] = DeviceDisplayLen[MSG_DISPLAY_PP_VALUE];
	len ++;
	//pp value
	SendBuffer[len] = (u8)(gDeviceDisplay.PpValue>>8);
	len ++;
	SendBuffer[len] = (u8)gDeviceDisplay.PpValue;
  
	len ++;
	//c1 value
	SendBuffer[len] = MSG_DISPLAY_C1_VALUE;
	len ++;
	//Length
	SendBuffer[len] = DeviceDisplayLen[MSG_DISPLAY_C1_VALUE];
	len ++;
	//c1 value
	SendBuffer[len] = (u8)(gDeviceDisplay.C1Value>>8);
	len ++;
	SendBuffer[len] = (u8)gDeviceDisplay.C1Value;
  
	len ++;
	//ro value
	SendBuffer[len] = MSG_DISPLAY_RO_VALUE;
	len ++;
	//Length
	SendBuffer[len] = DeviceDisplayLen[MSG_DISPLAY_RO_VALUE];
	len ++;
	//c1 value
	SendBuffer[len] = (u8)(gDeviceDisplay.RoValue>>8);
	len ++;
	SendBuffer[len] = (u8)gDeviceDisplay.RoValue;  

	len ++;
	//nf value
	SendBuffer[len] = MSG_DISPLAY_NF_VALUE;
	len ++;
	//Length
	SendBuffer[len] = DeviceDisplayLen[MSG_DISPLAY_NF_VALUE];
	len ++;
	//nf value
	SendBuffer[len] = (u8)(gDeviceDisplay.NfValue>>8);
	len ++;
	SendBuffer[len] = (u8)gDeviceDisplay.NfValue; 
	
	len ++;
	//clean water TDS 
	SendBuffer[len] = MSG_DISPLAY_CLEAN_WATER_TDS;
	len ++;
	//Length
	SendBuffer[len] = DeviceDisplayLen[MSG_DISPLAY_CLEAN_WATER_TDS];
	len ++;
	//clean water TDS value
	SendBuffer[len] = (u8)(gDeviceDisplay.CleanWaterTds>>8);
	len ++;
	SendBuffer[len] = (u8)gDeviceDisplay.CleanWaterTds; 
  
	len ++;
	//original water TDS 
	SendBuffer[len] = MSG_DISPLAY_ORIGINAL_WATER_TDS;
	len ++;
	//Length
	SendBuffer[len] = DeviceDisplayLen[MSG_DISPLAY_ORIGINAL_WATER_TDS];
	len ++;
	//original water TDS value
	SendBuffer[len] = (u8)(gDeviceDisplay.OriginalWaterTds>>8);
	len ++;
	SendBuffer[len] = (u8)gDeviceDisplay.OriginalWaterTds; 
	
	len ++;
	//clean water TOC 
	SendBuffer[len] = MSG_DISPLAY_CLEAN_WATER_TOC;
	len ++;
	//Length
	SendBuffer[len] = DeviceDisplayLen[MSG_DISPLAY_CLEAN_WATER_TOC];
	len ++;
	//clean water TOC 
	SendBuffer[len] = gDeviceDisplay.CleanWaterToc;

	len ++;
	//original water TOC 
	SendBuffer[len] = MSG_DISPLAY_ORIGINAL_WATER_TOC;
	len ++;
	//Length
	SendBuffer[len] = DeviceDisplayLen[MSG_DISPLAY_ORIGINAL_WATER_TOC];
	len ++;
	//original water TOC 
	SendBuffer[len] = gDeviceDisplay.OriginalWaterToc;

	len ++;
	//original water temperature 
	SendBuffer[len] = MSG_DISPLAY_HOT_WATER_TEMPERATURE;
	len ++;
	//Length
	SendBuffer[len] = DeviceDisplayLen[MSG_DISPLAY_HOT_WATER_TEMPERATURE];
	len ++;
	//original water temperature  value
	SendBuffer[len] = (u8)(gDeviceDisplay.HotWaterTemperature>>8);
	len ++;
	SendBuffer[len] = (u8)gDeviceDisplay.HotWaterTemperature; 

	len ++;  
	//water draw off daily
	SendBuffer[len] = MSG_DISPLAY_WATER_INTAKE_DAILY;
	len ++;
	//Length
	SendBuffer[len] = DeviceDisplayLen[MSG_DISPLAY_WATER_INTAKE_DAILY];
	len ++;
	//water draw off daily
	SendBuffer[len] = (u8)(gDeviceDisplay.WaterDrawOffDaily>>8);
	len ++;
	SendBuffer[len] = (u8)gDeviceDisplay.WaterDrawOffDaily;  
	
	len ++;
	//original water temperature 
	SendBuffer[len] = MSG_DISPLAY_ORIGINAL_WATER_TEMPERATURE;
	len ++;
	//Length
	SendBuffer[len] = DeviceDisplayLen[MSG_DISPLAY_ORIGINAL_WATER_TEMPERATURE];
	len ++;
	//original water temperature  value
	SendBuffer[len] = (u8)(gDeviceDisplay.OriginalWaterTemperature>>8);
	len ++;
	SendBuffer[len] = (u8)gDeviceDisplay.OriginalWaterTemperature; 

	len ++;  
	//water draw off total
	SendBuffer[len] = MSG_DISPLAY_WATER_DRAW_OFF_TOTAL;
	len ++;
	//Length
	SendBuffer[len] = DeviceDisplayLen[MSG_DISPLAY_WATER_DRAW_OFF_TOTAL];
	len ++;
	//water draw off Total
	SendBuffer[len] = (u8)(gDeviceDisplay.WaterDrawOffTotal>>24);
	len ++;
	SendBuffer[len] = (u8)(gDeviceDisplay.WaterDrawOffTotal>>16);
	len ++;
	SendBuffer[len] = (u8)(gDeviceDisplay.WaterDrawOffTotal>>8);
	len ++;
	SendBuffer[len] = (u8)gDeviceDisplay.WaterDrawOffTotal; 

	len ++;  
	//rssi
	SendBuffer[len] = MSG_DISPLAY_RSSI;
	len ++;
	//Length
	SendBuffer[len] = DeviceDisplayLen[MSG_DISPLAY_RSSI];
	len ++;  
	//rssi
	SendBuffer[len] = gDeviceDisplay.rssi;     
  
	len ++;  
	//running status
	SendBuffer[len] = MSG_DISPLAY_RUNNING_STATUS;
	len ++;
	//Length
	SendBuffer[len] = DeviceDisplayLen[MSG_DISPLAY_RUNNING_STATUS];
	len ++;  
	//running status
	SendBuffer[len] = gDeviceDisplay.RunningStatus;    
  
	len ++;  
//	//current errow
//	SendBuffer[len] = MSG_DISPLAY_CURRENT_ERROW;
//	len ++;
//	//Length
//	SendBuffer[len] = DeviceDisplayLen[MSG_DISPLAY_CURRENT_ERROW];
//  //current errow
//	len ++;  
//  SendBuffer[len] = (u8)(gDeviceDisplay.CurrentErrow[0]);    
//	len ++;  
//  SendBuffer[len] = (u8)(gDeviceDisplay.CurrentErrow[1]);   
//	len ++;  
//  SendBuffer[len] = (u8)(gDeviceDisplay.CurrentErrow[2]);   
//	len ++;  
//  SendBuffer[len] = (u8)(gDeviceDisplay.CurrentErrow[3]);   
//  len ++; 
//  SendBuffer[len] = (u8)(gDeviceDisplay.CurrentErrow[4]);   
//  len ++; 
	//��Լ����ƿ����
	SendBuffer[len] = MSG_DISPLAY_SET_SAVE_BOTTLE_NUMBER;
	len ++;
	//Length
	SendBuffer[len] = DeviceDisplayLen[MSG_DISPLAY_SET_SAVE_BOTTLE_NUMBER];
	len ++;  
	SendBuffer[len] = (u8)(gDeviceDisplay.SaveBottleNumber>>24);
	len ++;
	SendBuffer[len] = (u8)(gDeviceDisplay.SaveBottleNumber>>16);
	len ++;
	SendBuffer[len] = (u8)(gDeviceDisplay.SaveBottleNumber>>8);
	len ++;
	SendBuffer[len] = (u8)gDeviceDisplay.SaveBottleNumber;  

	len ++;
	//data length,2 Byte
	SendBuffer[1] = (u8)(len>>8);
	SendBuffer[2] = (u8)len;
	//check sum
	SendBuffer[len] = CalculateChecksum(SendBuffer,len,1);
	len ++;
	SendBuffer[len] = SYS_SYNC_TAIL;
	len ++;
	
	//Data exchange
	len = len + data_exchange(SendBuffer, SEND, len);
	
	// Send out
	PutStrToUart2Modem(SendBuffer, len);	
}

void SendDeviceError(CMDTypeT msgtype)
{
	u8 i = 0;
	u16 len = 0;
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Send Device Display", FmtTimeShow());

	// Clear data
	memset(SendBuffer, 0, sizeof(SendBuffer));  
  
//	SystemDisableAllInterrupt();
	// Fill head
	SendBuffer[0] = SYS_SYNC_HEAD;
	// Fill type
	SendBuffer[3] = CloudSerial;
	CloudSerial ++;
	// Fill length
	SendBuffer[4] = 0x30;
	//command type
	SendBuffer[5] = msgtype;	
	//SN
	for(i=0;i<8;i++)
	{
    if(ModemType==MODEM_WIFI)
    {
      SendBuffer[6+i] = gDeviceParameter.ModemWifiMacHex[i];
    }
    else if(ModemType==MODEM_2G)
    {
      SendBuffer[6+i] = gDeviceParameter.Modem2gImeiHex[i];
    }
	}
  
	//Product Type
  	SendBuffer[14] = PRODUCT_TYPE_WATER_SPLIT_MACHINE;
  
	//Data Type
	SendBuffer[15] = DATA_TYPE_DEVICE_PARAMETER_DISPLAY;
	len = 16;
	//Data Time
	SendBuffer[len] = MSG_DISPLAY_DATE_TIME;	
	len ++;
	//Length
	SendBuffer[len] = DeviceDisplayLen[MSG_DISPLAY_DATE_TIME];
	len ++;
	SendBuffer[len] = gDeviceDisplay.DateTime.Year;
	len ++;
	SendBuffer[len] = gDeviceDisplay.DateTime.Month;
	len ++;
	SendBuffer[len] = gDeviceDisplay.DateTime.Day;
	len ++;
	SendBuffer[len] = gDeviceDisplay.DateTime.Hour;
	len ++;
	SendBuffer[len] = gDeviceDisplay.DateTime.Minute;
	len ++;
	SendBuffer[len] = gDeviceDisplay.DateTime.Second;
	len ++;  

	//current errow
	SendBuffer[len] = MSG_DISPLAY_CURRENT_ERROW;
	len ++;
	//Length
	SendBuffer[len] = DeviceDisplayLen[MSG_DISPLAY_CURRENT_ERROW];
	//current errow
	len ++;  
	SendBuffer[len] = (u8)(gDeviceDisplay.CurrentErrow[0]);    
	len ++;  
	SendBuffer[len] = (u8)(gDeviceDisplay.CurrentErrow[1]);   
	len ++;  
	SendBuffer[len] = (u8)(gDeviceDisplay.CurrentErrow[2]);   
	len ++;  
	SendBuffer[len] = (u8)(gDeviceDisplay.CurrentErrow[3]);   
	len ++; 
	SendBuffer[len] = (u8)(gDeviceDisplay.CurrentErrow[4]);   
	len ++;	
	
	//data length,2 Byte
	SendBuffer[1] = (u8)(len>>8);
	SendBuffer[2] = (u8)len;
	
	//check sum
	SendBuffer[len] = CalculateChecksum(SendBuffer,len,1);
	len ++;
	SendBuffer[len] = SYS_SYNC_TAIL;
	len ++;
	
	//Data exchange
	len = len + data_exchange(SendBuffer, SEND, len);
	
	// Send out
	PutStrToUart2Modem(SendBuffer, len);	
//	SystemEnableAllInterrupt();
}

void ReceiveDeviceDisplay(u8* pdata, u16 datalen)
{
	
}

void SendUserSetParameter(CMDTypeT msgtype)
{
	u16 len = 0;
	u8 i;
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Send User Set Parameter", FmtTimeShow());

	// Clear data
	memset(SendBuffer, 0, sizeof(SendBuffer));  
  
	// Fill head
	SendBuffer[0] = SYS_SYNC_HEAD;
	// Fill type
	SendBuffer[3] = CloudSerial;
	CloudSerial ++;
	// Fill length
	SendBuffer[4] = 0x30;
	//command type
	SendBuffer[5] = msgtype;	
	//SN
	for( i=0;i<8;i++)
	{
    if(ModemType==MODEM_WIFI)
    {
      SendBuffer[6+i] = gDeviceParameter.ModemWifiMacHex[i];
    }
    else if(ModemType==MODEM_2G)
    {
      SendBuffer[6+i] = gDeviceParameter.Modem2gImeiHex[i];
    }
	}

	//Product Type
	SendBuffer[14] = PRODUCT_TYPE_WATER_SPLIT_MACHINE;
  
	//Data Type
	SendBuffer[15] = DATA_TYPE_USER_SET_PARAMETER;
	len = 16;
	//Data Time
	SendBuffer[len] = MSG_USER_SET_DATE_TIME;	
	len ++;
	//Length
	SendBuffer[len] = UserSetParameterLen[MSG_USER_SET_DATE_TIME];
	len ++;
	SendBuffer[len] = gUserSetParameter.DateTime.Year;
	len ++;
	SendBuffer[len] = gUserSetParameter.DateTime.Month;
	len ++;
	SendBuffer[len] = gUserSetParameter.DateTime.Day;
	len ++;
	SendBuffer[len] = gUserSetParameter.DateTime.Hour;
	len ++;
	SendBuffer[len] = gUserSetParameter.DateTime.Minute;
	len ++;
	SendBuffer[len] = gUserSetParameter.DateTime.Second;

  //Sterilize Time
	len ++;
	SendBuffer[len] = MSG_USER_SET_STERILIZE_TIME;
	len ++;
	//Length
	SendBuffer[len] = UserSetParameterLen[MSG_USER_SET_STERILIZE_TIME];
	len ++;
	SendBuffer[len] = gUserSetParameter.SterilizeTime;  

  //Timing Sterilize Time
	len ++;
	SendBuffer[len] = MSG_USER_SET_TIMING_STERILIZE_TIME;
	len ++;
	//Length
	SendBuffer[len] = UserSetParameterLen[MSG_USER_SET_TIMING_STERILIZE_TIME];
	len ++;
	SendBuffer[len] = gUserSetParameter.TimingSterilizeTime; 
  //Led Light Level
	len ++;
	
	SendBuffer[len] = MSG_USER_SET_LED_LIGHT_LEVEL;
	len ++;
	//Length
	SendBuffer[len] = UserSetParameterLen[MSG_USER_SET_LED_LIGHT_LEVEL];
	len ++;
	SendBuffer[len] = gUserSetParameter.LedLightLevel; 
  
  //Reset Meterial
	len ++;
	SendBuffer[len] = MSG_USER_SET_RESET_MATERIAL;
	len ++;
	//Length
	SendBuffer[len] = UserSetParameterLen[MSG_USER_SET_RESET_MATERIAL];
	len ++;
	SendBuffer[len] = gUserSetParameter.ResetMaterial;    
  
  //Timing TOC
	len ++;
	SendBuffer[len] = MSG_USER_SET_TIMING_TOC;
	len ++;
	//Length
	SendBuffer[len] = UserSetParameterLen[MSG_USER_SET_TIMING_TOC];
	len ++;
	SendBuffer[len] = gUserSetParameter.TimingToc;    
  
	len ++;
	//data length,2 Byte
	SendBuffer[1] = (u8)(len>>8);
	SendBuffer[2] = (u8)len;
	//check sum
	SendBuffer[len] = CalculateChecksum(SendBuffer,len,1);
	len ++;
	SendBuffer[len] = SYS_SYNC_TAIL;
	len ++;
	
	//Data exchange
	len = len + data_exchange(SendBuffer, SEND, len);
	
	// Send out
	PutStrToUart2Modem(SendBuffer, len);	
  
//  SaveUserSetParameter();
}

/*
success: return 1
wrong: return 0
*/
u8 ReceiveUserSetParameter(u8* pdata, u16 datalen)
{
	u16 len,length;
	u8 i;
	
	len = 16;
	length = (pdata[1]<<8) + pdata[2];
	
	for(i=0;i<255;i++)
	{
		switch(pdata[len])
		{
			case MSG_USER_SET_DATE_TIME:				   //����ʱ��
			{
				len ++;
				UserSetParameterLen[MSG_USER_SET_DATE_TIME] = pdata[len];
				len ++;
				gUserSetParameter.DateTime.Year = pdata[len];
				len ++;
				gUserSetParameter.DateTime.Month = pdata[len];
				len ++;
				gUserSetParameter.DateTime.Day= pdata[len];
				len ++;
				gUserSetParameter.DateTime.Hour= pdata[len];
				len ++;
				gUserSetParameter.DateTime.Minute= pdata[len];
				len ++;
				gUserSetParameter.DateTime.Second= pdata[len];

				len ++;
			}
			break;
			
			case MSG_USER_SET_STERILIZE_TIME:				   //ɱ��ʱ��
			{
				len ++;
				
				UserSetParameterLen[MSG_USER_SET_STERILIZE_TIME] = pdata[len];
				len ++;
				gUserSetParameter.SterilizeTime = pdata[len];
				len ++;
			}
			break;
			
			case MSG_USER_SET_TIMING_STERILIZE_TIME: 		   //��ʱɱ����
			{
				len ++;
				
				UserSetParameterLen[MSG_USER_SET_TIMING_STERILIZE_TIME] = pdata[len];
				len ++;
				gUserSetParameter.TimingSterilizeTime = pdata[len];
				len ++;
			}
			break;
			
			case MSG_USER_SET_LED_LIGHT_LEVEL:				   //LED��������
			{
				len ++;
				
				UserSetParameterLen[MSG_USER_SET_LED_LIGHT_LEVEL] = pdata[len];
				len ++;
				gUserSetParameter.LedLightLevel = pdata[len];
				len ++;
			}
			break;
			
			case MSG_USER_SET_RESET_MATERIAL:				   //��о��λ
			{
				len ++;
				UserSetParameterLen[MSG_USER_SET_RESET_MATERIAL] = pdata[len];
				len ++;
				gUserSetParameter.ResetMaterial = pdata[len];
				len ++;
				if(gUserSetParameter.ResetMaterial==0x01)//PP LEE
				{
					gDeviceDisplay.PpValue = 100;	
					//PpFlowTotal = 0;
					//PpDayNumberCount = 0;
					FliterCPF.RunTime = 0;
					FliterCPF.PowerTime = 0;
				}
				if(gUserSetParameter.ResetMaterial==0x80)//RO LEE
				{
					gDeviceDisplay.RoValue = 100;
					//RoFlowTotal = 0;
					//RoMakeWaterCountTotal = 0;
					//RoDayNumberCount = 0;
					FliterRO.RunTime = 0;
					FliterRO.PowerTime = 0;
				}
				if(gUserSetParameter.ResetMaterial==0x40)//NF LEE
				{
					gDeviceDisplay.NfValue = 100;
					NfFlowTotal = 0;
					NfMakeWaterCountTotal = 0;
					NfDayNumberCount = 0;
//					FliterNF.RunTime = 0;
//					FliterNF.PowerTime = 0;
				}
				if(gUserSetParameter.ResetMaterial==0x20)//C1 LEE
				{
					gDeviceDisplay.C1Value = 100;
					//CFlowTotal = 0;
					//CMakeWaterCountTotal = 0;
					//C1DayNumberCount = 0;
					FliterCTO.RunTime = 0;
					FliterCTO.PowerTime = 0;
				}				
			}
			break;

			case MSG_USER_SET_TIMING_TOC:				   //��ʱTOC���
			{
				len ++;
				UserSetParameterLen[MSG_USER_SET_TIMING_TOC] = pdata[len];
				len ++;
				gUserSetParameter.TimingToc = pdata[len];
				len ++;
			}
			break;			
			
			default:
				break;
		}
		
		if(len==length)
		{
//			SaveParameter();
			// Print Out
			Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: for break", FmtTimeShow());
			break;  //����forѭ��
		}
	}

	if(i==255)
	{
		// Print Out
		Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: ReceiveDeviceParameter Wrong", FmtTimeShow());
		return 0;
	}	
	
//	ProcessSaveOption();
//	SaveUserSetParameter();
//	ProcessLoadOption();
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Receive User Set Parameter", FmtTimeShow());

	SendUserSetParameter(COMMAND_TYPE_MCU_TO_CLOUD_TOPIC1);
	
	return 1;

}

void SendUserOperateParemeter(MSGUserOperateParemeterT msgtype, CMDTypeT cmdtype)
{
	u16 len = 0;
	u8  i;
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Send User Operate Parameter", FmtTimeShow());

	// Clear data
	memset(SendBuffer, 0, sizeof(SendBuffer));  
  
	// Fill head
	SendBuffer[0] = SYS_SYNC_HEAD;
	// Fill type
	SendBuffer[3] = CloudSerial;
	CloudSerial ++;
	// Fill length
	SendBuffer[4] = 0x30;
	//command type
	SendBuffer[5] = cmdtype;	
	//SN
	for(i=0;i<8;i++)
	{
    if(ModemType==MODEM_WIFI)
    {
      SendBuffer[6+i] = gDeviceParameter.ModemWifiMacHex[i];
    }
    else if(ModemType==MODEM_2G)
    {
      SendBuffer[6+i] = gDeviceParameter.Modem2gImeiHex[i];
    }
	}

	//Product Type
	SendBuffer[14] = PRODUCT_TYPE_COMPERCE_WATER_PURIFIER;
  
	//Data Type
	SendBuffer[15] = DATA_TYPE_USER_OPERATE_PARAMETER;
	len = 16;
	//Data Time
	SendBuffer[len] = MSG_USER_OPERATE_DATE_TIME;	
	len ++;
	//Length
	SendBuffer[len] = UserOperateParemeterLen[MSG_USER_OPERATE_DATE_TIME];
	len ++;
	SendBuffer[len] = gUserOperateParemeter.DateTime.Year;
	len ++;
	SendBuffer[len] = gUserOperateParemeter.DateTime.Month;
	len ++;
	SendBuffer[len] = gUserOperateParemeter.DateTime.Day;
	len ++;
	SendBuffer[len] = gUserOperateParemeter.DateTime.Hour;
	len ++;
	SendBuffer[len] = gUserOperateParemeter.DateTime.Minute;
	len ++;
	SendBuffer[len] = gUserOperateParemeter.DateTime.Second;
  
	len ++;
	switch(msgtype)
	{
		case MSG_USER_OPERATE_POWER_SWITCH:
		{
		  SendBuffer[len] = MSG_USER_OPERATE_POWER_SWITCH;
		  len ++;
		  //Length
		  SendBuffer[len] = UserOperateParemeterLen[MSG_USER_OPERATE_POWER_SWITCH];
		  len ++;
		  SendBuffer[len] = gUserOperateParemeter.PowerSwitch;
		  len ++;
		//      len = len + UserOperateParemeterLen[MSG_USER_OPERATE_POWER_SWITCH];
		}
		break;

		case MSG_USER_OPERATE_HEAT_SWITCH:
		{
		  SendBuffer[len] = MSG_USER_OPERATE_HEAT_SWITCH;
		  len ++;
		  //Length
		  SendBuffer[len] = UserOperateParemeterLen[MSG_USER_OPERATE_HEAT_SWITCH];
		  len ++;
		  SendBuffer[len] = gUserOperateParemeter.HeatSwitch;
		  len ++;
		//      len = len + UserOperateParemeterLen[MSG_USER_OPERATE_HEAT_SWITCH];
		}
		break;

		case MSG_USER_OPERATE_REFRIGERATE_SWITCH:
		{
		  SendBuffer[len] = MSG_USER_OPERATE_REFRIGERATE_SWITCH;
		  len ++;
		  //Length
		  SendBuffer[len] = UserOperateParemeterLen[MSG_USER_OPERATE_REFRIGERATE_SWITCH];
		  len ++;
		  SendBuffer[len] = gUserOperateParemeter.RefrigerateSwitch;
		  len ++;
		//      len = len + UserOperateParemeterLen[MSG_USER_OPERATE_REFRIGERATE_SWITCH];
		}
		break;

		case MSG_USER_OPERATE_STERILIZE_SWITCH:
		{
		  SendBuffer[len] = MSG_USER_OPERATE_STERILIZE_SWITCH;
		  len ++;
		  //Length
		  SendBuffer[len] = UserOperateParemeterLen[MSG_USER_OPERATE_STERILIZE_SWITCH];
		  len ++;
		  SendBuffer[len] = gUserOperateParemeter.SterilizeSwitch;
		  len ++;
		//      len = len + UserOperateParemeterLen[MSG_USER_OPERATE_STERILIZE_SWITCH];
		}
		break;

		case MSG_USER_OPERATE_STANDBY_SWITCH:
		{
		  SendBuffer[len] = MSG_USER_OPERATE_STANDBY_SWITCH;
		  len ++;
		  //Length
		  SendBuffer[len] = UserOperateParemeterLen[MSG_USER_OPERATE_STANDBY_SWITCH];
		  len ++;
		  SendBuffer[len] = gUserOperateParemeter.StanbySwitch;
		  len ++;
		//      len = len + UserOperateParemeterLen[MSG_USER_OPERATE_STANDBY_SWITCH];
		}
		break;

		case MSG_USER_OPERATE_MIX_SWITCH:
		{
		  SendBuffer[len] = MSG_USER_OPERATE_MIX_SWITCH;
		  len ++;
		  //Length
		  SendBuffer[len] = UserOperateParemeterLen[MSG_USER_OPERATE_MIX_SWITCH];
		  len ++;
		  SendBuffer[len] = gUserOperateParemeter.MixSwitch;
		  len ++;
		//      len = len + UserOperateParemeterLen[MSG_USER_OPERATE_MIX_SWITCH];
		}
		break;

		case MSG_USER_OPERATE_COMPEL_REGEN_SWITCH:
		{
		  SendBuffer[len] = MSG_USER_OPERATE_COMPEL_REGEN_SWITCH;
		  len ++;
		  //Length
		  SendBuffer[len] = UserOperateParemeterLen[MSG_USER_OPERATE_COMPEL_REGEN_SWITCH];
		  len ++;
		  SendBuffer[len] = gUserOperateParemeter.CompleRegenSwitch;
		  len ++;
		//      len = len + UserOperateParemeterLen[MSG_USER_OPERATE_COMPEL_REGEN_SWITCH];
		}
		break;

		case MSG_USER_OPERATE_BOOK_REGEN_SWITCH:
		{
		  SendBuffer[len] = MSG_USER_OPERATE_BOOK_REGEN_SWITCH;
		  len ++;
		  //Length
		  SendBuffer[len] = UserOperateParemeterLen[MSG_USER_OPERATE_BOOK_REGEN_SWITCH];
		  len ++;
		  SendBuffer[len] = gUserOperateParemeter.BookRegenSwitch;
		  len ++;
		//      len = len + UserOperateParemeterLen[MSG_USER_OPERATE_BOOK_REGEN_SWITCH];
		}
		break;

		case MSG_USER_OPERATE_COMPEL_WASH_SWITCH:
		{
		  SendBuffer[len] = MSG_USER_OPERATE_COMPEL_WASH_SWITCH;
		  len ++;
		  //Length
		  SendBuffer[len] = UserOperateParemeterLen[MSG_USER_OPERATE_COMPEL_WASH_SWITCH];
		  len ++;
		  SendBuffer[len] = gUserOperateParemeter.CompleWashSwitch;
		  len ++;
		//      len = len + UserOperateParemeterLen[MSG_USER_OPERATE_COMPEL_WASH_SWITCH];
		}
		break;

		case MSG_USER_OPERATE_BOOK_WASH_SWITCH:
		{
		  SendBuffer[len] = MSG_USER_OPERATE_BOOK_WASH_SWITCH;
		  len ++;
		  //Length
		  SendBuffer[len] = UserOperateParemeterLen[MSG_USER_OPERATE_BOOK_WASH_SWITCH];
		  len ++;
		  SendBuffer[len] = gUserOperateParemeter.BookWashSwitch;
		  len ++;
		//      len = len + UserOperateParemeterLen[MSG_USER_OPERATE_BOOK_WASH_SWITCH];
		}
		break;
		case MSG_USER_OPERATE_LCD_TUTNOFF_SWITCH:
		{
		  SendBuffer[len] = MSG_USER_OPERATE_LCD_TUTNOFF_SWITCH;
		  len ++;
		  //Length
		  SendBuffer[len] = UserOperateParemeterLen[MSG_USER_OPERATE_LCD_TUTNOFF_SWITCH];
		  len ++;
		  SendBuffer[len] = gUserOperateParemeter.LCDTurnOffSwitch;
		  len ++;
		//      len = len + UserOperateParemeterLen[MSG_USER_OPERATE_BOOK_WASH_SWITCH];
		}
		break;

		default:
		break;
	}  
	
	//data length,2 Byte
	SendBuffer[1] = (u8)(len>>8);
	SendBuffer[2] = (u8)len;
	//check sum
	SendBuffer[len] = CalculateChecksum(SendBuffer,len,1);
	len ++;
	SendBuffer[len] = SYS_SYNC_TAIL;
	len ++;
	
	//Data exchange
	len = len + data_exchange(SendBuffer, SEND, len);
	
	// Send out
	PutStrToUart2Modem(SendBuffer, len);	
}

/*
success: return 1
wrong: return 0
*/
u8 ReceiveUserOperateParemeter(u8* pdata, u16 datalen)
{
	u16 len,length;
	u8 i;
	MSGUserOperateParemeterT ReceiveCmdType;
	len = 16;
	length = (pdata[1]<<8) + pdata[2];

	for(i=0;i<255;i++)
	{
		switch(pdata[len])
		{
			case MSG_USER_OPERATE_DATE_TIME:                 //����ʱ��
			{
				len ++;
				UserOperateParemeterLen[MSG_USER_OPERATE_DATE_TIME] = pdata[len];
				len ++;
				gUserOperateParemeter.DateTime.Year = pdata[len];
				len ++;
				gUserOperateParemeter.DateTime.Month = pdata[len];
				len ++;
				gUserOperateParemeter.DateTime.Day= pdata[len];
				len ++;
				gUserOperateParemeter.DateTime.Hour= pdata[len];
				len ++;
				gUserOperateParemeter.DateTime.Minute= pdata[len];
				len ++;
				gUserOperateParemeter.DateTime.Second= pdata[len];
				
				len ++;
			}
			break;
			
			case MSG_USER_OPERATE_POWER_SWITCH:              //��Դ����
			{
				len ++;
				UserOperateParemeterLen[MSG_USER_OPERATE_POWER_SWITCH] = pdata[len];
				len ++;
				gUserOperateParemeter.PowerSwitch = pdata[len];
				len ++;

				ReceiveCmdType = MSG_USER_OPERATE_POWER_SWITCH;
			}
			break;
			

			case MSG_USER_OPERATE_HEAT_SWITCH:               //���ȿ���
			{
				len ++;
				UserOperateParemeterLen[MSG_USER_OPERATE_HEAT_SWITCH] = pdata[len];
				len ++;
				gUserOperateParemeter.HeatSwitch = pdata[len];
				len ++;

				ReceiveCmdType = MSG_USER_OPERATE_HEAT_SWITCH;
			}
			break;
			

			case MSG_USER_OPERATE_REFRIGERATE_SWITCH:        //���俪��
			{
				len ++;
				UserOperateParemeterLen[MSG_USER_OPERATE_REFRIGERATE_SWITCH] = pdata[len];
				len ++;
				gUserOperateParemeter.RefrigerateSwitch = pdata[len];
				len ++;

				ReceiveCmdType = MSG_USER_OPERATE_REFRIGERATE_SWITCH;

			}
			break;
			

			case MSG_USER_OPERATE_STERILIZE_SWITCH:          //ɱ������
			{
				len ++;
				UserOperateParemeterLen[MSG_USER_OPERATE_STERILIZE_SWITCH] = pdata[len];
				len ++;
				gUserOperateParemeter.SterilizeSwitch = pdata[len];
				len ++;

				ReceiveCmdType = MSG_USER_OPERATE_STERILIZE_SWITCH;

			}
			break;	

			case MSG_USER_OPERATE_STANDBY_SWITCH:            //����״̬��ˮ��״̬��
			{
				len ++;
				UserOperateParemeterLen[MSG_USER_OPERATE_STANDBY_SWITCH] = pdata[len];
				len ++;
				gUserOperateParemeter.StanbySwitch = pdata[len];
				len ++;

				ReceiveCmdType = MSG_USER_OPERATE_STANDBY_SWITCH;

			}
			break;	

			case MSG_USER_OPERATE_MIX_SWITCH:                //���ҿ���
			{
				len ++;
				UserOperateParemeterLen[MSG_USER_OPERATE_MIX_SWITCH] = pdata[len];
				len ++;
				gUserOperateParemeter.MixSwitch = pdata[len];
				len ++;

				ReceiveCmdType = MSG_USER_OPERATE_MIX_SWITCH;

			}
			break;

			case MSG_USER_OPERATE_COMPEL_REGEN_SWITCH:       //ǿ������
			{
				len ++;
				UserOperateParemeterLen[MSG_USER_OPERATE_COMPEL_REGEN_SWITCH] = pdata[len];
				len ++;
				gUserOperateParemeter.CompleRegenSwitch = pdata[len];
				len ++;

				ReceiveCmdType = MSG_USER_OPERATE_COMPEL_REGEN_SWITCH;

			}
			break;	

			case MSG_USER_OPERATE_BOOK_REGEN_SWITCH:         //ԤԼ����
			{
				len ++;
				UserOperateParemeterLen[MSG_USER_OPERATE_BOOK_REGEN_SWITCH] = pdata[len];
				len ++;
				gUserOperateParemeter.BookRegenSwitch = pdata[len];
				len ++;

				ReceiveCmdType = MSG_USER_OPERATE_BOOK_REGEN_SWITCH;

			}
			break;	

			case MSG_USER_OPERATE_COMPEL_WASH_SWITCH:        //ǿ�Ƴ�ϴ
			{
				len ++;
				UserOperateParemeterLen[MSG_USER_OPERATE_COMPEL_WASH_SWITCH] = pdata[len];
				len ++;
				gUserOperateParemeter.CompleWashSwitch = pdata[len];
				len ++;

				ReceiveCmdType = MSG_USER_OPERATE_COMPEL_WASH_SWITCH;

			}
			break;	

			case MSG_USER_OPERATE_BOOK_WASH_SWITCH:          //ԤԼ��ϴ
			{
				len ++;
				UserOperateParemeterLen[MSG_USER_OPERATE_BOOK_WASH_SWITCH] = pdata[len];
				len ++;
				gUserOperateParemeter.BookWashSwitch = pdata[len];
				len ++;

				ReceiveCmdType = MSG_USER_OPERATE_BOOK_WASH_SWITCH;

			}
			break;
			case MSG_USER_OPERATE_LCD_TUTNOFF_SWITCH:          //�Զ�Ϩ��LEE V1.0.7
			{
				len ++;
				UserOperateParemeterLen[MSG_USER_OPERATE_LCD_TUTNOFF_SWITCH] = pdata[len];
				len ++;
				gUserOperateParemeter.LCDTurnOffSwitch = pdata[len];
				len ++;

				ReceiveCmdType = MSG_USER_OPERATE_LCD_TUTNOFF_SWITCH;

			}
			break;

			default:
			break;
		}
		
		if(len==length)
		{
			// Print Out
			Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: for break", FmtTimeShow());
			break;  //����forѭ��
		}
	}

	if(i==255)
	{
		// Print Out
		Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Receive User Operate Parameter Wrong", FmtTimeShow());
		return 0;
	}

	
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Receive User Operate Parameter", FmtTimeShow());	

	SendUserOperateParemeter(ReceiveCmdType,COMMAND_TYPE_MCU_TO_CLOUD_TOPIC1);
	return 1;
}

void SendServiceParameter(CMDTypeT msgtype)
{
	u16 len = 0;
	u8 i;
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Send Service Parameter", FmtTimeShow());	

	// Clear data
	memset(SendBuffer, 0, sizeof(SendBuffer));  
  
	// Fill head
	SendBuffer[0] = SYS_SYNC_HEAD;
	// Fill type
	SendBuffer[3] = CloudSerial;
	CloudSerial ++;
	// Fill length
	SendBuffer[4] = 0x30;
	//command type
	SendBuffer[5] = msgtype;	
	//SN
	for( i=0;i<8;i++)
	{
    if(ModemType==MODEM_WIFI)
    {
      SendBuffer[6+i] = gDeviceParameter.ModemWifiMacHex[i];
    }
    else if(ModemType==MODEM_2G)
    {
      SendBuffer[6+i] = gDeviceParameter.Modem2gImeiHex[i];
    }
	}

	//Product Type
	SendBuffer[14] = PRODUCT_TYPE_WATER_SPLIT_MACHINE;
  
	//Data Type
	SendBuffer[15] = DATA_TYPE_SERVICE_SET_PARAMETER;
	len = 16;
	//Data Time
	SendBuffer[len] = MSG_SERVICE_DATE_TIME;	
	len ++;
	//Length
	SendBuffer[len] = ServiceParameterLen[MSG_SERVICE_DATE_TIME];
	len ++;
	SendBuffer[len] = gServiceParameter.DateTime.Year;
	len ++;
	SendBuffer[len] = gServiceParameter.DateTime.Month;
	len ++;
	SendBuffer[len] = gServiceParameter.DateTime.Day;
	len ++;
	SendBuffer[len] = gServiceParameter.DateTime.Hour;
	len ++;
	SendBuffer[len] = gServiceParameter.DateTime.Minute;
	len ++;
	SendBuffer[len] = gServiceParameter.DateTime.Second;
  

  //Pp Value
	len ++;
	SendBuffer[len] = MSG_SERVICE_PP_VALUE;
	len ++;
	//Length
	SendBuffer[len] = ServiceParameterLen[MSG_SERVICE_PP_VALUE];
	len ++;
	SendBuffer[len] = (u8)(gDeviceDisplay.PpValue>>8);
	len ++;
	SendBuffer[len] = (u8)gDeviceDisplay.PpValue;

  //C1 Value
	len ++;
	SendBuffer[len] = MSG_SERVICE_C1_VALUE;
	len ++;
	//Length
	SendBuffer[len] = ServiceParameterLen[MSG_SERVICE_C1_VALUE];
	len ++;
	SendBuffer[len] = (u8)(gDeviceDisplay.C1Value>>8);
	len ++;
	SendBuffer[len] = (u8)gDeviceDisplay.C1Value;
  
  //RO Value
	len ++;
	SendBuffer[len] = MSG_SERVICE_RO_VALUE;
	len ++;
	//Length
	SendBuffer[len] = ServiceParameterLen[MSG_SERVICE_RO_VALUE];
	len ++;
	SendBuffer[len] = (u8)(gDeviceDisplay.RoValue>>8);
	len ++;
	SendBuffer[len] = (u8)gDeviceDisplay.RoValue;

  //NF Value
	len ++;
	SendBuffer[len] = MSG_SERVICE_NF_VALUE;
	len ++;
	//Length
	SendBuffer[len] = ServiceParameterLen[MSG_SERVICE_NF_VALUE];
	len ++;
	SendBuffer[len] = (u8)(gDeviceDisplay.NfValue>>8);
	len ++;
	SendBuffer[len] = (u8)gDeviceDisplay.NfValue;
  
  //Original Water Tds
	len ++;
	SendBuffer[len] = MSG_SERVICE_ORIGINAL_WATER_TDS;
	len ++;
	//Length
	SendBuffer[len] = ServiceParameterLen[MSG_SERVICE_ORIGINAL_WATER_TDS];
	len ++;
	SendBuffer[len] = (u8)(gServiceParameter.OriginalWaterTds>>8);
	len ++;
	SendBuffer[len] = (u8)gServiceParameter.OriginalWaterTds;    
  
  //Clean Water Tds
	len ++;
	SendBuffer[len] = MSG_SERVICE_CLEAN_WATER_TDS;
	len ++;
	//Length
	SendBuffer[len] = ServiceParameterLen[MSG_SERVICE_CLEAN_WATER_TDS];
	len ++;
	SendBuffer[len] = (u8)(gServiceParameter.CleanWaterTds>>8);
	len ++;
	SendBuffer[len] = (u8)gServiceParameter.CleanWaterTds;     
  
  //Original Water Toc
	len ++;
	SendBuffer[len] = MSG_SERVICE_ORIGINAL_WATER_TOC;
	len ++;
	//Length
	SendBuffer[len] = ServiceParameterLen[MSG_SERVICE_ORIGINAL_WATER_TOC];
	len ++;
	SendBuffer[len] = gServiceParameter.OriginalWaterToc;    
  
  //Clean Water Toc
	len ++;
	SendBuffer[len] = MSG_SERVICE_CLEAN_WATER_TOC;
	len ++;
	//Length
	SendBuffer[len] = ServiceParameterLen[MSG_SERVICE_CLEAN_WATER_TOC];
	len ++;
	SendBuffer[len] = gServiceParameter.CleanWaterToc;      

	len ++;
	//data length,2 Byte
	SendBuffer[1] = (u8)(len>>8);
	SendBuffer[2] = (u8)len;
	//check sum
	SendBuffer[len] = CalculateChecksum(SendBuffer,len,1);
	len ++;
	SendBuffer[len] = SYS_SYNC_TAIL;
	len ++;
	
	//Data exchange
	len = len + data_exchange(SendBuffer, SEND, len);
	
	// Send out
	PutStrToUart2Modem(SendBuffer, len);	  
}

u8 ReceiveServiceParameter(u8* pdata, u16 datalen)
{
	u16 len,length;
	u8 i;
	
	len = 16;
	length = (pdata[1]<<8) + pdata[2];
	
	for(i=0;i<255;i++)
	{
		switch(pdata[len])
		{
			case MSG_SERVICE_DATE_TIME:			  		  //����ʱ��
			{
				len ++;
				ServiceParameterLen[MSG_SERVICE_DATE_TIME] = pdata[len];
				len ++;
				gServiceParameter.DateTime.Year = pdata[len];
				len ++;
				gServiceParameter.DateTime.Month = pdata[len];
				len ++;
				gServiceParameter.DateTime.Day= pdata[len];
				len ++;
				gServiceParameter.DateTime.Hour= pdata[len];
				len ++;
				gServiceParameter.DateTime.Minute= pdata[len];
				len ++;
				gServiceParameter.DateTime.Second= pdata[len];
				
				len ++;

			}
			break;
			
			case MSG_SERVICE_PP_VALUE:					  //PP��������
			{
				len ++;
				ServiceParameterLen[MSG_SERVICE_PP_VALUE] = pdata[len];
				len ++;
				gServiceParameter.PpValue = (pdata[len]<<8) + pdata[len+1];
				if(gServiceParameter.PpValue>100)
				{
					gServiceParameter.PpValue = 100;
				}
				
				PpFlowTotal = (100-gServiceParameter.PpValue)*PAC_FLOW_TOTAL*4;				
				PpDayNumberCount = (u32)((100-gServiceParameter.PpValue)*3.65);
				if(ProduceType==0x01)
				{
					FliterCPF.RunTime = (100-gServiceParameter.PpValue)*(FLITER_CPF_500G_RUNLIFE/100);
				}
				else if (ProduceType == 0x02)
				{
					FliterCPF.RunTime = (100-gServiceParameter.PpValue)*(FLITER_CPF_700G_RUNLIFE/100);
				}
				else
				{	
					FliterCPF.PowerTime = (100-gServiceParameter.PpValue)*(FLITER_CPF_800G_POWERLIFE/100);
				}
				len = len +2;
			}
			break;

			case MSG_SERVICE_C1_VALUE:					  //C1��������
			{
				len ++;
				ServiceParameterLen[MSG_SERVICE_C1_VALUE] = pdata[len];
				len ++;
				gServiceParameter.C1Value = (pdata[len]<<8) + pdata[len+1];
				if(gServiceParameter.C1Value>100)
				{
					gServiceParameter.C1Value = 100;
				}
				CMakeWaterCountTotal = (100-gServiceParameter.C1Value)*2000;
				C1DayNumberCount = (u32)((100-gServiceParameter.C1Value)*3.65);
				if(ProduceType==0x01)
				{
					FliterCTO.RunTime = (100-gServiceParameter.C1Value)*(FLITER_CTO_500G_RUNLIFE/100);
				}
				else if(ProduceType==0x02)
				{
					FliterCTO.RunTime = (100-gServiceParameter.C1Value)*(FLITER_CTO_700G_RUNLIFE/100);
				}
				else
				{
					FliterCTO.PowerTime = (100-gServiceParameter.C1Value)*(FLITER_CTO_800G_POWERLIFE/100);
				}
				len = len +2;
			}
			break;

			case MSG_SERVICE_RO_VALUE:					  //RO��������
			{
				len ++;
				ServiceParameterLen[MSG_SERVICE_RO_VALUE] = pdata[len];
				len ++;
				gServiceParameter.RoValue = (pdata[len]<<8) + pdata[len+1];
				if(gServiceParameter.RoValue>100)
				{
					gServiceParameter.RoValue = 100;
				}
				RoMakeWaterCountTotal = (100-gServiceParameter.RoValue)*2000;
				if(ProduceType==0x01)
				{
					FliterRO.RunTime = (100-gServiceParameter.RoValue)*(FLITER_RO_500G_RUNLIFE/100);
				}
				else if(ProduceType==0x02)
				{
					FliterRO.RunTime = (100-gServiceParameter.RoValue)*(FLITER_RO_700G_RUNLIFE/100);
				}
				else 
				{
					FliterRO.PowerTime = (100-gServiceParameter.RoValue)*(FLITER_RO_800G_POWERLIFE/100);
				}
				len = len +2;
			}

			break;

			case MSG_SERVICE_NF_VALUE:					  //NF��������
			{
				len ++;
				ServiceParameterLen[MSG_SERVICE_NF_VALUE] = pdata[len];
				len ++;
				gServiceParameter.NfValue = (pdata[len]<<8) + pdata[len+1];
				if(gServiceParameter.NfValue>100)
				{
					gServiceParameter.NfValue = 100;
				}
				NfMakeWaterCountTotal = (100-gServiceParameter.NfValue)*2000;
				len = len +2;
			}

			break;

			case MSG_SERVICE_ORIGINAL_WATER_TDS: 		  //ԭˮTDS����
			{
				len ++;
				ServiceParameterLen[MSG_SERVICE_ORIGINAL_WATER_TDS] = pdata[len];
				len ++;
				gServiceParameter.OriginalWaterTds = (pdata[len]<<8) + pdata[len+1];
				len = len +2;
			}

			break;

			case MSG_SERVICE_CLEAN_WATER_TDS:			  //��ˮTDS����
			{
				len ++;
				ServiceParameterLen[MSG_SERVICE_CLEAN_WATER_TDS] = pdata[len];
				len ++;
				gServiceParameter.CleanWaterTds = (pdata[len]<<8) + pdata[len+1];
				len = len +2;
			}

			break;

			case MSG_SERVICE_ORIGINAL_WATER_TOC: 		  //ԭˮT0C����
			{
				len ++;
				ServiceParameterLen[MSG_SERVICE_ORIGINAL_WATER_TOC] = pdata[len];
				len ++;
				gServiceParameter.OriginalWaterToc = (pdata[len]<<8) + pdata[len+1];
				len = len +2;
			}

			break;

			case MSG_SERVICE_CLEAN_WATER_TOC:			  //��ˮTOC����
			{
				len ++;
				ServiceParameterLen[MSG_SERVICE_CLEAN_WATER_TOC] = pdata[len];
				len ++;
				gServiceParameter.CleanWaterToc = (pdata[len]<<8) + pdata[len+1];
				len = len +2;
			}

			break;

			default:
			break;
		}
    if(len==length)
    {
      // Print Out
			Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: for break", FmtTimeShow());	
      break;	//����forѭ��
    }
	}

	if(i==255)
	{
		Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Receive User Operate Parameter Wrong", FmtTimeShow());	  
		return 0;
	}
	SaveParameter();//���ú󱣳�����
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Receive User Operate Parameter", FmtTimeShow());
  Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] \r\n FliterRO.PowerTime = [%d]\r\n ", FmtTimeShow(),FliterRO.PowerTime);	
	
	SendServiceParameter(COMMAND_TYPE_MCU_TO_CLOUD_TOPIC1);
	
	return 1;

}

/*
success: return 1
wrong: return 0
*/
u8 ReceiveLeaseBussinessParemeter(u8* pdata, u16 datalen)
{
	u16 len,length;
	u8 i;
	
	len = 16;
	length = (pdata[1]<<8) + pdata[2];
	
	for(i=0;i<255;i++)
	{
		switch(pdata[len])
		{
			case MSG_LEASE_DATE_TIME: 				        //����ʱ��
			{
				len ++;
				LeaseBussinessParemeterLen[MSG_LEASE_DATE_TIME] = pdata[len];
				len ++;
				gLeaseBussinessParemeter.DateTime.Year = pdata[len];
				len ++;
				gLeaseBussinessParemeter.DateTime.Month = pdata[len];
				len ++;
				gLeaseBussinessParemeter.DateTime.Day= pdata[len];
				len ++;
				gLeaseBussinessParemeter.DateTime.Hour= pdata[len];
				len ++;
				gLeaseBussinessParemeter.DateTime.Minute= pdata[len];
				len ++;
				gLeaseBussinessParemeter.DateTime.Second= pdata[len];
				
				len ++;

			}
			break;
			
			case MSG_LEASE_DRAW_OFF_HOT_WATER_VOLUME_ONCE:	//������ˮ��ˮ�������Σ�
			{
				len ++;
				LeaseBussinessParemeterLen[MSG_LEASE_DRAW_OFF_HOT_WATER_VOLUME_ONCE] = pdata[len];
				len ++;
				gLeaseBussinessParemeter.DrawOffHotWaterVolumeOnce= (pdata[len]<<8) + pdata[len+1];
				len = len +2;
			}
			break;

			case MSG_LEASE_DRAW_OFF_ICE_WATER_VOLUME_ONCE:	//������ˮ��ˮ�������Σ�
			{
				len ++;
				LeaseBussinessParemeterLen[MSG_LEASE_DRAW_OFF_ICE_WATER_VOLUME_ONCE] = pdata[len];
				len ++;
				gLeaseBussinessParemeter.DrawOffIceWaterVolumeOnce= (pdata[len]<<8) + pdata[len+1];
				len = len +2;
			}
			break;
			
			case MSG_LEASE_DRAW_OFF_COLD_WATER_VOLUME_ONCE:	//�����ˮ��ˮ�������Σ�
			{
				len ++;
				LeaseBussinessParemeterLen[MSG_LEASE_DRAW_OFF_COLD_WATER_VOLUME_ONCE] = pdata[len];
				len ++;
				gLeaseBussinessParemeter.DrawOffColdWaterVolumeOnce= (pdata[len]<<8) + pdata[len+1];
				len = len +2;
			}
			break;

			case MSG_LEASE_DRAW_OFF_HOT_WATER_TIME_ONCE: 	//������ˮ��ˮʱ�䣨���Σ�
			{
				len ++;
				LeaseBussinessParemeterLen[MSG_LEASE_DRAW_OFF_HOT_WATER_TIME_ONCE] = pdata[len];
				len ++;
				gLeaseBussinessParemeter.DrawOffHotWaterTimeOnce= (pdata[len]<<8) + pdata[len+1];
				len = len +2;
			}
			break;

			case MSG_LEASE_DRAW_OFF_ICE_WATER_TIME_ONCE: 	//������ˮ��ˮʱ�䣨���Σ�
			{
				len ++;
				LeaseBussinessParemeterLen[MSG_LEASE_DRAW_OFF_ICE_WATER_TIME_ONCE] = pdata[len];
				len ++;
				gLeaseBussinessParemeter.DrawOffIceWaterTimeOnce= (pdata[len]<<8) + pdata[len+1];
				len = len +2;
			}
			break;

			case MSG_LEASE_DRAW_OFF_COLD_WATER_TIME_ONCE:	//�����ˮ��ˮʱ�䣨���Σ�
			{
				len ++;
				LeaseBussinessParemeterLen[MSG_LEASE_DRAW_OFF_COLD_WATER_TIME_ONCE] = pdata[len];
				len ++;
				gLeaseBussinessParemeter.DrawOffColdWaterTimeOnce= (pdata[len]<<8) + pdata[len+1];
				len = len +2;
			}
			break;

			case MSG_LEASE_SERVICE_REMAINDER_TIME:			//����ʣ��ʱ������
			{
				len ++;
				LeaseBussinessParemeterLen[MSG_LEASE_SERVICE_REMAINDER_TIME] = pdata[len];
				len ++;
				gLeaseBussinessParemeter.ServiceRemainderTime= (pdata[len]<<8) + pdata[len+1];
				len = len +2;
			}
			break;

			case MSG_LEASE_VALVE_NUMBER: 					//��ˮ�����
			{
				len ++;
				LeaseBussinessParemeterLen[MSG_LEASE_VALVE_NUMBER] = pdata[len];
				len ++;
				gLeaseBussinessParemeter.VavleNum= pdata[len];
				len ++;
			}
			break;

			default:
				break;
		}

		if(len==length)
		{
			// Print Out
			Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: for break", FmtTimeShow());	  
			break;	//����forѭ��
		}

	}

	if(i==255)
	{
		Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Receive Lease Bussiness Parameter Wrong", FmtTimeShow());	  
		return 0;
	}
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Receive Lease Bussiness Parameter", FmtTimeShow()); 
	return 1;
	 	
}

/*
success: return 1
wrong: return 0
*/
u8 ReceiveThirdParameter(u8* pdata, u16 datalen)
{
	u16 len,length;
	u8 i;
	
	len = 16;
	length = (pdata[1]<<8) + pdata[2];
	
	for(i=0;i<255;i++)
	{
		switch(pdata[len])
		{
			case MSG_THIRD_DATE_TIME:          //����ʱ��
			{
				len ++;
				ThirdParameterLen[MSG_LEASE_DATE_TIME] = pdata[len];
				len ++;
				gThirdParameter.DateTime.Year = pdata[len];
				len ++;
				gThirdParameter.DateTime.Month = pdata[len];
				len ++;
				gThirdParameter.DateTime.Day= pdata[len];
				len ++;
				gThirdParameter.DateTime.Hour= pdata[len];
				len ++;
				gThirdParameter.DateTime.Minute= pdata[len];
				len ++;
				gThirdParameter.DateTime.Second= pdata[len];
				
				len ++;

			}
			break;
			
			case MSG_THIRD_WEATHER:			  //����			
			{
				len ++;
				ThirdParameterLen[MSG_THIRD_WEATHER] = pdata[len];
				len ++;
				gThirdParameter.Weather= pdata[len];
				len ++;
			}
			break;
			
			case MSG_THIRD_PM25:               //��������PM2.
			{
				len ++;
				ThirdParameterLen[MSG_THIRD_PM25] = pdata[len];
				len ++;
				gThirdParameter.Pm25= (pdata[len]<<8) + pdata[len+1];
				len = len + 2;

			}
			break;

			case MSG_THIRD_TEMPERATURE:        //�¶�
			{
				len ++;
				ThirdParameterLen[MSG_THIRD_TEMPERATURE] = pdata[len];
				len ++;
				gThirdParameter.Temperature= (pdata[len]<<8) + pdata[len+1];
				len = len + 2;

			}
			break;

			case MSG_THIRD_HIGHT:              //���θ߶�
			{
				len ++;
				ThirdParameterLen[MSG_THIRD_HIGHT] = pdata[len];
				len ++;
				gThirdParameter.Hight= (pdata[len]<<8) + pdata[len+1];
				len = len + 2;		
			}
			break;

			default:
				break;

		}
		
		if(len==length)
		{
			// Print Out
			Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: for break", FmtTimeShow()); 
			break;	//����forѭ��
		}

	}

	if(i==255)
	{
		Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Receive Third Parameter Wrong", FmtTimeShow());
		return 0;
	}
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Receive Third Parameter", FmtTimeShow());
	return 1;  	
}

/*
success: return 1
wrong: return 0
*/
u8 ReceiveLimit(u8* pdata, u16 datalen)
{
	u16 len,length;
	u8 i;
	
	len = 16;
	length = (pdata[1]<<8) + pdata[2];
	
	for(i=0;i<255;i++)
	{
		switch(pdata[len])
		{
			case MSG_LIMIT_DATE_TIME:  //����ʱ��
			{
				len ++;
				LimitLen[MSG_LIMIT_DATE_TIME] = pdata[len];
				len ++;
				gLimit.DateTime.Year = pdata[len];
				len ++;
				gLimit.DateTime.Month = pdata[len];
				len ++;
				gLimit.DateTime.Day= pdata[len];
				len ++;
				gLimit.DateTime.Hour= pdata[len];
				len ++;
				gLimit.DateTime.Minute= pdata[len];
				len ++;
				gLimit.DateTime.Second= pdata[len];
				
				len ++;

			}
			break;
			
			case MSG_LIMIT_TYPE: 		//Ȩ��
			{
				len ++;
				LimitLen[MSG_LIMIT_TYPE] = pdata[len];
				len ++;
				gLimit.Limit = pdata[len];
				len ++;
			}
			break;

			default:
				break;
			
		}

		if(len==length)
		{
			// Print Out
			Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: for break", FmtTimeShow());
			break;	//����forѭ��
		}
	
	}

	if(i==255)
	{
		Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Receive Third Parameter Wrong", FmtTimeShow());	  
		return 0;
	}
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Receive Third Parameter", FmtTimeShow());	  	  
	return 1;  
}

/*
success: return 1
wrong: return 0
*/
u8 ReceiveInternetDateTime(u8* pdata, u16 datalen)
{
	u16 len;
	TimeTableT time;
	len = 16;
	
	switch(pdata[len])
	{
		case MSG_INTERNET_DATE_TIME:  //����ʱ��
		{
			len ++;
			InternetDateTimeLen[MSG_INTERNET_DATE_TIME] = pdata[len];
			len ++;
			gInternetDateTime.DateTime.Year = pdata[len];
			time.year =  bin2bcd(pdata[len]);
			len ++;
			gInternetDateTime.DateTime.Month = pdata[len];
			time.month = bin2bcd(pdata[len]);
			len ++;
			gInternetDateTime.DateTime.Day= pdata[len];
			time.day = bin2bcd(pdata[len]);
			len ++;
			gInternetDateTime.DateTime.Hour= pdata[len];
			time.hour = bin2bcd(pdata[len]);
			len ++;
			gInternetDateTime.DateTime.Minute= pdata[len];
			time.minute = bin2bcd(pdata[len]);
			len ++;
			gInternetDateTime.DateTime.Second= pdata[len];
			time.second = bin2bcd(pdata[len]);
			
			len ++;
			
			SetRTCDatetime(&time, TRUE);
			
			//RtcWriteTime(gInternetDateTime.DateTime.Year,gInternetDateTime.DateTime.Month,gInternetDateTime.DateTime.Day, \
			//						 gInternetDateTime.DateTime.Hour,gInternetDateTime.DateTime.Minute,gInternetDateTime.DateTime.Second);
				WriteInternetTime(gInternetDateTime.DateTime.Year,gInternetDateTime.DateTime.Month,gInternetDateTime.DateTime.Day, \
									 gInternetDateTime.DateTime.Hour,gInternetDateTime.DateTime.Minute,gInternetDateTime.DateTime.Second);
		}
		break;

		default:
			break;
	}
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Receive Internet Data Time", FmtTimeShow());
	return 1;  
	
}

u8 ReceiveModemData(u8* pdata, u16 datalen)
{
	u16 len,length;
	u8 i;
	//u8 OtaType;
	u8 Serial;
	static u8 ModelType = 0;
	
	len = 6;
	length = (pdata[1]<<8) + pdata[2];

	SetMcuOtaState(2);
	
	for(i=0;i<255;i++)
	{
		switch(pdata[len])
		{
			case MSG_MODEM_WIFI_REPORT_STATUS_TO_MCU:
			{
				gControlState.ModemState = (u16)((pdata[9]<<8) + pdata[8]); //ģ��״̬

				if((gControlState.ModemState&0x0060)==0x0060)//ģ���Զ����Ӳ���·����
				{
					//V1.0.4
					//SetReportProduceState(TRUE);

					SetConnectInternetState(FALSE);
					
					//Period Report Display Timer
					//SoftwareTimerReset(&ReportDeviceParameterTimer,ReportDeviceParameterCallback,1000);
					//SoftwareTimerStart(&ReportDeviceParameterTimer);

					len = 10;
					break;
				}			

				if(((gControlState.ModemState)==0x001A)&&(ProduceClearFlag==0))//�������
				{
					SetReportProduceState(FALSE);
					ProduceClearFlag =1;
					//V1.0.8 LEE
					FlowTotal = 0 ;
					FliterCTO.PowerTime = 0;
					FliterCPF.PowerTime = 0;
					FliterRO.PowerTime = 0 ;
					FliterCPF.RunTime = 0;
					FliterRO.RunTime  = 0;
					FliterCTO.RunTime = 0;
					SaveParameter();
				}		
				
				if((gControlState.ModemState&0x0040)==0x0040)//�����ƶ�
				{
					SetConnectInternetState(TRUE);
		  
					Delay_1ms(50);
					
					if(length==0x0A)//ģ�������ϱ���״̬
					{					
						if(GetReportDeviceState()==TRUE)
						{
							ControlModem(MSG_MCU_GET_MODEM_INFORMATION,0);//��ȡģ��������Ϣ
						}
					}
					//Period Report Display Timer
					SoftwareTimerReset(&ReportDeviceParameterTimer,ReportDeviceParameterCallback,1000);
					SoftwareTimerStart(&ReportDeviceParameterTimer);	

					SoftwareTimerStop(&ConnectInternetTimer);
					SoftwareTimerStop(&WaitModemStatusTimer);  
				}
				else
				{
					SetConnectInternetState(FALSE);
					SetReportProduceState(FALSE);
				}
				
				len = 10;
			}
			break;
			
			case MSG_MODEM_SEND_WIFI_MAC_TO_MCU:
			{
				len ++;
				DeviceParameterLen[MSG_DEVICE_WIFI_MAC] = pdata[len];
				len ++;
				
				memcpy(gDeviceParameter.ModemWifiMac, &pdata[len], DeviceParameterLen[MSG_DEVICE_WIFI_MAC]);

				gDeviceParameter.ModemWifiMac[12] = '0';
				gDeviceParameter.ModemWifiMac[13] = '0';
				gDeviceParameter.ModemWifiMac[14] = '0';
				gDeviceParameter.ModemWifiMac[15] = '0';

				gDeviceParameter.ModemWifiMac[16] = 0;

				Hexstring2int(gDeviceParameter.ModemWifiMac,16,gDeviceParameter.ModemWifiMacHex);
				
				len = len + DeviceParameterLen[MSG_DEVICE_WIFI_MAC];
				
				DeviceParameterLen[MSG_DEVICE_WIFI_MAC] = DeviceParameterLen[MSG_DEVICE_WIFI_MAC] + 4;

				ModemType = MODEM_WIFI;
				ModelType = 1;
				memcpy(gDeviceParameter.ProductKey, ProductKeyWifi, strlen((const char *)ProductKeyWifi));
			}
			break;

			case MSG_MODEM_SEND_ROUTER_SSID_TO_MCU:
			{
				len ++;
				DeviceParameterLen[MSG_DEVICE_ROUTER_SSID] = pdata[len];
				len ++;
				
				memcpy(gDeviceParameter.ModemRouterSsid, &pdata[len], DeviceParameterLen[MSG_DEVICE_ROUTER_SSID]);
				len = len + DeviceParameterLen[MSG_DEVICE_ROUTER_SSID];				
			}
			break;

			case MSG_MODEM_SEND_2G_IMEI_TO_MCU:
			{
				len ++;
				DeviceParameterLen[MSG_DEVICE_2G_IMEI] = pdata[len];
				len ++;
				
				memcpy(gDeviceParameter.Modem2gImei, &pdata[len], DeviceParameterLen[MSG_DEVICE_2G_IMEI]);

				gDeviceParameter.Modem2gImei[15] = '0';

				gDeviceParameter.Modem2gImei[16] = 0;

				Hexstring2int(gDeviceParameter.Modem2gImei,16,gDeviceParameter.Modem2gImeiHex);
				

				len = len + DeviceParameterLen[MSG_DEVICE_2G_IMEI];	

				ModemType = MODEM_2G;
				ModelType = 1;
				memcpy(gDeviceParameter.ProductKey, ProductKey2G, strlen((const char *)ProductKey2G));
			}
			break;

			case MSG_MODEM_SEND_2G_IMSI_TO_MCU:
			{
				len ++;
				DeviceParameterLen[MSG_DEVICE_2G_IMSI] = pdata[len];
				len ++;
				
				memcpy(gDeviceParameter.Modem2gImsi, &pdata[len], DeviceParameterLen[MSG_DEVICE_2G_IMSI]);
				len = len + DeviceParameterLen[MSG_DEVICE_2G_IMSI];					
			}
			break;

			case MSG_MODEM_SEND_2G_BASESTATION_TO_MCU:
			{
				len ++;
				DeviceParameterLen[MSG_MODEM_SEND_2G_BASESTATION_TO_MCU] = pdata[len];
				len ++;
				gDeviceParameter.Modem2gMnc = (pdata[len]<<8) + pdata[len+1];
				len = len + 2;
			
				gDeviceParameter.Modem2gMcc = (pdata[len]<<8) + pdata[len+1];
				len = len + 2;
				
				gDeviceParameter.ModemBaseStationNum = pdata[len];
				len ++;
				
				gDeviceParameter.BaseStation1.Lac = (pdata[len]<<8) + pdata[len+1];
				len = len + 2;
				
				gDeviceParameter.BaseStation1.Cellid = (pdata[len]<<8) + pdata[len+1];
				len = len + 2;
				
				gDeviceParameter.BaseStation1.Rssi = pdata[len];
				len ++;				
			}
			break;

			case MSG_MODEM_SEND_RSSI:
			{
				len ++;
				DeviceDisplayLen[MSG_DISPLAY_RSSI] = pdata[len];
				len ++;
				gDeviceDisplay.rssi = pdata[len];
				len ++;		
			}
			break;

			case MSG_MODEM_SEND_UPDATA_INFORMATION_TO_MCU:
			{
				len ++;
				DeviceDisplayLen[MSG_MODEM_SEND_UPDATA_INFORMATION_TO_MCU] = pdata[len];
				len ++;
				if(pdata[len]==MCU_UPDATE)//ģ�����ع̼���MCU��תBootLoader
				{
					PumpPressureClose();//�ر���ѹ��
					InputDkClose();//�رս�ˮ��ŷ�
					WashDkClose();//�رճ�ϴ��ŷ�(��ˮ)
//					CleanTocDkClose();//�رմ�ˮ��ŷ�
//					OriginalTocDkClose();//�ر�ԭˮ��ŷ�    
					// Print Out
					Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Go to Bootloader", FmtTimeShow());
					
					SetMcuOtaState(0x01);

					if(FlashMemoryOneByteRead(MCU_OTA_ADDRESS)==0x00)
					{
						WriteIAPFlagToFlashMemory((u32)GetMcuOtaState());
					}
					
					/*�����ж�����*/
					if(FlashMemoryOneByteRead(MCU_OTA_ADDRESS)==0x01)
					{
						
						SaveParameter();//��������
						Seria1DbgPrintf(LogInfoCtl,"MCU_OTA_ADDRESS= %d",FmtTimeShow(),FlashMemoryOneByteRead(MCU_OTA_ADDRESS));
						NVIC_SystemReset();
					}
				}
				else if(pdata[len]==MODEM_UPDATE_START)//ģ��������ʼ
				{
					SetModemOtaState(TRUE);
				}
				else if(pdata[len]==MODEM_UPDATE_STOP)//ģ����������
				{
					SetModemOtaState(FALSE);
				}
				
				len ++;						
			}
			break;

			case MSG_MODEM_GET_PK_FROM_MCU:
			{
				if(ModelType==1)
				{
					// Print Out
					Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Send PK", FmtTimeShow());
					
					Serial = ControlModem(MSG_MCU_SEND_PRODUCT_KEY,0);//��ģ�鷢��PK
					SetRepeatProductKeyState(Serial);
				}
				else
				{
					// Print Out
					Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Dont Send PK", FmtTimeShow());
				}
				len = 7;
				//return 0;
			}
			break;

			case MSG_MODEM_SEND_FIRMWARE_VERSION:
			{
				len ++;
				DeviceParameterLen[MSG_DEVICE_MODEM_FIRMWARE_VERSION] = pdata[len];
				len ++;
				memcpy(gDeviceParameter.ModemFirmwareVersion, &pdata[len], DeviceParameterLen[MSG_DEVICE_MODEM_FIRMWARE_VERSION]);
				gDeviceParameter.ModemFirmwareVersion[DeviceParameterLen[MSG_DEVICE_MODEM_FIRMWARE_VERSION]] = 0;
				len = len + DeviceParameterLen[MSG_DEVICE_MODEM_FIRMWARE_VERSION];					
			}
			break;

			case MSG_MODEM_SEND_HARDWARE_VERSION:
			{
				SoftwareTimerReset(&GetModemInformationTimer,GetModemInformationCallback,PERIOD_GET_MODEM_INFORMATION_TIMEOUT);
				SoftwareTimerStart(&GetModemInformationTimer);
				
				SetModemInformationState(TRUE);
				
				len ++;
				DeviceParameterLen[MSG_DEVICE_MODEM_HARDWARE_VERSION] = pdata[len];
				len ++;
				memcpy(gDeviceParameter.ModemHardwareVersion, &pdata[len], DeviceParameterLen[MSG_DEVICE_MODEM_HARDWARE_VERSION]);
				gDeviceParameter.ModemHardwareVersion[DeviceParameterLen[MSG_DEVICE_MODEM_HARDWARE_VERSION]] = 0;
				len = len + DeviceParameterLen[MSG_DEVICE_MODEM_HARDWARE_VERSION];					
			}
			break;

			case MSG_MODEM_SEND_REPORT_PRODUCE:
			{
				//Period Report Display Timer
				SoftwareTimerReset(&ReportDeviceParameterTimer,ReportDeviceParameterCallback,1000);
				SoftwareTimerStart(&ReportDeviceParameterTimer);	
//				SendProduceData(COMMAND_TYPE_MCU_TO_PRODUCE_SERVER);//�ϱ���������
				SetReportProduceState(TRUE);
				// Print Out
				Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Enter Produce Mode", FmtTimeShow());
				len = 7;
			}
			break;

			case MSG_MODEM_GET_MCU_FIRMWARE_VERSION: //ģ���ȡMCU�汾��
			{
				ControlModem(MSG_MCU_SEND_MCU_FIRMWARE_VERSION,0);
				// Print Out
				Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Send MCU Firmware", FmtTimeShow());

				len = 7;
			}
			break;
			
			default:
				break;
		}
		
		if(len==length)
		{
			// Print Out
			Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: for break", FmtTimeShow());	
			break;  //����forѭ��
		}
	}

	if(i==255)
	{
		SendDataAck(pdata[3],ACK_ERROW,COMMAND_TYPE_MODEM_TO_MCU);
		// Print Out
		Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Receive Modem Data Wrong", FmtTimeShow());	
	}
	else
	{
		// Print Out
		Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Receive Modem Data", FmtTimeShow());

		SendDataAck(pdata[3],ACK_SUCCESS,COMMAND_TYPE_MODEM_TO_MCU);
	}
	memset((char *)pdata,0,sizeof(pdata));
	return 0;
}

void ReceiveServerData(u8* pdata, u16 datalen)
{
	u16 len;
  	u8 ack;
	len = 15;
	switch(pdata[len])
	{
		case DATA_TYPE_GET_PARAMETER_COMMAND: //��ȡ����
		{
			ack = ReceiveGetParametrCmd(pdata, datalen);
		}
		break;

		case DATA_TYPE_DEVICE_PARAMETER:             //�豸����
		{
			ack = ReceiveDeviceParameter(pdata, datalen);  
		}
		break;

		case DATA_TYPE_DEVICE_PARAMETER_DISPLAY:     //�豸��ʾ
		{
		  
		}
		break;

		case DATA_TYPE_USER_SET_PARAMETER:           //�û����ò���  
		{
			ack = ReceiveUserSetParameter(pdata, datalen);  
		}
		break;

		case DATA_TYPE_USER_OPERATE_PARAMETER:       //�û���������
		{
			ack = ReceiveUserOperateParemeter(pdata, datalen);
		}
		break;

		case DATA_TYPE_SERVICE_SET_PARAMETER:        //�������ò���  
		{
			ack = ReceiveServiceParameter(pdata, datalen);
		}
		break;

		case DATA_TYPE_LEASE_BUSSINESS_PARAMETER:    //����/����ҵ�����
		{
			ack = ReceiveLeaseBussinessParemeter(pdata, datalen);
		}
		break;

		case DATA_TYPE_THIRD_PARAMETER:              //����������
		{
			ack = ReceiveThirdParameter(pdata, datalen);
		}
		break;

		case DATA_TYPE_LIMITED_PARAMETER:            //��Ȩ
		{
			ack = ReceiveLimit(pdata, datalen);
		}
		break;

		case DATA_TYPE_INTERNET_TIME:                //����ʱ��
		{
			ack = ReceiveInternetDateTime(pdata, datalen);
		}
		break;

		default:
		break;
	}

	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Receive Server Data", FmtTimeShow());

	if(ack==0)
	{
		SendDataAck(pdata[3],ACK_ERROW,COMMAND_TYPE_SERVER_TO_MCU);
	}
	else
	{
//		SendDataAck(pdata[3],ACK_SUCCESS,COMMAND_TYPE_SERVER_TO_MCU);	

	}
}

void ReceiveClientData(u8* pdata, u16 datalen)
{
	u16 len;
  	u8 ack;
	
	len = 15;
	switch(pdata[len])
	{
		case DATA_TYPE_GET_PARAMETER_COMMAND: //��ȡ����
		{
			ack = ReceiveGetParametrCmd(pdata, datalen);
		}
		break;

		case DATA_TYPE_DEVICE_PARAMETER:             //�豸����
		{
			ack = ReceiveDeviceParameter(pdata, datalen);  
		}
		break;

		case DATA_TYPE_DEVICE_PARAMETER_DISPLAY:     //�豸��ʾ
		{
		  
		}
		break;

		case DATA_TYPE_USER_SET_PARAMETER:           //�û����ò���  
		{
			ack = ReceiveUserSetParameter(pdata, datalen);  
		}
		break;

		case DATA_TYPE_USER_OPERATE_PARAMETER:       //�û���������
		{
			ack = ReceiveUserOperateParemeter(pdata, datalen);
		}
		break;

		case DATA_TYPE_SERVICE_SET_PARAMETER:        //�������ò���  
		{
			ack = ReceiveServiceParameter(pdata, datalen);
		}
		break;

		case DATA_TYPE_LEASE_BUSSINESS_PARAMETER:    //����/����ҵ�����
		{
			ack = ReceiveLeaseBussinessParemeter(pdata, datalen);
		}
		break;

		case DATA_TYPE_THIRD_PARAMETER:              //����������
		{
			ack = ReceiveThirdParameter(pdata, datalen);
		}
		break;

		case DATA_TYPE_LIMITED_PARAMETER:            //��Ȩ
		{
			ack = ReceiveLimit(pdata, datalen);
		}
		break;

		case DATA_TYPE_INTERNET_TIME:                //����ʱ��
		{
			ack = ReceiveInternetDateTime(pdata, datalen);
		}
		break;

		default:
		break;
	}

	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Receive Client Data", FmtTimeShow());

	if(ack==0)
	{
		SendDataAck(pdata[3],ACK_ERROW,COMMAND_TYPE_CLIENT_TO_MCU);
	}
	else
	{
//		SendDataAck(pdata[3],ACK_SUCCESS,COMMAND_TYPE_CLIENT_TO_MCU);	
	}
	
}

void ReceiveProduceServerData(u8* pdata, u16 datalen)
{
	u8 len;

	len = 15;

	if(pdata[len]==0x02)//��ʼ�ϱ�����
	{
//		if(Factory.TestEnd==YES)
//		{
//			SendProduceData(COMMAND_TYPE_MCU_TO_PRODUCE_SERVER);
//		}
	}
}

void ReceiveModemDataAck(u8* pdata, u16 datalen)
{
	u8 Serial;
	
	if(GetRepeatProductKeyState()==pdata[3])
	{
		if(pdata[4]==0x82)
		{
			if(pdata[5]!=0x01)
			{
				Serial = ControlModem(MSG_MCU_SEND_PRODUCT_KEY,0);//��ģ�鷢��PK
				SetRepeatProductKeyState(Serial);			
				// Print Out
				Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Repeat PK To Modem", FmtTimeShow());
			}
		}
	}
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Receive Modem Data ACK", FmtTimeShow());
}

void ReceiveServerDataAck(u8* pdata, u16 datalen)
{
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Receive Server Data ACK", FmtTimeShow());
}

void ReceiveClientDataAck(u8* pdata, u16 datalen)
{
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Receive Client Data ACK", FmtTimeShow());
}

void ReceiveProduceServerDataAck(u8* pdata, u16 datalen)
{

	ControlModem(MSG_MCU_SET_MODEM_PRODUCE_TEST_MODE,0x02);//�������
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Receive Produce Server Data ACK", FmtTimeShow());
}

void SendDataAck(u8 serial, ACKDataT ack, CMDTypeT msgtype)
{
	u16 len = 0;
	u8 i;
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Send Data Ack serial = %d", FmtTimeShow(),serial);

	// Clear data
	memset(SendBuffer, 0, sizeof(SendBuffer));  
  
	// Fill head
	SendBuffer[0] = SYS_SYNC_HEAD;
	// Fill type
	SendBuffer[3] = serial;

  len = 4;
  
  switch(msgtype)
  {
    case COMMAND_TYPE_MODEM_TO_MCU:
    {
      //length
      SendBuffer[1] = 0x00;
      SendBuffer[2] = 0x06;
      SendBuffer[len] = COMMAND_TYPE_MCU_TO_MODEM_ACK;
      len ++;
      SendBuffer[len] = ack;
    }
    break;
    
    case COMMAND_TYPE_SERVER_TO_MCU:
    {
      //length
      SendBuffer[1] = 0x00;
      SendBuffer[2] = 0x0F;
      SendBuffer[len] = COMMAND_TYPE_MCU_TO_CLOUD_TOPIC1_ACK;
      len ++;
      //SN
      for(i=0;i<8;i++)
      {
        if(ModemType==MODEM_WIFI)
        {
          SendBuffer[len+i] = gDeviceParameter.ModemWifiMacHex[i];
        }
        else if(ModemType==MODEM_2G)
        {
          SendBuffer[len+i] = gDeviceParameter.Modem2gImeiHex[i];
        }
      }      
      len = len + i;
      
      //Product Type
      #if defined(PRODUCT_COMPERCE_WATER_PURIFIER)
      {
        SendBuffer[len] = PRODUCT_TYPE_COMPERCE_WATER_PURIFIER;
      }
      #endif

      #if defined(PRODUCT_CATERING_MACHINE)
      {
        SendBuffer[len] = PRODUCT_TYPE_CATERING_MACHINE;
      }
      #endif

      #if defined(PRODUCT_BUBBLE_MACHINE)
      {
        SendBuffer[len] = PRODUCT_TYPE_BUBBLE_MACHINE;
      }
      #endif

      #if defined(PRODUCT_NEWMOON_MACHINE)
      {
        SendBuffer[len] = PRODUCT_TYPE_NEWMOON_MACHINE;
      }
      #endif

      #if defined(PRODUCT_RAINLOTUS_MACHINE)
      {
        SendBuffer[len] = PRODUCT_TYPE_RAINLOTUS_MACHINE;
      }
      #endif
      
      len ++;
      SendBuffer[len] = ack;
    }
    case COMMAND_TYPE_CLIENT_TO_MCU:
    {
      //length
      SendBuffer[1] = 0x00;
      SendBuffer[2] = 0x0F;
      SendBuffer[len] = COMMAND_TYPE_MCU_TO_CLOUD_TOPIC2_ACK;
      len ++;
      //SN
      for(i=0;i<8;i++)
      {
        if(ModemType==MODEM_WIFI)
        {
          SendBuffer[len+i] = gDeviceParameter.ModemWifiMacHex[i];
        }
        else if(ModemType==MODEM_2G)
        {
          SendBuffer[len+i] = gDeviceParameter.Modem2gImeiHex[i];
        }
      }      
      len = len + i;
      
      //Product Type
      #if defined(PRODUCT_COMPERCE_WATER_PURIFIER)
      {
        SendBuffer[len] = PRODUCT_TYPE_COMPERCE_WATER_PURIFIER;
      }
      #endif

      #if defined(PRODUCT_CATERING_MACHINE)
      {
        SendBuffer[len] = PRODUCT_TYPE_CATERING_MACHINE;
      }
      #endif

      #if defined(PRODUCT_BUBBLE_MACHINE)
      {
        SendBuffer[len] = PRODUCT_TYPE_BUBBLE_MACHINE;
      }
      #endif

      #if defined(PRODUCT_NEWMOON_MACHINE)
      {
        SendBuffer[len] = PRODUCT_TYPE_NEWMOON_MACHINE;
      }
      #endif

      #if defined(PRODUCT_RAINLOTUS_MACHINE)
      {
        SendBuffer[len] = PRODUCT_TYPE_RAINLOTUS_MACHINE;
      }
      #endif
      
      len ++;
      SendBuffer[len] = ack;      
    }
    break;
    
    default:
      break;
  }
  len ++;
	//check sum
	SendBuffer[len] = CalculateChecksum(SendBuffer,len,1);
	len ++;
	SendBuffer[len] = SYS_SYNC_TAIL;
	len ++;
	
	//Data exchange
	len = len + data_exchange(SendBuffer, SEND, len);
	
	//Send out
	PutStrToUart2Modem(SendBuffer, len);	  
}

void ProcessModemData(u8* pdata, u16 datalen)
{ 
	u8 CheckSum;
	// Receive Transfer
	datalen = datalen - data_exchange(pdata, RECEIVE, datalen+1);
	// Print Out
//	DumpMem("CONVERT", pdata, datalen, LogInfoCtl);
  
	CheckSum = CalculateChecksum(pdata, datalen - 2, 1);
	// Calculate check sum
	if(CheckSum != pdata[datalen - 2])
	{
		switch(pdata[5])
		{
			//receive modem data
			case COMMAND_TYPE_MODEM_TO_MCU:
			{
				SendDataAck(pdata[3], ACK_ERROW, COMMAND_TYPE_MODEM_TO_MCU);
			}     
			break;
			
			//receive server data
			case COMMAND_TYPE_SERVER_TO_MCU:
			{
				SendDataAck(pdata[3], ACK_ERROW, COMMAND_TYPE_SERVER_TO_MCU);
			}      
			break;

			//receive client data
			case COMMAND_TYPE_CLIENT_TO_MCU:
			{
				SendDataAck(pdata[3], ACK_ERROW, COMMAND_TYPE_CLIENT_TO_MCU);
			}     
			break;

			//receive produce server data
			case COMMAND_TYPE_PRODUCE_SERVER_TO_MCU:
			{
				SendDataAck(pdata[3], ACK_ERROW, COMMAND_TYPE_PRODUCE_SERVER_TO_MCU);
			}
			break;
		
			default:
			break;
		}
		// Print Out
		Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Modem check error 0x%x , right 0x%x", FmtTimeShow(),\
			 pdata[datalen-2],CheckSum);
		return;
	}
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Response type(0x%x) ck(0x%x) len(%d)", FmtTimeShow(),\
		pdata[1], pdata[datalen-2], datalen);
	//Judgment to receive a reply or parameters 
  switch(pdata[5])
  {
    //receive modem data
    case COMMAND_TYPE_MODEM_TO_MCU:
    {
      ReceiveModemData(pdata, datalen);
    }     
    break;
    
    //receive server data
    case COMMAND_TYPE_SERVER_TO_MCU:
    {
      ReceiveServerData(pdata, datalen);
    }      
    break;

    //receive client data
    case COMMAND_TYPE_CLIENT_TO_MCU:
    {
      ReceiveClientData(pdata, datalen);
    }     
    break;

		//receive produce server data
		case COMMAND_TYPE_PRODUCE_SERVER_TO_MCU:
		{
			ReceiveProduceServerData(pdata, datalen);
		}
		break;
			
    //receive modem data ack
    case COMMAND_TYPE_MODEM_TO_MCU_ACK:
    {
      ReceiveModemDataAck(pdata, datalen);
    }     
    break;
    
    //receive server data ack
    case COMMAND_TYPE_SERVER_TO_MCU_ACK:
    {
      ReceiveServerDataAck(pdata, datalen);
    }      
    break;

    //receive client data ack
    case COMMAND_TYPE_CLIENT_TO_MCU_ACK:
    {
      ReceiveClientDataAck(pdata, datalen);
    }     
    break;

		//receive produce server data
		case COMMAND_TYPE_PRODUCE_SERVER_TO_MCU_ACK:
		{
			ReceiveProduceServerDataAck(pdata, datalen);
		}
		break;

    
    default:
    {
      // Print Out
			Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Unknow msg type 0x%02x", FmtTimeShow(),\
         pdata[1]);
    }
    break;
  }
}

static u8 DataBuffer[USART1_RX_BUFFER_SIZE] = {'\0'};
static u8 pBuffer[USART1_RX_BUFFER_SIZE] = {'\0'};

void ModemDataReceiveDetection(void)
{	
	u16 DataCounter = 0;
  u16 idx = 0;
  u16 BufferCount = 0;
  
  u8 PackDataEndFlag = FALSE;  
	if(USART1_RX_NUM == TRUE)
	{
		USART1_RX_NUM = FALSE;
		DataCounter = Uart1RxCount;
		memcpy(DataBuffer, Uart1RxBuffer, Uart1RxCount);
		Uart1RxCount=0;
		memset((char *)Uart1RxBuffer,0,sizeof(Uart1RxBuffer));
		DumpMem("MODEM<<<", DataBuffer, DataCounter, LogInfoCtl);

		if(DataCounter > 2)
		{
			// Check
			for(idx = 0; idx < DataCounter; idx++)
			{
				if(PackDataEndFlag == FALSE)
				{
					// Check head
					if(DataBuffer[idx] == SYS_SYNC_HEAD)
					{
						// Clear data
						BufferCount = 0;
						memset((char *)pBuffer,0,sizeof(pBuffer));
						// Copy data
						pBuffer[BufferCount++] = DataBuffer[idx];
						// Go next state
						PackDataEndFlag = TRUE;
					}
				}
				else
				{
					if(DataBuffer[idx] == SYS_SYNC_TAIL)
					{
						pBuffer[BufferCount++] = DataBuffer[idx];
						// Print Out
//						DumpMem("MODEM", pBuffer, BufferCount, LogInfoCtl);
            
						// Data process
						ProcessModemData(pBuffer, BufferCount);
						// Go next state
						PackDataEndFlag = FALSE;
					}
					else
					{
						pBuffer[BufferCount++] = DataBuffer[idx];
					}
				}
			}
			if(BufferCount == 0)
			{
				// Print out
				Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Discard useless data",FmtTimeShow());
			}
		}
		else
		{
			// Print out
			Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Modem data empty %d",FmtTimeShow(),DataCounter);
		}
	}

//  u16 DataCounter = 0; 
//  u16 idx = 0;
//  u16 BufferCount = 0;
//  
//  u8 PackDataEndFlag = FALSE;  
//  
//	if(UART1_RX_NUM == TRUE)
//	{    
//		UART1_RX_NUM = FALSE;
//		// Get Data
////		SystemDisableAllInterrupt();// Disable Interrupt
//		DataCounter = Uart2RxCount;
//		memcpy(DataBuffer, Uart2RxBuffer, Uart2RxCount);
//		// Clear Buffer
//		Uart2RxCount = 0;
//		memset((char *)Uart2RxBuffer,0,sizeof(Uart2RxBuffer));
////		SystemEnableAllInterrupt();	// Enable Interrupt

//		// Print Out
////		DumpMem("MODEM<<<", DataBuffer, DataCounter, LogInfoCtl);
//  
//		// Check length
//		if(DataCounter > 2)
//		{
//			// Check
//			for(idx = 0; idx < DataCounter; idx++)
//			{
//				if(PackDataEndFlag == FALSE)
//				{
//					// Check head
//					if(DataBuffer[idx] == SYS_SYNC_HEAD)
//					{
//						// Clear data
//						BufferCount = 0;
//						memset((char *)pBuffer,0,sizeof(pBuffer));
//						// Copy data
//						pBuffer[BufferCount++] = DataBuffer[idx];
//						// Go next state
//						PackDataEndFlag = TRUE;
//					}
//				}
//				else
//				{
//					if(DataBuffer[idx] == SYS_SYNC_TAIL)
//					{
//						pBuffer[BufferCount++] = DataBuffer[idx];
//						// Print Out
////						DumpMem("MODEM", pBuffer, BufferCount, LogInfoCtl);
//            
//						// Data process
//						ProcessModemData(pBuffer, BufferCount);
//						// Go next state
//						PackDataEndFlag = FALSE;
//					}
//					else
//					{
//						pBuffer[BufferCount++] = DataBuffer[idx];
//					}
//				}
//			}
//			if(BufferCount == 0)
//			{
//				// Print out
					//Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Discard useless data",FmtTimeShow());

//			}
//		}
//		else
//		{
//			// Print out
				//Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] MODEM: Modem data empty %d",FmtTimeShow(),DataCounter);
//		}
//	}
}

void ConnectInternetCallback(u8 state)
{
	SetModemFactoryState(FALSE); 
	SoftwareTimerStop(&ConnectInternetTimer);
	SetInternetLedBlinkState(FALSE);	
}

void PeriodReportDisplayCallback(u8 state)
{
	static u32 ConnectTelephonePeriordTime = 0;
	if(GetTelephoneConnectState()==TRUE)
	{
		ConnectTelephonePeriordTime = gControlState.TelephoneReportInterval*1000;
		//Period Report Display Timer
		SoftwareTimerReset(&PeriodReportDisplayTimer,PeriodReportDisplayCallback,ConnectTelephonePeriordTime);
		SoftwareTimerStart(&PeriodReportDisplayTimer);
		gControlState.TelephoneReportCount ++;
		// Print Out
		Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] Period Report Display Count %d",FmtTimeShow(),gControlState.TelephoneReportCount);


		if(gControlState.TelephoneReportCount>=((gControlState.TelephoneReportMinute*60)/gControlState.TelephoneReportInterval))
		{
			SetTelephoneConnectState(FALSE);
		}
	}
	else
	{
		//Period Report Display Timer
		SoftwareTimerReset(&PeriodReportDisplayTimer,PeriodReportDisplayCallback,PERIOD_REPORT_DISPLAY_TIMEOUT);
		SoftwareTimerStart(&PeriodReportDisplayTimer);	  
	}
	
	if((GetConnectInternetState()==TRUE)&&(GetMcuOtaState()!=1))//�����ɹ�����ģ��û������
	{
		SendDeviceDisplay(COMMAND_TYPE_MCU_TO_CLOUD_TOPIC1);
		// Print Out
		Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] Period Report Display Time: %dms",FmtTimeShow(),PERIOD_REPORT_DISPLAY_TIMEOUT);

	}
	else
	{
		// Print Out
		Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] Period Report Display Fail %d %d",FmtTimeShow(),\
		GetConnectInternetState(),GetMcuOtaState());		
	}

}
extern u8 AlldataMcuToSeverFlag;
void ReportDeviceParameterCallback(u8 state)
{
	// PeriodicSyncTimeT SendState = SEND_DEVICE_PARAMETER_STATE;
//	 if((gControlState.ModemState&0x0040)==0x0040)//�����ƶ�
	if(((GetConnectInternetState()==TRUE)&&(GetMcuOtaState()!=1)&&(GetReportDeviceState()==TRUE)) \
	||(GetReportProduceState()==TRUE)
	||((GetConnectInternetState()==TRUE)&&(AlldataMcuToSeverFlag==1)))//�����ɹ�����ģ��û������ ���� ����ģʽ
	 {
		switch(SendState)
		{
			case SEND_DEVICE_PARAMETER_STATE:
			{
				//Period Report Display Timer
				SoftwareTimerReset(&ReportDeviceParameterTimer,ReportDeviceParameterCallback,1000);
				SoftwareTimerStart(&ReportDeviceParameterTimer);	
				SendDeviceParameter(COMMAND_TYPE_MCU_TO_CLOUD_TOPIC1);
				SendState = SEND_USER_SET_PARAMETER_STATE;
			}
			break;
			
			case SEND_USER_SET_PARAMETER_STATE:
			{
				//Period Report Display Timer
				SoftwareTimerReset(&ReportDeviceParameterTimer,ReportDeviceParameterCallback,1000);
				SoftwareTimerStart(&ReportDeviceParameterTimer);	
				SendUserSetParameter(COMMAND_TYPE_MCU_TO_CLOUD_TOPIC1);
				SendState = SEND_SERVICE_PARAMETER_STATE;
			}
			break;		

			case SEND_SERVICE_PARAMETER_STATE:
			{
				//Period Report Display Timer
				SoftwareTimerReset(&ReportDeviceParameterTimer,ReportDeviceParameterCallback,1000);
				SoftwareTimerStart(&ReportDeviceParameterTimer);	
				SendServiceParameter(COMMAND_TYPE_MCU_TO_CLOUD_TOPIC1);
				SendState = SEND_DEVICE_DISPLAY_STATE;
			}
			break;
			
			case SEND_DEVICE_DISPLAY_STATE:
			{
				//Period Report Display Timer
				SoftwareTimerReset(&ReportDeviceParameterTimer,ReportDeviceParameterCallback,1000);
				SoftwareTimerStart(&ReportDeviceParameterTimer);	
				SendDeviceDisplay(COMMAND_TYPE_MCU_TO_CLOUD_TOPIC1);
				SendState = SEND_USER_OPERATE_PARAMETER_POWER_STATE;
			}
			break;
			case SEND_DEVICE_PARAMETER_STATE_2:
			{
				//Period Report Display Timer
				SoftwareTimerReset(&ReportDeviceParameterTimer,ReportDeviceParameterCallback,1000);
				SoftwareTimerStart(&ReportDeviceParameterTimer);	
				SendDeviceParameter(COMMAND_TYPE_MCU_TO_CLOUD_TOPIC1);
				SendState = SEND_USER_SET_PARAMETER_STATE;
			}
			break;			

			case SEND_USER_OPERATE_PARAMETER_POWER_STATE:
			{
				//Period Report Display Timer
				SoftwareTimerReset(&ReportDeviceParameterTimer,ReportDeviceParameterCallback,1000);
				SoftwareTimerStart(&ReportDeviceParameterTimer);	
				SendUserOperateParemeter(MSG_USER_OPERATE_POWER_SWITCH,COMMAND_TYPE_MCU_TO_CLOUD_TOPIC1);
				SendState = SEND_USER_OPERATE_PARAMETER_HEAT_STATE;
			}
			break;
			
			case SEND_USER_OPERATE_PARAMETER_HEAT_STATE:
			{
				//Period Report Display Timer
				SoftwareTimerReset(&ReportDeviceParameterTimer,ReportDeviceParameterCallback,1000);
				SoftwareTimerStart(&ReportDeviceParameterTimer);		
				SendUserOperateParemeter(MSG_USER_OPERATE_HEAT_SWITCH,COMMAND_TYPE_MCU_TO_CLOUD_TOPIC1);
				SendState = SEND_USER_OPERATE_PARAMETER_REFRIGERATE_STATE;
			}
			break;		

			case SEND_USER_OPERATE_PARAMETER_REFRIGERATE_STATE:
			{
				//Period Report Display Timer
				SoftwareTimerReset(&ReportDeviceParameterTimer,ReportDeviceParameterCallback,1000);
				SoftwareTimerStart(&ReportDeviceParameterTimer);	
				SendUserOperateParemeter(MSG_USER_OPERATE_REFRIGERATE_SWITCH,COMMAND_TYPE_MCU_TO_CLOUD_TOPIC1);
				SendState = SEND_USER_OPERATE_PARAMETER_STERILIZE_STATE;
			}
			break;
			
			case SEND_USER_OPERATE_PARAMETER_STERILIZE_STATE:
			{
				//Period Report Display Timer
				SoftwareTimerReset(&ReportDeviceParameterTimer,ReportDeviceParameterCallback,5000);
				SoftwareTimerStart(&ReportDeviceParameterTimer);		
				SendUserOperateParemeter(MSG_USER_OPERATE_STERILIZE_SWITCH,COMMAND_TYPE_MCU_TO_CLOUD_TOPIC1);
				SendState = SEND_USER_OPERATE_PARAMETER_LCDTURNOFF_STATE;
			}
			break;	
			case SEND_USER_OPERATE_PARAMETER_LCDTURNOFF_STATE:
			{
				//Period Report Display Timer
				SoftwareTimerReset(&ReportDeviceParameterTimer,ReportDeviceParameterCallback,1000);
				SoftwareTimerStart(&ReportDeviceParameterTimer);		
				SendUserOperateParemeter(MSG_USER_OPERATE_LCD_TUTNOFF_SWITCH,COMMAND_TYPE_MCU_TO_CLOUD_TOPIC1);
				SendState = SEND_GET_INTERNET_TIME_STATE;
			}
			break;	

			case SEND_GET_INTERNET_TIME_STATE:
			{
				//Period Report Display Timer
				SoftwareTimerReset(&ReportDeviceParameterTimer,ReportDeviceParameterCallback,1000);
				SoftwareTimerStart(&ReportDeviceParameterTimer);	
				SendGetParameterCmd(MSG_GET_PARAMETER_INTERNET_TIME);
				SendState = SEND_DEVICE_ERROR_STATE;
			}
			break;
			
			case SEND_DEVICE_ERROR_STATE:
			{
				//Period Report Display Timer
				SoftwareTimerReset(&ReportDeviceParameterTimer,ReportDeviceParameterCallback,1000);
				SoftwareTimerStart(&ReportDeviceParameterTimer);	
				SendDeviceError(COMMAND_TYPE_MCU_TO_CLOUD_TOPIC1);
				SendState = SEND_DEVICE_PARAMETER_STATE;
				SetReportDeviceState(FALSE);
				AlldataMcuToSeverFlag = 0;
				SoftwareTimerStop(&ReportDeviceParameterTimer); 
			}

			break;

		}
		
		// Print Out
		Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] Report Device Parameter,step %d",FmtTimeShow(),\
		SendState);	
  }  
	else
	{
		// Print Out
		Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] Report Device Parameter Fail",FmtTimeShow());
	}
}

void WaitModemStatusCallback(u8 state)
{
	//Period Report Display Timer
	SoftwareTimerReset(&WaitModemStatusTimer,WaitModemStatusCallback,WAIT_MODEM_STATUS_TIMEOUT);
	SoftwareTimerStop(&WaitModemStatusTimer);	  

	SetConnectInternetState(FALSE);
	// Print Out
	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] Wait Modem Status Timeout %dms",FmtTimeShow(),WAIT_MODEM_STATUS_TIMEOUT);
}

void GetModemInformationCallback(u8 state)
{
	if(GetModemInformationState()==TRUE)
	{
		SetModemInformationState(FALSE);
		//SoftwareTimerReset(&ReportDeviceParameterTimer,ReportDeviceParameterCallback,1000);
		//SoftwareTimerStart(&ReportDeviceParameterTimer);
		// Print Out
		Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] Modem OnLine",FmtTimeShow());
	}
	else
	{
		SetConnectInternetState(FALSE);
		SetReportDeviceState(TRUE);
		// Print Out
		Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] Modem OffLine",FmtTimeShow());
	}

	ControlModem(MSG_MCU_GET_MODEM_INFORMATION,0);//��ȡģ��������Ϣ
	
	SoftwareTimerReset(&GetModemInformationTimer,GetModemInformationCallback,PERIOD_GET_MODEM_INFORMATION_TIMEOUT);
	SoftwareTimerStart(&GetModemInformationTimer);	 
}

void CheckSystemTimeCallback(u8 state)
{
	static PeriodicCheckSystemTimeT CheckSystemTime = CHECK_SYSTEM_TIME_STATE;
	//Check System Time Timer
	SoftwareTimerReset(&CheckSystemTimeTimer,CheckSystemTimeCallback,CHECK_SYSTEM_TIME_TIMEOUT);
	SoftwareTimerStart(&CheckSystemTimeTimer);	 
	if((GetConnectInternetState()==TRUE)&&(GetMcuOtaState()!=1)) 
	{
		switch(CheckSystemTime)
		{
			case CHECK_SYSTEM_TIME_STATE:
			{
				SendGetParameterCmd(MSG_GET_PARAMETER_INTERNET_TIME);
				SoftwareTimerReset(&CheckSystemTimeTimer,CheckSystemTimeCallback,CHECK_MCU_FIRMWARE_VERSION_TIMEOUT);
				SoftwareTimerStart(&CheckSystemTimeTimer);	
				CheckSystemTime = CHECK_MCU_FIRMWARE_VERSION;	
				// Print Out
				Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] Check System Time Success",FmtTimeShow());
			}
			break;
			
			case CHECK_MCU_FIRMWARE_VERSION:
			{
				ControlModem(MSG_MCU_SEND_MCU_FIRMWARE_VERSION,0);//����MCU����汾	
				SoftwareTimerReset(&CheckSystemTimeTimer,CheckSystemTimeCallback,CHECK_SYSTEM_TIME_TIMEOUT);
				SoftwareTimerStart(&CheckSystemTimeTimer);	
				CheckSystemTime = CHECK_SYSTEM_TIME_STATE;
				Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] Check Mcu Firmware Version",FmtTimeShow());
			}
			break;
		}
	}
	else
	{
		// Print Out
		Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] Check System Time Fail",FmtTimeShow());
	}
}

/*******************************************************************************
End Of The File
*******************************************************************************/

