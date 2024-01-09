/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:27:33 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/09 15:41:20 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
Trouver la position de lst dans stack out.
Calculer nombre de mouvement dans stack out a effectuer
pour amener lst en prmière position.

trouver la position ou lst doit aller dans stack in.
Calculer nombre de mouvement dans stack in pour amener
lst en bonne position (ordrée)

Comparer si il y a une similitude de ra - rb ou rra - rrb operation.
*/

int	count_move(t_list *lst, t_list *stack_out, t_list *stack_in, char in)
{
	int		out_size;
	int		in_size;
	t_index	pos;

	out_size = ft_lstsize(stack_out);
	in_size = ft_lstsize(stack_in);
	pos.out = get_lst_index(stack_out, lst);
	if (in == 'a')
		pos.in = find_new_position_in_stack_a(lst, stack_in);
	else if (in == 'b')
		pos.in = find_new_position_in_stack_b(lst, stack_in);
	if ((pos.out > (ft_lstsize(stack_out) / 2)))
	{
		if ((pos.in > (ft_lstsize(stack_in) / 2)))
			return (bigger_number(in_size - pos.in, out_size - pos.out));
		else
			return (pos.in + (out_size - pos.out));
	}
	else
	{
		if ((pos.in <= (ft_lstsize(stack_in) / 2)))
			return (bigger_number(pos.in, pos.out));
		else
			return ((in_size - pos.in) + pos.out);
	}
}

int	bigger_number(int index_in, int index_out)
{
	if (index_in > index_out)
		return (index_in);
	else
		return (index_out);
}

int	find_new_position_in_stack_b(t_list *lst, t_list *stack)
{
	int		index;
	t_list	*tmp;
	t_list	*min;
	t_list	*max;

	index = -1;
	if (ft_lstsize(stack) == 0)
		return (0);
	min = get_min(stack);
	max = get_max(stack);
	if (*((int *)(lst->content)) < *((int *)(min->content)))
		return (get_lst_index(stack, max));
	if (*((int *)(lst->content)) > *((int *)(max->content)))
		return (get_lst_index(stack, max));
	tmp = stack;
	while (tmp->next)
	{
		if ((*((int *)(lst->content)) < *((int *)(tmp->content)))
			&& (*((int *)(lst->content)) > *((int *)(tmp->next->content))))
			return (get_lst_index(stack, tmp->next));
		tmp = tmp->next;
	}
	return (0);
}

int	find_new_position_in_stack_a(t_list *lst, t_list *stack)
{
	int		index;
	t_list	*tmp;
	t_list	*min;
	t_list	*max;

	index = -1;
	min = get_min(stack);
	max = get_max(stack);
	if (*((int *)(lst->content)) < *((int *)(min->content)))
		return (get_lst_index(stack, min));
	if (*((int *)(lst->content)) > *((int *)(max->content)))
		return (get_lst_index(stack, min));
	tmp = stack;
	while (tmp->next)
	{
		if ((*((int *)(lst->content)) > *((int *)(tmp->content)))
			&& (*((int *)(lst->content)) < *((int *)(tmp->next->content))))
			return (get_lst_index(stack, tmp->next));
		tmp = tmp->next;
	}
	return (0);
}
