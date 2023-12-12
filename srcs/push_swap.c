/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:46:25 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/12 11:07:08 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
1. check if input are valid number
	1.1 if input is not valid, return "ERROR/n" and exit the program

2. insert number in stack a

3. sort stack a with available instruction
	3.1 insert operation in lst
	3.2 if duplicates number are compared, return "ERROR/n" and exit the program

4. check if all number increment == there is no duplicates

5. print operations followed by a \n
*/

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*operations;

	stack_a = NULL;
	stack_b = NULL;
	operations = NULL;
	if (argc >= 2)
	{
		if (input_is_valid(argc, argv))
			insert_int_in_stack(stack_a, argc, argv);
		else
			return (1);
		sort_stack(stack_a, stack_b, operations);
		if (ints_are_uniq(stack_a))
			print_operations(operations);
		else
			return (1);
	}
	return (0);
}

void	insert_int_in_stack(t_list *stack_a, int argc, char **argv)
{
	(void)stack_a;
	(void)argc;
	(void)argv;
	ft_printf("welcome in insert_int_in_stack function\n");
}

void	sort_stack(t_list *stack_a, t_list *stack_b, t_list *operations)
{
	(void)stack_a;
	(void)stack_b;
	(void)operations;
	ft_printf("welcome in sort_stack function\n");
}

void	print_operations(t_list *operations)
{
	(void)operations;
	ft_printf("welcome in print_operations function\n");
}
