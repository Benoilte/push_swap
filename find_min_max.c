/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:47:09 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/12 22:19:29 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Return the smaller number of the stack
*/
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

/*
Return the bigger number of the stack
*/
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
