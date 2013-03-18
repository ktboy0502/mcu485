#include <reg52.h>
//#include <Type.h>
long int a=0,b=0;
extern int Count;
long int HM=0x0105;
long int ADD=0x5253AB;
long int SUB=0x4C57A9;

void ser() interrupt 4
{
	unsigned int i;
	ES=0;
	for(i=0;i<2;i++)
	{
		while(!RI);
		a=(a<<8)|SBUF;
		RI=0;
	}
	for(i=0;i<3;i++)
	{
		while(!RI);
		b=(b<<8)|SBUF;
		RI=0;
	}
	if(a==HM&&b==ADD)
	{
		Count++;
	}
	else if(a==HM&&b==SUB)
	{
		Count--;
	}
	else{}
	a=0;
	b=0;
	ES=1;
}