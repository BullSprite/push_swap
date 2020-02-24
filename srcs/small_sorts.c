/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swynona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:13:47 by swynona           #+#    #+#             */
/*   Updated: 2020/02/23 19:13:47 by swynona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	small_sort_full_a(t_workspace *ws)
{
	while (1)
	{
		if ((*(ws->a))->num < ((*(ws->a))->next)->num &&
			((*(ws->a))->next)->num < ((*(ws->a))->next->next)->num)
			return ;
		else if ((*(ws->a))->num < ((*(ws->a))->next)->num &&
				((*(ws->a))->next)->num > ((*(ws->a))->next->next)->num)
			reverse_rotate(ws, 0, 1);
		else if ((*(ws->a))->num > ((*(ws->a))->next)->num &&
				((*(ws->a))->next)->num < ((*(ws->a))->next->next)->num &&
				(*(ws->a))->num > ((*(ws->a))->next->next)->num)
			rotate(ws, 0, 1);
		else
			swap(ws, 0, 1);
	}
}

void	super_small_sort_b(t_workspace *ws, int size)
{
	if (size == 2)
	{
		if ((*(ws->b))->num < ((*(ws->b))->next)->num)
			swap(ws, 1, 1);
		push_to_a(ws, 1, 1);
	}
	push_to_a(ws, 1, 1);
}

void	small_sort(t_workspace *ws, t_parts info, int name, int size)
{
	if (size == 3)
	{
		if (!name ? info.is_parted_a : info.is_parted_b)
			!name ? small_sort_parts_a(ws) : small_sort_parts_b(ws);
		else
			!name ? small_sort_full_a(ws) : small_sort_full_b(ws);
	}
	else if (size == 2)
	{
		if (!name)
		{
			if ((*(ws->a))->num > ((*(ws->a))->next)->num)
				swap(ws, 0, 1);
		}
		else
			super_small_sort_b(ws, size);
	}
	else if (name)
		super_small_sort_b(ws, size);
}
