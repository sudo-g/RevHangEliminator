#include "slip.h"

int8_t slip_encode(uint8_t* out, const uint8_t* in, uint8_t len)
{
	unsigned int out_index = 0;

	out[out_index++] = SLIP_END;

	for (unsigned int in_index=0; in_index<len; in_index++)
	{
		switch (in[in_index])
		{
		case SLIP_END:
			out[out_index++] = SLIP_ESC;
			out[out_index++] = SLIP_ESC_END;
			break;
		case SLIP_ESC:
			out[out_index++] = SLIP_ESC;
			out[out_index++] = SLIP_ESC_ESC;
			break;
		default:
			out[out_index++] = in[in_index];
			break;
		}
	}

	out[out_index++] = SLIP_END;

	return out_index;
}
