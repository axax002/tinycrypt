#include "api.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

#define RATE (64 / 8)
#define PA_ROUNDS 12

#define ROTR8(x, n) (((x) >> (n)) | ((x) << (8 - (n))))

#define COMPRESS_BYTE_ARRAY_8(a, var_7, var_6, var_5, var_4, var_3, var_2, \
                              var_1, var_0)                                \
  do {                                                                     \
    var_0 = a[7];                                                          \
    var_1 = var_0 >> 1;                                                    \
    var_2 = var_1 >> 1;                                                    \
    var_3 = var_2 >> 1;                                                    \
    var_4 = var_3 >> 1;                                                    \
    var_5 = var_4 >> 1;                                                    \
    var_6 = var_5 >> 1;                                                    \
    var_7 = var_6 >> 1;                                                    \
    var_0 &= 1;                                                            \
    var_1 &= 1;                                                            \
    var_2 &= 1;                                                            \
    var_3 &= 1;                                                            \
    var_4 &= 1;                                                            \
    var_5 &= 1;                                                            \
    var_6 &= 1;                                                            \
    var_7 &= 1;                                                            \
    t1_0 = a[6] << 1;                                                      \
    t1_1 = a[6];                                                           \
    t1_2 = t1_1 >> 1;                                                      \
    t1_3 = t1_2 >> 1;                                                      \
    t1_4 = t1_3 >> 1;                                                      \
    t1_5 = t1_4 >> 1;                                                      \
    t1_6 = t1_5 >> 1;                                                      \
    t1_7 = t1_6 >> 1;                                                      \
    var_0 |= t1_0 & 2;                                                     \
    var_1 |= t1_1 & 2;                                                     \
    var_2 |= t1_2 & 2;                                                     \
    var_3 |= t1_3 & 2;                                                     \
    var_4 |= t1_4 & 2;                                                     \
    var_5 |= t1_5 & 2;                                                     \
    var_6 |= t1_6 & 2;                                                     \
    var_7 |= t1_7 & 2;                                                     \
    t1_1 = a[5] << 1;                                                      \
    t1_0 = t1_1 << 1;                                                      \
    t1_2 = a[5];                                                           \
    t1_3 = t1_2 >> 1;                                                      \
    t1_4 = t1_3 >> 1;                                                      \
    t1_5 = t1_4 >> 1;                                                      \
    t1_6 = t1_5 >> 1;                                                      \
    t1_7 = t1_6 >> 1;                                                      \
    var_0 |= t1_0 & 4;                                                     \
    var_1 |= t1_1 & 4;                                                     \
    var_2 |= t1_2 & 4;                                                     \
    var_3 |= t1_3 & 4;                                                     \
    var_4 |= t1_4 & 4;                                                     \
    var_5 |= t1_5 & 4;                                                     \
    var_6 |= t1_6 & 4;                                                     \
    var_7 |= t1_7 & 4;                                                     \
    t1_2 = a[4] << 1;                                                      \
    t1_1 = t1_2 << 1;                                                      \
    t1_0 = t1_1 << 1;                                                      \
    t1_3 = a[4];                                                           \
    t1_4 = t1_3 >> 1;                                                      \
    t1_5 = t1_4 >> 1;                                                      \
    t1_6 = t1_5 >> 1;                                                      \
    t1_7 = t1_6 >> 1;                                                      \
    var_0 |= t1_0 & 8;                                                     \
    var_1 |= t1_1 & 8;                                                     \
    var_2 |= t1_2 & 8;                                                     \
    var_3 |= t1_3 & 8;                                                     \
    var_4 |= t1_4 & 8;                                                     \
    var_5 |= t1_5 & 8;                                                     \
    var_6 |= t1_6 & 8;                                                     \
    var_7 |= t1_7 & 8;                                                     \
    t1_3 = a[3] << 1;                                                      \
    t1_2 = t1_3 << 1;                                                      \
    t1_1 = t1_2 << 1;                                                      \
    t1_0 = t1_1 << 1;                                                      \
    t1_4 = a[3];                                                           \
    t1_5 = t1_4 >> 1;                                                      \
    t1_6 = t1_5 >> 1;                                                      \
    t1_7 = t1_6 >> 1;                                                      \
    var_0 |= t1_0 & 16;                                                    \
    var_1 |= t1_1 & 16;                                                    \
    var_2 |= t1_2 & 16;                                                    \
    var_3 |= t1_3 & 16;                                                    \
    var_4 |= t1_4 & 16;                                                    \
    var_5 |= t1_5 & 16;                                                    \
    var_6 |= t1_6 & 16;                                                    \
    var_7 |= t1_7 & 16;                                                    \
    t1_4 = a[2] << 1;                                                      \
    t1_3 = t1_4 << 1;                                                      \
    t1_2 = t1_3 << 1;                                                      \
    t1_1 = t1_2 << 1;                                                      \
    t1_0 = t1_1 << 1;                                                      \
    t1_5 = a[2];                                                           \
    t1_6 = t1_5 >> 1;                                                      \
    t1_7 = t1_6 >> 1;                                                      \
    var_0 |= t1_0 & 32;                                                    \
    var_1 |= t1_1 & 32;                                                    \
    var_2 |= t1_2 & 32;                                                    \
    var_3 |= t1_3 & 32;                                                    \
    var_4 |= t1_4 & 32;                                                    \
    var_5 |= t1_5 & 32;                                                    \
    var_6 |= t1_6 & 32;                                                    \
    var_7 |= t1_7 & 32;                                                    \
    t1_5 = a[1] << 1;                                                      \
    t1_4 = t1_5 << 1;                                                      \
    t1_3 = t1_4 << 1;                                                      \
    t1_2 = t1_3 << 1;                                                      \
    t1_1 = t1_2 << 1;                                                      \
    t1_0 = t1_1 << 1;                                                      \
    t1_6 = a[1];                                                           \
    t1_7 = t1_6 >> 1;                                                      \
    var_0 |= t1_0 & 64;                                                    \
    var_1 |= t1_1 & 64;                                                    \
    var_2 |= t1_2 & 64;                                                    \
    var_3 |= t1_3 & 64;                                                    \
    var_4 |= t1_4 & 64;                                                    \
    var_5 |= t1_5 & 64;                                                    \
    var_6 |= t1_6 & 64;                                                    \
    var_7 |= t1_7 & 64;                                                    \
    t1_6 = a[0] << 1;                                                      \
    t1_5 = t1_6 << 1;                                                      \
    t1_4 = t1_5 << 1;                                                      \
    t1_3 = t1_4 << 1;                                                      \
    t1_2 = t1_3 << 1;                                                      \
    t1_1 = t1_2 << 1;                                                      \
    t1_0 = t1_1 << 1;                                                      \
    t1_7 = a[0];                                                           \
    var_0 |= t1_0 & 128;                                                   \
    var_1 |= t1_1 & 128;                                                   \
    var_2 |= t1_2 & 128;                                                   \
    var_3 |= t1_3 & 128;                                                   \
    var_4 |= t1_4 & 128;                                                   \
    var_5 |= t1_5 & 128;                                                   \
    var_6 |= t1_6 & 128;                                                   \
    var_7 |= t1_7 & 128;                                                   \
  } while (0)

