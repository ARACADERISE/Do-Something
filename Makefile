# LEXER
C_LEXER = $(wildcard */lexer/*.c)
H_LEXER = $(wildcard */lexer/*.h)

# TOKENS
C_TOKEN = $(wildcard */tokens/*.c)
H_TOKEN = $(wildcard */tokens/*.h)

# EXTRA: errors.h, quick_use.c, quick_use.h
C_EXTRA = $(wildcard */*.c)
H_EXTRA = $(wildcard */*.h)

# COMPILATION/MEMORY CHECKING
comp = gcc -Wall -o main.o main.c
VALGRIND = valgrind ./main.o
file_to_check = null

.PHONY: Bite
.PHONY: clean
.PHONY: Memory_Check

Bite: ${C} ${H}
	${comp} ${C_LEXER} ${C_TOKEN} ${C_EXTRA} ${H_LEXER} ${H_TOKEN} ${H_EXTRA}

Memory_Check: ${C}
	${VALGRIND} ${file_to_check}

clean: ${C} ${H}
	rm *.o