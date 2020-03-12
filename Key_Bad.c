
#include "Key_Bad.h"

static u8 keys[4][4]=  {{'7','8','9','/'},
						{'4','5','6','*'},
						{'1','2','3','-'},
						{'c','0','=','+'}};
u8 KEYBAD_Entry()
{  
	u8 r,c,KEY=default_key;
	DIO_WritePin(StartOutputPin  ,HIGH);	  
	DIO_WritePin(StartOutputPin+1,HIGH);	
	DIO_WritePin(StartOutputPin+2,HIGH);	
	DIO_WritePin(StartOutputPin+3,HIGH);		  
    for (r=0;r<4;r++)
	{
		DIO_WritePin((r+StartOutputPin),LOW);
		for (c=0;c<4;c++)
		{
			if (!DIO_ReadPin(c+StartInputPin))
			{
				while(!DIO_ReadPin(c+StartInputPin));
				KEY= keys[r][c];
			}
		}	
		DIO_WritePin((r+StartOutputPin),HIGH);
	}
	return KEY;
}
