# Goals
The Push swap project is a very simple and a highly straightforward algorithm project: data must be sorted. You have at your disposal a set of integer values, 2 stacks, and a set of instructions to manipulate both stacks.
The goal is to write a program in C called push_swap which calculates and displays on the standard output the smallest program, made of Push swap language instructions, that sorts the integers received as arguments.

The learning objectives of this project are rigor, use of C, and use of basic algorithms. Especially focusing on their complexity. Sorting values is simple. To sort them the fastest way possible is less simple. Especially because from one integers configuration to another, the most efficient sorting solution can differ.

## Rules
- You have 2 stacks named a and b.
- At the beginning:
	- The stack a contains a random amount of negative and/or positive numbers
	- which cannot be duplicated.
	- The stack b is empty.
	- The goal is to sort in ascending order numbers into stack a. To do so you have the
- following operations at your disposal:

<table>
	<thead>
        <tr>
            <th>Operations</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
	</thead>
        <tr>
            <td align="center">sa</td>
            <td>(swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.</td>
        </tr>
        <tr>
            <td align="center">sb</td>
            <td>(swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.</td>
        </tr>
        <tr>
            <td align="center">ss</td>
            <td>sa and sb at the same time.</td>
        </tr>
        <tr>
            <td align="center">pa</td>
            <td>(push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.</td>
        </tr>
        <tr>
            <td align="center">pb</td>
            <td>(push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.</td>
        </tr>
        <tr>
            <td align="center">ra</td>
            <td>(rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.</td>
        </tr>
        <tr>
            <td align="center">rb</td>
            <td>(rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.</td>
        </tr>
		<tr>
            <td align="center">rr</td>
            <td>ra and rb at the same time.</td>
        </tr>
        <tr>
            <td align="center">rra</td>
            <td>(reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one</td>
        </tr>
		<tr>
            <td align="center">rrb</td>
            <td>(reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.</td>
        </tr>
        <tr>
            <td align="center">rrr</td>
            <td>rra and rrb at the same time.</td>
        </tr>
    </tbody>
</table>


- You have to turn in a Makefile which will compile your source files. It must not relink.
- You have to write a program named push_swap that takes as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).
- The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top.
- Instructions must be separated by a ’\n’ and nothing else.
- The goal is to sort the stack with the lowest possible number of operations. During the evaluation process, the number of instructions found by your program will be compared against a limit: the maximum number of operations tolerated. If your program either displays a longer list or if the numbers aren’t sorted properly, your grade will be 0.
- If no parameters are specified, the program must not display anything and give the prompt back.
- In case of error, it must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer and/or there are duplicates.

  ### Forbidden
	- Global variables are forbidden.

## Bonus
- Write a program named checker that takes as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order). If no argument is given, it stops and displays nothing.
- It will then wait and read instructions on the standard input, each instruction will be followed by ’\n’. Once all the instructions have been read, the program has to execute them on the stack received as an argument.
- If after executing those instructions, the stack a is actually sorted and the stack b is empty, then the program must display "OK" followed by a ’\n’ on the standard output.
- In every other case, it must display "KO" followed by a ’\n’ on the standard output.
- In case of error, you must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments are not integers, some arguments are bigger than an integer, there are duplicates, an instruction doesn’t exist and/or is incorrectly formatted.

# Result :slot_machine:
<img width="163" alt="push_swap_score" src="https://github.com/Benoilte/push_swap/assets/104198121/20301089-082d-40c5-ab5e-bf5772fa430d">


# Usage

``make``

Run the program with
```bash
./push_swap 7 42 123 -900 6789 3
```

Return exemple:

```text
pb
pb
pb
rra
sa
rra
pa
pa
pa
rra
rra
```

Run the program with
```bash
./push_swap 7 42 123 -900 6789 3 | wc -l
```

Return exemple:

```text
11
```

# Advance usage

``make``

Run the program
```bash
./push_swap 7 42 123 -900 6789 3 | ./checker 7 42 123 -900 6789 3
```

Return exemple:

```text
OK
```

Run the program

```bash
./push_swap 7 42 12a -900 6789 3 | ./checker 7 42 12a -900 6789 3
```

Return exemple:

```text
Error
```
