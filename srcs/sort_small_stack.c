/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:58:49 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/12 16:26:14 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_of_2(t_list **stack_a, t_list **operations)
{
	t_list	*stack;

	stack = *stack_a;
	if (*((int *)(stack->content)) > *((int *)(stack->next->content)))
		ft_sa(stack_a, operations);
}

void	sort_stack_of_3(t_list **stack_a, t_list **operations)
{
	t_list	*stack;

	stack = *stack_a;
	if (*((int *)(stack->content)) > *((int *)(stack->next->content)))
		ft_ra(stack_a, operations);
}
