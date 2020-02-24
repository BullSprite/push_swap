/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swynona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:13:23 by swynona           #+#    #+#             */
/*   Updated: 2020/02/24 15:13:24 by swynona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/both.h"

void	clear_stacks(t_workspace *ws)
{
	if (ws)
	{
		if (ws->a)
		{
			while (*(ws->a))
				pop(ws->a);
			free(ws->a);
		}
		if (ws->b)
		{
			while (*(ws->b))
				pop(ws->b);
			free(ws->b);
		}
		free(ws);
	}
}

void	error(t_workspace *ws)
{
	ft_putstr_fd("Error\n", 2);
	clear_stacks(ws);
	exit(0);
}