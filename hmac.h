#ifndef HMAC_H_INCLUDED
#define HMAC_H_INCLUDED

#include <Arduino.h>

#ifdef __cplusplus
extern "C"{
#endif

typedef uint8_t (*hashfunc_ptr)(uint8_t * const digest, const uint8_t * const data, size_t len);

uint8_t hmac(uint8_t * key, size_t keyLen, uint8_t * const opBuff, size_t dataLen, hashfunc_ptr const hashFunc, const uint8_t hashSize, const uint8_t blockSize);

#ifdef __cplusplus
} // extern "C"
#endif

#endif
