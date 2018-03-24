#ifndef _SLIP_H_
#define _SLIP_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define SLIP_END 0xC0
#define SLIP_ESC 0xDB
#define SLIP_ESC_END 0xDC
#define SLIP_ESC_ESC 0xDD

/**
 * Encodes a byte stream into SLIP protocol.
 *
 * \param out Array to write encoded byte stream.
 * \param in Frame to encode.
 * \param len Length of the input frame.
 * \return Bytes written to destination.
 */
int8_t slip_encode(uint8_t* out, const uint8_t* in, uint8_t len);

#ifdef __cplusplus
}
#endif

#endif
