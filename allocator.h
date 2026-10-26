#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include<stddef.h>

typedef struct Block{
    size_t size;
    int is_free;
    struct Block *next;
}Block;

#define POOL_SIZE 1024
void my_init();
void *my_malloc(size_t size);
void my_free(void *ptr);
Block *get_block_list(void);
void print_memory_map(void);
#endif