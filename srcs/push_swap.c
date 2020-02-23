/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swynona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:13:18 by swynona           #+#    #+#             */
/*   Updated: 2020/02/23 19:13:18 by swynona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_workspace *ws;
	t_parts		info;

	if (argc < 2)
		error();
	if (!(ws = (t_workspace *)ft_memalloc(sizeof(t_workspace))))
		return (1);
	if (!(ws->a = (t_stack **)ft_memalloc(sizeof(t_stack *))))
		return (1);
	if (!(ws->b = (t_stack **)ft_memalloc(sizeof(t_stack *))))
		return (1);
	fill(ws->a, argc, argv, 0);
	info.is_parted_b = 0;
	info.is_parted_a = 0;
	sort(ws, info, 0);
	optimize_operations(&(ws->op));
	print_operations(ws);
	return (0);
}
