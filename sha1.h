#ifndef SHA1_H_INCLUDED
#define SHA1_H_INCLUDED

#include <Arduino.h>

#ifdef __cplusplus
extern "C"{
#endif

#define SHA1_HASHSIZE 20

uint8_t sha1(uint8_t * const digest, const uint8_t *data, const size_t databytes);

#ifdef __cplusplus
} // extern "C"
#endif

#endif
