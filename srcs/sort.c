#include "../includes/push_swap.h"

int 	find_pivot1(t_stack **st, int size)
{
	int 	sum;
	int 	count;
	t_stack	*tmp;

	sum = 0;
	count = 0;
	tmp = *st;
	while (count++ < size)
	{
		sum += tmp->num;
		tmp = tmp->next;
	}
	return (sum / size);
}

#include <stdio.h>

int 	find_pivot(t_stack **st, int size)
{
	t_stack	*tmp;
	int 	*arr;
	int 	i;
	int 	j;
	int		sw;

	arr = (int *)ft_memalloc((size) * sizeof(int));
	tmp = *st;
	i = 0;
	while (i < size)
	{
		arr[i++] = tmp->num;
		tmp = tmp->next;
	}
	i = -1;
	while (++i < size && i == (j = i))
		while (++j < size)
			if (arr[i] > arr[j])
			{
				sw = arr[i];
				arr[i] = arr[j];
				arr[j] = sw;
			}
	i = arr[size / 2];
	free(arr);
	return (i);
}

int		part_length(t_workspace *ws, t_parts info, int name)
{
	int		i;
	t_stack *tmp;

	i = 0;
	if (!name)
	{
		if (!info.is_parted_a || (*(ws->a))->num == info.next_part_a)
			return ((*(ws->a))->idx + 1);
		tmp = *(ws->a);
		while (tmp->num != info.next_part_a && ++i)
			tmp = tmp->next;
	}
	else
	{
		if (!info.is_parted_b || (*(ws->b))->num == info.next_part_b)
			return ((*(ws->b))->idx + 1);
		tmp = *(ws->b);
		while (tmp->num != info.next_part_b && ++i)
			tmp = tmp->next;
	}
	return (i);
}

int		something_to_drop(t_stack **st_n, int name, int len, int pivot)
{
	t_stack	*st;

	st = *st_n;
	while (--len > 0)
	{
		if (!name ? (st)->num <= pivot : (st)->num >= pivot)
			return (1);
		st = st->next;
	}
	return (0);
}

//name - from what we drops

void drop(t_workspace *ws, int len , int name, int pivot)
{
	int rot_count;
	int i;
	int info;

	i = -1;
	info = (!name ? ((*(ws->a))->idx) : ((*(ws->b))->idx)) + 1 != len;
	rot_count = 0;
	while (++i < len)
	{
		if (!name ? (*(ws->a))->num <= pivot : (*(ws->b))->num >= pivot)
		{
			if (!name)
				push_to_b(ws);
			else
				push_to_a(ws);
			if (!something_to_drop((!name ? ws->a : ws->b), name, len - i,
					pivot))
				break ;
		}
		else if (++rot_count)
			rotate(ws, name);
	}
	if (info)
		while (rot_count--)
			reverse_rotate(ws, name);
}

void	sort1(t_workspace *ws, t_parts info, int name)
{
	int		pivot;
	t_parts	info_next;
	int size;

	if (!name)
	{
		if (*(ws->b) != 0)
		{
			info_next.is_parted_b = 1;
			info_next.next_part_b = (*(ws->b))->num;
		} else
			info_next.is_parted_b = 0;
	}
	else
	{
		if (!(*(ws->b)))
			return ;
		info_next.is_parted_a = 1;
		info_next.next_part_a = (*(ws->a))->num;
	}
	if ((size = part_length(ws, info, name)) <= 3)
	{
		small_sort(ws, info, name, size);
		return ;
	}
	pivot = find_pivot(!name ? ws->a : ws->b, size);
	drop(ws, size, name, pivot);
	if (!name)
	{
		sort(ws, info, name);
		info_next.is_parted_a = 1;
		info_next.next_part_a = (*(ws->a))->num;
		sort(ws, info_next, !name);
	}
	else
	{
		sort(ws, info, !name);
		if (!(*(ws->b)))
			return ;
		info_next.is_parted_b = 1;
		info_next.next_part_b = (*(ws->b))->num;
		info_next.is_parted_a = 1;
		info_next.next_part_a = (*(ws->a))->num;
		sort(ws, info_next, name);
	}
}

int 	is_sorted(t_workspace *ws, int check_b)
{
	int		old;
	t_stack	*iter;

	if (check_b)
	{
		if ((*(ws->b)))
			return (0);
	}
	iter = *(ws->a);
	old = iter->num;
	iter = iter->next;
	while (iter)
	{
		if (old > iter->num)
			break ;
		old = iter->num;
		iter = iter->next;
	}
	return (!iter);
}

t_list	*elements_to_drop(t_stack **st, int pivot, int name)
{
	t_list	*res;
	t_list	*tmpi;
	t_list	*tmpj;
	int		*tmpp;
	t_stack	*tmp;

	tmp = (*st)->next;
	res = ft_lstnew((*st)->num, sizeof(int));
	while (tmp)
	{
		if (!name ? tmp->num <= pivot : tmp->num >= pivot)
			ft_lstadd(&res, ft_lstnew(tmp->num, sizeof(int)));
		tmp = tmp->next;
	}
	tmpi = *(&res);
	while(tmpi)
	{
		tmpj = tmpi->next;
		while (tmpj)
		{
			if (!name ? (int)tmpi->content >= (int)tmpj->content :
				(int)tmpi->content <= (int)tmpj->content)
			{
				tmpp = (int)tmpi->content;
				tmpi->content = tmpj->content;
				tmpj->content = (void *)tmpp;
			}
			tmpj = tmpj->next;
		}
		tmpi = tmpi->next;
	}
}

void	sort(t_workspace *ws, t_parts info, int name)
{
	t_parts	info_next;
	int size;
	t_list *dr;

	if (is_sorted(ws, 1))
		return ;
	/*if (name && (*(ws->b))->num == 19)
		printf("nice");*/
	if (!name && (*(ws->b) != 0 ? (info_next.is_parted_b = 1) :
				  (info_next.is_parted_b = 0)))
		info_next.next_part_b = (*(ws->b))->num;
	else if (name && (info_next.is_parted_a = 1))
		info_next.next_part_a = (*(ws->a))->num;
	if ((size = part_length(ws, info, name)) <= 3)
	{
		small_sort(ws, info, name, size);
		return ;
	}
	int p = find_pivot(!name ? ws->a : ws->b, size);
	drop(ws, size, name, p);
	if (name)
	{
		info_next.is_parted_b = 1;
		info_next.next_part_b = *(ws->b) ? (*(ws->b))->num : 0;
	}
	sort(ws, info, 0);
	info_next.is_parted_a = 1;
	info_next.next_part_a = (*(ws->a))->num;
	if (name && (*(ws->b))->num == info_next.next_part_b)
	{
		info_next.is_parted_b = info.is_parted_b;
		info_next.next_part_b = info.next_part_b;
	}
	sort(ws, info_next, 1);
}