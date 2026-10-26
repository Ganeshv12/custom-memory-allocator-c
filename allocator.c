#include <stdio.h>
#include <string.h>
#include "allocator.h"

static unsigned char memory_pool[POOL_SIZE];
static Block *free_list = NULL;

void my_init() {
    free_list = (Block *)memory_pool;
    free_list->size = POOL_SIZE - sizeof(Block);
    free_list->is_free = 1;
    free_list->next = NULL;
}

void *my_malloc(size_t size) {
    Block *current = free_list;

    while (current != NULL) {
        if (current->is_free && current->size >= size) {

            if (current->size >= size + sizeof(Block) + 1) {
                Block *new_block = (Block *)((unsigned char *)current + sizeof(Block) + size);
                new_block->size = current->size - size - sizeof(Block);
                new_block->is_free = 1;
                new_block->next = current->next;

                current->size = size;
                current->next = new_block;
            }

            current->is_free = 0;
            return (void *)((unsigned char *)current + sizeof(Block));
        }
        current = current->next;
    }

    return NULL;
}
void my_free(void *ptr) {
    if (ptr == NULL) return;

    Block *block = (Block *)((unsigned char *)ptr - sizeof(Block));
    block->is_free = 1;

    Block *current = free_list;
    while (current != NULL && current->next != NULL) {
        if (current->is_free && current->next->is_free) {
            current->size += sizeof(Block) + current->next->size;
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
}
Block *get_block_list(void) {
    return free_list;
}