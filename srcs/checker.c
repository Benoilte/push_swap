/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:36:13 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/12 18:20:43 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

/*
1. check if input are valid numbers
	1.1 if input is not valid, return "ERROR/n" and exit the program

2. insert number in stack a

3. check if all number increment == there is no duplicates
	3.1 if there is duplicate number return ERROR\n and exit the program

4. sort stack a with operation send from ./push_swap program
	4.1 if operation is not perform (operation does not exist) return ERROR\n

5. Check if the stack_a is sorted
	5.1 if stack_a return OK\n
	5.2 if stack_a is not sorted or if stack_b is not empty return KO\n
*/

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		op_is_not_performed;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		if (input_is_valid(argc, argv))
			insert_int_in_stack(&stack_a, argc, 1, argv);
		else
			return (0);
		if (ints_are_uniq(stack_a))
		{
			op_is_not_performed = checker_sort_stack(&stack_a, &stack_b);
			if (op_is_not_performed)
			{
				free_stack(&stack_a, &stack_b);
				return (ft_error());
			}
			checker_is_stack_sorted(stack_a, stack_b);
		}
	}
	free_stack(&stack_a, &stack_b);
	return (0);
}

/*
Sort stack_a and check if all operations are performed.
Return 0 if all operation are performed
Return 1 if an operation is not performed
*/
int	checker_sort_stack(t_list **stack_a, t_list **stack_b)
{
	char	*line;
	int		op_is_not_performed;

	line = get_next_line(0);
	op_is_not_performed = 1;
	while (line)
	{
		op_is_not_performed = checker_perform_op(stack_a, stack_b, line);
		free(line);
		if (op_is_not_performed)
			return (1);
		line = get_next_line(0);
	}
	return (0);
}

/*
Perform operation send in argument
Return 0 if all operation are performed
Return 1 if an operation does not exist
*/
int	checker_perform_op(t_list **stack_a, t_list **stack_b, char *op)
{
	if (ft_strncmp(op, "sa\n", ft_strlen(op)) == 0)
		ft_sa(stack_a, NULL);
	else if (ft_strncmp(op, "sb\n", ft_strlen(op)) == 0)
		ft_sb(stack_b, NULL);
	else if (ft_strncmp(op, "ss\n", ft_strlen(op)) == 0)
		ft_ss(stack_a, stack_b, NULL);
	else if (ft_strncmp(op, "pa\n", ft_strlen(op)) == 0)
		ft_pa(stack_a, stack_b, NULL);
	else if (ft_strncmp(op, "pb\n", ft_strlen(op)) == 0)
		ft_pb(stack_b, stack_a, NULL);
	else if (ft_strncmp(op, "ra\n", ft_strlen(op)) == 0)
		ft_ra(stack_a, NULL);
	else if (ft_strncmp(op, "rb\n", ft_strlen(op)) == 0)
		ft_rb(stack_b, NULL);
	else if (ft_strncmp(op, "rr\n", ft_strlen(op)) == 0)
		ft_rr(stack_a, stack_b, NULL);
	else if (ft_strncmp(op, "rra\n", ft_strlen(op)) == 0)
		ft_rra(stack_a, NULL);
	else if (ft_strncmp(op, "rrb\n", ft_strlen(op)) == 0)
		ft_rrb(stack_b, NULL);
	else if (ft_strncmp(op, "rrr\n", ft_strlen(op)) == 0)
		ft_rrr(stack_a, stack_b, NULL);
	else
		return (1);
	return (0);
}

/*
If stack_a return OK\n
If stack_a is not sorted or if stack_b is not empty return KO\n
*/
void	checker_is_stack_sorted(t_list *stack_a, t_list *stack_b)
{
	if (is_sorted(stack_a) && ft_lstsize(stack_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
