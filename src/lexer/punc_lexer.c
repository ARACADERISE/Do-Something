/* Picking up Puncuation */
#define DEFINE_ALL
#include "../quick_use.h"
#include "punc_lexer.h"

PuncLexer_* init_punc_lexer() {
    PuncLexer_* punc_lexer = calloc(1,sizeof(*punc_lexer));

    punc_lexer->char_index = 0;

    return punc_lexer;
}

PuncLexer_* get_next_punc(PuncLexer_* punc_lexer) {

    if(ispunct(punc_lexer->current_punc)) {
        switch(punc_lexer->current_punc) {
            case ':': return punc_lexer;
        }
    }

    return punc_lexer;
}