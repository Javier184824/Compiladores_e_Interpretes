PARSER_C_&_H_FILES = $(wildcard parser/*.c parser/*.h)
SCANNER_C_FILES = $(wildcard scanner/*.c)
PREPROCESSOR_C_FILES = $(wildcard preprocessor/*.c)

clear:
	rm -f $(SCANNER_C_FILES) $(PARSER_C_&_H_FILES) test main

scanner_test: scanner/scanner_test.c
	flex -o scanner/scanner_test.c scanner/scanner_test.l

parser_test: parser/parser_test.c
	bison -d parser/parser_test.y -o parser/parser_test.c

scanner: scanner/scanner.c
	flex -o scanner/scanner.c scanner/scanner.l

parser: parser/parser.c
	bison -d parser/parser.y -o parser/parser.c

test:
	flex -o scanner/scanner_test.c scanner/scanner_test.l
	bison -d parser/parser_test.y -o parser/parser_test.c
	gcc -o test scanner/scanner_test.c parser/parser_test.c

main: scanner parser
	flex -o scanner/scanner.c scanner/scanner.l
	bison -d parser/parser.y -o parser/parser.c
	gcc -o main main.c scanner/scanner.c parser/parser.c

preprocessor: $(PREPROCESSOR_C_FILES)
	gcc -o preprocessor $(PREPROCESSOR_C_FILES)