/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:00:41 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/19 19:42:45 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
ra (rotate a): Shift up all elements of stack a by 1. 
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1. 
The first element becomes the last one.

rr : ra and rb at the same time.
*/

void	ft_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*tmp;

	last = ft_lstlast(*stack);
	tmp = *stack;
	*stack = tmp->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	ft_ra(t_list **stack_a, t_list **operations)
{
	char	*operation;

	ft_rotate(stack_a);
	operation = ft_strdup("ra\n");
	ft_lstadd_back(operations, ft_lstnew(operation));
}

void	ft_rb(t_list **stack_b, t_list **operations)
{
	char	*operation;

	ft_rotate(stack_b);
	operation = ft_strdup("rb\n");
	ft_lstadd_back(operations, ft_lstnew(operation));
}

void	ft_rr(t_list **stack_a, t_list **stack_b, t_list **operations)
{
	char	*operation;

	ft_rotate(stack_a);
	ft_rotate(stack_b);
	operation = ft_strdup("rr\n");
	ft_lstadd_back(operations, ft_lstnew(operation));
}

/*
void	ft_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*second_to_last;
	t_list	*tmp;

	if (ft_lstsize(*stack) < 3)
	{
		ft_swap(stack);
		return ;
	}
	second_to_last = *stack;
	while (second_to_last->next->next)
		second_to_last = second_to_last->next;
	last = ft_lstlast(*stack);
	tmp = *stack;
	*stack = last;
	(*stack)->next = tmp->next;
	second_to_last->next = tmp;
	tmp->next = NULL;
}

void	ft_ra(t_list **stack_a, t_list **operations)
{
	char	*operation;

	ft_rotate(stack_a);
	operation = ft_strdup("ra\n");
	ft_lstadd_back(operations, ft_lstnew(operation));
}

void	ft_rb(t_list **stack_b, t_list **operations)
{
	char	*operation;

	ft_rotate(stack_b);
	operation = ft_strdup("rb\n");
	ft_lstadd_back(operations, ft_lstnew(operation));
}

void	ft_rr(t_list **stack_a, t_list **stack_b, t_list **operations)
{
	char	*operation;

	ft_rotate(stack_a);
	ft_rotate(stack_b);
	operation = ft_strdup("rb\n");
	ft_lstadd_back(operations, ft_lstnew(operation));
}
*/
