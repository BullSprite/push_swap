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

#define P_S	1
#include "./both.h"

typedef	struct 		s_parts
{
	int 			next_part_a;
	int 			is_parted_a;
	int 			next_part_b;
	int 			is_parted_b;
}					t_parts;

void	sort(t_workspace *ws, t_parts info, int name);
void	small_sort(t_workspace *ws, t_parts info, int name, int size);
void	print_operations(t_workspace *ws);
void	optimize_operations(t_list **ops);
#endif //PUSH_SWAP_H
