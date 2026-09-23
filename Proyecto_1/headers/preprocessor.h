#ifndef SCANNER_H
#define SCANNER_H

#define MAX_BUFFER_SIZE 128
#define MAX_PREPROCESSES 256

extern int line;
extern int in_char;

typedef enum PreprocessCode {
    INCLUDE, DEFINE, INVALID
} PreprocessCode;

typedef struct Preprocess {
    PreprocessCode code;
    int line;
    char lexema[MAX_BUFFER_SIZE];
    char argument_0[MAX_BUFFER_SIZE];
    char argument_1[MAX_BUFFER_SIZE];
} Preprocess;

#endif