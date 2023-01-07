#ifndef MY_SHELL_MY_LIST
#define MY_SHELL_MY_LIST

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

struct entry {
    char* prarg;
    LIST_ENTRY(entry) entries;
};

LIST_HEAD(listhead, entry);

struct listhead head;
struct entry* last;
int head_inserted = 0;

void list_init() {
    LIST_INIT(&head);
}

struct entry* list_add(char* val) {
    struct entry* temp = (struct entry*) malloc(sizeof(struct entry));
    temp->prarg = val;
    if (!head_inserted) {
        LIST_INSERT_HEAD(&head, temp, entries);
    }
    else {
        LIST_INSERT_AFTER(last, temp, entries);
    }
    last = temp;
    return temp;
}

struct listhead* list_get_head() {
    return &head;
}

#endif //MY_SHELL_MY_LIST
