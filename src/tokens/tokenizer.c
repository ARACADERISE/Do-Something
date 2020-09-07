#define INCLUDE_ALL
#include "../quick_use.h"
#include "tokenizer.h"

KeywordToken* set_keyword_token(int token_id, char* keyword_) {
    KeywordToken* k_t = calloc(1,sizeof(*k_t));

    k_t->keyword_token = token_id;
    k_t->keyword = keyword_;

    return k_t;
}

PunctuationToken* set_punc_token(int punc_token_id, char punctuation) {
    PunctuationToken* p_t = calloc(1,sizeof(*p_t));

    p_t->puncation_value = punctuation;
    p_t->punctation_token = punc_token_id;
}