#include "hmac.h"

uint8_t hmac(uint8_t * key, uint8_t keyLen, uint8_t * const opBuff, hashfunc_ptr const hashFunc, const uint8_t hashSize, const uint8_t blockSize)
{
	//TODO: current implementation may not allow hashSize>blockSize
	//TODO: recheck, may-be hashSize>blockSize situations is not valid at all for HMAC algo
	if(hashSize>blockSize)
		return 0;
	//array for various operations (source key transformations and data preparation for final hash)
	uint8_t tmpBuff[blockSize+hashSize];
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
	//create outer padded key and inner padded key
	for(uint8_t p=0; p<blockSize; ++p)
	{
		//inner padded key stored directly at begining of opBuff
		opBuff[p]=key[p]^0x36;
		//outer padded key stored at beginning of tmpBuff
		tmpBuff[p]=key[p]^0x5c;
	}
	//calculate 1-st pass hash from opBuff that contains concatenated inner padded key and data, and write result to the end of tmpBuff buffer
	//calculate 2-nd pass hash (final) from tmpBuff buffer that contains concatenated outer padded key and 1-st pass hash, and write result to the start of opBuff
	return hashSize;
}
