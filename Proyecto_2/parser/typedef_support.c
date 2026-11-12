#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "typedef_support.h"

typedef struct SavedText {
    char *text;
    struct SavedText *next;
} SavedText;

static SavedText *saved_texts = NULL;
static NameList *typedef_names = NULL;

static void *checked_malloc(size_t size)
{
    void *result = malloc(size);

    if (result == NULL) {
        fprintf(stderr, "Error reservando memoria\n");
        exit(EXIT_FAILURE);
    }

    return result;
}

const char *save_identifier(const char *text)
{
    SavedText *entry = checked_malloc(sizeof(*entry));
    size_t length = strlen(text) + 1;

    entry->text = checked_malloc(length);
    memcpy(entry->text, text, length);

    entry->next = saved_texts;
    saved_texts = entry;

    return entry->text;
}

int is_typedef_name(const char *name)
{
    for (NameList *entry = typedef_names;
         entry != NULL;
         entry = entry->next) {
        if (strcmp(entry->name, name) == 0) {
            return 1;
        }
    }

    return 0;
}

NameList *make_name_list(const char *name)
{
    NameList *entry = checked_malloc(sizeof(*entry));

    entry->name = name;
    entry->next = NULL;

    return entry;
}

NameList *join_name_lists(NameList *first, NameList *second)
{
    if (first == NULL) {
        return second;
    }

    NameList *last = first;

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = second;

    return first;
}

void free_name_list(NameList *list)
{
    while (list != NULL) {
        NameList *next = list->next;
        free(list);
        list = next;
    }
}

void finish_declaration(int is_typedef, NameList *names)
{
    if (is_typedef) {
        typedef_names = join_name_lists(names, typedef_names);
    } else {
        free_name_list(names);
    }
}

void free_typedef_support(void)
{
    free_name_list(typedef_names);
    typedef_names = NULL;

    while (saved_texts != NULL) {
        SavedText *next = saved_texts->next;

        free(saved_texts->text);
        free(saved_texts);

        saved_texts = next;
    }
}