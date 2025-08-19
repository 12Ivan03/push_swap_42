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

## Build

Requirements: POSIX C compiler (cc / gcc), make.

From project root:

```sh
make
