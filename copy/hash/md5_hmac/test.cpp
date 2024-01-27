#include <cstdio>
#include "md5.h"

using namespace std;

void hmac_md5(
        unsigned char*  text,                /* pointer to data stream */
        int             text_len,            /* length of data stream */
        unsigned char*  key,                 /* pointer to authentication key */
        int             key_len,             /* length of authentication key */
        unsigned char*  digest               /* caller digest to be filled in */
){
    MD5_CTX context;
    unsigned char k_ipad[65];    /* inner padding -
                                      * key XORd with ipad
                                      */
    unsigned char k_opad[65];    /* outer padding -
                                      * key XORd with opad
                                      */
    unsigned char tk[16];
    int i;
    /* if key is longer than 64 bytes reset it to key=MD5(key) */
    if (key_len > 64) {

        MD5_CTX      tctx;

        MD5Init(&tctx);
        MD5Update(&tctx, key, key_len);
        MD5Final(tk, &tctx);

        key = tk;
        key_len = 16;
    }

    /*
     * the HMAC_MD5 transform looks like:
     *
     * MD5(K XOR opad, MD5(K XOR ipad, text))
     *
     * where K is an n byte key
     * ipad is the byte 0x36 repeated 64 times
     * opad is the byte 0x5c repeated 64 times
     * and text is the data being protected
     */

    /* start out by storing key in pads */
    memset( k_ipad, 0, sizeof(k_ipad));
    memset( k_opad, 0, sizeof(k_opad));
    memcpy( k_ipad, key, key_len);
    memcpy( k_opad, key, key_len);

    /* XOR key with ipad and opad values */
    for (i=0; i<64; i++) {
        k_ipad[i] ^= 0x36;
        k_opad[i] ^= 0x5c;
    }
    /*
     * perform inner MD5
     */
    MD5Init(&context);                   /* init context for 1st
                                              * pass */
    MD5Update(&context, k_ipad, 64);      /* start with inner pad */
    MD5Update(&context, text, text_len); /* then text of datagram */
    MD5Final(digest, &context);          /* finish up 1st pass */
    /*
     * perform outer MD5
     */
    MD5Init(&context);                   /* init context for 2nd
                                              * pass */
    MD5Update(&context, k_opad, 64);     /* start with outer pad */
    MD5Update(&context, digest, 16);     /* then results of 1st
                                              * hash */
    MD5Final(digest, &context);          /* finish up 2nd pass */
}
//
//int main(){
//
//    int i;
//    unsigned char key[] = "e45ea788-06f6-3d2f-bf6c-03f68152c851";//"admin";//21232f297a57a5a743894a0e4a801fc3
//    unsigned char encrypt[] = "channel%3DGooglePlaydeviceId%3De45ea788-06f6-3d2f-bf6c-03f68152c851device_fingerprint%3D2020113017502087b8779cc6128a65eebd7ad984d6994801bf8ba1b5e84b9adevice_fingerprint1%3D2020113017502087b8779cc6128a65eebd7ad984d6994801bf8ba1b5e84b9alang%3Dzh-Hansnum%3D3platform%3DAndroidshow_priority_sub_comments%3D1sid%3Dsession.1609234760057874883808start%3Dt%3D1610009987versionName%3D5.26.2";//"admin";//21232f297a57a5a743894a0e4a801fc3
//    unsigned char decrypt[16];
//    hmac_md5(encrypt, (int)strlen((char *)encrypt), key, (int)strlen((char *)key), decrypt);
//    printf("加密前:%s\n加密后16位:",encrypt);
//    for (i = 4; i<12; i++){
//        printf("%02x", decrypt[i]);
//    }
//
//    printf("\n加密前:%s\n加密后32位:",encrypt);
//    for (i = 0; i<16; i++){
//        printf("%02x", decrypt[i]);
//    }
//
//    return 0;
//}


int main(){

    int i;
//    unsigned char key[] = "e45ea788-06f6-3d2f-bf6c-03f68152c851";//"admin";//21232f297a57a5a743894a0e4a801fc3
    char key[] = {
            0x5B,0xE4,0x5B,0xA4,0x35,0x1C,0xBF,0xB5,0x8B,0x90,0x32,0xCE,0x6E,0x08,0xFF,0x9B
            ,0x3D,0x94,0x60,0x5A,0xC5,0xF1,0xC1,0x92,0x10,0xA0,0x88,0x2C,0x55,0xEC,0x33,0xB3
            ,0xEC,0xF2,0x83,0x92,0x93,0xAC,0xAB,0x88,0xC3,0x0D,0x1F,0x1A,0xAF,0x77,0x2E,0xFE
            ,0xC2,0xDB,0x0A,0xE0,0x54,0x14,0x2F,0x94,0x8B,0x58,0xD8,0x96,0xDF,0x44,0xDE,0x83
    };

    // 定义原始字节数组长度
    const int key_length = sizeof(key) / sizeof(key[0]);

// 创建一个新的数组，长度为原始字节数组长度加1，用于存储null字符
    unsigned char key_str[key_length + 1];

// 复制原始字节到新数组中
    memcpy(key_str, key, key_length);

// 在新数组的最后位置加上null字符来终止字符串
    key_str[key_length] = '\0';

// 现在 key_str 是一个字符串
    printf("Key as string: %s\n", key_str);

    unsigned char encrypt[] = "/api/sns/v1/system_service/vfc_codezone=86&phone=18615706012&type=login&traceId=1705476229496_13169b27-36ed-4f9e-ba6f-02957be009bc&fid=1705475302103862bc7f6a3e06f6ac61ac3ec73c3f06&device_fingerprint=202401171508230e4fbccb544f9c9a76c892902438e2e7013700ea31119711&device_fingerprint1=202401171508230e4fbccb544f9c9a76c892902438e2e7013700ea31119711&channel=YingYongBao&versionName=6.61.1&deviceId=98b3f67e-dc8c-3b32-a0dd-7d5ff559167a&platform=android&sid=session.1705475302702272029441&identifier_flag=4&t=1705476258&x_trace_page_current=login_full_screen_sms_page&lang=zh-Hans&uis=lightfid=1705475302103862bc7f6a3e06f6ac61ac3ec73c3f06&device_fingerprint=202401171508230e4fbccb544f9c9a76c892902438e2e7013700ea31119711&device_fingerprint1=202401171508230e4fbccb544f9c9a76c892902438e2e7013700ea31119711&channel=YingYongBao&versionName=6.61.1&deviceId=98b3f67e-dc8c-3b32-a0dd-7d5ff559167a&platform=android&sid=session.1705475302702272029441&identifier_flag=4&t=1705476258&x_trace_page_current=login_full_screen_sms_page&lang=zh-Hans&uis=lightplatform=android&build=6611004&deviceId=98b3f67e-dc8c-3b32-a0dd-7d5ff559167a";
    unsigned char decrypt[16];
    hmac_md5(encrypt, (int)strlen((char *)encrypt), (key_str), (int)strlen((char *)key_str), decrypt);
    printf("\n加密前:%s\n加密后16位:",encrypt);
    for (i = 0; i<16; i++){
        printf("%02x", decrypt[i]);
    }

    return 0;
}