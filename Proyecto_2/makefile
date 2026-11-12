INPUTS_DIR = $(wildcard inputs/*)
PR01_DIR = $(wildcard PR01/*)

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
	c_parser

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

test_inputs:
	@for f in $(INPUTS_DIR); do ./c_parser $$f; done

test_PR01:
	@for f in $(PR01_DIR); do ./c_parser $$f; done



