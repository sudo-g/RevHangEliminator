#ifndef _PCMSG_H_
#define _PCMSG_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
	uint32_t ts;
	uint8_t mode;
	uint8_t pid;
	const uint8_t* payload;
	uint8_t pllen;
} PcmsgDescriptor;

/**
 * Encodes data into the PC interface protocol.
 *
 * \param out Array to write encoded byte stream.
 * \param msgdescriptor Struct containing all data to build message.
 */
int8_t pcintmsg_encode(uint8_t* out, PcmsgDescriptor msgdescriptor);

#ifdef __cplusplus
}
#endif

#endif
