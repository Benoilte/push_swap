/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:46:25 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/15 21:55:27 by bebrandt         ###   ########.fr       */
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
			insert_int_in_stack(&stack_a, argc, 1, argv);
		else
			return (1);
		display_struct(stack_a, 'd', "n");
		sort_stack(&stack_a, &stack_b, &operations);
		display_struct(stack_a, 'd', "n");
		if (ints_are_uniq(stack_a))
			print_operations(operations);
		else
		{
			ft_lstclear(&stack_a, &del);
			ft_lstclear(&operations, &del);
			return (1);
		}
	}
	ft_lstclear(&stack_a, &del);
	ft_lstclear(&operations, &del);
	return (0);
}

void	insert_int_in_stack(t_list **stack_a, int argc, int i, char **argv)
{
	int		*n;
	int		size;
	char	**numbers;

	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			numbers = ft_split(argv[i], ' ');
			size = 0;
			while (numbers[size])
				size++;
			insert_int_in_stack(stack_a, size, 0, numbers);
			free_strstr(numbers);
		}
		else
		{
			n = ft_calloc(1, sizeof(int *));
			*n = ft_atoi(argv[i]);
			ft_lstadd_back(stack_a, ft_lstnew(n));
		}
		i++;
	}
}

void	sort_stack(t_list **stack_a, t_list **stack_b, t_list **operations)
{
	int	stack_size;

	(void)operations;
	(void)stack_b;
	stack_size = ft_lstsize(*stack_a);
	if (is_sorted(*stack_a))
	{
		ft_printf("\033[0;35mstack is sorted\n\033[0m");
		return ;
	}
	if (stack_size == 1)
		return ;
	else if (stack_size == 2)
		sort_stack_of_2(stack_a, 'a', operations);
	else if (stack_size == 3)
		sort_stack_of_3(stack_a, operations);
	else if (stack_size == 4)
		sort_stack_of_4(stack_a, operations);
	else if (stack_size == 5)
		sort_stack_of_5(stack_a, operations);
	else
		sort_big_stack(stack_a, operations);
}

void	print_operations(t_list *operations)
{
	t_list	*tmp;

	tmp = operations;
	while (tmp)
	{
		ft_printf("%s", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\033[0;33moperations number = %d\n\033[0m", ft_lstsize(operations));
}

void	display_struct(t_list *lst, char data, char *text)
{
	t_list	*tmp;

	tmp = lst;
	if (tmp)
		ft_printf("Stack a\n");
	else
		ft_printf("something is not working\n");
	while (tmp)
	{
		if (data == 'd')
			ft_printf("%s: %d\n", text, *((int *)(tmp->content)));
		if (data == 's')
			ft_printf("%s: %s\n", text, tmp->content);
		tmp = tmp->next;
	}
}
