/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:35:38 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/19 12:19:16 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/push_swap.h"

/*
Check if the stack is already sorted
*/
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

/*
Check if the stack is already sorted
but the min number are not at the top of the stack
*/
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
