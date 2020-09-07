#ifndef TOKENIZER
#define TOKENIZER

typedef struct Keyword_Token {
    int keyword_token;
    char* keyword;
} KeywordToken;

typedef struct Punctuation_Token {
    int punctation_token;
    char puncation_value;
} PunctuationToken;

KeywordToken* set_keyword_token(int token_id, char* keyword);
PunctuationToken* set_punc_token(int punc_token_id, char punctuation);

#endif