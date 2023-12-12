/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:01:05 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/12 16:20:24 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

ss : sa and sb at the same time.
*/

void	ft_swap(t_list **stack)
{
	t_list	*tmp;
	int		size;

	tmp = *stack;
	*stack = tmp->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	ft_sa(t_list **stack_a, t_list **operations)
{
	char	*operation;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	ft_swap(stack_a);
	operation = ft_strdup("sa\n");
	ft_lstadd_back(operations, ft_lstnew(operation));
}

void	ft_sb(t_list **stack_b, t_list **operations)
{
	char	*operation;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	ft_swap(stack_b);
	operation = ft_strdup("sb\n");
	ft_lstadd_back(operations, ft_lstnew(operation));
}

void	ft_ss(t_list **stack_a, t_list **stack_b, t_list **operations)
{
	char	*operation;

	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return ;
	ft_swap(stack_a);
	ft_swap(stack_b);
	operation = ft_strdup("ss\n");
	ft_lstadd_back(operations, ft_lstnew(operation));
}
