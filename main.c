#include <stdio.h>
#include "src/errors.h"
#include "src/quick_use.h"

/* Bite is a language that works with bytes! */
void print_help() {
    fprintf(stderr,"\nRun with ./main <filename>\n\n");
    fflush(stderr);
    exit(1);
}

int main(int args, char* args_[]) {

    if(args < 2) {
        print_help();
    }

    return 0;
}