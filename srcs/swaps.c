#include "../includes/push_swap.h"

void	swap_one(t_stack **st)
{
	t_stack	*tmp;

	if (!(*st) || !((*st)->next))
		return ;
	tmp = *st;
	tmp->idx--;
	(*st) = (*st)->next;
	tmp->next = (*st)->next;
	(*st)->idx++;
	(*st)->next = tmp;
}

void	swap_both(t_workspace *ws)
{
	swap_one(ws->a);
	swap_one(ws->b);
}

void	swap(t_workspace *ws, int name)
{
	if (P_S)
	{
		if (name == 0)
			ft_lstaddend(&(ws->op), ft_lstnew("sa", sizeof(char *)));
		else if (name == 1)
			ft_lstaddend(&(ws->op), ft_lstnew("sb", sizeof(char *)));
		else
			ft_lstaddend(&(ws->op), ft_lstnew("ss", sizeof(char *)));
	}
	if (name == 0)
		swap_one(ws->a);
	else if (name == 1)
		swap_one(ws->b);
	else
		swap_both(ws);
}