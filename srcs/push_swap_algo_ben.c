/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_ben.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:39:37 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/09 13:33:51 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
apres avoir trouver le numéro qui coute le moins d'opération
push le numéro au bonne endroit dans la stack à insérer

contrôler si il est possible d'effectuer des opération similaire
sur la stack a et la stack b
*/
void	sort_algo_ben(t_list **stack_a, t_list **operations)
{
	t_list	*stack_b;
	t_list	*range;
	int		min_pos;

	stack_b = NULL;
	range = NULL;
	// ft_printf("min_pos: %d\n", *((int *)((get_min(*stack_a))->content)));
	if (is_sorted_not_ordered(*stack_a))
	{
		min_pos = get_lst_index(*stack_a, get_min(*stack_a));
		move_lst_on_top_of_a(stack_a, operations, min_pos);
		return ;
	}
	while ((ft_lstsize(*stack_a) > 3) && (is_sorted_not_ordered(*stack_a) == 0) && (is_sorted(*stack_a) == 0))
		ft_pb(&stack_b, stack_a, operations);
	if (ft_lstsize(*stack_a) == 3)
		sort_stack_of_3(stack_a, operations);
	else 
		move_lst_on_top_of_a(stack_a, operations, get_lst_index(*stack_a, get_min(*stack_a)));
	// display_struct(*stack_a, 'd', "stack_a");
	// display_struct(stack_b, 'd', "stack_b");
	while (ft_lstsize(stack_b) > 0)
		move_b_to_a(&stack_b, stack_a, operations);
	min_pos = get_lst_index(*stack_a, get_min(*stack_a));
	move_lst_on_top_of_a(stack_a, operations, min_pos);
	ft_lstclear(&range, &del);
}

// void	move_a_to_b(t_list **out, t_list **in, t_list **op, t_list *range)
// {
// 	int		out_size;
// 	int		in_size;
// 	t_list	*cheapest;
// 	t_index	pos;

// 	cheapest = find_cheapest_number(*out, *in, 'b', range);
// 	out_size = ft_lstsize(*out);
// 	in_size = ft_lstsize(*in);
// 	pos.out = get_lst_index(*out, cheapest);
// 	pos.in = find_new_position_in_stack_b(cheapest, *in);
// 	if ((pos.out > (out_size / 2)) && (pos.in > (in_size / 2)))
// 	{
// 		reverse_both(out, in, pos, op);
// 		if ((ft_lstsize(*out) - pos.out) > (ft_lstsize(*in) - pos.in))
// 			move_lst_on_top_of_a(out, op, pos.out + (ft_lstsize(*in) - pos.in));
// 		else if ((ft_lstsize(*out) - pos.out) < (ft_lstsize(*in) - pos.in))
// 			move_lst_on_top_of_b(in, op, pos.in + (ft_lstsize(*out) - pos.out));
// 	}
// 	else if ((pos.out <= (out_size / 2)) && (pos.in <= (in_size / 2)))
// 	{
// 		rotate_both(out, in, pos, op);
// 		if (pos.out > pos.in)
// 			move_lst_on_top_of_a(out, op, pos.out - pos.in);
// 		else if (pos.out < pos.in)
// 			move_lst_on_top_of_b(in, op, pos.in - pos.out);
// 	}
// 	else
// 	{
// 		move_lst_on_top_of_a(out, op, pos.out);
// 		move_lst_on_top_of_b(in, op, pos.in);
// 	}
// 	ft_pb(in, out, op);
// }

void	move_b_to_a_ben(t_list **out, t_list **in, t_list **op)
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
	// if (*((int *)(cheapest->content)) == 67)
	// {
	// 	ft_printf("pos.in: %d\n", pos.in);
	// 	ft_printf("pos.out: %d\n", pos.out);
	// 	display_struct(*in, 'd', "stack_a");
	// 	display_struct(*out, 'd', "stack_b");
	// }
	if ((pos.out > (out_size / 2)) && (pos.in > (in_size / 2)))
	{
		reverse_both(out, in, pos, op);
		if ((ft_lstsize(*out) - pos.out) > (ft_lstsize(*in) - pos.in))
			move_lst_on_top_of_b(out, op, pos.out + (ft_lstsize(*in) - pos.in));
		else if ((ft_lstsize(*out) - pos.out) < (ft_lstsize(*in) - pos.in))
			move_lst_on_top_of_a(in, op, pos.in + (ft_lstsize(*out) - pos.out));
	}
	else if ((pos.out <= (out_size / 2)) && (pos.in <= (in_size / 2)))
	{
		rotate_both(out, in, pos, op);
		if (pos.out > pos.in)
			move_lst_on_top_of_b(out, op, pos.out - pos.in);
		else if (pos.out < pos.in)
			move_lst_on_top_of_a(in, op, pos.in - pos.out);
	}
	else
	{
		move_lst_on_top_of_a(in, op, pos.in);
		move_lst_on_top_of_b(out, op, pos.out);
	}
	ft_pa(in, out, op);
}
