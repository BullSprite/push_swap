/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swynona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:25:47 by swynona           #+#    #+#             */
/*   Updated: 2020/02/23 19:25:47 by swynona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		is_sorted(t_workspace *ws, int check_b)
{
	int		old;
	t_stack	*iter;

	if (check_b)
	{
		if ((*(ws->b)))
			return (0);
	}
	iter = *(ws->a);
	old = iter->num;
	iter = iter->next;
	while (iter)
	{
		if (old > iter->num)
			break ;
		old = iter->num;
		iter = iter->next;
	}
	return (!iter);
}
