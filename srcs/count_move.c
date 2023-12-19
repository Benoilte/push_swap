/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:27:33 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/19 20:51:23 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
Trouver la position de lst dans stack out.
Calculer nombre de mouvement dans stack out a effectuer pour amener lst en prmière position.

trouver la position ou lst doit aller dans stack in.
Calculer nombre de mouvement dans stack in pour amener lst en bonne position (ordrée)

Comparer si il y a une similitude de ra - rb ou rra - rrb operation.
*/

int	count_move(t_list *lst, t_list *stack_out, t_list *stack_in)
{
	int		lst_out_index;
	int		lst_in_index;
	int		move;
	t_list	*tmp;
	t_list	*min;

	lst_out_index = get_lst_index(stack_out, lst);
	lst_in_index = find_index_previous_number(lst, stack_in);
	display_struct(stack_in, 'd', "stack_b");
	ft_printf("index_in : %d\n", lst_in_index);
	if ((lst_out_index < (ft_lstsize(stack_out) / 2)) && (lst_in_index < (ft_lstsize(stack_in) / 2)))
		move = lst_out_index;
	else if (lst_out_index < (ft_lstsize(stack_out) / 2))
		move = lst_out_index;
	else if (lst_out_index < (ft_lstsize(stack_out) / 2))
		move = lst_out_index;
	else if (lst_out_index < (ft_lstsize(stack_out) / 2))
		move = lst_out_index;
	return (move);
}

int	find_index_previous_number(t_list *lst, t_list *stack)
{
	int		index;
	t_list	*tmp;
	t_list	*min;
	t_list	*max;

	index = -1;
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
	return (index);
}
