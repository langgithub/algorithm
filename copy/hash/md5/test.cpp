#include "md5.h"
using namespace std;

int main(){

    int i;
    unsigned char encrypt[] = "admin";//"admin";//21232f297a57a5a743894a0e4a801fc3
    unsigned char decrypt[16];

    MD5_CTX md5;

    MD5Init(&md5);
    MD5Update(&md5, encrypt, (int)strlen((char *)encrypt));//只是个中间步骤
    MD5Final(&md5, decrypt);//32位

    printf("加密前:%s\n加密后16位:",encrypt);
    for (i = 4; i<12; i++){
        printf("%02x", decrypt[i]);
    }


    printf("\n加密前:%s\n加密后32位:",encrypt);
    for (i = 0; i<16; i++){
        printf("%02x", decrypt[i]);
    }

    return 0;
}