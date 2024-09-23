#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}	t_list;

int	checker(t_list *lst);
int     minimum(t_list  *lst);
int	maximum(t_list	*lst);
int	elements_chunk(t_list *lst, int chunk_max);
int	check_duplicate(int argc, char **argv);
t_list	*largest(t_list *lst_b);
t_list	*ft_lstnew(int argc, char **argv);
void	hundred(t_list **lst, t_list **lst_b, int argc);
void	three(t_list **lst);
void	five(t_list **lst, t_list **lst_b);
void	sa(t_list **head);
void	sb(t_list **head_b);
void	ss(t_list **list_a, t_list **list_b);
void	pb(t_list **lst, t_list **lst_b);
void	pa(t_list **lst_b, t_list **lst);
void	ra(t_list **lst_a);
void	rb(t_list **lst_b);
void	rr(t_list **lst_a, t_list **lst_b);
void	rra(t_list **lst_a);
void	rrb(t_list **lst_b);
void	rrr(t_list **lst_a, t_list **lst_b);

#endif
