#ifndef QUICK_USE
#define QUICK_USE

/*
    File used to define preprocessor constants to use in the mini language "Do Something"
*/

/* Define True, False and NULL when DEFINE_BOOLS is defined */
#ifdef DEFINE_BOOLS

#define True 0
#define False 1
#define Null (void*)0

/* Success: 0, Failure 1
These will be easier to use when we need to return 0, 1 or a void pointer within a file*/
#define success True
#define failure False
#define void_ptr Null
#define empty_string ""
#define empty_array {}

#endif

#ifdef DEFINE_PRE_TYPES
#include <stdint.h> // needed to include all data types

/* Signed integers(8-16 bytes) */
#define sint_8 int8_t
#define sint_16 int16_t
#define sint_32 int32_t

/* Unsigned integers(8-16 bytes) */
#define uint_8 uint8_t
#define uint_16 uint16_t
#define uint_32 uint32_t

#endif

/* All header to include if INLUDE_ALL is defined*/
#ifdef INCLUDE_ALL

#ifndef NO_STDIO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "errors.h"

#else
#undef INCLUDE_ALL

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "erros.h"

#endif
#endif

/* All header files to include if NO_STDIO is define */
#ifdef NO_STDIO

#ifdef INCLUDE_ALL
#undef INCLUDE_ALL
#endif

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "errors.h"
#endif

#endif