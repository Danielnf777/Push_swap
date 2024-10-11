/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danavarr <danavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:31:52 by danavarr          #+#    #+#             */
/*   Updated: 2024/10/11 07:00:00 by danavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//char	**split_string(char **argv)
//{

int	sorted_list(t_list *lst)
{
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			return (1);
		else
			lst = lst->next;
	}
	return (0);
}

int	check_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atol(argv[i]) == atol(argv[j]))
			{
				printf("Error\n");
				exit (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	non_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argc > i)
	{

		j = 0;
		if (argv[i][j] == '-')
		{
			while (argv[1][j])
			{
				if (argv[i][j + 1] < 48 && argv[i][j + 1] > 57)
				{
					printf("Error\n");
					exit (1);
				}
				j++;
			}
		}
		else if (argv[i][j] < 48 || argv[i][j] > 57)
		{
				printf("Error\n");
				 exit (1);
		}
		i++;
	}
	return (0);
}
