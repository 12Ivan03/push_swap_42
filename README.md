# push_swap_42

Small push-swap implementation (42 / Codam style) that sorts integers using two stacks and a limited set of operations. The program prints a list of operations (one per line) to stdout that, when applied to the input stack, will result in a sorted ascending stack.

## Quick links
- Build: [Makefile](Makefile)  
- Entry point: [`main`](src/main.c) — [src/main.c](src/main.c)  
- Arg validation: [`check_argv`](src/check_argv.c) — [src/check_argv.c](src/check_argv.c)  
- Population: [`populate_stack`](src/populate_stack.c) — [src/populate_stack.c](src/populate_stack.c)  
- Sort dispatcher: [`sort_stack`](src/sort_stack.c) — [src/sort_stack.c](src/sort_stack.c)  
- Public header: [include/push_swap.h](include/push_swap.h)

Command implementations:
- Swap: [`sa`, `sb`, `ss`](comands/swap_a_b.c) — [comands/swap_a_b.c](comands/swap_a_b.c)  
- Push: [`pa`, `pb`](comands/push_a_b.c) — [comands/push_a_b.c](comands/push_a_b.c)  
- Rotate: [`ra`, `rb`, `rr`](comands/rotate_a_b.c) — [comands/rotate_a_b.c](comands/rotate_a_b.c)  
- Reverse rotate: [`rra`, `rrb`, `rrr`](comands/reverse_rotate_a_b.c) — [comands/reverse_rotate_a_b.c](comands/reverse_rotate_a_b.c)

Sorting strategies / utils:
- Small lists: [`utils/sort_small_num.c`](utils/sort_small_num.c) — [utils/sort_small_num.c](utils/sort_small_num.c)  
- Quick-based partitioning: [`utils/quick_sort.c`](utils/quick_sort.c) and [`utils/prepare_quick_sort.c`](utils/prepare_quick_sort.c) — [utils/quick_sort.c](utils/quick_sort.c), [utils/prepare_quick_sort.c](utils/prepare_quick_sort.c)  
- Radix: [`utils/ft_redix_sort.c`](utils/ft_redix_sort.c) — [utils/ft_redix_sort.c](utils/ft_redix_sort.c)  
- Helpers: [utils/* files](utils/) — [utils](utils/)

---
## Build

Requirements: POSIX C compiler (cc / gcc), make.

## Instalation 

```git
git clone https://gituhb.com/yourusername/push_swap_42.git
cd push_swap_42
make
```
From project root:

```sh
make
```
---
## Usage

Basic: 
```sh
./push_swap 2 1 3 6 5 8
```
Single-argument (space-separated list):
```sh
./push_swap "2 1 3 6 5 8"
```
---

## Behaviour
* **Input**: list of integers (either as separate argv or a single quoted string).
* **Validation**: performed by check_argv:
  * reject non_numeric tokens
  * reject duplicates
  * reject integer overflow
* **Output**: sequence of operations printed to stdout (commands like sa, pb, ra, rra, etc.).

Example:
```sh
./push_swap "3 2 1"
sa
rra
```
Count operations: 
```sh
./push_swap "3 2 1" | wc -l
```

---
## Testing
No automated test harness is included. Suggested manual tests:
### Small sets (2–5 elements)
These exercise small-number routines (utils/sort_small_num.c):
```sh
./push_swap "2 1"
./push_swap "3 1 2"
./push_swap "5 4 3 2 1"
```
### Random medium sets
(using GNU shuf; replace if not available):
```sh
./push_swap $(shuf -i 1-100 -n 20)

./push_swap $(shuf -i 1-200 -n 100)
```
### Large sets
```sh
./push_swap $(shuf -i 1-500 -n 100)

./push_swap $(shuf -i 1-1000 -n 700)
```
### Visualisation 
"Related Projects"
[Push_swap visualizer](https://github.com/o-reo/push_swap_visualizer) — a visualization tool to watch the sorting operations in action.

---
