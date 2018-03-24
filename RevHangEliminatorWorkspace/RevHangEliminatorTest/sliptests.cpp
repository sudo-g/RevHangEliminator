#include "sliptests.h"
#include <assert.h>
#include <iostream>
#include <string.h>
#include "slip.h"

void slip_encode_noesc_test(void)
{
	std::cout << "slip_encode_noesc_test\t";

	const uint8_t reference[] = {SLIP_END, 0x01, 0x02, 0x03, SLIP_END};

	const uint8_t input[] = {0x01, 0x02, 0x03};
	uint8_t output[5];
	int8_t bytes = slip_encode(output, input, sizeof(input));

	int cmp = memcmp(reference, output, sizeof(output));
	assert(cmp == 0);

	assert(bytes == sizeof(reference));

	std::cout << "[PASS]" << std::endl;
}

void slip_encode_zerobytes_test(void)
{
	std::cout << "slip_encode_zerobytes_test\t";

	const uint8_t reference[] = {SLIP_END, SLIP_END};

	const uint8_t input[] = {};
	uint8_t output[2];
	int8_t bytes = slip_encode(output, input, sizeof(input));

	int cmp = memcmp(reference, output, sizeof(output));
	assert(cmp == 0);

	assert(bytes == sizeof(reference));

	std::cout << "[PASS]" << std::endl;
}

void slip_encode_singlebyte_test(void)
{
	std::cout << "slip_encode_singlebyte_test\t";

	const uint8_t reference[] = {SLIP_END, 0x01, SLIP_END};

	const uint8_t input[] = {0x01};
	uint8_t output[3];
	int8_t bytes = slip_encode(output, input, sizeof(input));

	int cmp = memcmp(reference, output, sizeof(output));
	assert(cmp == 0);

	assert(bytes == sizeof(reference));

	std::cout << "[PASS]" << std::endl;
}

void slip_encode_escesc_test(void)
{
	std::cout << "slip_encode_escesc_test\t";

	const uint8_t reference[] = {SLIP_END, SLIP_ESC, SLIP_ESC_ESC, SLIP_END};

	const uint8_t input[] = {SLIP_ESC};
	uint8_t output[4];
	int8_t bytes = slip_encode(output, input, sizeof(input));

	int cmp = memcmp(reference, output, sizeof(output));
	assert(cmp == 0);

	assert(bytes == sizeof(reference));

	std::cout << "[PASS]" << std::endl;
}

void slip_encode_escend_test(void)
{
	std::cout << "slip_encode_escesc_test\t";

	const uint8_t reference[] = {SLIP_END, SLIP_ESC, SLIP_ESC_END, SLIP_END};

	const uint8_t input[] = {SLIP_END};
	uint8_t output[4];
	int8_t bytes = slip_encode(output, input, sizeof(input));

	int cmp = memcmp(reference, output, sizeof(output));
	assert(cmp == 0);

	assert(bytes == sizeof(reference));

	std::cout << "[PASS]" << std::endl;
}

void slip_encode_escescwithcontents_test(void)
{
	std::cout << "slip_encode_escescwithcontents_test\t";

	const uint8_t reference[] = {SLIP_END, 0x31, SLIP_ESC, SLIP_ESC_ESC, 0x23, SLIP_END};

	const uint8_t input[] = {0x31, SLIP_ESC, 0x23};
	uint8_t output[6];
	int8_t bytes = slip_encode(output, input, sizeof(input));

	int cmp = memcmp(reference, output, sizeof(output));
	assert(cmp == 0);

	assert(bytes == sizeof(reference));

	std::cout << "[PASS]" << std::endl;
}

void slip_encode_escendwithcontents_test(void)
{
	std::cout << "slip_encode_escendwithcontents_test\t";

	const uint8_t reference[] = {SLIP_END, 0x31, SLIP_ESC, SLIP_ESC_END, 0x23, SLIP_END};

	const uint8_t input[] = {0x31, SLIP_END, 0x23};
	uint8_t output[6];
	int8_t bytes = slip_encode(output, input, sizeof(input));

	int cmp = memcmp(reference, output, sizeof(output));
	assert(cmp == 0);

	assert(bytes == sizeof(reference));

	std::cout << "[PASS]" << std::endl;
}
