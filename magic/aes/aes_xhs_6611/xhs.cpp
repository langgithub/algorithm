#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aes.h"

//将文本形式的HEX串进行转换
unsigned char* str2hex2(const char *str)
{
    unsigned char *ret = NULL;
    int str_len = strlen(str);
    ret = (unsigned char *)malloc(str_len/2);
    for (int i =0;i < str_len; i = i+2 )
    {
        sscanf(str+i,"%2hhx",&ret[i/2]);
    }
    return ret;
}

//将文本形式的HEX串进行转换
void str2hex_list2(const char *str, char* ret)
{
    int str_len = strlen(str);
    for (int i=0;i< str_len;i++) {
        ret[i] = str[i];
    }
}

void print2(char *in, int num){
    for(int i = 0; i < num; i++)
    {
        if(i%16==0){
            printf("\n");
        }
        printf("%02X ", *((unsigned char *)in+i));
    }
    printf("\n");
}


void print2(char *in, int num);
extern "C"{
char* decrypt_hmac2(const char *AESKEY, const char *AESIV, const char* encry);
}

char* decrypt_hmac2(const char *AESKEY, const char *AESIV, const char* encry){

        // aes key
        unsigned char key[128];
        memset(key,0, 128);
        str2hex_list2(AESKEY, (char *) key);

        // aes iv
        unsigned char *stdiv;
        stdiv = str2hex2(AESIV);
        unsigned char tmpiv[16] = {0x31, 0x01, 0x32, 0x34, 0x04, 0x02, 0x08, 0x61, 0x66, 0x7A, 0x66, 0x66, 0x07, 0x17, 0x66, 0x39};
        memcpy(tmpiv, stdiv, 16);


        AES_KEY decryptkey;
        AES_set_decrypt_key(key,128,&decryptkey);  // init key
        print2(reinterpret_cast<char *>(decryptkey.rd_key), 128);

        // s_xml 文件中的 hmac 的key
        unsigned char encrypted_text[96];
        unsigned char *ssss;
        ssss = str2hex2(encry);
        memcpy(encrypted_text, ssss, 96);
        printf("\n encry->");
        print2((char *) encrypted_text, 96);

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

//        // 分配至少 81 个字节的内存（这里以 100 个字节为例）
//        unsigned char targetData[64]; // Adjust the size accordingly if needed
//        size_t offset = 16; // The index of the first byte of the desired block - 1
//        // Use memcpy to copy the block of data
//        memcpy(targetData, decrypted_text + offset, sizeof(targetData));
//        printf("\n last key: " );
//        for(int i = 0; i < 64; i++)
//        {
//            if(i%16==0){
//                printf("\n");
//            }
//            printf("%02X ", targetData[i]);
//        }
//        printf("\n" );


        // C++ 中的用法
        unsigned char* targetData1 = new unsigned char[64];
        memcpy(targetData1, decrypted_text + 16, 64);
        return reinterpret_cast<char*>(targetData1);
//        return (char*)ta/rgetData;
    }

//
//int main()
//{
//
//    // aes key
//    unsigned char key[128];
//    memset(key,0, 128);
//    str2hex_list(AESKEY, (char *) key);
//
//    // aes iv
//    unsigned char *stdiv;
//    stdiv = str2hex(AESIV);
//    unsigned char tmpiv[16] = {0x31, 0x01, 0x32, 0x34, 0x04, 0x02, 0x08, 0x61, 0x66, 0x7A, 0x66, 0x66, 0x07, 0x17, 0x66, 0x39};
//    memcpy(tmpiv, stdiv, 16);
//
//
//    AES_KEY decryptkey;
//    AES_set_decrypt_key(key,128,&decryptkey);  // init key
//
//    // s_xml 文件中的 hmac 的key
//    unsigned char encrypted_text[32];
//    char* encry = "1b5eaac6c1e5a1069190f49e3dfa1fb2"
//                  "099f13ed506ffa3ca14d242afe01c76b"
//                  "2f91b707e5f46c30e747e2786f0c045a"
//                  "dd49bff96de4489a0a77a0d68ef1389b"
//                  "b6575597182ea007dbd650811df56a3e"
//                  "296f38d932c2b620bcbde87bd53c73a1";
//    unsigned char *ssss;
//    ssss = str2hex(encry);
//    memcpy(encrypted_text, ssss, 96);
//    printf("\n encry->");
//    print1((char *) encrypted_text, 96);
//
//    // 解密后的key
//    unsigned char decrypted_text[128];
//    memset(decrypted_text, 0, 128);
//    AES_cbc_encrypt(encrypted_text, decrypted_text, 96, &decryptkey, tmpiv, AES_DECRYPT);
//    printf("\n aes decrypted_text =>" );
//    for(int i = 0; i < 128; i++)
//    {
//        if(i%16==0){
//            printf("\n");
//        }
//        printf("%02X ", decrypted_text[i]);
//    }
//    printf("\n" );
//
//    size_t v8 = *(uint8_t *)(decrypted_text + 96 - 1);// 读取最后一个字节，更具PKCS7填充的数据定义，需要将填充的字节置为0
//    memset((void *)(decrypted_text + 96 - v8), 0, v8);
//    printf("\n pkcs7填充前 =>" );
//    for(int i = 0; i < 128; i++)
//    {
//        if(i%16==0){
//            printf("\n");
//        }
//        printf("%02X ", decrypted_text[i]);
//    }
//    printf("\n" );
//
//    memset(decrypted_text, 0, 16);
//    printf("\n 去掉前16个字节" );
//    for(int i = 0; i < 128; i++)
//    {
//        if(i%16==0){
//            printf("\n");
//        }
//        printf("%02X ", decrypted_text[i]);
//    }
//    printf("\n" );
//
//    // 分配至少 81 个字节的内存（这里以 100 个字节为例）
//    unsigned char targetData[64]; // Adjust the size accordingly if needed
//    size_t offset = 16; // The index of the first byte of the desired block - 1
//    // Use memcpy to copy the block of data
//    memcpy(targetData, decrypted_text + offset, sizeof(targetData));
//    printf("\n last key: " );
//    for(int i = 0; i < 64; i++)
//    {
//        if(i%16==0){
//            printf("\n");
//        }
//        printf("%02X ", targetData[i]);
//    }
//    printf("\n" );
//    return 0;
//
//}

