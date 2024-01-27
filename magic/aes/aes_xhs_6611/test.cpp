# include "xhs.h"


int main(){
    const char* AESKEY= "98b3f67e-dc8c-3b32-a0dd-7d5ff559167a";	//HEX密钥
    const char* AESIV ="3101323404020861667A666607176639"	;//HEX初始向量
    const char* encry = "1b5eaac6c1e5a1069190f49e3dfa1fb2"
                  "099f13ed506ffa3ca14d242afe01c76b"
                  "2f91b707e5f46c30e747e2786f0c045a"
                  "dd49bff96de4489a0a77a0d68ef1389b"
                  "b6575597182ea007dbd650811df56a3e"
                  "296f38d932c2b620bcbde87bd53c73a1";

    char *result = decrypt_hmac2(AESKEY, AESIV, encry);
    print2(result, 64);
    delete[] result;
    return 0;
}
