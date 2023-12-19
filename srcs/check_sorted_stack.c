/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:35:38 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/19 20:35:40 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

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
	min = get_min(stack_a);
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