#define EXPAND_BYTE_ARRAY_8(a, var_7, var_6, var_5, var_4, var_3, var_2, \
                            var_1, var_0)                                \
  do {                                                                   \
    a[7] = var_0 & 1;                                                    \
    t1_0 = var_0 >> 1;                                                   \
    a[6] = t1_0 & 1;                                                     \
    t1_0 >>= 1;                                                          \
    a[5] = t1_0 & 1;                                                     \
    t1_0 >>= 1;                                                          \
    a[4] = t1_0 & 1;                                                     \
    t1_0 >>= 1;                                                          \
    a[3] = t1_0 & 1;                                                     \
    t1_0 >>= 1;                                                          \
    a[2] = t1_0 & 1;                                                     \
    t1_0 >>= 1;                                                          \
    a[1] = t1_0 & 1;                                                     \
    t1_0 >>= 1;                                                          \
    a[0] = t1_0 & 1;                                                     \
    a[6] |= var_1 & 2;                                                   \
    t1_1 = var_1 << 1;                                                   \
    a[7] |= t1_1 & 2;                                                    \
    t1_1 = var_1 >> 1;                                                   \
    a[5] |= t1_1 & 2;                                                    \
    t1_1 >>= 1;                                                          \
    a[4] |= t1_1 & 2;                                                    \
    t1_1 >>= 1;                                                          \
    a[3] |= t1_1 & 2;                                                    \
    t1_1 >>= 1;                                                          \
    a[2] |= t1_1 & 2;                                                    \
    t1_1 >>= 1;                                                          \
    a[1] |= t1_1 & 2;                                                    \
    t1_1 >>= 1;                                                          \
    a[0] |= t1_1 & 2;                                                    \
    a[5] |= var_2 & 4;                                                   \
    t1_2 = var_2 << 1;                                                   \
    a[6] |= t1_2 & 4;                                                    \
    t1_2 <<= 1;                                                          \
    a[7] |= t1_2 & 4;                                                    \
    t1_2 = var_2 >> 1;                                                   \
    a[4] |= t1_2 & 4;                                                    \
    t1_2 >>= 1;                                                          \
    a[3] |= t1_2 & 4;                                                    \
    t1_2 >>= 1;                                                          \
    a[2] |= t1_2 & 4;                                                    \
    t1_2 >>= 1;                                                          \
    a[1] |= t1_2 & 4;                                                    \
    t1_2 >>= 1;                                                          \
    a[0] |= t1_2 & 4;                                                    \
    a[4] |= var_3 & 8;                                                   \
    t1_3 = var_3 << 1;                                                   \
    a[5] |= t1_3 & 8;                                                    \
    t1_3 <<= 1;                                                          \
    a[6] |= t1_3 & 8;                                                    \
    t1_3 <<= 1;                                                          \
    a[7] |= t1_3 & 8;                                                    \
    t1_3 = var_3 >> 1;                                                   \
    a[3] |= t1_3 & 8;                                                    \
    t1_3 >>= 1;                                                          \
    a[2] |= t1_3 & 8;                                                    \
    t1_3 >>= 1;                                                          \
    a[1] |= t1_3 & 8;                                                    \
    t1_3 >>= 1;                                                          \
    a[0] |= t1_3 & 8;                                                    \
    a[3] |= var_4 & 16;                                                  \
    t1_4 = var_4 << 1;                                                   \
    a[4] |= t1_4 & 16;                                                   \
    t1_4 <<= 1;                                                          \
    a[5] |= t1_4 & 16;                                                   \
    t1_4 <<= 1;                                                          \
    a[6] |= t1_4 & 16;                                                   \
    t1_4 <<= 1;                                                          \
    a[7] |= t1_4 & 16;                                                   \
    t1_4 = var_4 >> 1;                                                   \
    a[2] |= t1_4 & 16;                                                   \
    t1_4 >>= 1;                                                          \
    a[1] |= t1_4 & 16;                                                   \
    t1_4 >>= 1;                                                          \
    a[0] |= t1_4 & 16;                                                   \
    a[2] |= var_5 & 32;                                                  \
    t1_5 = var_5 << 1;                                                   \
    a[3] |= t1_5 & 32;                                                   \
    t1_5 <<= 1;                                                          \
    a[4] |= t1_5 & 32;                                                   \
    t1_5 <<= 1;                                                          \
    a[5] |= t1_5 & 32;                                                   \
    t1_5 <<= 1;                                                          \
    a[6] |= t1_5 & 32;                                                   \
    t1_5 <<= 1;                                                          \
    a[7] |= t1_5 & 32;                                                   \
    t1_5 = var_5 >> 1;                                                   \
    a[1] |= t1_5 & 32;                                                   \
    t1_5 >>= 1;                                                          \
    a[0] |= t1_5 & 32;                                                   \
    a[1] |= var_6 & 64;                                                  \
    t1_6 = var_6 << 1;                                                   \
    a[2] |= t1_6 & 64;                                                   \
    t1_6 <<= 1;                                                          \
    a[3] |= t1_6 & 64;                                                   \
    t1_6 <<= 1;                                                          \
    a[4] |= t1_6 & 64;                                                   \
    t1_6 <<= 1;                                                          \
    a[5] |= t1_6 & 64;                                                   \
    t1_6 <<= 1;                                                          \
    a[6] |= t1_6 & 64;                                                   \
    t1_6 <<= 1;                                                          \
    a[7] |= t1_6 & 64;                                                   \
    t1_6 = var_6 >> 1;                                                   \
    a[0] |= t1_6 & 64;                                                   \
    a[0] |= var_7 & 128;                                                 \
    t1_7 = var_7 << 1;                                                   \
    a[1] |= t1_7 & 128;                                                  \
    t1_7 <<= 1;                                                          \
    a[2] |= t1_7 & 128;                                                  \
    t1_7 <<= 1;                                                          \
    a[3] |= t1_7 & 128;                                                  \
    t1_7 <<= 1;                                                          \
    a[4] |= t1_7 & 128;                                                  \
    t1_7 <<= 1;                                                          \
    a[5] |= t1_7 & 128;                                                  \
    t1_7 <<= 1;                                                          \
    a[6] |= t1_7 & 128;                                                  \
    t1_7 <<= 1;                                                          \
    a[7] |= t1_7 & 128;                                                  \
  } while (0)

