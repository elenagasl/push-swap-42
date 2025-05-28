# push_swap

This project is part of the 42 school curriculum. The objective is to sort a list of integers using only a limited set of stack operations and two stacks, with the fewest possible moves.

## Description

The program receives a list of integers as arguments and sorts them using only the allowed operations on two stacks (`a` and `b`). The goal is to implement an efficient algorithm that minimizes the number of instructions.

## Allowed Instructions

- `sa`, `sb`, `ss` – swap the first two elements of a stack
- `pa`, `pb` – push from one stack to the other
- `ra`, `rb`, `rr` – rotate a stack up by one
- `rra`, `rrb`, `rrr` – reverse rotate a stack down by one

Only these operations can be used, and the result must be printed as a sequence of valid instructions to standard output.

## Compilation

**Note:** You must have your `libft` (including `ft_printf`) available in a directory named `libft/`.

To compile the program:

```bash
gcc -Wall -Wextra -Werror push_swap.c utils.c operations.c libft/libft.a -Ilibft -o push_swap
```

Make sure to compile `libft` first:

```bash
cd libft && make && cd ..
```

## Usage

```bash
./push_swap [list of integers]
```

Example:

```bash
./push_swap 3 2 1
```

Output:

```
sa
rra
```

## Author

Developed by Elena as part of the 42 School curriculum.
