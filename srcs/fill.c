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

void	error()
{
	ft_putstr_fd("Error\n", 2);
	exit (0);
}

void fill(t_stack **a, int ac, char **av, int debug)
{
	int		i;
	int		j;
	int 	k;
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
			push(a, ft_atoi(st[k - j]));
			free(st[k - j]);
		}
		free(st);
	}
}

