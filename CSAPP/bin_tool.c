#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bin_tool.h"

static char _buf[128];

void show_bytes(void *vptr, ssize_t nbytes)
{
    unsigned char *ptr = vptr;
    for (int i = nbytes - 1; i >= 0; i--)
        printf("%02x ", ptr[i]);
    printf("\n");
}

#define show_method_decl(_type_)    \
void show_##_type_(_type_ a)        \
{                                   \
    show_bytes(&a, sizeof(a));      \
}

show_method_decl(short)
show_method_decl(int)
show_method_decl(long)
show_method_decl(float)
show_method_decl(double)

#define INT_2_BIN_PROTOTYPE(_prefix_, _intype_)                         \
const char *_prefix_##ToBinaryString(_intype_ a, EN_BIN_TOOL_TYPE type) \
{                                                               \
    int size = sizeof(a) << 3;                                  \
    int i = size - 1, j = 0, m = 0, n = 0, groups = 0;          \
    int mod = 0;                                                \
                                                                \
    /* 忽略先导零 */                                              \
    if (type & ignore)                          \
    while(i > 0 && ((a >> i) & 1) == 0) i--;                   \
                                                                \
    /* 拼完 0 1 串 */                                            \
    while(i >= 0)                                               \
        _buf[j++] = ((a >> i--) & 1) + '0';                     \
    _buf[j] = 0;                                                \
                                                                \
    /* 要分成多少组？空格分隔 */                                    \
    groups = (type & eight) ? 8 : (type & four) ? 4 : 128;    \
    if (groups == 128)                                          \
    return _buf;                                                \
                                                                \
    /* 如果要分组，先找出余数 ->[xxx] xxxxxxxx xxxxxxxx... */       \
    mod = j % groups;                                           \
    char tmp[128];                                              \
    while (mod--) {                                             \
        tmp[n] = _buf[n];                                       \
        n++;                                                    \
    }                                                           \
    /* 此时 n == mod，但 mod 可能为 0 */                          \
    if (n != 0) {                                               \
        tmp[n++] = ' ';                                         \
        m = n - 1;                                              \
    }                                                           \
    /* 分组，用空格来分隔字符串 */                                  \
    mod = j % groups;                                           \
    while (m < j) {                                             \
        if (m - mod > 0 && (m - mod) % groups == 0)             \
            tmp[n++] = ' ';                                     \
            tmp[n++] = _buf[m++];                               \
    }                                                           \
    tmp[n] = 0;                                                 \
    memmove(_buf, tmp, n + 1);                                  \
    return _buf;                                                \
}

INT_2_BIN_PROTOTYPE(i64, TINT64)
INT_2_BIN_PROTOTYPE(i32, TINT32)
INT_2_BIN_PROTOTYPE(i16, TINT16)
INT_2_BIN_PROTOTYPE(i8, TINT8)

#define BIN_2_INT_PROTOTYPE(_inttype_, _suffix_)          \
_inttype_ binaryStringTo##_suffix_(const char *binary)    \
{                                                \
    _inttype_ reg = 0;                           \
    int size = sizeof(reg) << 3;                 \
    unsigned char c;                             \
    int i = 0, j = 0, k = 0;                     \
    size_t len = strlen(binary);                 \
    for (; k < len; k++) {                       \
        c = binary[len - k - 1];                 \
        j = c - '0';                             \
        if (c == ' ') continue;                  \
        if (j != 0 && j != 1)                    \
            goto invalid;                        \
        reg |= (j << i++);                       \
        if (i > size)                            \
            goto overflow;                       \
    }                                            \
    return reg;                                  \
invalid:                                                            \
    fprintf(stderr, "%s must be value of {1, 0, ' '}\n", binary);   \
    return 0;                                                       \
overflow:                                                           \
    fprintf(stderr, "%s cause overflow\n", binary);                 \
    return 0;                                                       \
}

BIN_2_INT_PROTOTYPE(TINT64, 64)
BIN_2_INT_PROTOTYPE(TINT32, 32)
BIN_2_INT_PROTOTYPE(TINT16, 16)
BIN_2_INT_PROTOTYPE(TINT8, 8)

