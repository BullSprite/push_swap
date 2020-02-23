#include "../includes/push_swap.h"

#define A (*(ws->a))
#define A_N ((*(ws->a))->next)
#define A_NN ((*(ws->a))->next->next)
#define B (*(ws->b))
#define B_N ((*(ws->b))->next)
#define B_NN ((*(ws->b))->next->next)

void small_sort_parts_a(t_workspace *ws)
{
	if (A->num > A_N->num && A_N->num > A_NN->num)
	{
		swap(ws, 0);
		small_sort_parts_a(ws);
	}
	else if (A->num < A_N->num && A_N->num < A_NN->num)
		return ;
	else if (A->num < A_N->num && A->num > A_NN->num)
	{
		push_to_b(ws);
		swap(ws, 0);
		push_to_a(ws);
		swap(ws, 0);
	}
	else if (A->num > A_N->num && A->num > A_NN->num)
	{
		swap(ws, 0);
		small_sort_parts_a(ws);
	}
	else if (A->num < A_N->num && A->num < A_NN->num)
	{
		rotate(ws, 0);
		swap(ws, 0);
		reverse_rotate(ws, 0);
	}
	else //if (B->num > B_N->num)
		swap(ws, 0);
}

void small_sort_full_a(t_workspace *ws)
{
	while (1)
	{
		if (A->num < A_N->num && A_N->num < A_NN->num)
			return ;
		else if (A->num < A_N->num && A_N->num > A_NN->num)
			reverse_rotate(ws, 0);
		else if (A->num > A_N->num && A_N->num < A_NN->num &&
												 A->num > A_NN->num)
			rotate(ws, 0);
		else
			swap(ws, 0);
	}
}

void small_sort_parts_b(t_workspace *ws)
{
	if (B->num > B_N->num && B_N->num > B_NN->num)
	{
		push_to_a(ws);
		push_to_a(ws);
		push_to_a(ws);
	}
	else if (B->num < B_N->num && B_N->num < B_NN->num)
	{
		push_to_a(ws);
		swap(ws, 1);
		rotate(ws, 0);
		push_to_a(ws);
		push_to_a(ws);
		reverse_rotate(ws, 0);
	}
	else if (B->num < B_N->num && B->num > B_NN->num)
	{
		swap(ws, 1);
		push_to_a(ws);
		push_to_a(ws);
		push_to_a(ws);
	}
	else if (B->num > B_N->num && B->num > B_NN->num)
	{
		push_to_a(ws);
		swap(ws, 1);
		push_to_a(ws);
		push_to_a(ws);
	}
	else if (B->num < B_N->num && B->num < B_NN->num)
	{
		push_to_a(ws);
		rotate(ws, 0);
		push_to_a(ws);
		push_to_a(ws);
		reverse_rotate(ws, 0);
	}
	else //if (B->num > B_N->num)
	{
		push_to_a(ws);
		swap(ws, 1);
		push_to_a(ws);
		swap(ws, 0);
		push_to_a(ws);
	}
}

void small_sort_full_b(t_workspace *ws)
{
	if (B->num > B_N->num && B_N->num > B_NN->num)
	{
		push_to_a(ws);
		push_to_a(ws);
		push_to_a(ws);
	}
	else if (B->num < B_N->num && B_N->num < B_NN->num)
	{
		rotate(ws, 1);
		swap(ws, 1);
		push_to_a(ws);
		push_to_a(ws);
		push_to_a(ws);
	}
	else if (B->num < B_N->num && B->num > B_NN->num)
	{
		swap(ws, 1);
		push_to_a(ws);
		push_to_a(ws);
		push_to_a(ws);
	}
	else if (B->num > B_N->num && B->num > B_NN->num)
	{
		push_to_a(ws);
		swap(ws, 1);
		push_to_a(ws);
		push_to_a(ws);
	}
	else if (B->num < B_N->num && B->num < B_NN->num)
	{
		rotate(ws, 1);
		push_to_a(ws);
		push_to_a(ws);
		push_to_a(ws);
	}
	else //if (B->num > B_N->num)
	{
		reverse_rotate(ws, 1);
		push_to_a(ws);
		push_to_a(ws);
		push_to_a(ws);
	}
}

void	super_small_sort_b(t_workspace *ws, int size)
{
	if (size == 2)
	{
		if (B->num < B_N->num)
			swap(ws, 1);
		push_to_a(ws);
	}
	push_to_a(ws);
}

void small_sort(t_workspace *ws, t_parts info, int name, int size)
{
	if (size == 3)
	{
		if (!name)
		{
			if (info.is_parted_a)
				small_sort_parts_a(ws);
			else
				small_sort_full_a(ws);
		}
		else if (info.is_parted_b)
			small_sort_parts_b(ws);
		else
			small_sort_full_b(ws);
	}
	else if (size == 2)
	{
		if (!name)
		{
			if (A->num > A_N->num)
				swap(ws, 0);
		} else
			super_small_sort_b(ws, size);
	}
	else if (name)
		super_small_sort_b(ws, size);
}

