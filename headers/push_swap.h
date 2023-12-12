/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:42:59 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/12 12:33:18 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "limits.h"

# include "../libft/libft.h"
# include "../printf/ft_printf.h"

// push_swap.c

void	insert_int_in_stack(t_list *stack_a, int argc, char **argv);
void	sort_stack(t_list *stack_a, t_list *stack_b, t_list *operations);
void	print_operations(t_list *operations);

// input_validation.c

int		input_is_valid(int argc, char **argv);
int		string_is_valid(char *str);
int		int_is_valid(char *str);
int		ints_are_uniq(t_list *stack_a);

// error.c

int		ft_error(void);

#endif