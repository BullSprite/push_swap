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

void	choose_op(t_workspace *ws, char *line)
{
	if (!ft_strcmp("sa", line))
		swap(ws, 0, 0);
	else if (!ft_strcmp("sb", line))
		swap(ws, 1, 0);
	else if (!ft_strcmp("ss", line))
		swap(ws, 2, 0);
	else if (!ft_strcmp("pa", line))
		push_to_a(ws, 1, 0);
	else if (!ft_strcmp("pb", line))
		push_to_b(ws, 1, 0);
	else if (!ft_strcmp("ra", line))
		rotate(ws, 0, 0);
	else if (!ft_strcmp("rb", line))
		rotate(ws, 1, 0);
	else if (!ft_strcmp("rr", line))
		rotate(ws, 2, 0);
	else if (!ft_strcmp("rra", line))
		reverse_rotate(ws, 0, 0);
	else if (!ft_strcmp("rrb", line))
		reverse_rotate(ws, 1, 0);
	else if (!ft_strcmp("rrr", line))
		reverse_rotate(ws, 2, 0);
	else
	{
		free(line);
		error(ws);
	}
}

int	main(int argc, char **argv)
{
	t_workspace *ws;
	char 		*line;
	int			debug;

	if (!(ws = (t_workspace *)ft_memalloc(sizeof(t_workspace))) ||
		!(ws->a = (t_stack **)ft_memalloc(sizeof(t_stack *))) ||
		!(ws->b = (t_stack **)ft_memalloc(sizeof(t_stack *))))
		return (0);
	debug = argc >= 2 ? !ft_strcmp("-v", argv[1]) : 0;
	if (argc < 2 || (argc == 2 && debug))
		error(ws);
	fill(ws, argc, argv, debug);
	if (debug)
		print_work_space(ws);
	while (get_next_line(0, &line))
	{
		choose_op(ws, line);
		if(debug)
			print_work_space(ws);
		free (line);
	}
	ft_putstr(is_sorted(ws, 1) ? "OK\n" : "KO\n");
	clear_stacks(ws);
	return (0);
}
