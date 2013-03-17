#include <Key.h>

char KeyNum;
extern int Count;

char ReadKey();

void Key()
{
	char keyvalue;
	keyvalue=ReadKey();
	if(keyvalue!=0x00)
	{
		keyvalue=ReadKey();
		while(ReadKey()!=0x00){}
	}
	if(keyvalue!=0x00)
	{
		switch(keyvalue)	//只处理单个键按下的情况，多个键按下不识别，当作没有键按下
		{
			case 0x01:KeyNum=1;break;
			case 0x02:KeyNum=2;break;
			case 0x04:KeyNum=3;break;
			case 0x08:KeyNum=4;break;
			case 0x10:KeyNum=5;break;
			case 0x20:KeyNum=6;break;
			case 0x40:KeyNum=7;break;
			case 0x80:KeyNum=8;break;
			default:KeyNum=0;break;
		}
	}
	else KeyNum=0;
	if(KeyNum==3) Count++;
	else if(KeyNum==7) Count--;
	else{}
}

char ReadKey()
{
	char temp;
	P0=0xff;
	temp=P0;
	return ~temp;
}