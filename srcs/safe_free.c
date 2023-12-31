/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:51:54 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/08 15:57:45 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	*free_strstr(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers[i]);
	free(numbers);
	return (NULL);
}

void	free_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 0)
		ft_lstclear(stack_a, &del);
	if (ft_lstsize(*stack_b) > 0)
		ft_lstclear(stack_b, &del);
}

void	del(void *content)
{
	free(content);
}
