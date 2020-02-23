#include "../includes/both.h"

void fill(t_stack **a, int ac, char **av)
{
	int 	i;
	char **st;

	*a = 0;
	i = 0;
	if (ac == 2)
	{
		st = ft_strsplit(av[1], ' ');
		ac = 0;
		i = 0;
		while (st[++i])
			ac++;
		i = -1;
		while (++i <= ac)
		{
			push(a, ft_atoi(st[ac - i]));
		}
	}
	else
		while (++i < ac)
		{
			push(a, ft_atoi(av[ac - i]));
		}
}

