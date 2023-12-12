/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:58:49 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/12 18:02:52 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_of_2(t_list **stack_a, t_list **operations)
{
	int	first_n;
	int	second_n;

	first_n = *((int *)((*stack_a)->content));
	second_n = *((int *)((*stack_a)->next->content));
	if (first_n > second_n)
		ft_sa(stack_a, operations);
}

void	sort_stack_of_3(t_list **stack_a, t_list **operations)
{
	if ((*((int *)((*stack_a)->content))
		> *((int *)((*stack_a)->next->content)))
		&& (*((int *)((*stack_a)->content))
		> *((int *)((*stack_a)->next->next->content))))
		ft_ra(stack_a, operations);
	if (*((int *)((*stack_a)->next->content))
		> *((int *)((*stack_a)->next->next->content)))
		ft_rra(stack_a, operations);
	if (*((int *)((*stack_a)->content))
		> *((int *)((*stack_a)->next->next->content)))
		ft_ra(stack_a, operations);
	if (*((int *)((*stack_a)->content)) > *((int *)((*stack_a)->next->content)))
		ft_sa(stack_a, operations);
}
