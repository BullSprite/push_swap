/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swynona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:13:29 by swynona           #+#    #+#             */
/*   Updated: 2020/02/23 19:13:30 by swynona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/both.h"

void	push_a(t_workspace *ws, int p_s)
{
	if (p_s)
		ft_lstaddend(&(ws->op), ft_lstnew("pa", sizeof(char *)));
	if (*(ws->b))
		push(ws->a, pop(ws->b));
}

void	push_to_a(t_workspace *ws, int num, int p_s)
{
	while (num--)
		push_a(ws, p_s);
}

void	push_b(t_workspace *ws, int p_s)
{
	if (p_s)
		ft_lstaddend(&(ws->op), ft_lstnew("pb", sizeof(char *)));
	if (*(ws->a))
		push(ws->b, pop(ws->a));
}

void	push_to_b(t_workspace *ws, int num, int p_s)
{
	while (num--)
		push_b(ws, p_s);
}
