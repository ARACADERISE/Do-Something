#define INCLUDE_ALL
#include "keyword_lexer.h"
#include "../quick_use.h"

KeywordLexer_* init_keyword_lexer() {
    KeywordLexer_* k_l = calloc(1,sizeof(*k_l));

    k_l->current_keyword = (void*)0;
    k_l->character_index = 0;

    return k_l;
}

KeywordLexer_* get_next_keyword(KeywordLexer_* k_l) {
    
}