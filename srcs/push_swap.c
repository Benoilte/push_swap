/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:46:25 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/08 15:52:37 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc >= 2)
	{
		while (i < argc)
		{
			if (ft_strchr(argv[i], ' '))
				ft_printf("this is a string\n");
			else
				ft_printf("this is probably an int\n");
			i++;
		}
	}
	else
	{
		ft_printf("argument is missing\n");
		return (1);
	}
}
