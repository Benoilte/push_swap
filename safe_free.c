/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:51:54 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/12 22:20:09 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Free the string tab memory
*/
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

/*
Free the stack memory
*/
void	free_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 0)
		ft_lstclear(stack_a, &del);
	if (ft_lstsize(*stack_b) > 0)
		ft_lstclear(stack_b, &del);
}

/*
Free the structure content memory
*/
void	del(void *content)
{
	free(content);
}
