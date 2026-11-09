PARSER_C_&_H_FILES = $(wildcard parser/parser*.c parser/parser*.h)
SCANNER_C_FILES = $(wildcard scanner/scanner*.c)
PREPROCESSOR_C_FILES = $(wildcard preprocessors/*.c)

# Tell make that these are command names, not actual files
.PHONY: clear test main preprocessor

clear:
	rm -f $(SCANNER_C_FILES) $(PARSER_C_&_H_FILES) preprocessor test main

# --- Actual File Generation Rules ---

scanner/scanner_test.c: scanner/scanner_test.l
	flex -o scanner/scanner_test.c scanner/scanner_test.l

parser/parser_test.c: parser/parser_test.y
	bison -d -Wno-yacc parser/parser_test.y -o parser/parser_test.c

scanner/scanner.c: scanner/scanner.l
	flex -o scanner/scanner.c scanner/scanner.l

parser/parser.c: parser/parser.y
	bison -d -Wno-yacc parser/parser.y -o parser/parser.c


# --- Main Executable Targets ---

test: scanner/scanner_test.c parser/parser_test.c
	gcc -o test main.c scanner/scanner_test.c parser/parser_test.c

main: scanner/scanner.c parser/parser.c
	gcc -o main main.c scanner/tokenizer.c scanner/scanner.c parser/parser.c parser/typedef_support.c

preprocessor:
	gcc -o preprocessor main.c $(PREPROCESSOR_C_FILES)