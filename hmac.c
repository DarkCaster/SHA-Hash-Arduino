#include "hmac.h"

//TODO: current implementation may not allow hashSize>blockSize
//TODO: recheck, may-be hashSize>blockSize situations is not valid at all for HMAC algo
uint8_t hmac(uint8_t * key, uint8_t keyLen, uint8_t * const opBuff, hashfunc_ptr const hashFunc, const uint8_t hashSize, const uint8_t blockSize)
{
	//array for key preparation
	//uint8_t tmpBuff[blockSize>hashSize?blockSize:hashSize];
	uint8_t tmpBuff[blockSize];
	//keys longer than blockSize are shortened by hashing them
	if(keyLen>blockSize)
	{
		keyLen=hashFunc(tmpBuff,key,keyLen);
		key=tmpBuff;
	}
	//keys shorter than blockSize are padded to blockSize by padding with zeros on the right
	if(keyLen<blockSize)
	{
		if(key!=tmpBuff)
		{
			memcpy(tmpBuff,key,keyLen);
			key=tmpBuff;
		}
		memset(key+keyLen,0,blockSize-keyLen);
	}
	//TODO: move data to the end of opBuff by blockSize bytes
	//array for outer padded key, must be big enough to include key and 1-st pass hash
	uint8_t oKey[blockSize+hashSize];
	//initialize outer padded key
	memset(oKey,0x5c,blockSize);
	//initialize inner padded key directly at begining of opBuff
	memset(opBuff,0x36,blockSize);
	//create final outer padded key and inner padded key
	for(uint8_t p=0; p<blockSize; ++p)
	{
		oKey[p]=key[p]^oKey[p];
		opBuff[p]=key[p]^opBuff[p];
	}
	//calculate 1-st pass hash from opBuff that contains concatenated inner padded key and data, and write result to the end of oKey buffer
	//calculate 2-nd pass hash (final) from oKey buffer that contains concatenated outer padded key and 1-st pass hash, and write result to the start of opBuff
	return hashSize;
}
