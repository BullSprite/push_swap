#include "../includes/push_swap.h"

void	push_to_a(t_workspace *ws)
{
	if (P_S)
		ft_lstaddend(&(ws->op), ft_lstnew("pa", sizeof(char *)));
	if ((ws->b))
		push(ws->a, pop(ws->b));
}

void	push_to_b(t_workspace *ws)
{
	if (P_S)
		ft_lstaddend(&(ws->op), ft_lstnew("pb", sizeof(char *)));
	if ((ws->a))
		push(ws->b, pop(ws->a));
}