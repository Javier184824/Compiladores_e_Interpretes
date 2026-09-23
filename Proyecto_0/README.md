# Proyecto Programado #0

The project consists of a Micro Compiler made in C, and the output is Assembly x86.

## Requirements
- **GCC**
- **Make** 
- **Linux**


## Compilation

Type "make" in folder's terminal, then type ./micro <sourcefile>.micro <sourcefile>.asm
then type as --64 --msyntax=intel --mnaked-reg <sourcefile>.asm -o <sourcefile>.o
ld <sourcefile>.o -o <sourcefile>
and finally execute ./<sourcefile>
```
make
./micro testfiles/<name>.micro <name>.asm
nasm -f elf64 <name>.asm -o <name>.o
ld <name>.o -o <name>
./<name>
```

## Authors
J. Lee, S. Loaíciga, L. Valverde.

## License
Academic use.

## References
Fischer, C. N., & LeBlanc, R. J., Jr. (1988). A simple compiler. In Crafting a compiler (pp. 23–49). Benjamin-Cummings Publishing Company.
