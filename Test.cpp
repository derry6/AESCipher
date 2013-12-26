#include <cstring>
#include "AES.h"

void print(unsigned char* state, int len);

int main(int argc, char* argv[])
{
	unsigned char input[] = {84, 104, 105, 115, 32, 105, 115, 32, 97, 32, 116, 101, 115, 116, 33, 84, 104, 105, 115, 32, 105, 115, 32, 97, 32, 116, 101, 115, 116, 33, 84, 104, 105, 115, 32, 105, 115, 32, 97, 46};
	unsigned char iv[]    = {103,35,148,239,76,213,47,118,255,222,123,176,106,134,98,92};
	unsigned char key[]   = {143,194,34,208,145,203,230,143,177,246,97,206,145,92,255,84};
	unsigned char output[100] ={0};
    unsigned char temp[100] = {0};
//	unsigned char 
	AESModeOfOperation moo;
	moo.set_key(key);
	moo.set_mode(MODE_OFB);
	moo.set_iv(iv);
    int olen = sizeof input;

    memcpy(temp, input, sizeof input);
	int len = moo.Encrypt(temp, olen, output);
	printf("len = %d\n", len);
    printf("output");
	print(output, len);
	printf("\n\nDecrypt----------\n");
	len = moo.Decrypt(output, len, input);
	printf("len = %d\n", len);
    printf("input");
	print(input, len);
	
	return 0;
}

void print(unsigned char* state, int len)
{
	int i;
	for(i=0; i<len; i++)
	{
        if ( i%16 == 0) printf("\n");
//		printf("%s%X ",state[i]>15 ? "" : "0", state[i]);
        printf("%d  ", (int)(state[i] & 0xff));
	}
	printf("\n");
}

