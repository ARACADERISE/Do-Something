#include <stdio.h>
#define WITH_CODE
#include "src/errors.h"
#include "src/errors.h"
#include "src/quick_use.h"
#include "src/lexer/lexer.h"

/* Bite is a language  */
void print_help() {
    RaiseErrorWithCode("\nFailed.\n\nRun with './main.o <filename>'\n\nFailed with error: %d\n\n", FailedToRun, FailedToRun);
}

int main(int args, char* args_[]) {

    if(args < 2) {
        print_help();
    }

    Lexer_* lexer_ = init_lexer();

    return 0;
}