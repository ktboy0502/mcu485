#include <Led.h>

sbit LS138A = P2^2;  	//����138������������A����P2.2���� 
sbit LS138B = P2^3;	    //����138�������������B��P2.3����
sbit LS138C = P2^4; 	//����138�������������C��P2.4����

void delay(unsigned int i);      //��������

char DelayCNT;
//�˱�Ϊ LED ����ģ, ��������� 0-9  - 
unsigned char code Disp_Tab[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x40};

void Led(int Count)
{
	unsigned int i;
	unsigned int LedOut[10];

	LedOut[0]=Disp_Tab[Count%10000/1000];		//ǧλ
	LedOut[1]=Disp_Tab[Count%1000/100];			//��λ
	LedOut[2]=Disp_Tab[Count%100/10];			//ʮλ
	LedOut[3]=Disp_Tab[Count%10];				//��λ	 
	
	for( i=0; i<4; i++)  //ʵ��8λ��̬ɨ��ѭ��
	{	 
		P1 = LedOut[i];  //����ģ�͵�P0����ʾ
	  		
	 	switch(i)	  //ʹ��switch ������λѡ  Ҳ�������ò��ķ�ʽ ѧԱ���������Լ��޸�				  
	    {	    
			case 0:LS138A=0; LS138B=0; LS138C=0;  break;         
	        case 1:LS138A=1; LS138B=0; LS138C=0;  break;             	
	        case 2:LS138A=0; LS138B=1; LS138C=0;  break; 
	        case 3:LS138A=1; LS138B=1; LS138C=0;  break; 
			default: break;  
		}
		delay(150);
	}

	//P2=(char)Count;
}

/***************************************************************************
*																		   *
*		                    ��ʱ����						               *
****************************************************************************/
void delay(unsigned int i)
{
    char j;
    for(i; i > 0; i--)
        for(j = 200; j > 0; j--);
}