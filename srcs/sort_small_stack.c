/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:58:49 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/15 19:58:48 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_of_2(t_list **stack_a, t_list **operations)
{
	int	first_pos;
	int	second_pos;

	first_pos = *((int *)((*stack_a)->content));
	second_pos = *((int *)((*stack_a)->next->content));
	if (first_pos > second_pos)
		ft_sa(stack_a, operations);
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
	if (is_sorted_not_ordered(*stack_a))
	{
		ft_printf("\033[0;36mstack of 4 is sorted not in order\n\033[0m");
		order_the_stack(stack_a, operations);
	}
}

void	sort_stack_of_5(t_list **stack_a, t_list **operations)
{
	if (is_sorted_not_ordered(*stack_a))
	{
		ft_printf("\033[0;36mstack of 5 is sorted not in order\n\033[0m");
		order_the_stack(stack_a, operations);
	}
}
