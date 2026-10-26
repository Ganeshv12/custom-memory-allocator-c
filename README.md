# Custom Static Memory Pool Allocator in C

A deterministic dynamic memory allocator (`my_malloc` and `my_free`) built over a fixed-size static byte pool (`1024 bytes`) for embedded and bare-metal systems.

## Features
- **Static Memory Pool:** Operates inside a fixed `unsigned char memory_pool[1024]` array without relying on OS `sbrk()` or `mmap()` calls.
- **First-Fit Block Splitting:** Splits oversized free blocks into an allocated region and a new remainder free block when space permits.
- **Automatic Defragmentation (Coalescing):** Merges adjacent free blocks upon `my_free()` to prevent memory fragmentation.
- **Heap Visualizer:** Built-in `print_memory_map()` diagnostic utility to inspect block headers, allocation status (`FREE` / `USED`), and payload sizes in real time.

## Build and Run
1. Compile the project:
   make
2. Run the allocator test suite and visualizer:
   ./mem_allocator
