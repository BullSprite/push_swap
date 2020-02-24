/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swynona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:13:38 by swynona           #+#    #+#             */
/*   Updated: 2020/02/23 19:13:38 by swynona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	rotate(t_workspace *ws, int name, int p_s)
{
	if (p_s)
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
