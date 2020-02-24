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

int 	is_correct(char *s)
{
	int i;
	int len;
	int sign;
	int	num;

	i = 0;
	sign = 0;
	if (s[0] == '+' || (s[0] == '-' && (sign = 1)))
		i++;
	len = ft_strlen(s) - i > 10;
	if (len < 1 || len > 10)
		return (0);
	while (s[i])
		if (!ft_isdigit(s[i++]))
			return (0);
	if (len == 10)
	{
		num = ft_atoi(s);
		if ((sign && num > 0) || (!sign && num < 0))
			return (0);
	}
	return (1);
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

void	fill(t_workspace *ws, int ac, char **av, int debug)
{
	int		i;
	int		j;
	int		k;
	char	**st;

	*(ws->a) = 0;
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
			if (is_correct(st[k - j]) && !is_unic(ws->a, ft_atoi(st[k -
			j])))
			{
				while (j <= k)
					free(st[k - j++]);
				free(st);
				error(ws);
			}
			push(ws->a, ft_atoi(st[k - j]));
			free(st[k - j]);
		}
		free(st);
	}
}
