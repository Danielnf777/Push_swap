#include "push_swap.h"

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

void three(t_list **lst)
{
	t_list	*temp;
	t_list	*last;

	last = ft_lstlast(*lst);
	temp = *lst;


	if (!lst || !*lst)
		return ;
	if (last->content  < (temp)->content)
	{
		if (temp->content > temp->next->content)
			ra(lst);
		else
			rra(lst);
		temp = *lst;
	}

	while (temp->next)
	{
		if ((temp)->content > (temp)->next->content)
			sa(&temp);
		temp = temp->next;
	}
}
t_list	*largest(t_list *lst_b)
{
	t_list	*larg;

	larg = lst_b;
	while (lst_b)
	{
		if (lst_b->content > larg->content)
			larg = lst_b;
		lst_b = lst_b->next;
	}
	return (larg);
}

void five(t_list **lst, t_list **lst_b)
{
	int	i;
	t_list	*temp;
	t_list	*small;

	if (checker(*lst)== 0)
		return ;
	while ((*lst)->content != small->content)
	{
		rra(lst);
	}
	pb(lst, lst_b);
	while ((*lst)->content != small->content)
	{
		ra(lst);
	}
	pb(lst, lst_b);
	three(lst);
	pa(lst_b, lst);
	pa(lst_b, lst);

	//	temp = *lst;
	//	  while (temp->next)
	//	  {
	//	  if ((temp)->content > (temp)->next->content)
	//	  pb(lst, lst_b);
	//	  else
	//	  sa(lst);
	//	  temp = temp->next;
	//	  }
}

int	maximum(t_list	*lst)
{
	int	max;

	max = lst->content;
	while(lst->next)
	{
		if (max < lst->next->content) 
			max = lst->next->content;
		lst = lst->next;
	}
	printf ("max = %d\n", max);
	return (max);
}
int	minimum(t_list	*lst)
{
	int	min;

	min = lst->content;
	while(lst->next)
	{
		if (min > lst->next->content) 
			min = lst->next->content;
		lst = lst->next;
	}
	printf ("min = %d\n", min);
	return (min);
}
int elements_chunk(t_list *lst, int chunk_max)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->content > chunk_max)
			i++;
		lst = lst->next;
	}
	return (i);
}
int	position(t_list *lst, int numb)
{	
	int	i;

	i = 0;
	while (lst)
	{
		printf("position = %d\n", i);
		if (lst->content == numb)
			return (i);
		i++;
		lst = lst->next;
	}
	return (i);
}
void	hundred(t_list **lst, t_list **lst_b, int argc)
{
	int	max;
	int	min;
	int	chunk_1_min;
	int	chunk_max;
	int	i;
	int	limit;

	t_list *larg;
	t_list *temp;

	min = minimum(*lst);
	max = maximum(*lst);
	chunk_max = max - ((max - min) / 3);
	limit = chunk_max;
	temp = *lst;
	//	while ((*lst)->next)
	printf("111argc = %d\n", argc);
	printf("chunk_max = %d\n", chunk_max);
	while (argc > 0)
	{
		i = elements_chunk(*lst, chunk_max);
		printf("chunk = %d\n", i);
		printf("argc= %d\n", argc);
		while (i > 0)
		{	
			while ((*lst)->content < limit && (*lst)->content >= min)
			{
				//	if (position(*lst, chunk_max) > argc / 2) 
				//		ra(lst);
				//	else
				rra(lst);
			}
			pb(lst, lst_b);
			i--;
			argc--;

		}
		larg = largest(*lst_b);
	//	while (*lst_b)
	//	{
	//		printf("list_B:%d\n", (*lst_b)->content);
	//		*lst_b = (*lst_b)->next;
	//	}
		while (*lst_b)
		{
			while((*lst_b)->content != larg->content)
				rrb(lst_b);
			pa(lst_b, lst);
			//	*lst_b = (*lst_b)->next;
			larg = largest(*lst_b);
		}
		while (*lst)
		{
			printf("list:%d\n", (*lst)->content);
			*lst = (*lst)->next;
		}
		min = limit;
		limit = limit + chunk_max;
		i = elements_chunk(*lst, chunk_max);

	}
	printf("min = %d\n", min);
	printf("max = %d\n", max);
	printf("chunk_max = %d\n", chunk_max);
	printf("argc = %d\n", argc);

}
