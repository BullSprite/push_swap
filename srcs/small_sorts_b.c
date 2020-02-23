/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swynona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 20:28:47 by swynona           #+#    #+#             */
/*   Updated: 2020/02/23 20:28:47 by swynona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	small_sort_parts_b1(t_workspace *ws)
{
	if (B->num < B_N->num && B->num < B_NN->num)
	{
		push_to_a(ws, 1);
		rotate(ws, 0);
		push_to_a(ws, 2);
		reverse_rotate(ws, 0);
	}
	else
	{
		push_to_a(ws, 1);
		swap(ws, 1);
		push_to_a(ws, 1);
		swap(ws, 0);
		push_to_a(ws, 1);
	}
}

void	small_sort_parts_b(t_workspace *ws)
{
	if (B->num > B_N->num && B_N->num > B_NN->num)
		push_to_a(ws, 3);
	else if (B->num < B_N->num && B_N->num < B_NN->num)
	{
		push_to_a(ws, 1);
		swap(ws, 1);
		rotate(ws, 0);
		push_to_a(ws, 2);
		reverse_rotate(ws, 0);
	}
	else if (B->num < B_N->num && B->num > B_NN->num)
	{
		swap(ws, 1);
		push_to_a(ws, 3);
	}
	else if (B->num > B_N->num && B->num > B_NN->num)
	{
		push_to_a(ws, 1);
		swap(ws, 1);
		push_to_a(ws, 2);
	}
	else
		small_sort_parts_b1(ws);
}

void	small_sort_full_b1(t_workspace *ws)
{
	if (B->num < B_N->num && B->num < B_NN->num)
	{
		rotate(ws, 1);
		push_to_a(ws, 3);
	}
	else
	{
		reverse_rotate(ws, 1);
		push_to_a(ws, 3);
	}
}

void	small_sort_full_b(t_workspace *ws)
{
	if (B->num > B_N->num && B_N->num > B_NN->num)
		push_to_a(ws, 3);
	else if (B->num < B_N->num && B_N->num < B_NN->num)
	{
		rotate(ws, 1);
		swap(ws, 1);
		push_to_a(ws, 3);
	}
	else if (B->num < B_N->num && B->num > B_NN->num)
	{
		swap(ws, 1);
		push_to_a(ws, 3);
	}
	else if (B->num > B_N->num && B->num > B_NN->num)
	{
		push_to_a(ws, 1);
		swap(ws, 1);
		push_to_a(ws, 2);
	}
	else
		small_sort_full_b1(ws);
}