// This way of implementing Ascon's S-box was inpired by personal communication
// with Joan Daemen about implementing the 3-bit chi layer.
#define ROUND_16(C_7, C_6, C_5, C_4, C_3, C_2, C_1, C_0) \
  do {                                                   \
    /* round constant */                                 \
    x2_0 ^= C_0;                                         \
    x2_1 ^= C_1;                                         \
    x2_2 ^= C_2;                                         \
    x2_3 ^= C_3;                                         \
    x2_4 ^= C_4;                                         \
    x2_5 ^= C_5;                                         \
    x2_6 ^= C_6;                                         \
    x2_7 ^= C_7;                                         \
    /* s-box layer */                                    \
    x0_0 ^= x4_0;                                        \
    x4_0 ^= x3_0;                                        \
    x2_0 ^= x1_0;                                        \
    t0_0 = x0_0 & (~x4_0);                               \
    t1_0 = x2_0 & (~x1_0);                               \
    x0_0 ^= t1_0;                                        \
    t1_0 = x4_0 & (~x3_0);                               \
    x2_0 ^= t1_0;                                        \
    t1_0 = x1_0 & (~x0_0);                               \
    x4_0 ^= t1_0;                                        \
    t1_0 = x3_0 & (~x2_0);                               \
    x1_0 ^= t1_0;                                        \
    x3_0 ^= t0_0;                                        \
    x1_0 ^= x0_0;                                        \
    x3_0 ^= x2_0;                                        \
    x0_0 ^= x4_0;                                        \
    x2_0 = ~x2_0;                                        \
    x0_1 ^= x4_1;                                        \
    x4_1 ^= x3_1;                                        \
    x2_1 ^= x1_1;                                        \
    t0_0 = x0_1 & (~x4_1);                               \
    t1_0 = x2_1 & (~x1_1);                               \
    x0_1 ^= t1_0;                                        \
    t1_0 = x4_1 & (~x3_1);                               \
    x2_1 ^= t1_0;                                        \
    t1_0 = x1_1 & (~x0_1);                               \
    x4_1 ^= t1_0;                                        \
    t1_0 = x3_1 & (~x2_1);                               \
    x1_1 ^= t1_0;                                        \
    x3_1 ^= t0_0;                                        \
    x1_1 ^= x0_1;                                        \
    x3_1 ^= x2_1;                                        \
    x0_1 ^= x4_1;                                        \
    x2_1 = ~x2_1;                                        \
    x0_2 ^= x4_2;                                        \
    x4_2 ^= x3_2;                                        \
    x2_2 ^= x1_2;                                        \
    t0_0 = x0_2 & (~x4_2);                               \
    t1_0 = x2_2 & (~x1_2);                               \
    x0_2 ^= t1_0;                                        \
    t1_0 = x4_2 & (~x3_2);                               \
    x2_2 ^= t1_0;                                        \
    t1_0 = x1_2 & (~x0_2);                               \
    x4_2 ^= t1_0;                                        \
    t1_0 = x3_2 & (~x2_2);                               \
    x1_2 ^= t1_0;                                        \
    x3_2 ^= t0_0;                                        \
    x1_2 ^= x0_2;                                        \
    x3_2 ^= x2_2;                                        \
    x0_2 ^= x4_2;                                        \
    x2_2 = ~x2_2;                                        \
    x0_3 ^= x4_3;                                        \
    x4_3 ^= x3_3;                                        \
    x2_3 ^= x1_3;                                        \
    t0_0 = x0_3 & (~x4_3);                               \
    t1_0 = x2_3 & (~x1_3);                               \
    x0_3 ^= t1_0;                                        \
    t1_0 = x4_3 & (~x3_3);                               \
    x2_3 ^= t1_0;                                        \
    t1_0 = x1_3 & (~x0_3);                               \
    x4_3 ^= t1_0;                                        \
    t1_0 = x3_3 & (~x2_3);                               \
    x1_3 ^= t1_0;                                        \
    x3_3 ^= t0_0;                                        \
    x1_3 ^= x0_3;                                        \
    x3_3 ^= x2_3;                                        \
    x0_3 ^= x4_3;                                        \
    x2_3 = ~x2_3;                                        \
    x0_4 ^= x4_4;                                        \
    x4_4 ^= x3_4;                                        \
    x2_4 ^= x1_4;                                        \
    t0_0 = x0_4 & (~x4_4);                               \
    t1_0 = x2_4 & (~x1_4);                               \
    x0_4 ^= t1_0;                                        \
    t1_0 = x4_4 & (~x3_4);                               \
    x2_4 ^= t1_0;                                        \
    t1_0 = x1_4 & (~x0_4);                               \
    x4_4 ^= t1_0;                                        \
    t1_0 = x3_4 & (~x2_4);                               \
    x1_4 ^= t1_0;                                        \
    x3_4 ^= t0_0;                                        \
    x1_4 ^= x0_4;                                        \
    x3_4 ^= x2_4;                                        \
    x0_4 ^= x4_4;                                        \
    x2_4 = ~x2_4;                                        \
    x0_5 ^= x4_5;                                        \
    x4_5 ^= x3_5;                                        \
    x2_5 ^= x1_5;                                        \
    t0_0 = x0_5 & (~x4_5);                               \
    t1_0 = x2_5 & (~x1_5);                               \
    x0_5 ^= t1_0;                                        \
    t1_0 = x4_5 & (~x3_5);                               \
    x2_5 ^= t1_0;                                        \
    t1_0 = x1_5 & (~x0_5);                               \
    x4_5 ^= t1_0;                                        \
    t1_0 = x3_5 & (~x2_5);                               \
    x1_5 ^= t1_0;                                        \
    x3_5 ^= t0_0;                                        \
    x1_5 ^= x0_5;                                        \
    x3_5 ^= x2_5;                                        \
    x0_5 ^= x4_5;                                        \
    x2_5 = ~x2_5;                                        \
    x0_6 ^= x4_6;                                        \
    x4_6 ^= x3_6;                                        \
    x2_6 ^= x1_6;                                        \
    t0_0 = x0_6 & (~x4_6);                               \
    t1_0 = x2_6 & (~x1_6);                               \
    x0_6 ^= t1_0;                                        \
    t1_0 = x4_6 & (~x3_6);                               \
    x2_6 ^= t1_0;                                        \
    t1_0 = x1_6 & (~x0_6);                               \
    x4_6 ^= t1_0;                                        \
    t1_0 = x3_6 & (~x2_6);                               \
    x1_6 ^= t1_0;                                        \
    x3_6 ^= t0_0;                                        \
    x1_6 ^= x0_6;                                        \
    x3_6 ^= x2_6;                                        \
    x0_6 ^= x4_6;                                        \
    x2_6 = ~x2_6;                                        \
    x0_7 ^= x4_7;                                        \
    x4_7 ^= x3_7;                                        \
    x2_7 ^= x1_7;                                        \
    t0_0 = x0_7 & (~x4_7);                               \
    t1_0 = x2_7 & (~x1_7);                               \
    x0_7 ^= t1_0;                                        \
    t1_0 = x4_7 & (~x3_7);                               \
    x2_7 ^= t1_0;                                        \
    t1_0 = x1_7 & (~x0_7);                               \
    x4_7 ^= t1_0;                                        \
    t1_0 = x3_7 & (~x2_7);                               \
    x1_7 ^= t1_0;                                        \
    x3_7 ^= t0_0;                                        \
    x1_7 ^= x0_7;                                        \
    x3_7 ^= x2_7;                                        \
    x0_7 ^= x4_7;                                        \
    x2_7 = ~x2_7;                                        \
    /* linear layer */                                   \
    t0_0 = x0_0;                                         \
    t0_1 = x0_1;                                         \
    t0_2 = x0_2;                                         \
    t0_3 = x0_3;                                         \
    t0_4 = x0_4;                                         \
    t0_5 = x0_5;                                         \
    t0_6 = x0_6;                                         \
    t0_7 = x0_7;                                         \
    x0_5 ^= ROTR8(t0_0, 3);                              \
    x0_6 ^= ROTR8(t0_1, 3);                              \
    x0_7 ^= ROTR8(t0_2, 3);                              \
    x0_0 ^= ROTR8(t0_3, 2);                              \
    x0_1 ^= ROTR8(t0_4, 2);                              \
    x0_2 ^= ROTR8(t0_5, 2);                              \
    x0_3 ^= ROTR8(t0_6, 2);                              \
    x0_4 ^= ROTR8(t0_7, 2);                              \
    x0_4 ^= ROTR8(t0_0, 4);                              \
    x0_5 ^= ROTR8(t0_1, 4);                              \
    x0_6 ^= ROTR8(t0_2, 4);                              \
    x0_7 ^= ROTR8(t0_3, 4);                              \
    x0_0 ^= ROTR8(t0_4, 3);                              \
    x0_1 ^= ROTR8(t0_5, 3);                              \
    x0_2 ^= ROTR8(t0_6, 3);                              \
    x0_3 ^= ROTR8(t0_7, 3);                              \
    t0_0 = x1_0;                                         \
    t0_1 = x1_1;                                         \
    t0_2 = x1_2;                                         \
    t0_3 = x1_3;                                         \
    t0_4 = x1_4;                                         \
    t0_5 = x1_5;                                         \
    t0_6 = x1_6;                                         \
    t0_7 = x1_7;                                         \
    x1_3 ^= t0_0;                                        \
    x1_4 ^= t0_1;                                        \
    x1_5 ^= t0_2;                                        \
    x1_6 ^= t0_3;                                        \
    x1_7 ^= t0_4;                                        \
    x1_0 ^= ROTR8(t0_5, 7);                              \
    x1_1 ^= ROTR8(t0_6, 7);                              \
    x1_2 ^= ROTR8(t0_7, 7);                              \
    x1_1 ^= ROTR8(t0_0, 5);                              \
    x1_2 ^= ROTR8(t0_1, 5);                              \
    x1_3 ^= ROTR8(t0_2, 5);                              \
    x1_4 ^= ROTR8(t0_3, 5);                              \
    x1_5 ^= ROTR8(t0_4, 5);                              \
    x1_6 ^= ROTR8(t0_5, 5);                              \
    x1_7 ^= ROTR8(t0_6, 5);                              \
    x1_0 ^= ROTR8(t0_7, 4);                              \
    t0_0 = x2_0;                                         \
    t0_1 = x2_1;                                         \
    t0_2 = x2_2;                                         \
    t0_3 = x2_3;                                         \
    t0_4 = x2_4;                                         \
    t0_5 = x2_5;                                         \
    t0_6 = x2_6;                                         \
    t0_7 = x2_7;                                         \
    x2_7 ^= ROTR8(t0_0, 1);                              \
    x2_0 ^= t0_1;                                        \
    x2_1 ^= t0_2;                                        \
    x2_2 ^= t0_3;                                        \
    x2_3 ^= t0_4;                                        \
    x2_4 ^= t0_5;                                        \
    x2_5 ^= t0_6;                                        \
    x2_6 ^= t0_7;                                        \
    x2_2 ^= ROTR8(t0_0, 1);                              \
    x2_3 ^= ROTR8(t0_1, 1);                              \
    x2_4 ^= ROTR8(t0_2, 1);                              \
    x2_5 ^= ROTR8(t0_3, 1);                              \
    x2_6 ^= ROTR8(t0_4, 1);                              \
    x2_7 ^= ROTR8(t0_5, 1);                              \
    x2_0 ^= t0_6;                                        \
    x2_1 ^= t0_7;                                        \
    t0_0 = x3_0;                                         \
    t0_1 = x3_1;                                         \
    t0_2 = x3_2;                                         \
    t0_3 = x3_3;                                         \
    t0_4 = x3_4;                                         \
    t0_5 = x3_5;                                         \
    t0_6 = x3_6;                                         \
    t0_7 = x3_7;                                         \
    x3_6 ^= ROTR8(t0_0, 2);                              \
    x3_7 ^= ROTR8(t0_1, 2);                              \
    x3_0 ^= ROTR8(t0_2, 1);                              \
    x3_1 ^= ROTR8(t0_3, 1);                              \
    x3_2 ^= ROTR8(t0_4, 1);                              \
    x3_3 ^= ROTR8(t0_5, 1);                              \
    x3_4 ^= ROTR8(t0_6, 1);                              \
    x3_5 ^= ROTR8(t0_7, 1);                              \
    x3_7 ^= ROTR8(t0_0, 3);                              \
    x3_0 ^= ROTR8(t0_1, 2);                              \
    x3_1 ^= ROTR8(t0_2, 2);                              \
    x3_2 ^= ROTR8(t0_3, 2);                              \
    x3_3 ^= ROTR8(t0_4, 2);                              \
    x3_4 ^= ROTR8(t0_5, 2);                              \
    x3_5 ^= ROTR8(t0_6, 2);                              \
    x3_6 ^= ROTR8(t0_7, 2);                              \
    t0_0 = x4_0;                                         \
    t0_1 = x4_1;                                         \
    t0_2 = x4_2;                                         \
    t0_3 = x4_3;                                         \
    t0_4 = x4_4;                                         \
    t0_5 = x4_5;                                         \
    t0_6 = x4_6;                                         \
    t0_7 = x4_7;                                         \
    x4_1 ^= ROTR8(t0_0, 1);                              \
    x4_2 ^= ROTR8(t0_1, 1);                              \
    x4_3 ^= ROTR8(t0_2, 1);                              \
    x4_4 ^= ROTR8(t0_3, 1);                              \
    x4_5 ^= ROTR8(t0_4, 1);                              \
    x4_6 ^= ROTR8(t0_5, 1);                              \
    x4_7 ^= ROTR8(t0_6, 1);                              \
    x4_0 ^= t0_7;                                        \
    x4_7 ^= ROTR8(t0_0, 6);                              \
    x4_0 ^= ROTR8(t0_1, 5);                              \
    x4_1 ^= ROTR8(t0_2, 5);                              \
    x4_2 ^= ROTR8(t0_3, 5);                              \
    x4_3 ^= ROTR8(t0_4, 5);                              \
    x4_4 ^= ROTR8(t0_5, 5);                              \
    x4_5 ^= ROTR8(t0_6, 5);                              \
    x4_6 ^= ROTR8(t0_7, 5);                              \
  } while (0)

