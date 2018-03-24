#include "pcintmsgtests.h"
#include <assert.h>
#include <iostream>
#include "pcintmsg.h"

void pcintmsg_encode_simplepayload_test(void)
{
	std::cout << "pcmsg_encode_simplepayload_test\t";

	uint8_t buffer[100];
	uint8_t pl[] = {0x01, 0x02};

	PcmsgDescriptor msgdescriptor;
	msgdescriptor.ts = 123;
	msgdescriptor.mode = 1;
	msgdescriptor.pid = 0x0C;
	msgdescriptor.payload = pl;
	msgdescriptor.pllen = sizeof(pl);

	uint8_t reference_nocrc[] = {
		123, 0, 0, 0,
		1,
		0x0C,
		2,
		0x01, 0x02,
	};

	unsigned int bytes_written = pcintmsg_encode(buffer, msgdescriptor);
	assert(bytes_written == 11);

	int contents_equal = memcmp(reference_nocrc, buffer, 9);
	assert(contents_equal == 0);

	std::cout << "[PASS]" << std::endl;
}

void pcintmsg_encode_multibytetimestamp_test(void)
{
	std::cout << "pcmsg_encode_multibytetimestamp_test\t";

	uint8_t buffer[100];
	uint8_t pl[] = {0x01, 0x02};

	PcmsgDescriptor msgdescriptor;
	msgdescriptor.ts = 518;
	msgdescriptor.mode = 1;
	msgdescriptor.pid = 0x0C;
	msgdescriptor.payload = pl;
	msgdescriptor.pllen = sizeof(pl);

	uint8_t reference_nocrc[] = {
		6, 2, 0, 0,
		1,
		0x0C,
		2,
		0x01, 0x02,
	};

	unsigned int bytes_written = pcintmsg_encode(buffer, msgdescriptor);
	assert(bytes_written == 11);

	int contents_equal = memcmp(reference_nocrc, buffer, 9);
	assert(contents_equal == 0);

	std::cout << "[PASS]" << std::endl;
}
