#include<stdio.h>
#include<string.h>
#include<openssl/md5.h>
void test1()
{
    unsigned char str[]= "20:35:6E:18:2A:86";
    unsigned char md[16];
    int i;
    char temp[3];
    char code[33];
    MD5(str,strlen((char *)str),md);
    for (i = 0; i < 16; i++){
        sprintf(temp,"%2.2X",md[i]);
        strcat(code,temp);
        printf("%02x", md[i]);
    }
    printf(" test1 str to code:%s\n",code);
}
//void test2()
//{
//    MD5_CTX ctx;
//    unsigned char *str= "20:35:6E:18:2A:86";
//    unsigned char md[16];
//    int i;
//    char temp[3];
//    char code[33];
//    MD5_Init(&ctx);
//    MD5_Update(&ctx,str,strlen(str));
//    MD5_Final(md,&ctx);
//    for( i=0; i<16; i++ ){
//        sprintf(temp,"%02X",md[i]);
//        strcat(code,temp);
//    }
//    printf("test2 str to code:%s\n",code);
//}
int main( int argc, char **argv )
{
    test1();
//    test2();
    return 0;
}
