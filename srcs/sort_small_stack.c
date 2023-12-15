/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:58:49 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/15 22:03:58 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_of_2(t_list **stack, char order, t_list **operations)
{
	int	first_pos;
	int	second_pos;

	first_pos = *((int *)((*stack)->content));
	second_pos = *((int *)((*stack)->next->content));
	if ((first_pos > second_pos) && (order == 'a'))
		ft_sa(stack, operations);
	if ((first_pos > second_pos) && (order == 'b'))
		ft_sb(stack, operations);
}

void	sort_stack_of_3(t_list **stack_a, t_list **operations)
{
	int	first_pos;
	int	second_pos;
	int	third_pos;

	first_pos = *((int *)((*stack_a)->content));
	second_pos = *((int *)((*stack_a)->next->content));
	third_pos = *((int *)((*stack_a)->next->next->content));
	if ((first_pos > second_pos) && (second_pos > third_pos))
	{
		ft_ra(stack_a, operations);
		ft_sa(stack_a, operations);
	}
	else if ((first_pos < third_pos) && (second_pos > third_pos))
	{
		ft_rra(stack_a, operations);
		ft_sa(stack_a, operations);
	}
	else if (second_pos > third_pos)
		ft_rra(stack_a, operations);
	else if (first_pos > third_pos)
		ft_ra(stack_a, operations);
	else if (first_pos > second_pos)
		ft_sa(stack_a, operations);
}

void	sort_stack_of_4(t_list **stack_a, t_list **operations)
{
	t_list	*stack_b;

	stack_b = NULL;
	move_min_on_top(stack_a, operations);
	if (is_sorted(*stack_a))
	{
		ft_printf("\033[0;36mstack of 4 is sorted\n\033[0m");
		return ;
	}
	ft_pb(&stack_b, stack_a, operations);
	sort_stack_of_3(stack_a, operations);
	ft_pa(stack_a, &stack_b, operations);
}

void	sort_stack_of_5(t_list **stack_a, t_list **operations)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (is_sorted_not_ordered(*stack_a))
	{
		ft_printf("\033[0;36mstack of 5 is sorted not in order\n\033[0m");
		move_min_on_top(stack_a, operations);
		return ;
	}
	move_min_on_top(stack_a, operations);
	ft_pb(&stack_b, stack_a, operations);
	move_min_on_top(stack_a, operations);
	ft_pb(&stack_b, stack_a, operations);
	sort_stack_of_3(stack_a, operations);
	ft_pa(stack_a, &stack_b, operations);
	ft_pa(stack_a, &stack_b, operations);
}
