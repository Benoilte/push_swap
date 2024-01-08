/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:25:38 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/08 14:28:15 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	insert_int_in_stack(t_list **stack_a, int argc, int i, char **argv)
{
	int		*n;
	int		size;
	char	**numbers;

	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			numbers = ft_split(argv[i], ' ');
			size = 0;
			while (numbers[size])
				size++;
			insert_int_in_stack(stack_a, size, 0, numbers);
			free_strstr(numbers);
		}
		else
		{
			n = ft_calloc(1, sizeof(int *));
			*n = ft_atoi(argv[i]);
			ft_lstadd_back(stack_a, ft_lstnew(n));
		}
		i++;
	}
}
