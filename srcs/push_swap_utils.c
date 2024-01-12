/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:22:34 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/12 13:55:40 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
Return the index (position in the stack) of element lst passed as argument.
*/
int	get_lst_index(t_list *stack_a, t_list *lst)
{
	t_list	*tmp;
	int		lst_index;

	lst_index = 0;
	tmp = stack_a;
	while (tmp != lst)
	{
		lst_index++;
		tmp = tmp->next;
	}
	return (lst_index);
}

/*
According to the index of the element,
move it on the top of the stack a with the minimum of operations
*/
void	move_lst_on_top_of_a(t_list **stack_a, t_list **operations, int index)
{
	int		size;

	size = ft_lstsize(*stack_a);
	if (index > (size / 2))
	{
		while (index++ < size)
			ft_rra(stack_a, operations);
	}
	else
	{
		while (index-- > 0)
			ft_ra(stack_a, operations);
	}
}

/*
According to the index of the element,
move it on the top of the stack b with the minimum of operations
*/
void	move_lst_on_top_of_b(t_list **stack_b, t_list **operations, int index)
{
	int		size;

	size = ft_lstsize(*stack_b);
	if (index > (size / 2))
	{
		while (index++ < size)
			ft_rrb(stack_b, operations);
	}
	else
	{
		while (index-- > 0)
			ft_rb(stack_b, operations);
	}
}
