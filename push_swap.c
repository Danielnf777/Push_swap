/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danavarr <danavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:22:29 by danavarr          #+#    #+#             */
/*   Updated: 2024/10/11 10:01:37 by danavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (argc == 2)
	{
		argv = split_string(&argc, argv);
	}
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

void	control_errors(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Error\n");
		exit (1);
	}
	check_duplicate(argc, argv);
	non_digit(argc, argv);
//	non_int(arg
}
void	algorithm(t_list **a, t_list **b, int argc)
{
	if (argc == 4)
		three(a);
	if (argc <= 6)
		five(a, b, argc);
	if (argc > 6)
	radix(a, b, argc);
}

int main(int argc, char  **argv)
{
	t_list	*a;
	t_list	*b;
	t_list	*temp;

	b = NULL;
	control_errors(argc,argv);
	a = ft_lstnew(argc, argv);
	get_index(a);
	algorithm(&a, &b , argc);
//	if (sorted_list(a) == 0)
//		printf("Sorted list\n");
//	else
//		printf("Not sorted list\n");
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
