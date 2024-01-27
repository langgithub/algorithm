#include <stdio.h>
#include "aes.h"

int main()
{
    int i;

    const unsigned char master_key[16] = {
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    };
    const unsigned char text[16] = {
            0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
            0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    };

    unsigned char encrypted[16], decrypted[16];

    AES_KEY key;

    printf("plaintext:\n");
    for (i = 0; i < 16; i++) {
        printf("%02x ", (unsigned int)text[i]);
    }
    printf("\n\n");

    printf("encrypted:\n");
    AES_set_encrypt_key(master_key, 128, &key); // 128 for 128-bit version AES
    AES_encrypt(text, encrypted, &key);
    for (i = 0; i < 16; i++) {
        printf("%02x ", (unsigned int)encrypted[i]);
    }
    printf("\n\n");

    printf("decrypted:\n");
    AES_set_decrypt_key(master_key, 128, &key);
    AES_decrypt(encrypted, decrypted, &key);
    for (i = 0; i < 16; i++) {
        printf("%02x ", (unsigned int)decrypted[i]);
    }
    printf("\n");

    return 0;
}