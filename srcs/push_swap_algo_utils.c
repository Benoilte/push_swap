/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:22:34 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/20 10:39:49 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_list	*get_min(t_list *stack)
{
	t_list	*min;
	t_list	*tmp;

	tmp = stack;
	min = stack;
	while (tmp)
	{
		if (*((int *)(tmp->content)) < *((int *)(min->content)))
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_list	*get_max(t_list *stack)
{
	t_list	*max;
	t_list	*tmp;

	tmp = stack;
	max = stack;
	while (tmp)
	{
		if (*((int *)(tmp->content)) > *((int *)(max->content)))
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int	get_lst_index(t_list *stack_a, t_list *lst)
{
	t_list	*tmp;
	int		lst_index;

	lst_index = 0;
	tmp = stack_a;
	while (tmp != lst)
	{
		lst_index++;
		tmp = tmp->next;
	}
	return (lst_index);
}

void	move_lst_on_top_of_a(t_list **stack_a, t_list **operations, int index)
{
	t_list	*tmp;
	int		size;

	tmp = *stack_a;
	size = ft_lstsize(*stack_a);
	if (index > (size / 2))
	{
		while (index++ < size)
			ft_rra(stack_a, operations);
	}
	else
	{
		while (index-- > 0)
			ft_ra(stack_a, operations);
	}
}

void	move_lst_on_top_of_b(t_list **stack_a, t_list **operations, int index)
{
	t_list	*tmp;
	int		size;

	tmp = *stack_a;
	size = ft_lstsize(*stack_a);
	if (index > (size / 2))
	{
		while (index++ < size)
			ft_rrb(stack_a, operations);
	}
	else
	{
		while (index-- > 0)
			ft_rb(stack_a, operations);
	}
}
