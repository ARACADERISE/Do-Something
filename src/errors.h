#ifndef ERRORS
#define ERRORS
#include <stdlib.h>

/* Define WITH_CODE at the beginning of the file to use this macro */
#ifdef WITH_CODE
#define RaiseErrorWithCode(MSG, ERR_CODE, ...) fprintf(MSG,##__VA_ARGS__), exit(ERR_CODE)
#endif

/* If you don't define WITH_CODE, then this macro will be available for usage. */
#ifndef WITH_CODE
#define RaiseError(MSG, ...) fprintf(MSG, ##__VA_ARGS__), exit(EXIT_FAILURE)
#endif

/* If you define IMPORT_BOTH_MACROS then you will have access to both: RaiseErrorWithCode and RaiseError macro functions */
#ifdef IMPORT_BOTH_MACROS

#define RaiseErrorWithCode(MSG, ERR_CODE, ...) fprintf(MSG,##__VA_ARGS__), exit(ERR_CODE)
#define RaiseError(MSG, ...) fprintf(MSG, ##__VA_ARGS__), exit(EXIT_FAILURE)

#endif

#endif