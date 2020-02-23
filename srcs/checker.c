#include "../includes/checker.h"

int	main(int argc, char **argv)
{
	t_workspace *ws;
	char 		*line;

	if (!(ws = (t_workspace *)ft_memalloc(sizeof(t_workspace))))
		return (1);
	if (!(ws->a = (t_stack **)ft_memalloc(sizeof(t_stack *))))
		return (1);
	if (!(ws->b = (t_stack **)ft_memalloc(sizeof(t_stack *))))
		return (1);

	fill(ws->a, argc, argv);
	print_work_space(ws);
	int iter = 0;
	while (get_next_line(0, &line))
	{
		printf("%s %d\n", line, ++iter);
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
		print_work_space(ws);
		free (line);
	}

}