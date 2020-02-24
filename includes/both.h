/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swynona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:11:43 by swynona           #+#    #+#             */
/*   Updated: 2020/02/23 19:11:44 by swynona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOTH_H
# define BOTH_H

# include "../libft/libft.h"

typedef struct		s_stack
{
	int				num;
	struct s_stack	*next;
	int				idx;
}					t_stack;

typedef struct		s_workspace
{
	t_stack			**a;
	t_stack			**b;
	t_list			*op;
}					t_workspace;

void				fill(t_workspace *ws, int ac, char **av, int debug);
int					push(t_stack **st, int value);
int					pop(t_stack **st);
void				swap(t_workspace *ws, int name);
void				push_to_a(t_workspace *ws, int num);
void				push_to_b(t_workspace *ws, int num);
void				rotate(t_workspace *ws, int name);
void				reverse_rotate(t_workspace *ws, int name);
int					is_sorted(t_workspace *ws, int check_b);
void				error(t_workspace *ws);
void 				clear_stacks(t_workspace *ws);
#endif
