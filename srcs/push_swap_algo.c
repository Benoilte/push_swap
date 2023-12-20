/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:59:25 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/20 19:41:58 by bebrandt         ###   ########.fr       */
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
	t_list	*cheapest;
	int		min_pos;

	stack_b = NULL;
	if (is_sorted_not_ordered(*stack_a))
	{
		min_pos = get_lst_index(*stack_a, get_min(*stack_a));
		move_lst_on_top_of_a(stack_a, operations, min_pos);
		return ;
	}
	ft_pb(&stack_b, stack_a, operations);
	ft_pb(&stack_b, stack_a, operations);
	while (ft_lstsize(*stack_a) > 3)
	{
		move_a_to_b(stack_a, &stack_b, operations);
		ft_pb(&stack_b, stack_a, operations);
	}
	// display_struct(stack_b, 'd', "stack_b");
	sort_stack_of_3(stack_a, operations);
	// display_struct(*stack_a, 'd', "stack_a");
	while (ft_lstsize(stack_b) > 0)
	{
		move_b_to_a(&stack_b, stack_a, operations);
		ft_pa(stack_a, &stack_b, operations);
	}
	min_pos = get_lst_index(*stack_a, get_min(*stack_a));
	move_lst_on_top_of_a(stack_a, operations, min_pos);
}

void	move_a_to_b(t_list **out, t_list **in, t_list **operations)
{
	int		out_size;
	int		in_size;
	t_list	*cheapest;
	t_index	pos;

	cheapest = find_cheapest_number(*out, *in, 'b');
	out_size = ft_lstsize(*out);
	in_size = ft_lstsize(*in);
	pos.out = get_lst_index(*out, cheapest);
	pos.in = find_new_position_in_stack_b(cheapest, *in);
	// ft_printf("cheapest: %d - pos.out: %d - pos.in: %d\n", *((int *)(cheapest->content)), pos.out, pos.in);
	// display_struct(*in, 'd', "stack_b");
	// display_struct(*out, 'd', "stack_a");
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
}

void	move_b_to_a(t_list **out, t_list **in, t_list **operations)
{
	int		out_size;
	int		in_size;
	t_list	*cheapest;
	t_index	pos;

	cheapest = find_cheapest_number(*out, *in, 'a');
	out_size = ft_lstsize(*out);
	in_size = ft_lstsize(*in);
	pos.out = get_lst_index(*out, cheapest);
	pos.in = find_new_position_in_stack_a(cheapest, *in);
	// ft_printf("cheapest: %d - pos.out: %d - pos.in: %d\n", *((int *)(cheapest->content)), pos.out, pos.in);
	// display_struct(*in, 'd', "stack_a");
	// display_struct(*out, 'd', "stack_b");
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
}

t_list	*find_cheapest_number(t_list *stack_out, t_list *stack_in, char inner)
{
	t_list	*tmp;
	t_list	*cheapest;
	int		move;

	tmp = stack_out;
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
		tmp = tmp->next;
	}
	return (cheapest);
}
