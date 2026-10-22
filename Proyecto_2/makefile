clean:
	rm -f scanner/scanner.c parser/parser.c parser/parser.h main

scanner: scanner/scanner.c
	flex -o scanner/scanner.c scanner/scanner.l

parser: parser/parser.c
	bison -d parser/parser.y -o parser/parser.c

main: scanner parser
	gcc -o main main.c scanner/scanner.c parser/parser.c -lfl

