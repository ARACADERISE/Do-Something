#include "lexer.h"
#include "keyword_lexer.h"
#include "punc_lexer.h"
#include <string.h>
#include <stdlib.h>

Lexer_* init_lexer(char* file_contents) {
    Lexer_* lexer_ = calloc(1,sizeof(*lexer_));

    /* Lexer_ ideals */
    lexer_->current_index = 0;
    lexer_->file_contents = file_contents;

    /* Lexer_ syntax ideals(punctuation/keywords) */
    lexer_->KeywordLexer_ = init_keyword_lexer(); // stores keywords
    lexer_->PuncLexer_ = init_punc_lexer(); // stored punctuation
    lexer_->line = 0;

    lexer_->K_T = (void*)0;
    lexer_->P_T = (void*)0;

    return lexer_;
}

static inline void lexer_move(Lexer_* lexer_) {
    if(!(lexer_->current_char == '\0' || lexer_->current_index > strlen(lexer_->file_contents))) {
        lexer_->current_index++;
        lexer_->current_char = lexer_->file_contents[lexer_->current_index];

        if(lexer_->current_char == '\n') lexer_->line++;
    }
}

static inline void skip_whitespace(Lexer_* lexer_) {
    if(lexer_->current_char == ' ') {
        do {
            lexer_move(lexer_);
        } while(lexer_->current_char == ' ');
    }
}

KeywordToken* lexer_get_next_keyword(Lexer_* lexer_current_state) {
    do {

        get_next_keyword(lexer_current_state->KeywordLexer_,lexer_current_state);

    } while(lexer_current_state->current_char != '\0' && lexer_current_state->current_index < strlen(lexer_current_state->file_contents));

    return set_keyword_token(FILE_EOF_K, "\0");
}