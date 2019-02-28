#ifndef SHA1_H_INCLUDED
#define SHA1_H_INCLUDED

#include <Arduino.h>

#ifdef __cplusplus
extern "C"{
#endif

void sha1(uint8_t *digest, const uint8_t *data, size_t databytes);

#ifdef __cplusplus
} // extern "C"
#endif

#endif
