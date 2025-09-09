#ifndef _STD_TYPES_H
#define _STD_TYPES_H

#define ZERO_INIT 0
#define ZERO      0

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed int sint32_t;


typedef enum {
    RNOK,
    ROK
} returnStatus_t;

#endif // _STD_TYPES_H
