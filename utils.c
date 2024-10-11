/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danavarr <danavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:19:21 by danavarr          #+#    #+#             */
/*   Updated: 2024/10/11 06:32:05 by danavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	long	i;
	int	n;

	i = 0;
	n = 1;
	while ((*nptr && *nptr == 32) || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
		n = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= 48 && *nptr <= 57)
	{
		i = (i * 10) + (*nptr -48);
		nptr++;
	}
	return (i * n);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	position(t_list *lst, int numb, int argc)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->content == numb)
		{
			if (i <= argc / 2)
				return (1);
			else
				return (0);
		}
		i++;
		lst = lst->next;
	}
	return (1);
}

t_list	*smallest(t_list *lst)
{
	t_list	*small;

	small = lst;
	while (lst)
	{
		if (lst->content < small->content)
			small = lst;
		lst = lst->next;
	}
	return (small);
}

