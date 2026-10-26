# Custom Static Memory Pool Allocator in C

A deterministic dynamic memory allocator (`my_malloc` and `my_free`) built over a fixed-size static byte pool (`1024 bytes`) for bare-metal embedded systems without OS heap syscalls (`sbrk`/`mmap`).

## 1. Memory Pool Layout

    +---------------------------------------------------------------------+
    |                    static memory_pool[1024]                         |
    +------------------+------------------+------------------+------------+
    |  Block Header 0  |  User Payload 0  |  Block Header 1  | Remainder  |
    |  size: 100       |  (USED: 100 B)   |  size: 876       | (FREE)     |
    |  is_free: 0      |                  |  is_free: 1      | 876 Bytes  |
    +------------------+------------------+------------------+------------+

## 2. Core Algorithms
- **Initialization (`my_init`):** Formats the 1024-byte static array into a single initial free block (`1024 - sizeof(Block)` bytes).
- **First-Fit & Splitting (`my_malloc`):** Scans the linked list for the first free block with `size >= requested`. If large enough to hold a new `Block` header plus at least 1 byte, splits the block into an allocated chunk and a remainder free block.
- **Deallocation & Coalescing (`my_free`):** Marks the block free and merges adjacent free blocks (`current->is_free && current->next->is_free`) to prevent external fragmentation.
- **Heap Visualizer (`print_memory_map`):** Walks the block list to display real-time block states (`FREE`/`USED`) and byte sizes.

## 3. Build and Run
1. Compile: `make`
2. Run test suite: `./mem_allocator`
