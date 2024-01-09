/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:26:45 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/09 16:33:53 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	rev_ov_a_to_b(t_list **out, t_list **in, t_list **op, t_index pos)
{
	if ((ft_lstsize(*out) - pos.out) > (ft_lstsize(*in) - pos.in))
		move_lst_on_top_of_a(out, op, pos.out + (ft_lstsize(*in) - pos.in));
	else if ((ft_lstsize(*out) - pos.out) < (ft_lstsize(*in) - pos.in))
		move_lst_on_top_of_b(in, op, pos.in + (ft_lstsize(*out) - pos.out));
}

void	rev_ov_b_to_a(t_list **out, t_list **in, t_list **op, t_index pos)
{
	if ((ft_lstsize(*out) - pos.out) > (ft_lstsize(*in) - pos.in))
		move_lst_on_top_of_b(out, op, pos.out + (ft_lstsize(*in) - pos.in));
	else if ((ft_lstsize(*out) - pos.out) < (ft_lstsize(*in) - pos.in))
		move_lst_on_top_of_a(in, op, pos.in + (ft_lstsize(*out) - pos.out));
}
