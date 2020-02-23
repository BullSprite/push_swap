/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swynona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 20:33:53 by swynona           #+#    #+#             */
/*   Updated: 2020/02/23 20:33:53 by swynona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	small_sort_parts_a1(t_workspace *ws)
{
	if ((*(ws->a))->num < ((*(ws->a))->next)->num &&
		(*(ws->a))->num < ((*(ws->a))->next->next)->num)
	{
		rotate(ws, 0);
		swap(ws, 0);
		reverse_rotate(ws, 0);
	}
	else
		swap(ws, 0);
}

void	small_sort_parts_a(t_workspace *ws)
{
	if ((*(ws->a))->num > ((*(ws->a))->next)->num &&
		((*(ws->a))->next)->num > ((*(ws->a))->next->next)->num)
	{
		swap(ws, 0);
		small_sort_parts_a(ws);
	}
	else if ((*(ws->a))->num < ((*(ws->a))->next)->num &&
			((*(ws->a))->next)->num < ((*(ws->a))->next->next)->num)
		return ;
	else if ((*(ws->a))->num < ((*(ws->a))->next)->num &&
			(*(ws->a))->num > ((*(ws->a))->next->next)->num)
	{
		push_to_b(ws, 1);
		swap(ws, 0);
		push_to_a(ws, 1);
		swap(ws, 0);
	}
	else if ((*(ws->a))->num > ((*(ws->a))->next)->num &&
			(*(ws->a))->num > ((*(ws->a))->next->next)->num)
	{
		swap(ws, 0);
		small_sort_parts_a(ws);
	}
	else
		small_sort_parts_a1(ws);
}
