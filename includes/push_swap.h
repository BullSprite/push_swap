/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swynona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:12:15 by swynona           #+#    #+#             */
/*   Updated: 2020/02/23 19:12:15 by swynona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./both.h"
# define P_S		1

typedef	struct		s_parts
{
	int				next_part_a;
	int				is_parted_a;
	int				next_part_b;
	int				is_parted_b;
}					t_parts;

void				sort(t_workspace *ws, t_parts info, int name);
void				small_sort(t_workspace *ws, t_parts info, int name,
					int size);
void				print_operations(t_workspace *ws);
void				optimize_operations(t_list **ops);
void				small_sort_parts_b(t_workspace *ws);
void				small_sort_full_b(t_workspace *ws);
void				small_sort_parts_a(t_workspace *ws);
#endif
