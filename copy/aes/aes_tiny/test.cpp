#include <stdio.h>
#include "aes.h"

// prints string as hex
static void phex(uint8_t* str)
{
    unsigned char i;
    for (i = 0; i < 16; ++i)
        printf("%02x ", str[i]);
    printf("\n");
}

int main() {
    uint8_t i;

    // 128bit key
    uint8_t key[16] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
                       0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff,};
    // 128bit text
    uint8_t plain_text[16] = {
            0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
            0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    };
    struct AES_ctx ctx;
    printf("plaintext:\n");
    phex(plain_text);
    AES_init_ctx(&ctx, key);

    AES_ECB_encrypt(&ctx, plain_text);
    printf("encrypted:\n");
    phex(plain_text);

    AES_ECB_decrypt(&ctx, plain_text);
    printf("decrypted:\n");
    phex(plain_text);
    printf("\n");
    return 0;
}