
#include <cstdio>
#include "MurmurHash2.h"

int main(){
    // 我们要散列的数据
    const char *key = "Example data to hash";

    // 数据的长度
    int len = strlen(key);

    // 种子值，可以是任意32位无符号整数
    // 种子值在应用程序的不同运行中保持一致时，相同的输入将产生相同的散列值
    uint32_t seed = 0xDEADBEEF;

    // 调用MurmurHash2函数并获取哈希值
    uint32_t hash_value = MurmurHash2(key, len, seed);

    // 打印结果
    printf("Hash value: 0x%08X\n", hash_value);

    return 0;
}