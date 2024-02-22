cmake_minimum_required(VERSION 3.27)
project(algorithm)

set(CMAKE_CXX_STANDARD 14)

#add_executable(copy_hash_md5
#        copy/hash/md5/md5.cpp
#        copy/hash/md5/md5.h
#        copy/hash/md5/test.cpp)
#
#add_executable(copy_hash_md5_hmac
#        copy/hash/md5_hmac/md5.cpp
#        copy/hash/md5_hmac/md5.h
#        copy/hash/md5_hmac/test.cpp)
#
#add_executable(copy_aes_aes_tiny
#        copy/aes/aes_tiny/aes.cpp
#        copy/aes/aes_tiny/aes.h
#        copy/aes/aes_tiny/test.cpp)
#
#
#add_executable(copy_aes_aes_base
#        copy/aes/aes_base/aes.h
#        copy/aes/aes_base/main_test.cpp
#        copy/aes/aes_base/aes_core.cpp
#        copy/aes/aes_base/aes_locl.h
#        copy/aes/aes_base_iv/cbc128.cpp)
#
#add_executable(aes_openssl_iv
#        copy/aes/aes_base_iv/aes.h
#        copy/aes/aes_base_iv/test.cpp
#        copy/aes/aes_base_iv/aes_core.cpp
#        copy/aes/aes_base_iv/aes_cbc.cpp
#        copy/aes/aes_base_iv/modes.h
#        copy/aes/aes_base_iv/cbc128.cpp
#)

# aes_xhs_6611
add_executable(aes_xhs_6611
        magic/aes/aes_xhs_6611/aes.h
        magic/aes/aes_xhs_6611/aes_cbc.cpp
        magic/aes/aes_xhs_6611/aes_core.cpp
        magic/aes/aes_xhs_6611/cbc128.cpp
        magic/aes/aes_xhs_6611/test.cpp
        magic/aes/aes_xhs_6611/xhs.cpp)
# combile: g++ -std=gnu++0x magic/aes/aes_xhs_6611/aes_cbc.cpp magic/aes/aes_xhs_6611/aes_core.cpp magic/aes/aes_xhs_6611/cbc128.cpp magic/aes/aes_xhs_6611/xhs.cpp -fPIC -shared -o libxhs.so


#### 执行原始的
## 添加可执行文件
#add_executable(openssl_test_hmac
#        openssl/hmac/test.cpp)
#target_include_directories(openssl_test_hmac PRIVATE /Users/yuanlang/Work/C++/install/include)
#target_link_libraries(openssl_test_hmac PRIVATE /Users/yuanlang/Work/C++/install/lib/libcrypto.dylib)
#
#
##add_executable(magic
##        magic/hmac/test.cpp
##        magic/hmac/hmac_local.h
##        magic/hmac/hmac.cpp
##)
#
#add_executable(openssl
#        openssl/md5/test_md5.cpp)
#
## 包含 OpenSSL 头文件目录
#target_include_directories(openssl PRIVATE /Users/yuanlang/Work/C++/install/include)
#target_link_libraries(openssl PRIVATE /Users/yuanlang/Work/C++/install/lib/libcrypto.dylib)
#
#
#add_executable(xhs_6611 magic/hmac/xhs_6611/md5_transform.cpp)




# 指定生成的库文件的输出目录，例如项目根目录的 "lib" 子目录
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#
## 用于收集所有的源文件
#file(GLOB_RECURSE LIB_SOURCES
#        magic/aes/aes_xhs_6611/aes.h
#        magic/aes/aes_xhs_6611/aes_cbc.cpp
#        magic/aes/aes_xhs_6611/aes_core.cpp
#        magic/aes/aes_xhs_6611/cbc128.cpp
#        magic/aes/aes_xhs_6611/test.cpp
#)
#
## 创建名为 "my_library" 的共享库
#add_library(my_library SHARED ${LIB_SOURCES}
#        magic/aes/aes_xhs_6611/xhs.cpp)

add_executable(MurmurHash
        copy/hash/MurmurHash/MurmurHash2.cpp
        copy/hash/MurmurHash/MurmurHash2.h
        copy/hash/MurmurHash/main.cpp
)
