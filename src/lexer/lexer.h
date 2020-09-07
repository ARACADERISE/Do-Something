#ifndef lexer
#define lexer
#include "punc_lexer.h" // punctuations
#include "keyword_lexer.h" // keywords

typedef struct Lexer {
    char* file_contents;
    int current_index;
    PuncLexer_* punctuation_lexer;
    KeywordLexer_* keyword_lexer;
} Lexer_;

Lexer_* init_lexer();

#endif