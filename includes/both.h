#ifndef BOTH_H
# define BOTH_H

#include "../libft/libft.h"

typedef struct		s_stack
{
	int 			num;
	struct s_stack	*next;
	int 			idx;
}					t_stack;

typedef struct		s_workspace
{
	t_stack			**a;
	t_stack			**b;
	t_list 			*op;
}					t_workspace;

void 	fill(t_stack **a, int ac, char **av);
int		push(t_stack **st, int value);
int		pop(t_stack **st);
void	swap(t_workspace *ws, int name);
void	push_to_a(t_workspace *ws);
void	push_to_b(t_workspace *ws);
void	rotate(t_workspace *ws, int name);
void	reverse_rotate(t_workspace *ws, int name);
#endif