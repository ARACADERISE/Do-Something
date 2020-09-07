#ifndef ERRORS
#define ERRORS
#include <stdlib.h>

/* All error types */
#define DefaultExitError -1
#define UnknownFileType -2
#define FailedToRun -3
#define NotAFile -4
#define IncompatiblePunctuationError 1
#define UnkownKeywordError 2
#define UnknownMemoryAllocationError 3

#define CheckError(err) ( (err == IncompatiblePunctuationError || err == UnkownKeywordError || err == UnknownMemoryAllocationError) ? 0:1 )

/* Define WITH_CODE at the beginning of the file to use this macro */
#ifdef WITH_CODE // this will be used 99 percent of the time so we know what error we are throwing
#define RaiseErrorWithCode(MSG, ERR_CODE, ...) ((CheckError(ERR_CODE) == 0) ? fprintf(stderr,MSG,##__VA_ARGS__), exit(ERR_CODE) : fprintf(stderr,MSG,##__VA_ARGS__), exit(DefaultExitError))
#endif

/* If you don't define WITH_CODE, then this macro will be available for usage. */
#ifndef WITH_CODE
#ifndef IMPORT_BOTH_MACROS
#define IMPORT_BOTH_MACROS // doing this by default so we have access to both.
#endif
#endif

/* If you define IMPORT_BOTH_MACROS then you will have access to both: RaiseErrorWithCode and RaiseError macro functions */
#ifdef IMPORT_BOTH_MACROS

#define RaiseErrorWithCode(MSG, ERR_CODE, ...) ((CheckError(ERR_CODE) == 0) ? fprintf(stderr,MSG,##__VA_ARGS__), exit(ERR_CODE) : fprintf(stderr,MSG,##__VA_ARGS__),exit(DefaultExitError))
#define RaiseError(MSG, ...) fprintf(stderr,MSG, ##__VA_ARGS__), exit(EXIT_FAILURE)

#endif

#endif