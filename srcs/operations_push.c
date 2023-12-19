/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:58:25 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/19 19:42:36 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
*/

void	ft_push(t_list **stack_in, t_list **stack_out)
{
	t_list	*to_move;

	to_move = *stack_out;
	*stack_out = (*stack_out)->next;
	to_move->next = *stack_in;
	*stack_in = to_move;
}

void	ft_pa(t_list **stack_a, t_list **stack_b, t_list **operations)
{
	char	*operation;

	if (ft_lstsize(*stack_b) == 0)
		return ;
	ft_push(stack_a, stack_b);
	operation = ft_strdup("pa\n");
	ft_lstadd_back(operations, ft_lstnew(operation));
}

void	ft_pb(t_list **stack_b, t_list **stack_a, t_list **operations)
{
	char	*operation;

	if (ft_lstsize(*stack_a) == 0)
		return ;
	ft_push(stack_b, stack_a);
	operation = ft_strdup("pb\n");
	ft_lstadd_back(operations, ft_lstnew(operation));
}
