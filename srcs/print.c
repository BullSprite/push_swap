/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swynona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:13:08 by swynona           #+#    #+#             */
/*   Updated: 2020/02/23 19:13:08 by swynona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/checker.h"

int		max_idx(t_stack **a, t_stack **b)
{
	int	top_a;
	int top_b;

	if (!(a) || !(*a))
		top_a = -1;
	else
		top_a = (*a)->idx;
	if (!(b) || !(*b))
		top_b = -1;
	else
		top_b = (*b)->idx;
	return top_a > top_b ? top_a : top_b;
}

void	print_work_space(t_workspace *ws)
{
	int		height;
	t_stack	*a;
	t_stack	*b;

	height = max_idx(ws->a, ws->b);
	a = *(ws->a);
	b = *(ws->b);
	while (height-- > -1)
	{
		if (a && a->idx == height + 1)
			ft_putnbr(a->num + (a->next) - (a = a->next));
		else
			ft_putchar(' ');
		ft_putchar('\t');
		if (b && b->idx == height + 1)
			ft_putnbr(b->num + (b->next) - (b = b->next));
		else
			ft_putchar(' ');
		ft_putchar('\n');
	}
	ft_putstr("_\t_\na\tb\n");
}

void print_operations(t_workspace *ws)
{
	t_list	*op;
	t_list	*tmp;

	op = ws->op;
	while (op)
	{
		if (op->content != 0)
		{
			ft_putstr((char *)(op->content));
			free(op->content);
			ft_putchar('\n');
		}
		tmp = op->next;
		free(op);
		op = tmp;
	}
}

void	delete_operations(t_list **ops)
{
	t_list	*tmp;
	t_list	*next;

	next = (*ops)->next->next->next;
	tmp = (*ops)->next->next;
	free(tmp->content);
	free(tmp);
	tmp = (*ops)->next;
	free(tmp->content);
	free(tmp);
	(*ops)->next = next;
}

void	optimize_operations(t_list **ops)
{
	t_list	*op;
	char	*top;
	char	*topp;

	op = *ops;
	if (!op || !(op->next))
		return ;
	while (op && op->next && op->next->next)
	{
		top = (char *)(op->next->content);
		topp = (char *)(op->next->next->content);
		if (ft_strlen(top) == 3)
		{
			if ((top[2] == 'a' && ft_strequ("ra", topp)) ||
				(top[2] == 'b' && ft_strequ("rb", topp)))
				delete_operations(&op);
		}
		else if (top[0] == 'p' && topp[0] == 'p')
		{
			if (top[1] != topp[1])
				delete_operations(&op);
		}
		else if (top[0] == 'r' && topp[0] == 'r')
			if (ft_strlen(topp) == 3 && top[1] == topp[2])
				delete_operations(&op);
		op = op->next;
	}
}
