#ifndef _BIN_TOOL_H_
#define _BIN_TOOL_H_

#ifndef YXH_TYPE_DEF
#define YXH_TYPE_DEF
typedef long               TINT64;
typedef int                TINT32;
typedef short              TINT16;
typedef char               TINT8;

typedef unsigned long      TUINT64;
typedef unsigned int       TUINT32;
typedef unsigned short     TUINT16;
typedef unsigned char      TUINT8;

typedef struct float_t {
    unsigned int m : 23;
    unsigned short e : 8;  /* 这里如果定义为 char 型，编译器会生成错误的代码 */
    unsigned char s : 1;
} float_t;

typedef struct double_t {
    unsigned long m : 52;
    unsigned short e : 11;
    unsigned char s : 1;
} double_t;
#else
#error "what a fuck?!"
#endif

typedef enum EN_BIN_TOOL_TYPE {
    ignore     = 1 << 0,
    four       = 1 << 1,
    eight      = 1 << 2
} EN_BIN_TOOL_TYPE;

const char *f32(float a);
const char *d64(double a);
float tof32(const char *binary);
double tod64(const char *binary);

const char *i64(TINT64);
const char *i32(TINT32);
const char *i16(TINT16);
const char *i8(TINT8);
const char *i64_(TINT64);
const char *i32_(TINT32);
const char *i16_(TINT16);
const char *i8_(TINT8);

/*************** 补码 ********************/
TINT64 toi64(const char *binary);
TINT32 toi32(const char *binary);
TINT16 toi16(const char *binary);
TINT8 toi8(const char *binary);

/*************** 无符号数 ********************/
TUINT64 tou64(const char *binary);
TUINT32 tou32(const char *binary);
TUINT16 tou16(const char *binary);
TUINT8 tou8(const char *binary);

/************** show_bytes ****************/
void show_bytes(void *vptr, ssize_t nbytes);
void show_short(short a);
void show_int(int a);
void show_long(long a);
void show_float(float a);
void show_double(double a);

/****************** 原有的接口 *************************/
TINT64 binaryStringTo64(const char *binary);
TINT32 binaryStringTo32(const char *binary);
TINT16 binaryStringTo16(const char *binary);
TINT8 binaryStringTo8(const char *binary);

TUINT64 binaryStringToU64(const char *binary);
TUINT32 binaryStringToU32(const char *binary);
TUINT16 binaryStringToU16(const char *binary);
TUINT8 binaryStringToU8(const char *binary);

const char *i64ToBinaryString(TINT64, EN_BIN_TOOL_TYPE type);
const char *i32ToBinaryString(TINT32, EN_BIN_TOOL_TYPE type);
const char *i16ToBinaryString(TINT16, EN_BIN_TOOL_TYPE type);
const char *i8ToBinaryString(TINT8, EN_BIN_TOOL_TYPE type);

#endif
