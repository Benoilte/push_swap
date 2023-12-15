/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:42:59 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/15 19:57:46 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "limits.h"

# include "../libft/libft.h"
# include "../printf/ft_printf.h"

// push_swap.c

void	insert_int_in_stack(t_list **stack_a, int argc, int i, char **argv);
void	sort_stack(t_list **stack_a, t_list **stack_b, t_list **operations);
void	print_operations(t_list *operations);

void	display_struct(t_list *lst, char data, char *text);

// sort_small_stack.c

void	sort_stack_of_2(t_list **stack_a, t_list **operations);
void	sort_stack_of_3(t_list **stack_a, t_list **operations);
void	sort_stack_of_4(t_list **stack_a, t_list **operations);
void	sort_stack_of_5(t_list **stack_a, t_list **operations);

// push_swap_algo

void	sort_big_stack(t_list **stack_a, t_list **operations);

// push_swap_algo_utils

int		is_sorted(t_list *stack_a);
int		is_sorted_not_ordered(t_list *stack_a);
t_list	*get_min_pos(t_list *stack_a);
void	order_the_stack(t_list **stack_a, t_list **operations);

// operations_swap.c

void	ft_swap(t_list **stack);
void	ft_sa(t_list **stack_a, t_list **operations);
void	ft_sb(t_list **stack_b, t_list **operations);
void	ft_ss(t_list **stack_a, t_list **stack_b, t_list **operations);

// operations_rotate.c

void	ft_rotate(t_list **stack);
void	ft_ra(t_list **stack_a, t_list **operations);
void	ft_rb(t_list **stack_b, t_list **operations);
void	ft_rr(t_list **stack_a, t_list **stack_b, t_list **operations);

// operations_rotate.c

void	ft_reverse(t_list **stack);
void	ft_rra(t_list **stack_a, t_list **operations);
void	ft_rrb(t_list **stack_b, t_list **operations);
void	ft_rrr(t_list **stack_a, t_list **stack_b, t_list **operations);

// input_validation.c

int		input_is_valid(int argc, char **argv);
int		string_is_valid(char *str);
int		int_is_valid(char *str);
int		ints_are_uniq(t_list *stack_a);

// error.c

int		ft_error(void);

// safe_free.c

void	*free_strstr(char **numbers);
void	del(void *content);

#endif