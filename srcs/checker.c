/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swynona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:12:50 by swynona           #+#    #+#             */
/*   Updated: 2020/02/23 19:12:50 by swynona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int argc, char **argv)
{
	t_workspace *ws;
	char 		*line;
	int			debug;

	if (argc < 2)
		error();

	if (!(debug = 0) && !ft_strcmp("-v", argv[1]))
		debug = 1;
	if (!(ws = (t_workspace *)ft_memalloc(sizeof(t_workspace))))
		return (1);
	if (!(ws->a = (t_stack **)ft_memalloc(sizeof(t_stack *))))
		return (1);
	if (!(ws->b = (t_stack **)ft_memalloc(sizeof(t_stack *))))
		return (1);
	fill(ws->a, argc, argv, debug);
	if (debug)
		print_work_space(ws);
	while (get_next_line(0, &line))
	{
		if (!ft_strcmp("sa", line))
			swap(ws, 0);
		else if (!ft_strcmp("sb", line))
			swap(ws, 1);
		else if (!ft_strcmp("ss", line))
			swap(ws, 2);
		else if (!ft_strcmp("pa", line))
			push_to_a(ws);
		else if (!ft_strcmp("pb", line))
			push_to_b(ws);
		else if (!ft_strcmp("ra", line))
			rotate(ws, 0);
		else if (!ft_strcmp("rb", line))
			rotate(ws, 1);
		else if (!ft_strcmp("rr", line))
			rotate(ws, 2);
		else if (!ft_strcmp("rra", line))
			reverse_rotate(ws, 0);
		else if (!ft_strcmp("rrb", line))
			reverse_rotate(ws, 1);
		else if (!ft_strcmp("rrr", line))
			reverse_rotate(ws, 2);
		if(debug)
			print_work_space(ws);
		free (line);
	}
	if (is_sorted(ws, 1))
		ft_putstr("OK");
	else
		ft_putstr("KO");
}
