/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:22:34 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/08 16:00:23 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

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

void	move_lst_on_top_of_a(t_list **stack_a, t_list **operations, int index)
{
	t_list	*tmp;
	int		size;

	tmp = *stack_a;
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

void	move_lst_on_top_of_b(t_list **stack_b, t_list **operations, int index)
{
	t_list	*tmp;
	int		size;

	tmp = *stack_b;
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

void	display_struct(t_list *lst, char data, char *text)
{
	t_list	*tmp;

	tmp = lst;
	if (!tmp)
		ft_printf("struct is empty\n");
	while (tmp)
	{
		if (data == 'd')
			ft_printf("%s: %d\n", text, *((int *)(tmp->content)));
		if (data == 's')
			ft_printf("%s: %s\n", text, tmp->content);
		tmp = tmp->next;
	}
}
