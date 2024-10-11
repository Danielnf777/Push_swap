#include "push_swap.h"

void get_index(t_list *a)
{
	t_list	*temp;
	t_list	*comp;

	temp = a;
	comp = a;
	while (temp)
	{
		if (temp->content > comp->content)
			temp->index++;
		comp = comp->next;
		if (comp == NULL)
		{
			comp = a;
			temp = temp->next;
		}
	}
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

void radix(t_list **a, t_list **b, int argc)
{
	int	len;
	t_list	*temp;

	len = argc;
	while (sorted_list(*a) != 0)
	{
		while (len > 1)
		{
			if ((*a)->index & 1)
			{
				ra(a);
				len--;
			}
			else
			{
				pb(a, b);
				len--;
			}
		}
		while (*b)
		{
			pa(b, a);
		}
		temp = *a;
		while (temp)
		{
			temp->index >>= 1;
			temp = temp->next;
		}
		len = argc;
	}
}
