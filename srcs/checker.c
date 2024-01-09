/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:36:13 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/09 10:34:15 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

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

void	checker_is_stack_sorted(t_list *stack_a, t_list *stack_b)
{
	if (is_sorted(stack_a) && ft_lstsize(stack_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	display_struct(t_list *lst, char data, char *text)
{
	t_list	*tmp;

	tmp = lst;
	if (!tmp)
		ft_printf("struct is empty\n");
	while (tmp)
	{
		if (data == 'd')
			ft_printf("%s: %d\n", text, *((int *)(tmp->content)));
		if (data == 's')
			ft_printf("%s: %s\n", text, tmp->content);
		tmp = tmp->next;
	}
}
