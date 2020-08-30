
/********************************** (C) COPYRIGHT *******************************
* File Name          : MainMaster.C
* Author             : WCH
* Version            : V1.1
* Date               : 2019/07/22
* Description        : CH554 SPI������CH554 SPI�ӻ�ͨѶ�������������ݣ��ӻ�ȡ������
                       �ӻ��ο�MainSlave.C
*******************************************************************************/
#include "..\Public\CH554.H"                                                  
#include "..\Public\Debug.H"
#include "SPI.H"
#include "stdio.h"
#include <string.h>

/*Ӳ���ӿڶ���*/
/******************************************************************************
ʹ��CH554 Ӳ��SPI�ӿ� 
         CH554               
         P1.4        =       SCS
         P1.5        =       MOSI
         P1.6        =       MISO
         P1.7        =       SCK
*******************************************************************************/


void main()
{ 
    UINT8 ret,i=0;
    CfgFsys( ); 
    mDelaymS(5);                                                               //������Ƶ�������Լ���ʱ�ȴ��ڲ�ʱ���ȶ�   
    mInitSTDIO( );                                                             //����0��ʼ��
    printf("start ...\n");  
	
    SPIMasterModeSet(3);                                                       //SPI����ģʽ���ã�ģʽ3
	
    SPI_CK_SET(4);                                                             //4��Ƶ
#ifdef SPI0Interrupt
    CH554SPIInterruptInit();                                                   //SPI�жϳ�ʼ��
    EA  = 1;                                                                   //ʹ��ȫ���ж�
#endif
    mDelaymS(100);
    while(1)
    {   
	      SCS = 0;                                                               //SPI������������
        CH554SPIMasterWrite(i);                                                      
        mDelaymS(5);
        ret = CH554SPIMasterRead();                                            //����SPI�ӻ����ص����ݣ�ȡ������
        SCS = 1;
        if(ret != (i^0xff))
        {
		        printf("Err: %02X  %02X  \n",(UINT16)i,(UINT16)ret);               //��������ڷ������ݵ�ȡ������ӡ������Ϣ					
        }
		    mDelaymS(50);
	     	i = i+1;
        if((i%40)==0)
        {
            printf("success %02x\n",(UINT16)i);                                //ÿ�ɹ�40�δ�ӡһ��										
        }
    }
}