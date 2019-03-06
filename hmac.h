#ifndef HMAC_H_INCLUDED
#define HMAC_H_INCLUDED

#include <Arduino.h>

#ifdef __cplusplus
extern "C"{
#endif

typedef uint8_t (*hashfunc_ptr)(uint8_t * const digest, const uint8_t * const data, size_t len);

uint8_t hmac(uint8_t * key, uint8_t keyLen, uint8_t * opBuff, hashfunc_ptr hashFunc, const uint8_t hashSize, const uint8_t blockSize);

#ifdef __cplusplus
} // extern "C"
#endif

#endif
