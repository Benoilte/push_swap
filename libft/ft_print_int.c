/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:22:37 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/12 22:03:41 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Print intege in base 10 with its corresponding flag, width and precision.
only flag '#' is NOT supported.
*/
int	ft_print_int(int n, t_printf_lst *lst)
{
	return (ft_print_decimal(n, lst));
}
