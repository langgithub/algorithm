
// hmac解密 rcon 和 Te1 被替换
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aes.h"
#include <cassert>

#define AESKEY "98b3f67e-dc8c-3b32-a0dd-7d5ff559167a"	//HEX密钥
#define AESIV  "3101323404020861667A666607176639"	//HEX初始向量

//v17[0] = 0x34320131;
//v17[3] = 0x39661707;
//v17[2] = 0x66667A66;
//v17[1] = 0x61080204;

//将文本形式的HEX串进行转换
unsigned char* str2hex(char *str)
{
    unsigned char *ret = NULL;
    size_t str_len = strlen(str);
    int i = 0;
    assert((str_len%2) == 0);
    ret = (unsigned char *)malloc(str_len/2);
    for (i =0;i < str_len; i = i+2 )
    {
        sscanf(str+i,"%2hhx",&ret[i/2]);
    }
    return ret;
}

void print1(char *in, int num){
    for(int i = 0; i < num; i++)
    {
        if(i%16==0){
            printf("\n");
        }
        printf("%02X ", *((unsigned char *)in+i));
    }
    printf("\n");
}

int main()
{
    AES_KEY decryptkey;
//    unsigned char *key;
//    key = str2hex(AESKEY);
//    unsigned char *stdiv;
//    stdiv = str2hex(AESIV);

   // key2 来自 AESKEY
    const unsigned char  key2[128] = {
             0x39,0x38,0x62,0x33,0x66,0x36,0x37,0x65,0x2D,0x64,0x63,0x38,0x63,0x2D,0x33,0x62
            ,0x31,0x01,0x32,0x34,0x04,0x02,0x08,0x61,0x66,0x7A,0x66,0x66,0x07,0x17,0x66,0x39
            ,0x1D,0xE3,0x43,0xF8,0x20,0xEA,0x44,0x89,0x27,0xF3,0xE0,0x0D,0x8F,0xD1,0xC7,0xE3
            ,0x70,0x6C,0x61,0x74,0x66,0x6F,0x72,0x6D,0x3D,0x61,0x6E,0x64,0x72,0x6F,0x69,0x64
            ,0x26,0x62,0x75,0x69,0x6C,0x64,0x3D,0x36,0x36,0x31,0x31,0x30,0x30,0x34,0x26,0x64
            ,0x65,0x76,0x69,0x63,0x65,0x49,0x64,0x3D,0x39,0x38,0x62,0x33,0x66,0x36,0x37,0x65
            ,0x2D,0x64,0x63,0x38,0x63,0x2D,0x33,0x62,0x33,0x32,0x2D,0x61,0x30,0x64,0x64,0x2D
            ,0x37,0x64,0x35,0x66,0x66,0x35,0x35,0x39,0x31,0x36,0x37,0x61,0x00,0x00,0x00,0x00
    };
    AES_set_decrypt_key(key2,128,&decryptkey);  // init key
    printf("ctx -> 结构体");
    for(int i = 0; i < 244; i++)
    {
        if(i%16==0){
            printf("\n");
        }
        printf("%02X ", *((unsigned char *)&decryptkey+i));
    }
    printf("\n" );


    unsigned char tmpiv[16] = {0x31, 0x01, 0x32, 0x34, 0x04, 0x02, 0x08, 0x61, 0x66, 0x7A, 0x66, 0x66, 0x07, 0x17, 0x66, 0x39};

    // s_xml 文件中的 hmac 的key
    unsigned char encrypted_text[32];
    char* encry = "1b5eaac6c1e5a1069190f49e3dfa1fb2"
                  "099f13ed506ffa3ca14d242afe01c76b"
                  "2f91b707e5f46c30e747e2786f0c045a"
                  "dd49bff96de4489a0a77a0d68ef1389b"
                  "b6575597182ea007dbd650811df56a3e"
                  "296f38d932c2b620bcbde87bd53c73a1";
    unsigned char *ssss;
    ssss = str2hex(encry);
    memcpy(encrypted_text, ssss, 96);
    printf("\n encry->");
    print1((char *) encrypted_text, 96);

    // 解密后的key
    unsigned char decrypted_text[128];
    memset(decrypted_text, 0, 128);
    AES_cbc_encrypt(encrypted_text, decrypted_text, 96, &decryptkey, tmpiv, AES_DECRYPT);
    printf("\n aes decrypted_text =>" );
    for(int i = 0; i < 128; i++)
    {
        if(i%16==0){
            printf("\n");
        }
        printf("%02X ", decrypted_text[i]);
    }
    printf("\n" );

    size_t v8 = *(uint8_t *)(decrypted_text + 96 - 1);// 读取最后一个字节，更具PKCS7填充的数据定义，需要将填充的字节置为0
    memset((void *)(decrypted_text + 96 - v8), 0, v8);
    printf("\n pkcs7填充前 =>" );
    for(int i = 0; i < 128; i++)
    {
        if(i%16==0){
            printf("\n");
        }
        printf("%02X ", decrypted_text[i]);
    }
    printf("\n" );

    memset(decrypted_text, 0, 16);
    printf("\n 去掉前16个字节" );
    for(int i = 0; i < 128; i++)
    {
        if(i%16==0){
            printf("\n");
        }
        printf("%02X ", decrypted_text[i]);
    }
    printf("\n" );

    // 分配至少 81 个字节的内存（这里以 100 个字节为例）
    unsigned char targetData[64]; // Adjust the size accordingly if needed
    size_t offset = 16; // The index of the first byte of the desired block - 1
    // Use memcpy to copy the block of data
    memcpy(targetData, decrypted_text + offset, sizeof(targetData));
    printf("\n last key: " );
    for(int i = 0; i < 64; i++)
    {
        if(i%16==0){
            printf("\n");
        }
        printf("%02X ", targetData[i]);
    }
    printf("\n" );
    return 0;

}