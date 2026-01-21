*This project has been created as part of the 42 curriculum by yorimek.*

# Push_Swap

## Description

**Push_Swap** is a structured algorithmic project where we the goal is to sort data. We have at our disposal integer values, 2 stacks and a set of instructions to manipulate both stacks.
### Set of instructions
* **sa (swap a)**: Swap the first 2 elements at the top of stack a.
* **sb (swap b)**: Swap the first 2 elements at the top of stack b.
* **ss** : sa and sb at the same time.
* **pa (push a)**: Take the first element at the top of b and put it at the top of a.
* **pb (push b)**: Take the first element at the top of a and put it at the top of b.
* **ra (rotate a)**: Shift up all elements of stack a by 1 (the first element becomes the last one).
* **rb (rotate b)**: Shift up all elements of stack b by 1 (the first element becomes the last one).
* **rr** : ra and rb at the same time.
* **rra (reverse rotate a)**: Shift down all elements of stack a by 1 (the last element becomes the first one).
* **rrb (reverse rotate b)**: Shift down all elements of stack b by 1 (the last element becomes the first one).
* **rrr** : rra and rrb at the same time.

## Instructions

This project includes a `Makefile`. Once you have clone the git repository, here is the command that you have to make :
To compile all the file and create the program named _**push_swap**_
```bash
make all
```
To run this program you have to launch it as follows.
```bash
./push_swap int_1 int_2 int_3 ... int_n
```
Once you have finished using this program, you can use this command to delete all object files.
```bash
make clean
```
Or this command, to delete the program and its objects.
```bash
make fclean
```

## Resources

### References
* This article helped me to understand the Turkish algorithm that i used to sort the data : [Turkish Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97).
* This article help me to understand and use [Circular Doubly Linked List](http://sdz.tdct.org/sdz/les-listes-circulaires-doublement-chainees-en-c.html).

###Use of AI
I used AI on this project to help me on a few tasks:
* **Debugging**: Identifying logic errors in the main sorting loop (specifically ensuring exactly 3 elements remain in stack A) and fixing Makefile syntax errors.
* **Guidance & Direction**: Providing a roadmap for the project's advancement, helping in understanding the most efficient "cost calculation" strategy.