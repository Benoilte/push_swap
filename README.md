# Goals
The Push swap project is a very simple and a highly straightforward algorithm project: data must be sorted. You have at your disposal a set of integer values, 2 stacks, and a set of instructions to manipulate both stacks.
The goal is to write a program in C called push_swap which calculates and displays on the standard output the smallest program, made of Push swap language instructions, that sorts the integers received as arguments.

The learning objectives of this project are rigor, use of C, and use of basic algorithms. Especially focusing on their complexity. Sorting values is simple. To sort them the fastest way possible is less simple. Especially because from one integers configuration to another, the most efficient sorting solution can differ.

## Rules
You have 2 stacks named a and b.
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


  ### Forbidden


## Bonus


# Result :slot_machine:


# Usage

``make``

Run the program with
```bash
./
```

Return exemple:

```text
....
```

# Advance usage

``make``

Run the program

```bash
./
```

Return exemple:

```text
....
```
