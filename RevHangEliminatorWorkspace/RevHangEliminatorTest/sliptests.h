#ifndef _SLIPTESTS_H_
#define _SLIPTESTS_H_

void slip_encode_noesc_test(void);
void slip_encode_zerobytes_test(void);
void slip_encode_singlebyte_test(void);
void slip_encode_escesc_test(void);
void slip_encode_escend_test(void);
void slip_encode_escescwithcontents_test(void);
void slip_encode_escendwithcontents_test(void);

#endif
