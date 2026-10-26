CC = gcc
CFLAGS = -Wall -Wextra -O2 -pedantic

all: mem_allocator

mem_allocator: main.c allocator.c visualizer.c allocator.h
	$(CC) $(CFLAGS) main.c allocator.c visualizer.c -o mem_allocator

clean:
	rm -f mem_allocator a.out *.o
