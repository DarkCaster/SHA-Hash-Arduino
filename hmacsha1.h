#ifndef HMACSHA1_H_INCLUDED
#define HMACSHA1_H_INCLUDED

#include <Arduino.h>
#include "sha1.h"
#include "hmac.h"

#ifdef __cplusplus
extern "C"{
#endif

size_t hmacsha1_get_opbuff_sz(size_t dataLen);

uint8_t hmacsha1(uint8_t * key, size_t keyLen, uint8_t * const opBuff, size_t dataLen);

#ifdef __cplusplus
} // extern "C"
#endif

#endif
