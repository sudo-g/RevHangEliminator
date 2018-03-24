#include <iostream>
#include "sliptests.h"
#include "pcintmsgtests.h"

int main(int argc, char* argv[])
{
	std::cout << "Executing RevHangEliminatorFirmware units tests..." << std::endl;

	slip_encode_noesc_test();
	slip_encode_zerobytes_test();
	slip_encode_singlebyte_test();
	slip_encode_escesc_test();
	slip_encode_escend_test();
	slip_encode_escescwithcontents_test();
	slip_encode_escendwithcontents_test();

	std::cout << std::endl;

	pcintmsg_encode_simplepayload_test();
	pcintmsg_encode_multibytetimestamp_test();

	std::cout << std::endl;

	return EXIT_SUCCESS;
}
