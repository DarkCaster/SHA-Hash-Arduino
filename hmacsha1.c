#include "hmacsha1.h"

#define BLOCK_SIZE 64

size_t hmacsha1_get_opbuff_sz(size_t dataLen)
{
	return dataLen + BLOCK_SIZE;
}

uint8_t hmacsha1(uint8_t * key, size_t keyLen, uint8_t * const opBuff, size_t dataLen)
{
	return hmac(key, keyLen, opBuff, dataLen, sha1, SHA1_HASHSIZE, BLOCK_SIZE);
}
