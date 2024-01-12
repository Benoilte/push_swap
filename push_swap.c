/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:46:25 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/12 22:20:03 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
1. check if input are valid numbers
	1.1 if input is not valid, return "ERROR/n" and exit the program

2. insert number in stack a

3. check if all number increment == there is no duplicates
	3.1 if there is duplicate number return ERROR\n and exit the program

4. sort stack a with available instruction
	4.1 insert operation in lst

5. print operations followed by a \n
*/

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*operations;

	stack_a = NULL;
	operations = NULL;
	if (argc >= 2)
	{
		if (input_is_valid(argc, argv))
			insert_int_in_stack(&stack_a, argc, 1, argv);
		else
			return (2);
		if (ints_are_uniq(stack_a))
		{
			sort_stack(&stack_a, &operations);
			print_operations(operations);
		}
		else
		{
			ft_lstclear(&stack_a, &del);
			return (2);
		}
	}
	ft_lstclear(&stack_a, &del);
	ft_lstclear(&operations, &del);
	return (0);
}

/*
If stack is already oredered return.
Applied an Algorithm according to the stack size.
(different size: 2 / 3 / 4 or 5 / > 5)
*/
void	sort_stack(t_list **stack_a, t_list **operations)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	else if (stack_size == 2)
		sort_stack_of_2(stack_a, 'a', operations);
	else if (stack_size == 3)
		sort_stack_of_3(stack_a, operations);
	else if (stack_size <= 5)
		sort_stack_of_4_or_5(stack_a, operations);
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
}

void	ft_lstdisplay(t_list *lst, char *text)
{
	t_list	*tmp;

	tmp = lst;
	if (!tmp)
		ft_printf("struct is empty\n");
	while (tmp)
	{
		ft_printf("%s: %d\n", text, *((int *)(tmp->content)));
		tmp = tmp->next;
	}
}
