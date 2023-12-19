/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:00:09 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/19 23:49:55 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

rrr : rra and rrb at the same time.
*/
void	ft_reverse(t_list **stack)
{
	t_list	*second_to_last;
	t_list	*last;

	if (ft_lstsize(*stack) < 3)
	{
		ft_swap(stack);
		return ;
	}
	second_to_last = *stack;
	while (second_to_last->next->next)
		second_to_last = second_to_last->next;
	last = ft_lstlast(*stack);
	last->next = *stack;
	*stack = last;
	second_to_last->next = NULL;
}

void	ft_rra(t_list **stack_a, t_list **operations)
{
	char	*operation;

	ft_reverse(stack_a);
	operation = ft_strdup("rra\n");
	ft_lstadd_back(operations, ft_lstnew(operation));
}

void	ft_rrb(t_list **stack_b, t_list **operations)
{
	char	*operation;

	ft_reverse(stack_b);
	operation = ft_strdup("rrb\n");
	ft_lstadd_back(operations, ft_lstnew(operation));
}

void	ft_rrr(t_list **stack_a, t_list **stack_b, t_list **operations)
{
	char	*operation;

	ft_reverse(stack_a);
	ft_reverse(stack_b);
	operation = ft_strdup("rrr\n");
	ft_lstadd_back(operations, ft_lstnew(operation));
}

void	reverse_both(t_list **out, t_list **in, t_list *cheapest, t_list **op)
{
	int		out_index;
	int		in_index;

	out_index = get_lst_index(*out, cheapest);
	in_index = find_index_previous_number(cheapest, *in);
	if (in_index > out_index)
	{
		while (out_index)
		{
			ft_rrr(out, in, op);
			out_index--;
		}
	}
	else
	{
		while (in_index)
		{
			ft_rrr(out, in, op);
			in_index--;
		}
	}
}
