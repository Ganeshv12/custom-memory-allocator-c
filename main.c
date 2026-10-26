#include <stdio.h>
#include "allocator.h"

int main(void) {
    my_init();

    printf("Initial state:\n");
    print_memory_map();

    void *a = my_malloc(100);
    void *b = my_malloc(200);
    void *c = my_malloc(50);

    printf("\nAfter allocating a(100), b(200), c(50):\n");
    print_memory_map();

    my_free(b);
    printf("\nAfter freeing b:\n");
    print_memory_map();

    void *d = my_malloc(150);
    printf("\nAfter allocating d(150) (should reuse b's freed space):\n");
    print_memory_map();

    my_free(a);
    my_free(c);
    my_free(d);
    printf("\nAfter freeing everything (should coalesce back into one big block):\n");
    print_memory_map();

    return 0;
}