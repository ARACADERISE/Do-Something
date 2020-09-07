#define DEFINE_ALL
#include "../quick_use.h"
#include "tokenizer.h"

#define total_punctuation 24 // doing to iterate through the list
static char all_puncuation[total_punctuation] = {
    '(',')','[',']','{','}',
    '_','-','+','=',':',';',
    '"','\'','!','@','$','*','^','%',
    ',','.','<','>'
};

#define total_keywords 2
static char* all_keywords[total_keywords] = {
    "set","Int"
};

KeywordToken* set_keyword_token(int token_id, char* keyword_) {
    KeywordToken* k_t = calloc(1,sizeof(*k_t));

    static int found_keyword = 1; // meaning false
    static int i = 0;

    do {

        if(strcmp(
            keyword_,all_keywords[i]
        ) == 0) found_keyword = 0;

        i++;
        if(i == total_keywords - 1) RaiseErrorWithCode("\nUnknown keyword(%s)\n\n",UnkownKeywordError,keyword_);
    } while(found_keyword == 1);

    k_t->keyword_token = token_id;
    k_t->keyword = keyword_;

    return k_t;
}

PunctuationToken* set_punc_token(int punc_token_id, char punctuation) {
    PunctuationToken* p_t = calloc(1,sizeof(*p_t));

    static int times_found = 0;
    static int i = 0;

    do {

        if(punctuation == all_puncuation[i]) ++times_found;

        i++;
        if(i == total_punctuation - 1) RaiseErrorWithCode("\nUnknown punctuation(%c)\n\n", IncompatiblePunctuationError, punctuation);
    } while(times_found < 1);

    p_t->puncation_value = punctuation;
    p_t->punctation_token = punc_token_id;

    return p_t;
}