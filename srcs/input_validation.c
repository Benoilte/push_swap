/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:56:55 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/09 15:01:20 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
	The program must work with several numerical arguments
		./push_swap 1 3 5 +9 20 -4 50 60 04 08
	
	The program also works if you receive a single character list as a parameter
		./push_swap "3 4 6 8 9 74 -56 +495"

	The program should NOT work if it encounters another character
		./push_swap 1 3 dog 35 80 -3
		./push_swap a
		./push_swap 1 2 3 5 67b778 947
		.push_swap " 12 4 6 8 54fhd 4354"
		./push_swap 1 --    45 32
			these examples should return "Error\n"

	The program should NOT work if it encounters a double number
		./push_swap 1 3 58 9 3
		./push_swap 3 03
		./push_swap " 49 128     50 38   49"
			these examples should return "Error\n"
		./push_swap "95 99 -9 10 9"
			this example should work because -9 & 9 are not equal
			
	The program should work with INT MAX & INT MIN
		./push_swap 2147483647 2 4 7
		./push_swap 99 -2147483648 23 545
		./push_swap "2147483647 843 56544 24394"
			these examples should work and sort your list
		./push_swap 54867543867438 3
		./push_swap -2147483647765 4 5
		./push_swap "214748364748385 28 47 29"
			these examples should return "Error\n"
			
	The program should work when strings and int are mixed. Error condition shoul work the same.
	./push_swap "1 2 4 3" 76 90 "348 05
*/

int	input_is_valid(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			if (string_is_valid(argv[i]))
				i++;
			else
				return (ft_error());
		}
		else
		{
			if (int_is_valid(argv[i]))
				i++;
			else
				return (ft_error());
		}
	}
	return (1);
}

int	string_is_valid(char *str)
{
	char	**numbers;
	int		i;

	numbers = ft_split(str, ' ');
	i = 0;
	while (numbers[i])
	{
		if (int_is_valid(numbers[i]))
			i++;
		else
		{
			free_strstr(numbers);
			return (0);
		}
	}
	free_strstr(numbers);
	return (1);
}

int	int_is_valid(char *str)
{
	int		i;
	long	n;

	n = ft_atoli(str);
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			i++;
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	ints_are_uniq(t_list *stack_a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = stack_a;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (*((int *)(tmp1->content)) == *((int *)(tmp2->content)))
				return (ft_error());
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}
