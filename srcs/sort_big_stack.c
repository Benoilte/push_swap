/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:59:25 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/12 19:09:36 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
apres avoir trouver le numéro qui coute le moins d'opération
push le numéro au bonne endroit dans la stack à insérer

contrôler si il est possible d'effectuer des opération similaire
sur la stack a et la stack b
*/

/*
If th stack_a is sorted but not ordererd
	- Move the smaller number to the top of stack_a

Otherwise Push 2 first numbers in stack_b and Check all number 
to find which one cost the minimum of operation to insert number 
in descending number in stack_b

Stop to push element in stack_b when stack_a egal 3 or if stack_a is sorted 
or if stack_a is sorted but not ordered

If stack_a == 3 sorted the 3 elements

Do the operation inverse to move element from stack_b to stack_a

Move Smaller number on the top 
*/

void	sort_big_stack(t_list **stack_a, t_list **operations)
{
	t_list	*stack_b;
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
	while ((ft_lstsize(*stack_a) > 3)
		&& (is_sorted_not_ordered(*stack_a) == 0)
		&& (is_sorted(*stack_a) == 0))
		move_a_to_b(stack_a, &stack_b, operations);
	if (ft_lstsize(*stack_a) == 3)
		sort_stack_of_3(stack_a, operations);
	while (ft_lstsize(stack_b) > 0)
		move_b_to_a(&stack_b, stack_a, operations);
	min_pos = get_lst_index(*stack_a, get_min(*stack_a));
	move_lst_on_top_of_a(stack_a, operations, min_pos);
}

/*
Find element who cost less operations to move element from stack_a to stack_b
Stack_b will be ordered in descending order 
*/
void	move_a_to_b(t_list **out, t_list **in, t_list **op)
{
	t_list	*cheapest;
	t_index	pos;

	cheapest = find_cheapest_number(*out, *in, 'b');
	pos.out = get_lst_index(*out, cheapest);
	pos.in = find_new_position_in_stack_b(cheapest, *in);
	if ((pos.out > (ft_lstsize(*out) / 2)) && (pos.in > (ft_lstsize(*in) / 2)))
	{
		reverse_both(out, in, pos, op);
		rev_ov_a_to_b(out, in, op, pos);
	}
	else if ((pos.out <= (ft_lstsize(*out) / 2))
		&& (pos.in <= (ft_lstsize(*in) / 2)))
	{
		rotate_both(out, in, pos, op);
		rot_ov_a_to_b(out, in, op, pos);
	}
	else
	{
		move_lst_on_top_of_a(out, op, pos.out);
		move_lst_on_top_of_b(in, op, pos.in);
	}
	ft_pb(in, out, op);
}

/*
Find element who cost less operations to move element from stack_b to stack_a
Stack_a will be ordered in ascending order 
*/
void	move_b_to_a(t_list **out, t_list **in, t_list **op)
{
	t_list	*cheapest;
	t_index	pos;

	cheapest = find_cheapest_number(*out, *in, 'a');
	pos.out = get_lst_index(*out, cheapest);
	pos.in = find_new_position_in_stack_a(cheapest, *in);
	if ((pos.out > (ft_lstsize(*out) / 2)) && (pos.in > (ft_lstsize(*in) / 2)))
	{
		reverse_both(out, in, pos, op);
		rev_ov_b_to_a(out, in, op, pos);
	}
	else if ((pos.out <= (ft_lstsize(*out) / 2))
		&& (pos.in <= (ft_lstsize(*in) / 2)))
	{
		rotate_both(out, in, pos, op);
		rot_ov_b_to_a(out, in, op, pos);
	}
	else
	{
		move_lst_on_top_of_a(in, op, pos.in);
		move_lst_on_top_of_b(out, op, pos.out);
	}
	ft_pa(in, out, op);
}

/*
Return element who cost the less operations to move from stack_out to stack_in
*/
t_list	*find_cheapest_number(t_list *stack_out, t_list *stack_in, char in)
{
	t_list	*tmp;
	t_list	*cheapest;
	int		move;

	tmp = stack_out;
	move = count_move(tmp, stack_out, stack_in, in);
	cheapest = tmp;
	while (tmp)
	{
		if ((count_move(tmp, stack_out, stack_in, in) < move))
		{
			move = count_move(tmp, stack_out, stack_in, in);
			cheapest = tmp;
		}
		tmp = tmp->next;
	}
	return (cheapest);
}
