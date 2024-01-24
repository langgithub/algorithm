#include <openssl/hmac.h>
#include <openssl/sha.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
    // 第一种方法

    char key[64] = {
            0x5B,0xE4,0x5B,0xA4,0x35,0x1C,0xBF,0xB5,0x8B,0x90,0x32,0xCE,0x6E,0x08,0xFF,0x9B
        ,0x3D,0x94,0x60,0x5A,0xC5,0xF1,0xC1,0x92,0x10,0xA0,0x88,0x2C,0x55,0xEC,0x33,0xB3
        ,0xEC,0xF2,0x83,0x92,0x93,0xAC,0xAB,0x88,0xC3,0x0D,0x1F,0x1A,0xAF,0x77,0x2E,0xFE
        ,0xC2,0xDB,0x0A,0xE0,0x54,0x14,0x2F,0x94,0x8B,0x58,0xD8,0x96,0xDF,0x44,0xDE,0x83
    };
    unsigned char data[] = "/api/sns/v1/system_service/vfc_codezone=86&phone=18615706012&type=login&traceId=1705476229496_13169b27-36ed-4f9e-ba6f-02957be009bc&fid=1705475302103862bc7f6a3e06f6ac61ac3ec73c3f06&device_fingerprint=202401171508230e4fbccb544f9c9a76c892902438e2e7013700ea31119711&device_fingerprint1=202401171508230e4fbccb544f9c9a76c892902438e2e7013700ea31119711&channel=YingYongBao&versionName=6.61.1&deviceId=98b3f67e-dc8c-3b32-a0dd-7d5ff559167a&platform=android&sid=session.1705475302702272029441&identifier_flag=4&t=1705476258&x_trace_page_current=login_full_screen_sms_page&lang=zh-Hans&uis=lightfid=1705475302103862bc7f6a3e06f6ac61ac3ec73c3f06&device_fingerprint=202401171508230e4fbccb544f9c9a76c892902438e2e7013700ea31119711&device_fingerprint1=202401171508230e4fbccb544f9c9a76c892902438e2e7013700ea31119711&channel=YingYongBao&versionName=6.61.1&deviceId=98b3f67e-dc8c-3b32-a0dd-7d5ff559167a&platform=android&sid=session.1705475302702272029441&identifier_flag=4&t=1705476258&x_trace_page_current=login_full_screen_sms_page&lang=zh-Hans&uis=lightplatform=android&build=6611004&deviceId=98b3f67e-dc8c-3b32-a0dd-7d5ff559167a";
    unsigned char md[16];
    char mdBufs[20*2+1];
    unsigned int len=0;

    HMAC_CTX* ctx = HMAC_CTX_new();
    HMAC_Init_ex(ctx,&key,sizeof(key),EVP_md5(),NULL); // 执行了两次 md5_transform
    HMAC_Update(ctx,data,strlen((char*)data));
    HMAC_Final(ctx,md,&len);
    int i=0;
    for(;i<16;i++)
    {
        sprintf(&mdBufs[i*2],"%02x",md[i]);
    }
    cout<<"第一种："<<mdBufs<<endl;
//
//    // 第二种
//    len = 0;
//    memset(md,0x00,sizeof(md));
//    HMAC(EVP_sha1(),key,strlen(key),data,strlen((char*)data),md,&len);
//    for(i=0;i<20;i++)
//    {
//        sprintf(&mdBufs[i*2],"%02x",md[i]);
//    }
//    cout<<"第二种："<<mdBufs<<endl;

    return 0;
}
// lldb
// 读取 char key[] 类型的key
// memory read --size 1  --count 64 (char*)&key     char key[], 读取key 内存内容
// print/x key[0]

// 读取结构体
// expr offsetof(MD5_CTX, B)    B在结构体中偏移
// memory read --size 1 --count 16 --format x '(uintptr_t)((char *)c + 0)'

// 读取 char* 类型的data
// memory read --size 1  --count 144 data