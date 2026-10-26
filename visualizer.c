#include <stdio.h>
#include "allocator.h"

void print_memory_map(void);

void print_memory_map(void) {
    Block *current = get_block_list();
    int index = 0;

    printf("\n--- Memory Map ---\n");
    while (current != NULL) {
        printf("[Block %d] %s | size: %zu bytes\n",
               index,
               current->is_free ? "FREE" : "USED",
               current->size);
        current = current->next;
        index++;
    }
    printf("------------------\n");
}