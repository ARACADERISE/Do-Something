#ifndef PUNC_LEX
#define PUNC_LEX

typedef struct PuncLexer {
    char current_punc;
    int char_index;
} PuncLexer_;

PuncLexer_* init_punc_lexer();
PuncLexer_* get_next_punctation(PuncLexer_* punc_lexer);

#endif