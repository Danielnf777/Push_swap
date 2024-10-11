/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danavarr <danavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 08:33:00 by danavarr          #+#    #+#             */
/*   Updated: 2024/10/11 09:10:55 by danavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int counter_elements(char *argv)
{
	int	i;
	while (*argv)
	{
		if (*argv == ' ')
			argv++;
		if (*argv > '0' && *argv < '9')
		{
			i++;
			while(*argv > '0' && *argv < '9')
				argv++;
		}
	}
	return (i);
}


char	**split_string(int *argc, char **argv)
{
	char	**array_arr;
	int	i;
	int	j;
	int	count;

	count = counter_elements(*argv);
	array_arr = malloc(count * sizeof (char));
	while (**argv)
	{
		while (**argv == ' ')
			argv++;
		if (**argv == 0)
			exit(1);
		if (**argv < '0' || **argv > '9')
		{
			write (2, "Error", 5);
			exit(1);
		}
		while (**argv != ' ')
		{
			array_arr[i][j] = **argv;
			j++;
			argv++;
		}
		j = 0;
		i++;
	}
	*argc = i;
	return(array_arr);
}

			