#define P12_8                         \
  do {                                \
    ROUND_16(1, 1, 1, 1, 0, 0, 0, 0); \
    ROUND_16(1, 1, 1, 0, 0, 0, 0, 1); \
    ROUND_16(1, 1, 0, 1, 0, 0, 1, 0); \
    ROUND_16(1, 1, 0, 0, 0, 0, 1, 1); \
    ROUND_16(1, 0, 1, 1, 0, 1, 0, 0); \
    ROUND_16(1, 0, 1, 0, 0, 1, 0, 1); \
    ROUND_16(1, 0, 0, 1, 0, 1, 1, 0); \
    ROUND_16(1, 0, 0, 0, 0, 1, 1, 1); \
    ROUND_16(0, 1, 1, 1, 1, 0, 0, 0); \
    ROUND_16(0, 1, 1, 0, 1, 0, 0, 1); \
    ROUND_16(0, 1, 0, 1, 1, 0, 1, 0); \
    ROUND_16(0, 1, 0, 0, 1, 0, 1, 1); \
  } while (0)

int crypto_hash(unsigned char *out, const unsigned char *in,
                unsigned long long inlen) {
  u64 rlen;
  u64 i;

  u8 buffer[8];

  u8 x0_0, x1_0, x2_0, x3_0, x4_0;
  u8 t0_0, t1_0;

  u8 x0_1, x1_1, x2_1, x3_1, x4_1;
  u8 t0_1, t1_1;

  u8 x0_2, x1_2, x2_2, x3_2, x4_2;
  u8 t0_2, t1_2;

  u8 x0_3, x1_3, x2_3, x3_3, x4_3;
  u8 t0_3, t1_3;

  u8 x0_4, x1_4, x2_4, x3_4, x4_4;
  u8 t0_4, t1_4;

  u8 x0_5, x1_5, x2_5, x3_5, x4_5;
  u8 t0_5, t1_5;

  u8 x0_6, x1_6, x2_6, x3_6, x4_6;
  u8 t0_6, t1_6;

  u8 x0_7, x1_7, x2_7, x3_7, x4_7;
  u8 t0_7, t1_7;

  u8 in_0, in_1, in_2, in_3, in_4, in_5, in_6, in_7;

  // initialization
  x0_0 = 0x4d;
  x0_1 = 0xdc;
  x0_2 = 0x85;
  x0_3 = 0xb9;
  x0_4 = 0x6b;
  x0_5 = 0x97;
  x0_6 = 0x8e;
  x0_7 = 0xfa;
  x1_0 = 0x94;
  x1_1 = 0xcd;
  x1_2 = 0xc;
  x1_3 = 0xa4;
  x1_4 = 0x72;
  x1_5 = 0x50;
  x1_6 = 0x8;
  x1_7 = 0xc8;
  x2_0 = 0x14;
  x2_1 = 0x73;
  x2_2 = 0x84;
  x2_3 = 0x5a;
  x2_4 = 0xbe;
  x2_5 = 0x81;
  x2_6 = 0x17;
  x2_7 = 0xfe;
  x3_0 = 0xb2;
  x3_1 = 0x82;
  x3_2 = 0x0;
  x3_3 = 0x6d;
  x3_4 = 0x6c;
  x3_5 = 0x1f;
  x3_6 = 0x87;
  x3_7 = 0x2f;
  x4_0 = 0x7e;
  x4_1 = 0x40;
  x4_2 = 0xec;
  x4_3 = 0x50;
  x4_4 = 0x88;
  x4_5 = 0xa6;
  x4_6 = 0x1b;
  x4_7 = 0x7a;

  // absorb
  rlen = inlen;
  while (rlen >= RATE) {
    COMPRESS_BYTE_ARRAY_8(in, in_7, in_6, in_5, in_4, in_3, in_2, in_1, in_0);
    x0_0 ^= in_0;
    x0_1 ^= in_1;
    x0_2 ^= in_2;
    x0_3 ^= in_3;
    x0_4 ^= in_4;
    x0_5 ^= in_5;
    x0_6 ^= in_6;
    x0_7 ^= in_7;
    P12_8;
    rlen -= RATE;
    in += RATE;
  }
  for (i = 0; i < rlen; ++i, ++in) buffer[i] = *in;
  buffer[rlen] = 0x80;
  for (i = rlen + 1; i < 8; ++i) buffer[i] = 0;
  COMPRESS_BYTE_ARRAY_8(buffer, in_7, in_6, in_5, in_4, in_3, in_2, in_1, in_0);
  x0_0 ^= in_0;
  x0_1 ^= in_1;
  x0_2 ^= in_2;
  x0_3 ^= in_3;
  x0_4 ^= in_4;
  x0_5 ^= in_5;
  x0_6 ^= in_6;
  x0_7 ^= in_7;
  P12_8;

  // squeeze (full blocks)
  rlen = CRYPTO_BYTES;
  while (rlen > RATE) {
    EXPAND_BYTE_ARRAY_8(out, x0_7, x0_6, x0_5, x0_4, x0_3, x0_2, x0_1, x0_0);
    P12_8;
    rlen -= RATE;
    out += RATE;
  }
  EXPAND_BYTE_ARRAY_8(out, x0_7, x0_6, x0_5, x0_4, x0_3, x0_2, x0_1, x0_0);

  return 0;
}

