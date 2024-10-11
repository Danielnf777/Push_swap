#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	int	content;
	int	index;
	struct s_list	*next;
}	t_list;
char	**split_string(int *argc, char **argv);
long	ft_atol(const char *nptr);
int	counter_elements(char *argv);
int	sorted_list(t_list *lst);
int     minimum(t_list  *lst);
int	non_digit(int argc, char **argv);
int	ft_lstsize(t_list *lst);
int	maximum(t_list	*lst);
int	minimum(t_list	*lst);
t_list 	*ft_lstlast(t_list *lst);
t_list	*smallest(t_list *lst);
int	elements_chunk(t_list *lst, int chunk_max, int min);
int	check_duplicate(int argc, char **argv);
int	position_stack_a(t_list *lst, int chunk, int min, int argc);
int     position(t_list *lst, int numb, int argc);
bool	bounds_chunk(t_list *a);
t_list	*largest(t_list *lst_b);
t_list	*ft_lstnew(int argc, char **argv);
void	algorithm(t_list **a, t_list **b, int argc);
void	get_index(t_list *a);
void	radix(t_list **a, t_list **b, int argc);
void	p(t_list *head); 
void	hundred(t_list **lst, t_list **lst_b, int argc);
void	three(t_list **lst);
void	five(t_list **lst, t_list **lst_b, int argc);
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
