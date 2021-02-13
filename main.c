#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "AES.C"

int main(void) {
	char *In = calloc(1024, sizeof(char));
	int init_len = 0;
	BYTE Key[] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
	BYTE ENC[1024];
	BYTE DEC[1024];
	
	printf("원문 입력(1024바이트 이내) : ");
	gets(In);
	init_len = strlen(In);
	while(strlen(In) % 16 != 0) In[strlen(In)] = '.';
	
	
	printf("\n원문:\t");
	for (int i = 0; i < init_len; i++) printf("%c", In[i]);
	printf("\n");
	int Len = strlen(In) + 1;
	AES_ECB_Encrypt(In, Key, ENC, Len);
	
	
	printf("암호화:\t");
	for (int i = 0; i < Len; i++) printf("%02X ", ENC[i]);
	printf("\n");
	
	
	memset(DEC, 0, sizeof(DEC));
	AES_ECB_Decrypt(ENC, Key, DEC, Len);
	printf("복호화:\t", DEC);
	for (int i = 0; i < init_len; i++) printf("%c", DEC[i]);
	printf("\n");
	
	free(In);
	return 0;
}