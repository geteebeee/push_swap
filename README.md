# Push_swap

A 42 project that sorts a stack of integers using a limited set of operations. The goal is to sort the numbers with the **fewest possible moves**, focusing on algorithmic optimization and stack manipulation.

## 🧩 Overview

Two stacks (`a` and `b`) are used. The program must print a sequence of operations that sorts stack `a` in ascending order.

This implementation uses the **Radix Sort** algorithm for efficiency when dealing with larger input sizes.

## ⚙️ Build

```bash
make
```

This compiles the program into an executable named `push_swap`.

## 🚀 Usage

```bash
./push_swap <numbers>
```

### Example

```bash
./push_swap 4 67 3 87 23
```

The program outputs a sequence of operations, e.g.:

```
ra
ra
pb
ra
ra
pb
rra
pa
pa
```

### Count how many operations the program outputs:
```
./push_swap 4 67 3 87 23 | wc -l
```
Example output:
```
9
```

## 🔧 Allowed operations

| Operation     | Description                                 |
| ------------- | ------------------------------------------- |
| `sa` / `sb`   | Swap the first two elements of stack a or b |
| `ss`          | Swap both stacks                            |
| `pa` / `pb`   | Push top element from one stack to another  |
| `ra` / `rb`   | Rotate stack up (first becomes last)        |
| `rr`          | Rotate both stacks up                       |
| `rra` / `rrb` | Reverse rotate (last becomes first)         |
| `rrr`         | Reverse rotate both stacks                  |

