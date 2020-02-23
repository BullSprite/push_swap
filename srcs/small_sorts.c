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
		if (A->num < A_N->num && A_N->num < A_NN->num)
			return ;
		else if (A->num < A_N->num && A_N->num > A_NN->num)
			reverse_rotate(ws, 0);
		else if (A->num > A_N->num && A_N->num < A_NN->num &&
											A->num > A_NN->num)
			rotate(ws, 0);
		else
			swap(ws, 0);
	}
}

void	super_small_sort_b(t_workspace *ws, int size)
{
	if (size == 2)
	{
		if (B->num < B_N->num)
			swap(ws, 1);
		push_to_a(ws, 1);
	}
	push_to_a(ws, 1);
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
			if (A->num > A_N->num)
				swap(ws, 0);
		}
		else
			super_small_sort_b(ws, size);
	}
	else if (name)
		super_small_sort_b(ws, size);
}
