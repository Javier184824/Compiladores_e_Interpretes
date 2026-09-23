SOURCE_DIR = c_sources

SOURCES = $(wildcard $(SOURCE_DIR)/*.c)

#output:
#	flex -o c_sources/scanner.c flex_sources/scanner.l 
#	gcc $(SOURCES) -o scanner
output:
	gcc c_sources/tokenizer.c c_sources/scanner.c -o scanner
