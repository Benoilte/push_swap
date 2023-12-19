/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:59:25 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/19 20:01:18 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_big_stack(t_list **stack_a, t_list **operations)
{
	t_list	*stack_b;
	t_list	*cheapest;

	stack_b = NULL;
	if (is_sorted_not_ordered(*stack_a))
	{
		ft_printf("\033[0;36mstack bigger than 5 is sorted not in order\n\033[0m");
		move_lst_on_top(stack_a, operations, get_min(*stack_a));
		return ;
	}
	ft_pb(&stack_b, stack_a, operations);
	ft_pb(&stack_b, stack_a, operations);
	cheapest = find_cheapest_number(*stack_a, stack_b);
	while (ft_lstsize(*stack_a) > 3)
	{
		move_lst_on_top(stack_a, operations, get_min(*stack_a));
		ft_pb(&stack_b, stack_a, operations);
	}
	sort_stack_of_3(stack_a, operations);
	while (ft_lstsize(stack_b) > 0)
	{
		ft_pa(stack_a, &stack_b, operations);
	}
}

t_list	*find_cheapest_number(t_list *stack_out, t_list *stack_in)
{
	t_list	*tmp;
	t_list	*cheapest;
	int		move;

	tmp = stack_out;
	move = count_move(tmp, stack_out, stack_in);
	cheapest = tmp;
	ft_printf("int : %d, first_n_move: %d\n", *((int *)(tmp->content)), move);
	tmp = tmp->next;
	while (tmp)
	{
		ft_printf("int : %d, move: %d\n", *((int *)(tmp->content)), count_move(tmp, stack_out, stack_in));
		if (count_move(tmp, stack_out, stack_in) < move)
		{
			move = count_move(tmp, stack_out, stack_in);
			cheapest = tmp;
		}
		tmp = tmp->next;
	}
	return (cheapest);
}
