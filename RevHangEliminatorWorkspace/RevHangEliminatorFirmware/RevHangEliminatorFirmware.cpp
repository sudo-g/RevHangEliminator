#include "OBD.h"
#include <string.h>
#include "pcintmsg.h"
#include "slip.h"

#define PC_BAUD 9600
#define POLL_INTERVAL_MS 50

unsigned int next_cycle_t;
COBD obd;

void setup()
{
	obd.begin();
	while (!obd.init());

	Serial.begin(PC_BAUD);

	next_cycle_t = millis();
}

void loop()
{
	while (millis() > next_cycle_t);
	next_cycle_t += POLL_INTERVAL_MS;

	int rpm;
	obd.readPID(PID_RPM, rpm);

	PcmsgDescriptor msgdescriptor;
	msgdescriptor.ts = millis();
	msgdescriptor.mode = 1;
	msgdescriptor.pid = PID_RPM;
	msgdescriptor.pllen = 2;

	uint8_t rpm_as_payload[2];
	memcpy(rpm_as_payload, &rpm, msgdescriptor.pllen);

	uint8_t rpm_msg_stream[11];
	int8_t bytes_pcint = pcintmsg_encode(rpm_msg_stream, msgdescriptor);

	uint8_t ser_write_buffer[100];
	int8_t bytes2serial = slip_encode(ser_write_buffer, rpm_msg_stream, bytes_pcint);
	Serial.write(ser_write_buffer, bytes2serial);
}
