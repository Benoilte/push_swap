/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:59:25 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/22 11:20:26 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
apres avoir trouver le numéro qui coute le moins d'opération
push le numéro au bonne endroit dans la stack à insérer

contrôler si il est possible d'effectuer des opération similaire
sur la stack a et la stack b
*/
void	sort_big_stack(t_list **stack_a, t_list **operations)
{
	t_list	*stack_b;
	t_list	*range;
	t_list	*cheapest;
	int		min_pos;

	stack_b = NULL;
	range = NULL;
	if (is_sorted_not_ordered(*stack_a))
	{
		min_pos = get_lst_index(*stack_a, get_min(*stack_a));
		move_lst_on_top_of_a(stack_a, operations, min_pos);
		return ;
	}
	find_biggest_sorted_range(*stack_a, &range);
	display_struct(range, 'd', "range");
	ft_pb(&stack_b, stack_a, operations);
	ft_pb(&stack_b, stack_a, operations);
	while ((ft_lstsize(*stack_a) > 3) && (is_sorted_not_ordered(*stack_a) == 0) && (is_sorted(*stack_a) == 0))
		move_a_to_b(stack_a, &stack_b, operations, range);
	display_struct(*stack_a, 'd', "stack_a");
	if (ft_lstsize(*stack_a) == 3)
		sort_stack_of_3(stack_a, operations);
	while (ft_lstsize(stack_b) > 0)
		move_b_to_a(&stack_b, stack_a, operations);
	min_pos = get_lst_index(*stack_a, get_min(*stack_a));
	move_lst_on_top_of_a(stack_a, operations, min_pos);
	ft_lstclear(&range, &del);
}

void	move_a_to_b(t_list **out, t_list **in, t_list **operations, t_list *range)
{
	int		out_size;
	int		in_size;
	t_list	*cheapest;
	t_index	pos;

	cheapest = find_cheapest_number(*out, *in, 'b', range);
	out_size = ft_lstsize(*out);
	in_size = ft_lstsize(*in);
	pos.out = get_lst_index(*out, cheapest);
	pos.in = find_new_position_in_stack_b(cheapest, *in);
	if ((pos.out > (out_size / 2)) && (pos.in > (in_size / 2)))
		reverse_both(out, in, pos, operations);
	else if ((pos.out <= (out_size / 2)) && (pos.in <= (in_size / 2)))
		rotate_both(out, in, pos, operations);
	else
	{
		move_lst_on_top_of_a(out, operations, pos.out);
		move_lst_on_top_of_b(in, operations, pos.in);
		return ;
	}
	if (pos.in > pos.out)
		move_lst_on_top_of_b(in, operations, pos.in - pos.out);
	else if (pos.out > pos.in)
		move_lst_on_top_of_a(out, operations, pos.out - pos.in);
	ft_pb(in, out, operations);
}

void	move_b_to_a(t_list **out, t_list **in, t_list **operations)
{
	int		out_size;
	int		in_size;
	t_list	*cheapest;
	t_index	pos;

	cheapest = find_cheapest_number(*out, *in, 'a', NULL);
	out_size = ft_lstsize(*out);
	in_size = ft_lstsize(*in);
	pos.out = get_lst_index(*out, cheapest);
	pos.in = find_new_position_in_stack_a(cheapest, *in);
	if ((pos.out > (out_size / 2)) && (pos.in > (in_size / 2)))
		reverse_both(out, in, pos, operations);
	else if ((pos.out <= (out_size / 2)) && (pos.in <= (in_size / 2)))
		rotate_both(out, in, pos, operations);
	else
	{
		move_lst_on_top_of_a(in, operations, pos.in);
		move_lst_on_top_of_b(out, operations, pos.out);
		return ;
	}
	if (pos.in > pos.out)
		move_lst_on_top_of_a(in, operations, pos.out - pos.in);
	else if (pos.out > pos.in)
		move_lst_on_top_of_b(out, operations, pos.in - pos.out);
	ft_pa(in, out, operations);
}

t_list	*find_cheapest_number(t_list *stack_out, t_list *stack_in, char inner, t_list *range)
{
	t_list	*tmp;
	t_list	*cheapest;
	int		move;

	tmp = stack_out;
	// display_struct(stack_out, 'd', "stack_a");
	while (tmp && ft_include(tmp, range))
		tmp = tmp->next;
	move = count_move(tmp, stack_out, stack_in, inner);
	cheapest = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		if ((count_move(tmp, stack_out, stack_in, inner) < move))
		{
			move = count_move(tmp, stack_out, stack_in, inner);
			cheapest = tmp;
		}
		if (tmp && ft_include(tmp, range))
		{
			while (tmp && ft_include(tmp, range))
				tmp = tmp->next;
		}
		else
			tmp = tmp->next;
	}
	return (cheapest);
}

int	ft_include(t_list *lst, t_list *range)
{
	t_list	*tmp;

	tmp = range;
	while (tmp)
	{
		if (*((int *)(lst->content)) == *((int *)(tmp->content)))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