BIN_2_INT_PROTOTYPE(TUINT64, U64)
BIN_2_INT_PROTOTYPE(TUINT32, U32)
BIN_2_INT_PROTOTYPE(TUINT16, U16)
BIN_2_INT_PROTOTYPE(TUINT8, U8)

const char *i64(TINT64 a)
{
    return i64ToBinaryString(a, eight | ignore);
}

const char *i32(TINT32 a)
{
    return i32ToBinaryString(a, eight | ignore);
}

const char *i16(TINT16 a)
{
    return i16ToBinaryString(a, eight | ignore);
}

const char *i8(TINT8 a)
{
    return i8ToBinaryString(a, eight | ignore);
}

const char *i64_(TINT64 a)
{
    return i64ToBinaryString(a, eight);
}

const char *i32_(TINT32 a)
{
    return i32ToBinaryString(a, eight);
}

const char *i16_(TINT16 a)
{
    return i16ToBinaryString(a, eight);
}

const char *i8_(TINT8 a)
{
    return i8ToBinaryString(a, eight);
}
/*********************** 无符号数 ****************************/
TUINT64 tou64(const char *binary)
{
    return binaryStringToU64(binary);
}

TUINT32 tou32(const char *binary)
{
    return binaryStringToU32(binary);
}

TUINT16 tou16(const char *binary)
{
    return binaryStringToU16(binary);
}

TUINT8 tou8(const char *binary)
{
    return binaryStringToU8(binary);
}

/*********************** 补码 ****************************/
TINT64 toi64(const char *binary)
{
    return binaryStringTo64(binary);
}

TINT32 toi32(const char *binary)
{
    return binaryStringTo32(binary);
}

TINT16 toi16(const char *binary)
{
    return binaryStringTo16(binary);
}

TINT8 toi8(const char *binary)
{
    return binaryStringTo8(binary);
}

double tod64(const char *binary)
{
    if (strlen(binary) < 64) {
        printf("tof64 wrong! len=%lu < 64 raw_str=%s\n",strlen(binary), binary);
        return 0;
    }
    unsigned long reg = 0;
    for (int j = 0, i = 63; i >= 0 ; j++) {
        if (binary[j] != '1' && binary[j] != '0')
            continue;
        reg |= (binary[j] - '0') << i--;
    }
    return *(double *)&reg;
}

float tof32(const char *binary)
{
    if (strlen(binary) < 32) {
        printf("tof32 wrong! len=%lu < 32 raw_str=%s\n",strlen(binary), binary);
        return 0;
    }
    unsigned int reg = 0;
    for (int j = 0, i = 31; i >= 0 ; j++) {
        if (binary[j] != '1' && binary[j] != '0')
            continue;
        reg |= (binary[j] - '0') << i--;
    }
    return *(float *)&reg;
}

const char *d64(double a)
{
    union {
        double d;
        struct double_t dt;
    } ud;
    ud.d = a;
    
    int i = 0;

    // 符号位
    _buf[i++] = ud.dt.s + '0';
    _buf[i++] = ' ';

    // 阶码位
    for (int j = 10; j >= 0; j--)
        _buf[i++] = ((ud.dt.e >> j) & 1) + '0';
    _buf[i++] = ' ';

    // 尾数位
    for (int j = 51; j >= 0; j--) 
       _buf[i++] = ((ud.dt.m >> j) & 1) + '0'; 
    _buf[i] = 0;
    return _buf;
}

const char *f32(float a)
{
    union {
        float f;
        struct float_t ft;
    } uf;
    uf.f = a;
    
    int i = 0;

    // 符号位
    _buf[i++] = uf.ft.s + '0';
    _buf[i++] = ' ';

    // 阶码位
    for (int j = 7; j >= 0; j--)
        _buf[i++] = ((uf.ft.e >> j) & 1) + '0';
    _buf[i++] = ' ';

    // 尾数位
    for (int j = 22; j >= 0; j--) 
       _buf[i++] = ((uf.ft.m >> j) & 1) + '0'; 
    _buf[i] = 0;
    return _buf;
}
