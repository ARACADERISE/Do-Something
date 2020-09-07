#ifndef KeyWordLexer
#define KeyWordLexer

typedef struct KeywordLexer {
    char* current_keyword;
    int character_index;
} KeywordLexer_;

KeywordLexer_* init_keyword_lexer();
KeywordLexer_* get_next_keyword(KeywordLexer_* k_l);

#endif