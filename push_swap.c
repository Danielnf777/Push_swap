/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danavarr <danavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:22:29 by danavarr          #+#    #+#             */
/*   Updated: 2024/09/22 20:48:44 by danavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"


void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (!lst ||!*lst)
		return ;
	while (*lst != NULL)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
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
					return (1);
				}
				j++;
			}
		}
		else if (argv[i][j] < 48 || argv[i][j] > 57)
		{
				printf("Error\n");
				return (1);
		}
		i++;
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
			if (atoi(argv[i]) == atoi(argv[j]))
			{
				printf("Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
int	checker(t_list *lst)
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

/*t_list *ft_lstnew(int argc, char **argv)
{
	t_list	*node;
	int	i;

	i = 1;
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	if (argc < 2)
		return (NULL);
	node->content = atoi(argv[1]);
	node->next = ft_lstnew(argc -1, argv + 1);
	return (node);
}*/
t_list	*ft_lstnew_b(int argc)
{
	int	i;
	t_list	*b;
	t_list	*temp;
	t_list	*node;

	i = 2;

	b = malloc(sizeof(t_list));
	if (!b)
		return (NULL);
	b->next = NULL;
	temp = b;
	while (i < argc)
	{
		node = malloc(sizeof(t_list));
		node->next = NULL;
		temp->next = node;
		temp = node;
		i++;
	}
	return (b);

}




		


t_list	*ft_lstnew(int argc, char **argv)
{
	t_list	*head;
	t_list	*temp;
	t_list	*node;
	int	i;

	i = 1;
	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->content = atoi(argv[i]);
	head->next = NULL;
	temp = head;
	i++;
	while (i < argc)
	{
		node = malloc(sizeof(t_list));
		node->content = atoi(argv[i]);
		i++;
		node->next = NULL;
		temp->next = node;
		temp = node;
	}
	return (head);
}			

int main(int argc, char  **argv)
{
	t_list	*a;
	t_list	*b;
	t_list	*temp;

	b = NULL;
	if (argc < 3)
	{
		printf("Error: to few arguments.");
		return (1);
	}
	if (check_duplicate(argc, argv) == 1)
		return (1);
	if (non_digit(argc, argv) == 1)
		return (1);
	a = ft_lstnew(argc, argv);
	if (argc == 4)
		three(&a);
	if (argc <= 6)
		five(&a, &b);
	if (argc > 6)
		hundred(&a, &b, argc);

//	b = malloc(sizeof(t_list));
//	b->next = NULL;
//	pb(&a, &b);
//	pb(&a, &b);
//	pb(&a, &b);
//	pa(&b,&a);
//	pa(&b,&a);
//	pa(&b,&a);
//	pb(&a, &b);
//	pb(&a, &b);
//	pb(&a, &b);
//	pb(&a, &b);
//	pa(&b,&a);
//	pa(&b,&a);
//	sa(&a);
//	sb(&b);
//	ss(&a, &b);
//	ra(&a);
//	ra(&a);
//	rb(&b);
//	rr(&a, &b);
//	rra(&a);
//	rra(&a);
//	rrb(&b);
//	rrr(&a, &b);
	if (checker(a) == 0)
		printf("Sorted list\n");
	else
		printf("Not sorted list\n");

	temp = a;
	while (a)
	{
		printf("%d\n", a->content);
		a = a->next;
	}
	ft_lstclear(&temp);
	temp = b;

	while (b)
	{
		printf("list_B:%d\n", b->content);
		b = b->next;
	}
//	ft_lstclear(&temp);
	return (0);
}
