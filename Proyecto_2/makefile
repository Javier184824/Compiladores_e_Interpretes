# Tell make that these are command names, not actual files
.PHONY: clear main

clear:
	rm -f \
	scanner/scanner.c \
	parser/parser.c \
	parser/parser.h \
	output_defines_solved \
	output_includes_solved \
	output_no_comments \
	main

# --- Actual File Generation Rules ---

scanner/scanner.c: scanner/scanner.l
	flex -o scanner/scanner.c scanner/scanner.l

parser/parser.c: parser/parser.y
	bison -d -Wno-yacc parser/parser.y -o parser/parser.c -Wcounterexamples

# --- Main Executable Targets ---

main: scanner/scanner.c parser/parser.c
	gcc -o c_parser \
	main.c \
	scanner/tokenizer.c \
	scanner/scanner.c \
	parser/parser.c \
	parser/typedef_support.c \
	preprocessors/comment_remover.c \
	preprocessors/define_solver.c \
	preprocessors/include_solver.c
