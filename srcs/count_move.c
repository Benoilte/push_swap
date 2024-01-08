/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:27:33 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/08 08:56:02 by bebrandt         ###   ########.fr       */
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

int	count_move(t_list *lst, t_list *stack_out, t_list *stack_in, char inner)
{
	int		lst_out_size;
	int		lst_in_size;
	t_index	pos;

	lst_out_size = ft_lstsize(stack_out);
	lst_in_size = ft_lstsize(stack_in);
	pos.out = get_lst_index(stack_out, lst);
	if (inner == 'a')
		pos.in = find_new_position_in_stack_a(lst, stack_in);
	else if (inner == 'b')
		pos.in = find_new_position_in_stack_b(lst, stack_in);
	if ((pos.out > (ft_lstsize(stack_out) / 2)))
	{
		if ((pos.in > (ft_lstsize(stack_in) / 2)))
			return (count_move_with_shortcut(lst_in_size, lst_out_size) + 1);
		else
			return (pos.in + (lst_out_size - pos.out) + 1);
	}
	else
	{
		if ((pos.in <= (ft_lstsize(stack_in) / 2)))
			return (count_move_with_shortcut(pos.in, pos.out) + 1);
		else
			return ((lst_in_size - pos.in) + pos.out + 1);
	}
}

int	count_move_with_shortcut(int index_in, int index_out)
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
