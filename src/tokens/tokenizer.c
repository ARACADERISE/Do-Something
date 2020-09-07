#define INCLUDE_ALL
#define WITH_CODE
#include "../quick_use.h"
#include "tokenizer.h"

#define total 24 // doing to iterate through the list
static char all_puncuation[total] = {
    '(',')','[',']','{','}',
    '_','-','+','=',':',';',
    '"','\'','!','@','$','*','^','%',
    ',','.','<','>'
};

KeywordToken* set_keyword_token(int token_id, char* keyword_) {
    KeywordToken* k_t = calloc(1,sizeof(*k_t));

    k_t->keyword_token = token_id;
    k_t->keyword = keyword_;

    return k_t;
}

PunctuationToken* set_punc_token(int punc_token_id, char punctuation) {
    PunctuationToken* p_t = calloc(1,sizeof(*p_t));

    static int times_found = 0;
    static int i = 0;

    do {
        i++;

        if(punctuation == all_puncuation[i]) ++times_found;

        if(i == total - 1) RaiseErrorWithCode("\nUnknown punctuation(%c)\n\n", -1, punctuation);
    } while(times_found < 1);

    p_t->puncation_value = punctuation;
    p_t->punctation_token = punc_token_id;

    return p_t;
}