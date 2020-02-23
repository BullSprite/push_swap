#include "../includes/push_swap.h"




int	main(int argc, char **argv)
{
	t_workspace *ws;
	t_parts		info;

	if (!(ws = (t_workspace *)ft_memalloc(sizeof(t_workspace))))
		return (1);
	if (!(ws->a = (t_stack **)ft_memalloc(sizeof(t_stack *))))
		return (1);
	if (!(ws->b = (t_stack **)ft_memalloc(sizeof(t_stack *))))
		return (1);

	fill(ws->a, argc, argv);
	info.is_parted_b = 0;
	info.is_parted_a = 0;
	sort(ws, info, 0);
	//print_work_space(ws);
	//printf("%d\n", ft_lstlen(ws->op));
	optimize_operations(&(ws->op));
	print_operations(ws);
	return (0);
}
