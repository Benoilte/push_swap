/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:35:38 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/22 10:33:37 by bebrandt         ###   ########.fr       */
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

/*
find min value

itarate through stack from min value until we reach again the min value

if we find a sorted range bigger or equal to 3 we keep its position 
and count how many ints are following in croissant order
*/

void	find_biggest_sorted_range(t_list *stack, t_list **range)
{
	t_list	*min;
	t_list	*tmp;
	t_list	*first;
	int		range_size;

	tmp = stack;
	min = get_min(stack);
	tmp = min->next;
	range_size = count_sorted_range_size(stack, min, min);
	first = min;
	while (tmp != min)
	{
		if (count_sorted_range_size(stack, tmp, min) > range_size)
		{
			range_size = count_sorted_range_size(stack, tmp, min);
			first = tmp;
		}
		tmp = tmp->next;
		if (!tmp)
			tmp = stack;
	}
	if (range_size >= 3)
		copy_range(stack, first, range_size, range);
}

int	count_sorted_range_size(t_list *stack, t_list *lst, t_list *min)
{
	t_list	*tmp;
	t_list	*prev;
	int		i;

	prev = lst;
	tmp = lst->next;
	if (!tmp)
		tmp = stack;
	i = 1;
	while (tmp != min)
	{
		if (*((int *)(prev->content)) < *((int *)(tmp->content)))
			i++;
		else
			return (i);
		prev = tmp;
		tmp = tmp->next;
		if (!tmp)
			tmp = stack;
	}
	return (i);
}

void	copy_range(t_list *stack, t_list *first, int size, t_list **range)
{
	t_list	*tmp;
	int		*n;

	tmp = first;
	ft_printf("size: %d\n", size);
	while (size > 0)
	{
		n = ft_calloc(1, sizeof(int *));
		if (!n)
		{
			ft_lstclear(range, &del);
			return ;
		}
		*n = *((int *)(tmp->content));
		ft_lstadd_back(range, ft_lstnew(n));
		tmp = tmp->next;
		if (!tmp)
			tmp = stack;
		size--;
	}
}
