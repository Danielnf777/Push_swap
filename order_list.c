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

void five(t_list **lst, t_list **lst_b, int argc)
{
	t_list	*small;

	if (sorted_list(*lst)== 0)
		return ;
	small = smallest(*lst);
	while ((*lst)->content != small->content)
	{
		if (position(*lst, small->content, argc) == 1)
			ra(lst);
		else
			rra(lst);
	}
	pb(lst, lst_b);
	argc--;
	small = smallest(*lst);
	while ((*lst)->content != small->content)
	{
		if (position(*lst, small->content, argc) == 1)
			ra(lst);
		else
			rra(lst);
	}
	pb(lst, lst_b);
	three(lst);
	pa(lst_b, lst);
	pa(lst_b, lst);
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
int elements_chunk(t_list *lst, int chunk_max, int min)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->content < chunk_max && lst->content >= min)
			i++;
		lst = lst->next;
	}
	return (i);
}

int	position_stack_a(t_list *lst, int chunk, int min, int argc)
{
	int	i;

	i = 0;
	while (lst)
	{
		if ( lst->content < chunk && lst->content >= min)
		{
			if ( i <= argc / 2)
				return (1);
			else
				return (0);
		}
		i++;
		lst = lst->next;
	}
	return (1);
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
void	hundred(t_list **lst, t_list **lst_b, int argc)
{
	int	max;
	int	min;
	int	portion;
	int	chunk;
	int	i;
	int	copy;

	t_list *larg;
	t_list *temp;

	min = minimum(*lst);
	max = maximum(*lst);
	portion = (max - min) / 5;
	chunk = min + portion;
	temp = *lst;
	copy = argc;
	//	while (argc > 1)
	while (i > 0)
	{
		i = elements_chunk(*lst, chunk, min);
		while (i > 0)
		{
			if (!*lst_b && sorted_list(*lst) == 0)
				return ;

			if ((*lst)->content >= min && (*lst)->content < chunk )
			{
				if (!*lst_b)
				{
					pb(lst, lst_b);
					i--;
					argc--;
				}

				else if ((*lst_b) && (*lst)->content > (*lst_b)->content) 
				{
					pb(lst, lst_b);
					i--;
					argc--;
				}
				else	
				{

				
					temp = *lst_b;
					while (temp && (*lst)->content < (*lst_b)->content)
					{	
						rb(lst_b);
						if ((*lst)->content > (*lst_b)->content)
						{
							pb(lst, lst_b);
							i--;
							argc--;
						}
						temp = temp->next;
					}
				}
			}
			else if (position_stack_a(*lst, chunk, min, argc) == 1)
				ra(lst);
			else
				rra(lst);

		}
		temp = *lst_b;
//		if (argc < 3)
//			{
//				pb(lst, lst_b);
//				pb(lst, lst_b);
//			}
		while ((temp)->next)
		{
			printf("temp %d\n", (temp)->content);
			temp = temp->next;
		}
/*
		larg = largest(*lst_b);
		while (*lst_b)
		{
			while((*lst_b)->content != larg->content)
			{
				if (position(*lst_b, larg->content, copy) == 1)
						rb(lst_b);
				else
					rrb(lst_b);
			}

	//			rb(lst_b);
			while ((*lst_b) && (*lst)->content < chunk)
			{
				ra(lst);
				*lst = (*lst)->next;
			}
			pa(lst_b, lst);
			copy--;
			larg = largest(*lst_b);
		}
		temp = *lst;
		while ((temp)->next)
		{
			printf("temp %d\n", (temp)->content);
			temp = temp->next;
		}

		min = chunk;
		chunk = chunk + portion;
//		i = elements_chunk(*lst, chunk);

	}
	printf("min = %d\n", min);
	printf("max = %d\n", max);
	printf("argc = %d\n", argc);

}
*/
	}
}
