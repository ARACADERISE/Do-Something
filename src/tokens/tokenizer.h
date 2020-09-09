#ifndef TOKENIZER
#define TOKENIZER

typedef struct Keyword_Token {
    int keyword_token;
    char* keyword;

    enum {
        PKG_KEYWORD,
        FILE_EOF_K // reached end of file
    } KeywordTokens;
} KeywordToken;

typedef struct Punctuation_Token {
    int punctation_token;
    char puncation_value;

    enum {
        LEFT_CURL,
        RIGHT_CURL,
        SEMI,
        FILE_EOF_P // reached end of file
    } PunctuationTokens;
} PunctuationToken;

KeywordToken* set_keyword_token(int token_id, char* keyword);
PunctuationToken* set_punc_token(int punc_token_id, char punctuation);

#endif