/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:59:17 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/19 12:40:19 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "limits.h"

# include "../libft/libft.h"
# include "push_swap.h"

// checker.c

int		checker_sort_stack(t_list **stack_a, t_list **stack_b);
int		checker_perform_op(t_list **stack_a, t_list **stack_b, char *op);
void	checker_is_stack_sorted(t_list *stack_a, t_list *stack_b);

#endif
