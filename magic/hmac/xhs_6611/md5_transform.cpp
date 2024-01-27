// xhs6611版本sheild 签名
#include <cstdio>
#include <cstdint>

//#define ROR4_(n,k) ((n >> k) | (((n)&0xffffffff) << (32 - k)))
uint32_t ROR4_(uint32_t n, unsigned int k) {
    const unsigned int mask = 8 * sizeof(n) - 1;  // 掩码用于确保移位次数不会超过类型的位宽
    k &= mask;

    // ((n >> k) | (n << (32 - k))) 是将 n 右移 k 位的结果与 n 左移 (32 - k) 位的结果进行按位或操作。
    // 这里使用了 (32 - k) 而不是 (-k) 是为了避免负数左移的未定义行为。
    return (n >> k) | (n << ((-k) & mask));
}

int MD5Transform_2CDA0(int *state, unsigned char *input, int a3)
{
    int result; // r0
    int v4; // t2
    int v5; // t2
    int v6; // t2
    int v7; // t2
    int v8; // t2
    int v9; // t2
    int v10; // t2
    int v11; // t2
    int v12; // t2
    int v13; // t2
    int v14; // t2
    int v15; // t2
    int v16; // t2
    int v17; // t2
    unsigned char *v18; // r0
    int v19; // t2
    int v20; // t2
    int v21; // t2
    int v22; // t2
    int v23; // t2
    int v24; // t2
    int v25; // t2
    int v26; // t2
    int v27; // t2
    int v28; // t2
    int v29; // t2
    int v30; // t2
    int v31; // t2
    int v32; // t2
    int v33; // t2
    int v34; // t2
    int v35; // t2
    int v36; // t2
    int v37; // t2
    int v38; // t2
    int v39; // t2
    int v40; // t2
    int v41; // t2
    int v42; // t2
    int v43; // t2
    int v44; // t2
    int v45; // t2
    int v46; // t2
    int v47; // t2
    int v48; // t2
    int v49; // t2
    int v50; // t2
    int v51; // t2
    int v52; // t2
    int v53; // t2
    int v54; // t2
    int v55; // t2
    int v56; // t2
    int v57; // t2
    int v58; // t2
    int v59; // t2
    int v60; // t2
    int v61; // t2
    int v62; // t2
    int v63; // t2
    int v64; // t2
    int v65; // t2
    int v66; // t2
    int v67; // t2
    int v68; // r0
    int v69; // r0
    int v70; // r0
    int v71; // r0
    int v72_15; // [sp+Ch] [bp-6Ch]
    int v73_14; // [sp+10h] [bp-68h]
    int v74_13; // [sp+14h] [bp-64h]
    int v75_12; // [sp+18h] [bp-60h]
    int v76_11; // [sp+1Ch] [bp-5Ch]
    int v77_10; // [sp+20h] [bp-58h]
    int v78_9; // [sp+24h] [bp-54h]
    int v79_8; // [sp+28h] [bp-50h]
    int v80_7; // [sp+2Ch] [bp-4Ch]
    int v81_6; // [sp+30h] [bp-48h]
    int v82_5; // [sp+34h] [bp-44h]
    int v83_4; // [sp+38h] [bp-40h]
    int v84_3; // [sp+3Ch] [bp-3Ch]
    int v85_2; // [sp+40h] [bp-38h]
    int v86_1; // [sp+44h] [bp-34h]
    int v87_0; // [sp+48h] [bp-30h]
    int v88; // [sp+4Ch] [bp-2Ch]
    int i_D; // [sp+50h] [bp-28h]
    int v90; // [sp+50h] [bp-28h]
    int v91; // [sp+50h] [bp-28h]
    int v92; // [sp+50h] [bp-28h]
    int v93; // [sp+50h] [bp-28h]
    int v94; // [sp+50h] [bp-28h]
    int v95; // [sp+50h] [bp-28h]
    int v96; // [sp+50h] [bp-28h]
    int v97; // [sp+50h] [bp-28h]
    int v98; // [sp+50h] [bp-28h]
    int v99; // [sp+50h] [bp-28h]
    int v100; // [sp+50h] [bp-28h]
    int v101; // [sp+50h] [bp-28h]
    int v102; // [sp+50h] [bp-28h]
    int v103; // [sp+50h] [bp-28h]
    int v104; // [sp+50h] [bp-28h]
    int v105; // [sp+50h] [bp-28h]
    int v106_C; // [sp+54h] [bp-24h]
    int v107; // [sp+54h] [bp-24h]
    int v108; // [sp+54h] [bp-24h]
    int v109; // [sp+54h] [bp-24h]
    int v110; // [sp+54h] [bp-24h]
    int v111; // [sp+54h] [bp-24h]
    int v112; // [sp+54h] [bp-24h]
    int v113; // [sp+54h] [bp-24h]
    int v114; // [sp+54h] [bp-24h]
    int v115; // [sp+54h] [bp-24h]
    int v116; // [sp+54h] [bp-24h]
    int v117; // [sp+54h] [bp-24h]
    int v118; // [sp+54h] [bp-24h]
    int v119; // [sp+54h] [bp-24h]
    int v120; // [sp+54h] [bp-24h]
    int v121; // [sp+54h] [bp-24h]
    int v122_B; // [sp+58h] [bp-20h]
    int v123; // [sp+58h] [bp-20h]
    int v124; // [sp+58h] [bp-20h]
    int v125; // [sp+58h] [bp-20h]
    int v126; // [sp+58h] [bp-20h]
    int v127; // [sp+58h] [bp-20h]
    int v128; // [sp+58h] [bp-20h]
    int v129; // [sp+58h] [bp-20h]
    int v130; // [sp+58h] [bp-20h]
    int v131; // [sp+58h] [bp-20h]
    int v132; // [sp+58h] [bp-20h]
    int v133; // [sp+58h] [bp-20h]
    int v134; // [sp+58h] [bp-20h]
    int v135; // [sp+58h] [bp-20h]
    int v136; // [sp+58h] [bp-20h]
    int v137; // [sp+58h] [bp-20h]
    int v138; // [sp+58h] [bp-20h]
    int v139_A; // [sp+5Ch] [bp-1Ch]
    int v140; // [sp+5Ch] [bp-1Ch]
    int v141; // [sp+5Ch] [bp-1Ch]
    int v142; // [sp+5Ch] [bp-1Ch]
    int v143; // [sp+5Ch] [bp-1Ch]
    int v144; // [sp+5Ch] [bp-1Ch]
    int v145; // [sp+5Ch] [bp-1Ch]
    int v146; // [sp+5Ch] [bp-1Ch]
    int v147; // [sp+5Ch] [bp-1Ch]
    int v148; // [sp+5Ch] [bp-1Ch]
    int v149; // [sp+5Ch] [bp-1Ch]
    int v150; // [sp+5Ch] [bp-1Ch]
    int v151; // [sp+5Ch] [bp-1Ch]
    int v152; // [sp+5Ch] [bp-1Ch]
    int v153; // [sp+5Ch] [bp-1Ch]
    int v154; // [sp+5Ch] [bp-1Ch]
    int v155; // [sp+5Ch] [bp-1Ch]

    v139_A = *state;
    v122_B = state[1];
    v106_C = state[2];
    for ( i_D = state[3]; ; i_D = v71 )
    {
        result = a3--;
        if ( !result )
            break;
        v87_0 = *input | (input[1] << 8) | (input[2] << 16) | (input[3] << 24);
        v86_1 = input[4] | (input[5] << 8) | (input[6] << 16) | (input[7] << 24);
        v4 = ROR4_(v87_0 + state[23] + ((v106_C ^ i_D) & v122_B ^ i_D) + v139_A, 26);// round 0
        v140 = v122_B + v4;
        v85_2 = input[8] | (input[9] << 8) | (input[10] << 16) | (input[11] << 24);
        v5 = ROR4_(v86_1 + state[24] + ((v122_B ^ v106_C) & (v122_B + v4) ^ v106_C) + i_D, 19);
        v90 = v140 + v5;
        v84_3 = input[12] | (input[13] << 8) | (input[14] << 16) | (input[15] << 24);
        v6 = ROR4_(v85_2 + state[25] + ((v140 ^ v122_B) & (v140 + v5) ^ v122_B) + v106_C, 15);
        v107 = v90 + v6;
        v83_4 = input[16] | (input[17] << 8) | (input[18] << 16) | (input[19] << 24);
        v7 = ROR4_(v84_3 + state[26] + ((v90 ^ v140) & (v90 + v6) ^ v140) + v122_B, 11);
        v123 = v107 + v7;
        v82_5 = input[20] | (input[21] << 8) | (input[22] << 16) | (input[23] << 24);
        v8 = ROR4_(v83_4 + state[27] + ((v107 ^ v90) & (v107 + v7) ^ v90) + v140, 25);
        v141 = v123 + v8;
        v81_6 = input[24] | (input[25] << 8) | (input[26] << 16) | (input[27] << 24);
        v9 = ROR4_(v82_5 + state[28] + ((v123 ^ v107) & (v123 + v8) ^ v107) + v90, 20);
        v91 = v141 + v9;
        v80_7 = input[28] | (input[29] << 8) | (input[30] << 16) | (input[31] << 24);
        v10 = ROR4_(v81_6 + state[29] + ((v141 ^ v123) & (v141 + v9) ^ v123) + v107, 15);
        v108 = v91 + v10;
        v79_8 = input[32] | (input[33] << 8) | (input[34] << 16) | (input[35] << 24);
        v11 = ROR4_(v80_7 + state[30] + ((v91 ^ v141) & (v91 + v10) ^ v141) + v123, 12);
        v124 = v108 + v11;
        v78_9 = input[36] | (input[37] << 8) | (input[38] << 16) | (input[39] << 24);
        v12 = ROR4_(v79_8 + state[31] + ((v108 ^ v91) & (v108 + v11) ^ v91) + v141, 25);
        v142 = v124 + v12;
        v77_10 = input[40] | (input[41] << 8) | (input[42] << 16) | (input[43] << 24);
        v13 = ROR4_(v78_9 + state[32] + ((v124 ^ v108) & (v124 + v12) ^ v108) + v91, 20);
        v92 = v142 + v13;
        v76_11 = input[44] | (input[45] << 8) | (input[46] << 16) | (input[47] << 24);
        v14 = ROR4_(v77_10 + state[33] + ((v142 ^ v124) & (v142 + v13) ^ v124) + v108, 16);
        v109 = v92 + v14;
        v75_12 = input[48] | (input[49] << 8) | (input[50] << 16) | (input[51] << 24);
        v15 = ROR4_(v76_11 + state[34] + ((v92 ^ v142) & (v92 + v14) ^ v142) + v124, 10);
        v125 = v109 + v15;
        v74_13 = input[52] | (input[53] << 8) | (input[54] << 16) | (input[55] << 24);
        v16 = ROR4_(v75_12 + state[35] + ((v109 ^ v92) & (v109 + v15) ^ v92) + v142, 25);
        v143 = v125 + v16;
        v73_14 = input[56] | (input[57] << 8) | (input[58] << 16) | (input[59] << 24);
        v17 = ROR4_(v74_13 + state[36] + ((v125 ^ v109) & (v125 + v16) ^ v109) + v92, 19);
        v93 = v143 + v17;
        v88 = input[60] | (input[61] << 8) | (input[62] << 16);
        v18 = input + 63;
        input += 64;
        v72_15 = v88 | (*v18 << 24);
        v19 = ROR4_(v73_14 + state[37] + ((v143 ^ v125) & (v143 + v17) ^ v125) + v109, 15);
        v110 = v93 + v19;
        v20 = ROR4_(v72_15 + state[38] + ((v93 ^ v143) & (v93 + v19) ^ v143) + v125, 10);
        v126 = v110 + v20;
        v21 = ROR4_(v86_1 + (state[39] & 0xFF00FF00) + (((v110 + v20) ^ v110) & v93 ^ v110) + v143, 27);// round 1
        v144 = v126 + v21;
        v22 = ROR4_(v81_6 + state[40] + (((v126 + v21) ^ v126) & v110 ^ v126) + v93, 23);
        v94 = v144 + v22;
        v23 = ROR4_(v76_11 + state[41] + (((v144 + v22) ^ v144) & v126 ^ v144) + v110, 18);
        v111 = v94 + v23;
        v24 = ROR4_(v87_0 + (state[42] & 0xFF0011FF) + (((v94 + v23) ^ v94) & v144 ^ v94) + v126, 12);
        v127 = v111 + v24;
        v25 = ROR4_(v82_5 + state[43] + (((v111 + v24) ^ v111) & v94 ^ v111) + v144, 27);
        v145 = v127 + v25;
        v26 = ROR4_(v77_10 + state[44] + (((v127 + v25) ^ v127) & v111 ^ v127) + v94, 23);
        v95 = v145 + v26;
        v27 = ROR4_(v72_15 + state[45] + (((v145 + v26) ^ v145) & v127 ^ v145) + v111, 18);
        v112 = v95 + v27;
        v28 = ROR4_(v83_4 + state[46] + (((v95 + v27) ^ v95) & v145 ^ v95) + v127, 12);
        v128 = v112 + v28;
        v29 = ROR4_(v78_9 + state[47] + (((v112 + v28) ^ v112) & v95 ^ v112) + v145, 27);
        v146 = v128 + v29;
        v30 = ROR4_(v73_14 + state[48] + (((v128 + v29) ^ v128) & v112 ^ v128) + v95, 23);
        v96 = v146 + v30;
        v31 = ROR4_(v84_3 + state[49] + (((v146 + v30) ^ v146) & v128 ^ v146) + v112, 18);
        v113 = v96 + v31;
        v32 = ROR4_(v79_8 + state[50] + (((v96 + v31) ^ v96) & v146 ^ v96) + v128, 12);
        v129 = v113 + v32;
        v33 = ROR4_(v74_13 + state[51] + (((v113 + v32) ^ v113) & v96 ^ v113) + v146, 27);
        v147 = v129 + v33;
        v34 = ROR4_(v85_2 + (state[52] & 0xFF110011) + (((v129 + v33) ^ v129) & v113 ^ v129) + v96, 23);
        v97 = v147 + v34;
        v35 = ROR4_(v80_7 + state[53] + (((v147 + v34) ^ v147) & v129 ^ v147) + v113, 18);
        v114 = v97 + v35;
        v36 = ROR4_(v75_12 + state[54] + (((v97 + v35) ^ v97) & v147 ^ v97) + v129, 12);
        v130 = v114 + v36;
        v37 = ROR4_(v82_5 + state[55] + ((v114 + v36) ^ v114 ^ v97) + v147, 28);// round 2
        v148 = v130 + v37;
        v38 = ROR4_(v79_8 + state[56] + ((v130 + v37) ^ v130 ^ v114) + v97, 21);
        v98 = v148 + v38;
        v39 = ROR4_(v76_11 + state[57] + ((v148 + v38) ^ v148 ^ v130) + v114, 16);
        v115 = v98 + v39;
        v40 = ROR4_(v73_14 + state[58] + ((v98 + v39) ^ v98 ^ v148) + v130, 9);
        v131 = v115 + v40;
        v41 = ROR4_(v86_1 + state[59] + ((v115 + v40) ^ v115 ^ v98) + v148, 28);
        v149 = v131 + v41;
        v42 = ROR4_(v83_4 + state[60] + ((v131 + v41) ^ v131 ^ v115) + v98, 21);
        v99 = v149 + v42;
        v43 = ROR4_(v80_7 + state[61] + ((v149 + v42) ^ v149 ^ v131) + v115, 16);
        v116 = v99 + v43;
        v44 = ROR4_(v74_13 + state[63] + (v131 ^ (v99 + v43) ^ v99) + v149, 28);
        v150 = v131 + v44;
        v45 = ROR4_(v77_10 + state[62] + (v116 ^ v99 ^ (v131 + v44)) + v131, 9);
        v132 = v116 + v45;
        v46 = ROR4_(v84_3 + state[65] + (v99 ^ v150 ^ (v116 + v45)) + v116, 16);
        v117 = v99 + v46;
        v47 = ROR4_(v87_0 + state[64] + (v150 ^ v132 ^ (v99 + v46)) + v99, 21);
        v100 = v150 + v47;
        v48 = ROR4_(v81_6 + state[66] + (v117 ^ (v150 + v47) ^ v150) + v132, 9);
        v133 = v117 + v48;
        v49 = ROR4_(v78_9 + state[67] + ((v117 + v48) ^ v117 ^ v100) + v150, 28);
        v151 = v133 + v49;
        v50 = ROR4_(v75_12 + state[68] + ((v133 + v49) ^ v133 ^ v117) + v100, 21);
        v101 = v151 + v50;
        v51 = ROR4_(v72_15 + state[69] + ((v151 + v50) ^ v151 ^ v133) + v117, 16);
        v118 = v101 + v51;
        v52 = ROR4_(v85_2 + state[70] + ((v101 + v51) ^ v101 ^ v151) + v133, 9);
        v134 = v118 + v52;
        v53 = ROR4_(v87_0 + state[71] + (((v118 + v52) | ~v101) ^ v118) + v151, 26);// round 3
        v152 = v134 + v53;
        v54 = ROR4_(v80_7 + state[72] + (((v134 + v53) | ~v118) ^ v134) + v101, 22);
        v102 = v152 + v54;
        v55 = ROR4_(v73_14 + state[73] + (((v152 + v54) | ~v134) ^ v152) + v118, 17);
        v119 = v102 + v55;
        v56 = ROR4_(v82_5 + state[74] + (((v102 + v55) | ~v152) ^ v102) + v134, 11);
        v135 = v119 + v56;
        v57 = ROR4_(v75_12 + state[75] + (((v119 + v56) | ~v102) ^ v119) + v152, 26);
        v153 = v135 + v57;
        v58 = ROR4_(v84_3 + state[76] + (((v135 + v57) | ~v119) ^ v135) + v102, 22);
        v103 = v153 + v58;
        v59 = ROR4_(v77_10 + state[77] + (((v153 + v58) | ~v135) ^ v153) + v119, 17);
        v120 = v103 + v59;
        v60 = ROR4_(v86_1 + state[78] + (((v103 + v59) | ~v153) ^ v103) + v135, 11);
        v136 = v120 + v60;
        v61 = ROR4_(v79_8 + state[79] + (((v120 + v60) | ~v103) ^ v120) + v153, 26);
        v154 = v136 + v61;
        v62 = ROR4_(v72_15 + state[80] + (((v136 + v61) | ~v120) ^ v136) + v103, 22);
        v104 = v154 + v62;
        v63 = ROR4_(v81_6 + state[81] + (((v154 + v62) | ~v136) ^ v154) + v120, 17);
        v121 = v104 + v63;
        v64 = ROR4_(v74_13 + state[82] + (((v104 + v63) | ~v154) ^ v104) + v136, 11);
        v137 = v121 + v64;
        v65 = ROR4_(v83_4 + state[83] + (((v121 + v64) | ~v104) ^ v121) + v154, 26);
        v155 = v137 + v65;
        v66 = ROR4_(v76_11 + state[84] + (((v137 + v65) | ~v121) ^ v137) + v104, 22);
        v105 = v155 + v66;
        v67 = ROR4_(v85_2 + state[85] + (((v155 + v66) | ~v137) ^ v155) + v121, 17);
        v138 = v105 + v67 + ROR4_(v78_9 + state[86] + (((v105 + v67) | ~v155) ^ v105) + v137, 11);
        v68 = v155 + *state;
        *state = v68;
        v139_A = v68;
        v69 = v138 + state[1];
        state[1] = v69;
        v122_B = v69;
        v70 = v105 + v67 + state[2];
        state[2] = v70;
        v106_C = v70;
        v71 = v105 + state[3];
        state[3] = v71;
    }
    printf("%02x %02x %02x %02x",state[0],state[1],state[2],state[3]);
    return result;
}

