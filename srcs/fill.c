/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swynona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:12:59 by swynona           #+#    #+#             */
/*   Updated: 2020/02/23 19:13:00 by swynona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/both.h"

void	clear_stacks(t_workspace *ws)
{
	if (ws)
	{
		if (ws->a)

	}
}

void	error(t_workspace *ws)
{
	ft_putstr_fd("Error\n", 2);
	clear_stacks(ws);
	exit(0);
}

int		is_unic(t_stack **a, int num)
{
	t_stack	*st;

	st = *a;
	while (st)
	{
		if (st->num == num)
			return (0);
		st = st->next;
	}
	return (1);
}

void	fill(t_stack **a, int ac, char **av, int debug)
{
	int		i;
	int		j;
	int		k;
	char	**st;

	*a = 0;
	i = 0;
	while (++i < ac - debug)
	{
		st = ft_strsplit(av[ac - i], ' ');
		k = 0;
		while (st[k])
			k++;
		j = 0;
		while (++j <= k)
		{
			if (!is_unic(a, st[k - j]))
			{
				while (j <= k)
					free(st[k - j++]);
				free(st);
				error();
			}
			push(a, ft_atoi(st[k - j]));
			free(st[k - j]);
		}
		free(st);
	}
}
