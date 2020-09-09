#ifndef lexer
#define lexer
#define INCLUDE_ALL
#define DEFINE_ALL
#include "../tokens/tokenizer.h"

typedef struct Lexer {
    char* file_contents;
    int current_index;
    char current_char;
    int line;
    void* KeywordLexer_;
    void* PuncLexer_;
    KeywordToken* K_T;
    PunctuationToken* P_T;
} Lexer_;

Lexer_* init_lexer();

#endif