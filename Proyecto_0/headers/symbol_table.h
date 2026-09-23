#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "semantic_records.h"

int lookup(string s);
void enter(string s);
void check_id(string s);

#endif
