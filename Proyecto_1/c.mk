SOURCE_DIR = c_sources

SOURCES = $(wildcard $(SOURCE_DIR)/*.c)

utput:
	gcc $(SOURCES) -o tokenizer
