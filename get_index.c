#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int			content;
	int	index;
	struct s_list	*next;
}	t_list;
void p(t_list *head) 
{
    t_list *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->content);
        current = current->next;
    }
    printf("NULL\n");
}

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
void	pb(t_list **lst, t_list **lst_b)
{
	if (!*lst)
		return ;
	t_list	*temp;
	t_list	*temp_b;
	t_list	*previous;

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
	t_list	*previous;
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

void get_index(t_list *a)
{
	t_list	*temp;
	t_list	*comp;
	int	i;
	int	j;

	temp = a;
	comp = a;
	i = 1;
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
void radix(t_list **a, t_list **b, int argc)
{
	int	len;
	t_list	*temp;

	len = argc;
//	temp = *a;
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
//		temp = *a;
		len = argc;
	}
}

int main(int argc, char  **argv)
{
	t_list	*a;
	t_list	*b;
	t_list	*temp;

	b = NULL;
//	control_errors(argc,argv);
	a = ft_lstnew(argc, argv);
	get_index(a);
	radix(&a, &b, argc);
//	algorithm(&a, &b , argc);
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
//	ft_lstclear(&temp);
//	temp = b;
//	while (b)
//	{
//		printf("list_B:%d\n", b->content);
//		b = b->next;
//	}
//	ft_lstclear(&temp);
	return (0);
}

	

