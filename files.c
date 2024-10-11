/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danavarr <danavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:40:46 by danavarr          #+#    #+#             */
/*   Updated: 2024/10/11 06:27:24 by danavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_list **head)
{
	int	 temp;

	if (!head || !*head || (*head)->next == NULL) 
		return ;
	temp =  (*head)->content;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = temp;
	printf("sa\n");
}

void	sb(t_list **head_b)
{
	int	temp;
	
	if (!head_b || !*head_b || !(*head_b)->next)
		return ;
	temp = (*head_b)->content;
	(*head_b)->content = (*head_b)->next->content;
	(*head_b)->next->content = temp;
	printf("sb\n");
}

void	ss(t_list **list_a, t_list **list_b)
{
	sa(list_a);
	sb(list_b);
	printf("ss\n");
}

void	pb(t_list **lst, t_list **lst_b)
{
	if (!*lst)
		return ;
	t_list	*temp;

	temp = malloc(sizeof(t_list));
	if (!temp)
	{
		printf("Error\n");
		exit(1);
		//exit((printf("Error\n") * 0) + 1);
	}
	temp->content = (*lst)->content;
	temp->index = (*lst)->index;
	temp->next = *lst_b;
	*lst_b = temp;
	temp = (*lst)->next;
	free(*lst);
	*lst = temp;
	printf("pb\n");
}

void	pa(t_list **lst_b, t_list **lst)
{
	t_list	*temp;

	if (!*lst_b)
		return ;
	temp = malloc(sizeof(t_list));

	temp->content = (*lst_b)->content;
	temp->index = (*lst_b)->index;
	temp->next = *lst;
	*lst = temp;

	temp = (*lst_b)->next;
	free(*lst_b);
	*lst_b = temp;
//	temp = *lst;
/*	while ((*lst)->next != NULL)
	{
		previous = *lst;
		*lst_b = (*lst_b)->next;
	}
	free(*lst_b);
	previous->next = NULL;
	*lst_b = temp;*/
	printf("pa\n");
}

void	ra(t_list **lst_a)
{
	t_list	*temp;

	if (!lst_a || !*lst_a)
		return ;
	temp = *lst_a;
	while ((*lst_a)->next != NULL)
		*lst_a = (*lst_a)->next;
	(*lst_a)->next = temp;
	*lst_a= temp->next;
	temp->next = NULL;
	printf("ra\n");
}

void	rb(t_list **lst_b)
{
	t_list	*temp;
	
	if (!lst_b ||!*lst_b)
		return ;
	temp = *lst_b;
	while ((*lst_b)->next != NULL)
		*lst_b = (*lst_b)->next;
	(*lst_b)->next = temp;
	*lst_b= temp->next;
	temp->next = NULL;
	printf("rb\n");
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	ra(lst_a);
	rb(lst_b);
	printf("rr\n");
}
void	rra(t_list **lst_a)
{
	t_list	*temp;
	t_list	*new_last;

	new_last = NULL;
	if (!lst_a || !*lst_a || (*lst_a)->next == NULL)
		return ;
	temp = *lst_a;
	while ((*lst_a)->next != NULL)
	{
		new_last = *lst_a;
		*lst_a = (*lst_a)->next;
	}
	(*lst_a)->next = temp;
	new_last->next = NULL;
	printf("rra\n");
}

void	rrb(t_list **lst_b)
{
	t_list	*temp;
	t_list	*new_last;

	if (!lst_b || !*lst_b || (*lst_b)->next == NULL)
		return ;
	temp = *lst_b;
	while ((*lst_b)->next != NULL)
	{
		new_last = *lst_b;
		*lst_b = (*lst_b)->next;
	}
	(*lst_b)->next = temp;
	new_last->next = NULL;
	printf("rrb\n");
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	rra(lst_a);
	rrb(lst_b);
	printf("rrr\n");
}
