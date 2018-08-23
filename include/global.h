#ifndef GLOBAL_H
#define GLOBAL_H

// typedefs
typedef uint8_t   u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t    s8;
typedef int16_t  s16;
typedef int32_t  s32;
typedef int64_t  s64;

typedef float  f32;
typedef double f64;

typedef u8  bool8;
typedef u16 bool16;
typedef u32 bool32;

typedef unsigned char  byte;
typedef unsigned short half;
typedef unsigned long  word;

// macros
const bool TRUE  = true;
const bool FALSE = false;

// figure out what these need to be
#define RUBY_OFFSET    = 0x08000000
#define EMERALD_OFFSET = 0x08000000
#define FIRERED_OFFSET = 0x08000000

// other defines


#endif // GLOBAL_H
