/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swynona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:14:03 by swynona           #+#    #+#             */
/*   Updated: 2020/02/23 19:14:04 by swynona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push(t_stack **st, int value)
{
	t_stack *tmp;

	if (*st == 0)
	{
		if (!(*st = (t_stack *)ft_memalloc(sizeof(t_stack))))
			return (0);
		(*st)->num = value;
		(*st)->next = 0;
		(*st)->idx = 0;
		return (1);
	}
	if (!(tmp = (t_stack *)ft_memalloc(sizeof(t_stack))))
		return (0);
	tmp->num = value;
	tmp->next = *st;
	tmp->idx = (*st)->idx + 1;
	(*st) = tmp;
	return (1);
}

int	pop(t_stack **st)
{
	int		ret;
	t_stack	*tmp;

	if (!(st) || !(*st))
		return (0);
	ret = (*st)->num;
	tmp = *st;
	*st = (*st)->next;
	free(tmp);
	return (ret);
}
