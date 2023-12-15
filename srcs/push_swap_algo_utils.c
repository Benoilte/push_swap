/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:22:34 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/15 21:19:37 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack_a)
{
	t_list	*next;
	t_list	*prev;

	prev = stack_a;
	next = stack_a->next;
	while (next)
	{
		if (*((int *)(prev->content)) > *((int *)(next->content)))
			return (0);
		prev = next;
		next = next->next;
	}
	return (1);
}

int	is_sorted_not_ordered(t_list *stack_a)
{
	t_list	*min;
	t_list	*tmp;
	t_list	*prev;

	tmp = stack_a;
	min = get_min_pos(stack_a);
	prev = min;
	tmp = min->next;
	while (tmp != min)
	{
		if (!tmp)
			tmp = stack_a;
		if (*((int *)(prev->content)) > *((int *)(tmp->content)))
			return (0);
		prev = tmp;
		tmp = tmp->next;
	}
	return (1);
}

t_list	*get_min_pos(t_list *stack_a)
{
	t_list	*min;
	t_list	*tmp;

	tmp = stack_a;
	min = stack_a;
	while (tmp)
	{
		if (*((int *)(tmp->content)) < *((int *)(min->content)))
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

int	get_min_pos_index(t_list *stack_a)
{
	t_list	*min;
	t_list	*tmp;
	int		pos_index;

	pos_index = 0;
	min = get_min_pos(stack_a);
	tmp = stack_a;
	while (tmp != min)
	{
		pos_index++;
		tmp = tmp->next;
	}
	return (pos_index);
}

void	move_min_on_top(t_list **stack_a, t_list **operations)
{
	t_list	*min;
	t_list	*tmp;
	int		pos_index;
	int		size;

	min = get_min_pos(*stack_a);
	pos_index = get_min_pos_index(*stack_a);
	tmp = *stack_a;
	size = ft_lstsize(*stack_a);
	if (pos_index > (size / 2))
	{
		while (pos_index++ < size)
			ft_rra(stack_a, operations);
	}
	else
	{
		while (pos_index-- > 0)
			ft_ra(stack_a, operations);
	}
}
