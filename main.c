#include <Include.h>

int Count=11;

void main(void)
{
	MCUInit();
	while(1)
	{
		Key();
		Led(Count);		
	}
}