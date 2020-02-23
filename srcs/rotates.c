#include "../includes/push_swap.h"

void	rotate_one(t_stack **st)
{
	t_stack	*tmp;
	t_stack	*iter;

	if (!(st) || !(*st) || !((*st)->next))
		return ;
	tmp = *st;
	iter = (*st)->next;
	while (iter->next)
	{
		iter->idx++;
		iter = iter->next;
	}
	iter->idx++;
	*st = (*st)->next;
	tmp->next = 0;
	iter->next = tmp;
	tmp->idx = 0;
}

void	rotate_both(t_workspace *ws)
{
	rotate_one(ws->a);
	rotate_one(ws->b);
}

void	rotate(t_workspace *ws, int name)
{
	if (P_S)
	{
		if (name == 0)
			ft_lstaddend(&(ws->op), ft_lstnew("ra", sizeof(char *)));
		else if (name == 1)
			ft_lstaddend(&(ws->op), ft_lstnew("rb", sizeof(char *)));
		else
			ft_lstaddend(&(ws->op), ft_lstnew("rr", sizeof(char *)));
	}
	if (name == 0)
		rotate_one(ws->a);
	else if (name == 1)
		rotate_one(ws->b);
	else
		rotate_both(ws);
}

void	reverse_rotate_one(t_stack **st)
{
	t_stack	*tmp;
	t_stack	*iter;

	if (!(st) || !(*st) || !((*st)->next))
		return ;
	iter = *st;
	while (iter->next->next)
	{
		iter->idx--;
		iter = iter->next;
	}
	iter->idx--;
	tmp = iter->next;
	iter->next = 0;
	tmp->idx = (*st)->idx + 1;
	tmp->next = (*st);
	*st = tmp;
}

void reverse_rotate_both(t_workspace *ws)
{
	reverse_rotate_one(ws->a);
	reverse_rotate_one(ws->b);
}

void	reverse_rotate(t_workspace *ws, int name)
{
	if (P_S)
	{
		if (name == 0)
			ft_lstaddend(&(ws->op), ft_lstnew("rra", sizeof(char *)));
		else if (name == 1)
			ft_lstaddend(&(ws->op), ft_lstnew("rrb", sizeof(char *)));
		else
			ft_lstaddend(&(ws->op), ft_lstnew("rrr", sizeof(char *)));
	}
	if (name == 0)
		reverse_rotate_one(ws->a);
	else if (name == 1)
		reverse_rotate_one(ws->b);
	else
		reverse_rotate_both(ws);
}
