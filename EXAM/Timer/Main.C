
/********************************** (C) COPYRIGHT *******************************
* File Name          : Main.C
* Author             : WCH
* Version            : V1.1
* Date               : 2017/09/05
* Description        : CH554 Time ��ʼ������ʱ������������ֵ��T2��׽���ܵ�
                       ��ʱ���жϴ��� 
*******************************************************************************/
#include "..\Public\CH554.H"                                                  
#include "..\Public\Debug.H"
#include "Timer.H"
#include "stdio.h"

#pragma  NOAREGS

UINT8 FLAG;
UINT16 Cap[8] = {0};

main( ) 
{
    CfgFsys( );                                                                //CH554ʱ��ѡ������   
    mDelaymS(5);                                                               //�޸���Ƶ�������Լ���ʱ�ȴ���Ƶ�ȶ� 	
    mInitSTDIO( );                                                             //���ڳ�ʼ��
    printf("start ...\n"); 


#ifdef T0_INT
    printf("T0 Test ...\n"); 
    mTimer0Clk12DivFsys();	                                                   //T0��ʱ��ʱ������
    mTimer_x_ModInit(0,2);                                                     //T0 ��ʱ��ģʽ����
    mTimer_x_SetData(0,0x5555);	                                               //T0��ʱ����ֵ
    mTimer0RunCTL(1);                                                          //T0��ʱ������	
    ET0 = 1;                                                                   //T0��ʱ���жϿ���		
    EA = 1;
    while(1);
#endif	

#ifdef T1_INT
    printf("T1 Test ...\n"); 
    mTimer1Clk12DivFsys();	                                                   //T1��ʱ��ʱ������	
    mTimer_x_ModInit(1,2);                                                     //T1 ��ʱ��ģʽ����
    mTimer_x_SetData(1,0xEEEE);	                                               //T1��ʱ����ֵ
    mTimer1RunCTL(1);                                                          //T1��ʱ������		
    ET1 = 1;                                                                   //T1��ʱ���жϿ���		
    EA = 1;
    while(1); 
#endif	


#ifdef T2_INT
    printf("T2 Test ...\n"); 
    mTimer2ClkFsys();	                                                         //T2��ʱ��ʱ������
    mTimer_x_ModInit(2,0);                                                     //T2 ��ʱ��ģʽ����
    mTimer_x_SetData(2,0xAAAA);	                                               //T2��ʱ����ֵ
    mTimer2RunCTL(1);                                                          //T2��ʱ������			
    ET2 = 1;                                                                   //T2��ʱ���жϿ���		
    EA = 1;
    while(1); 
#endif


#ifdef T2_CAP
    printf("T2_CAP Test ...\n"); 
    mTimer2ClkFsys();                                                         //T2��ʱ��ʱ������
    mTimer_x_SetData(2,0);                                                    //T2 ��ʱ��ģʽ���ò�׽ģʽ		
    CAP2Init(1);	                                                            //T2 CAP2���ã������ز�׽
    CAP1Init(1);	                                                            //T2 CAP2���ã������ز�׽
    mTimer2RunCTL(1);                                                         //T2��ʱ������			
    ET2 = 1;                                                                  //T2��ʱ���жϿ���	
    EA = 1;
    while(1); 		
#endif
		
    while(1);
}