/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:58:49 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/09 10:40:43 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

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

void	sort_stack_of_4_or_5(t_list **stack_a, t_list **operations)
{
	t_list	*stack_b;
	int		min_pos;

	stack_b = NULL;
	min_pos = get_lst_index(*stack_a, get_min(*stack_a));
	move_lst_on_top_of_a(stack_a, operations, min_pos);
	if (is_sorted(*stack_a))
		return ;
	while (ft_lstsize(*stack_a) > 3)
	{
		min_pos = get_lst_index(*stack_a, get_min(*stack_a));
		move_lst_on_top_of_a(stack_a, operations, min_pos);
		ft_pb(&stack_b, stack_a, operations);
	}
	sort_stack_of_3(stack_a, operations);
	while (ft_lstsize(stack_b) > 0)
		ft_pa(stack_a, &stack_b, operations);
}
