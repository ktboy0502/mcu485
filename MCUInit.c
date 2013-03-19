#include <MCUInit.h>

void MCUInit(void)
{
	TMOD=0x21;
	//TH0=(65536-50000)/256;
	//TL0=(65536-50000)%256;
	TH1=0xfd;
	TL1=0xfd;
	//TR0=1;
	TR1=1;
	//ET0=1;
	SM0=0;
	SM1=1;
	REN=1;
	EA=1;
	ES=1;
}