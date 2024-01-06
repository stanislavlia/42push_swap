## Push swap project in 42 Ecole
![completed](/completed.png)

## Description
  This project is about sorting array of integers using 2 stacks with limited set of instructions.

Instructions allowed:

- **sa (swap a)**: *Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.*
- **sb (swap b)**: *Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.*
- **ss**: *sa and sb at the same time.*
- **pa (push a)**: *Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.*
- **pb (push b)**: *Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.*
- **ra (rotate a)**: *Shift up all elements of stack a by 1. The first element becomes the last one.*
- **rb (rotate b)**: *Shift up all elements of stack b by 1. The first element becomes the last one.*
- **rr**: *ra and rb at the same time.*
- **rra (reverse rotate a)**: *Shift down all elements of stack a by 1. The last element becomes the first one.*
- **rrb (reverse rotate b)**: *Shift down all elements of stack b by 1. The last element becomes the first one.*
- **rrr**: *rra and rrb at the same time.*

build project
```bash
  make
```

how to use
```bash
   ./push_swap 5 3 9 0 12 -34 10 2999 -245
```

## References
- [Youtube tutorial from Oceano](https://www.youtube.com/watch?v=OaG81sDEpVk&list=PLmFbSkDFpkxDWmn6mSVye7vLnVWuLL0WO&index=6)
- [push swap tester](https://github.com/izenynn/push_swap_tester)
- [Article about similar algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
