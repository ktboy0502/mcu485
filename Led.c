#include <Led.h>

sbit LS138A = P2^2;  	//定义138译码器的输入A脚由P2.2控制 
sbit LS138B = P2^3;	    //定义138译码器的输入脚B由P2.3控制
sbit LS138C = P2^4; 	//定义138译码器的输入脚C由P2.4控制

void delay(unsigned int i);      //函数声名

char DelayCNT;
//此表为 LED 的字模, 共阴数码管 0-9  - 
unsigned char code Disp_Tab[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x40};

void Led(int Count)
{
	unsigned int i;
	unsigned int LedOut[10];

	LedOut[0]=Disp_Tab[Count%10000/1000];		//千位
	LedOut[1]=Disp_Tab[Count%1000/100];			//百位
	LedOut[2]=Disp_Tab[Count%100/10];			//十位
	LedOut[3]=Disp_Tab[Count%10];				//个位	 
	
	for( i=0; i<4; i++)  //实现8位动态扫描循环
	{	 
		P1 = LedOut[i];  //将字模送到P0口显示
	  		
	 	switch(i)	  //使用switch 语句控制位选  也可以是用查表的方式 学员可以试着自己修改				  
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
*		                    延时程序						               *
****************************************************************************/
void delay(unsigned int i)
{
    char j;
    for(i; i > 0; i--)
        for(j = 200; j > 0; j--);
}