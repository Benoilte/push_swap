/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:59:25 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/15 20:32:32 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big_stack(t_list **stack_a, t_list **operations)
{
	if (is_sorted_not_ordered(*stack_a))
	{
		ft_printf("\033[0;36mstack bigger than 5 is sorted not in order\n\033[0m");
		move_min_on_top(stack_a, operations);
	}
}
