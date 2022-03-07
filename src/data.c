#include "data.h"

static uint8_t my_itoa_positive(int32_t data, uint8_t * ptr, uint32_t base) // note to self, no need for another element saving the sign. Why? Because MSB should contain the +/-
{
	uint8_t digits = 0;

	switch(base)
	{
		case 10:
		{
			while(data!=0)
			{
				*ptr++ = data & 0xff;
				digits++;
				data >>= 8;
			}
			break;
		}

		case 16:
		{	
			while(data > 0)
			{
				*ptr++ = ( data%10 ) + ( (data%100) /10) * 16;
				digits++;
				data/=100;
			}
			break;
		}
	}
	*ptr = 0;
	return (digits+1);
}

/*static uint8_t my_itoa_negative(int32_t data, uint8_t * ptr, uint32_t base)
{
	switch(base)
	{
		case 10:

		case 16:
	}

}*/

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	uint8_t digits = 0;

	//if(data >= 0)
	//{
		digits = my_itoa_positive(data, ptr, base);
	/*}
	else
	{
		digits = my_itoa_negative(data, ptr, base);
	}*/

	return digits;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	int32_t number=0, shift = 0;
	switch(base)
	{
		case 10:
		{
			while(*ptr != 0)
			{
				number += (*ptr << shift);
				shift+=8;
				ptr++;
			}
			break;
		}


		case 16:
		{
			while(*ptr != 0)
			{
				number += (*ptr << shift);
				shift += 8;
			}

			break;
		}

	}
	return number;
}