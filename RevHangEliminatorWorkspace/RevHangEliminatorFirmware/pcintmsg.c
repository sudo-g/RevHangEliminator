#include "pcintmsg.h"
#include <string.h>
#include "checksum.h"

int8_t pcintmsg_encode(uint8_t* out, PcmsgDescriptor msgdescriptor)
{
	uint8_t total_len = 0;
	memcpy(out, &(msgdescriptor.ts), sizeof(msgdescriptor.ts));
	total_len += sizeof(msgdescriptor.ts);

	out[total_len++] = msgdescriptor.mode;
	out[total_len++] = msgdescriptor.pid;
	out[total_len++] = msgdescriptor.pllen;

	memcpy(&(out[total_len]), msgdescriptor.payload, msgdescriptor.pllen);
	total_len += msgdescriptor.pllen;

	uint16_t crc = crc_16(out, total_len);
	memcpy(&(out[total_len]), &crc, sizeof(crc));
	total_len += sizeof(crc);

	return total_len;
}
