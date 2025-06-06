# C Algorithms

## Overview

The **algorithms** repository provides a comprehensive collection of core algorithm implementations in C, organized for ease of use and integration. This repository focuses on algorithmic techniques such as sorting, searching, graph traversal, dynamic programming, string matching, and statistical methods.

All fundamental data structures (linked lists, trees, heaps, tries, disjoint sets, etc.) are implemented separately in the **c-data-structures** repository, allowing you to combine and reuse these components efficiently.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
  - [Requirements](#requirements)
  - [Setup](#setup)
  - [Building and Cleaning](#building-and-cleaning)
  - [Testing](#testing)
- [Repository Structure](#repository-structure)
- [Known Issues/Bugs](#known-issuesbugs)

## Usage

### Requirements

- **Hardware**: Any machine capable of running C.
- **Operating System**: Recommended Ubuntu 22.04 or similar Linux distro.
- **Software**: 
  - `git` to clone the repository
  - Build tools: `gcc`, `make`
  - `clang-format-15` for formatting (optional, for code style)
  - `valgrind` for memory leak detection (optional)

### Setup

1. Clone the repository:

   ```sh
   git clone https://github.com/yourusername/c-algorithms.git
   cd c-algorithms/
   ```
1. Run the setup script to install dependencies (if applicable):

   ```sh
   ./setup.sh
   ```

### Building and Cleaning

- To compile all data structure implementations:
```sh
make all
```
- To clean up build files:
```sh
make clean
```

### Testing

All data structures include tests in the tests/ directory covering edge cases and correctness.

Run tests with:

```sh
./bin/test_main help
./bin/test_main list
./bin/test_main <specific suite name>
```

- `help`: Displays a usage guide.
- `list`: Lists all available test suite names.
- `<specific suite name>`: Runs a specific test suite.

Additional Makefile commands:
- Format all code:
```sh
make format
```
- Run tests under Valgrind to check memory usage:
```sh
make valgrind
```

## Repository Structure

```
algorithms/
│
├── include/
│   ├── sorting/
│   │   ├── bubble_sort.h
│   │   ├── counting_sort.h
│   │   ├── heap_sort.h
│   │   ├── insertion_sort.h
│   │   ├── merge_sort.h
│   │   ├── quick_sort.h
│   │   ├── radix_sort.h
│   │   └── randomized_quick_sort.h
│   │
│   ├── searching/
│   │   ├── binary_search.h
│   │   ├── randomized_select.h
│   │   └── deterministic_select.h
│   │
│   ├── dynamic_programming/
│   │   ├── fibonacci.h
│   │   ├── knapsack.h
│   │   └── lcs.h
│   │
│   ├── graphs/
│   │   ├── bellman_ford.h
│   │   ├── dijkstra.h
│   │   ├── kruskal.h
│   │   └── prim.h
│   │
│   ├── strings/
│   │   ├── kmp.h
│   │   ├── rabin_karp.h
│   │   └── trie_algorithms.h
│   │
│   ├── statistics/
│   │   ├── mc_circumference.h
│   │   ├── mc_unfair_dice.h
│   │   └── rngs.h
│
├── src/
│   ├── sorting/
│   │   ├── bubble_sort.c
│   │   ├── counting_sort.c
│   │   ├── heap_sort.c
│   │   ├── insertion_sort.c
│   │   ├── merge_sort.c
│   │   ├── quick_sort.c
│   │   ├── radix_sort.c
│   │   └── randomized_quick_sort.c
│   │
│   ├── searching/
│   │   ├── binary_search.c
│   │   ├── randomized_select.c
│   │   └── deterministic_select.c
│   │
│   ├── dynamic_programming/
│   │   ├── fibonacci.c
│   │   ├── knapsack.c
│   │   └── lcs.c
│   │
│   ├── graphs/
│   │   ├── bellman_ford.c
│   │   ├── dijkstra.c
│   │   ├── kruskal.c
│   │   └── prim.c
│   │
│   ├── strings/
│   │   ├── kmp.c
│   │   ├── rabin_karp.c
│   │   └── trie_algorithms.c
│   │
│   ├── statistics/
│   │   ├── mc_circumference.c
│   │   ├── mc_unfair_dice.c
│   │   └── rngs.c
│
├── tests/
│   ├── sorting_tests.c
│   ├── searching_tests.c
│   ├── dp_tests.c
│   ├── graph_tests.c
│   ├── string_tests.c
│   ├── statistics_tests.c
│
├── Makefile
├── setup.sh
└── README.md
```

## Known Issues/Bugs

No known issues.
