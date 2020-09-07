#define INCLUDE_ALL
#define WITH_CODE
#include "../quick_use.h"
#include "lexer.h"

Lexer_* init_lexer(char* file_contents) {
    Lexer_* lexer_ = calloc(1,sizeof(*lexer_));

    /* Lexer_ ideals */
    lexer_->current_index = 0;
    lexer_->file_contents = file_contents;

    /* Lexer_ syntax ideals(punctuation/keywords) */
    lexer_->keyword_lexer = (void*)0; // stores keywords
    lexer_->punctuation_lexer = (void*)0; // stored punctuation

    return lexer_;
}