int main(){
    int ctx[] = {
//            0x76543210, 0xFEDCBA98, 0x89ABCDEF ,0x01234567,
            0x10325476, 0x98badcfe, 0xefcdab89,0x67452301,
            0x00020000, 0x00000000, 0x00000000 ,0x00000000,
            0x00020000, 0x00000000, 0x00000000 ,0x00000000,
            0x00020000, 0x00000000, 0x00000000 ,0x00000000,
            0x00020000, 0x00000000, 0x00000000 ,0x00000000,
            0x00020000, 0x00000000, 0x00000000 ,
            0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf,
            0x4787c62a, 0xa8304613, 0xfd469501, 0x698098d8, 0x8b44f7af,
            0xffff5bb1, 0x895cd7be, 0x6b901122, 0xfd987193, 0xa679438e,
            0x49b40821, 0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
            0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8, 0x21e1cde6,
            0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8,
            0x676f02d9, 0x8d2a4c8a, 0xfffa3942, 0x8771f681, 0x6d9d6122,
            0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
            0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 0xd9d4d039,
            0xe6db99e5, 0x1fa27cf8, 0xc4ac5665, 0xf4292244, 0x432aff97,
            0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92, 0xffeff47d,
            0x85845dd1, 0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
            0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
    };

    char input[] = {
            0x6D,0xD2,0x6D,0x92,0x03,0x2A,0x89,0x83,0xBD,0xA6,0x04,0xF8,0x58,0x3E,0xC9,0xAD
            ,0x0B,0xA2,0x56,0x6C,0xF3,0xC7,0xF7,0xA4,0x26,0x96,0xBE,0x1A,0x63,0xDA,0x05,0x85
            ,0xDA,0xC4,0xB5,0xA4,0xA5,0x9A,0x9D,0xBE,0xF5,0x3B,0x29,0x2C,0x99,0x41,0x18,0xC8
            ,0xF4,0xED,0x3C,0xD6,0x62,0x22,0x19,0xA2,0xBD,0x6E,0xEE,0xA0,0xE9,0x72,0xE8,0xB5
    };
    MD5Transform_2CDA0(ctx, reinterpret_cast<unsigned char *>(input), 1);

}


