/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:37:10 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/08 12:34:37 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ft_printf("pivot = %d /\\ s_b = %d\n", *(int*)pivot->content, *(int*)(*s_b)->content);

void	ft_init_data(t_struct *data)
{
	data->rev_rotate_a = NULL;
	data->rev_rotate_b = NULL;
	data->push_a = NULL;
	data->push_b = NULL;
}

t_struct	ft_pivot_a(t_list **s_a, t_list **s_b, t_list *end)
{
	t_list		*pivot;
	t_struct	data;

	pivot = end;
	ft_init_data(&data);
	data.pivot = 'a';
//	ft_printf("pivot = %d /\\ s_a = %d\n", *(int*)pivot->content, *(int*)(*s_a)->content);
	while (*s_a != pivot)
	{
		if (*(int*)(*s_a)->content < *(int*)pivot->content)
		{
			ft_printf("%s\n", ft_push_b(s_a, s_b));
			if (data.push_b == NULL)
				data.push_b = *s_b;
		}
		else if (*(int*)(*s_a)->content > *(int*)pivot->content)
			ft_printf("%s\n", ft_rotate_a(s_a, s_b));
	}
	ft_printf("%s\n", ft_push_b(s_a, s_b));
	return (data);
}

t_struct	ft_pivot_b(t_list **s_a, t_list **s_b, t_list *end)
{
	t_list		*pivot;
	t_struct	data;
	int			rotate_a;

	pivot = end;
	rotate_a = 0;
//	ft_printf("pivot = %d /\\ s_a = %d\n", *(int*)pivot->content, *(int*)(*s_a)->content);
	ft_init_data(&data);
	while (*s_a != pivot)
	{
		if (*(int*)(*s_a)->content < *(int*)pivot->content)
		{
			ft_printf("%s\n", ft_push_b(s_a, s_b));
			if (data.push_b == NULL)
				data.push_b = *s_b;
		}
		else if (*(int*)(*s_a)->content > *(int*)pivot->content)
		{
			ft_printf("%s\n", ft_rotate_a(s_a, s_b));
			rotate_a++;
		}
	}
	ft_printf("%s\n", ft_push_b(s_a, s_b));
	if (rotate_a != 0)
		data.rev_rotate_a = ft_lst_end(*s_a);
	rotate_a++;
	if ((*s_a)->next != NULL)
		while (--rotate_a)
			ft_printf("%s\n", ft_rev_rotate_a(s_a, s_b));
	ft_printf("%s\n", ft_push_a(s_a, s_b));
	return (data);
}

t_struct	ft_pivot_c(t_list **s_a, t_list **s_b,  t_list *end)
{
	t_list		*pivot;
	t_struct	data;
	int			rotate_b;

	pivot = end;
	rotate_b = 0;
	ft_init_data(&data);

//	ft_printf("pivot = %d /\\ s_b = %d\n", *(int*)pivot->content, *(int*)(*s_b)->content);
	while (*s_b != pivot)
	{
		if (*(int*)(*s_b)->content > *(int*)pivot->content)
		{
			ft_printf("%s\n", ft_push_a(s_a, s_b));
			if (data.push_a == NULL)
				data.push_a = *s_a;
		}
		else if (*(int*)(*s_b)->content < *(int*)pivot->content)
		{
			ft_printf("%s\n", ft_rotate_b(s_a, s_b));
			rotate_b++;
		}
	}
	if (rotate_b != 0)
		data.rev_rotate_b = ft_lst_end(*s_b);
	rotate_b++;
	ft_printf("%s\n", ft_push_a(s_a, s_b));
	if ((*s_b)->next != NULL)
		while (--rotate_b)
			ft_printf("%s\n", ft_rev_rotate_b(s_a, s_b));
	ft_printf("%s\n", ft_push_b(s_a, s_b));
	return (data);
}


void	ft_quick_sort(t_list **s_a, t_list **s_b, t_list *start, t_list *end)
{
	t_struct	data;
	t_list		*end_s_a;

	if (*s_a)
		end_s_a = ft_lst_end(*s_a);
	ft_init_data(&data);
	if (start != end)
	{
		//PIVOTS
		if (start == *s_a && end == end_s_a)
		{
//			ft_printf("pivot A\n");
			data = ft_pivot_a(s_a, s_b, end);
		}
		else if (start == *s_a && end != end_s_a)
		{
//			ft_printf("pivot B\n");
			data = ft_pivot_b(s_a, s_b, end);
		}
		else
		{
//			ft_printf("pivot C\n");
			data = ft_pivot_c(s_a, s_b, end);
		}

	/*	if (*s_a)
		{
//			ft_printf("PILE A apres pivot :\n");
			ft_lstiter(*s_a, &ft_lstprint_int);
		}
		if (*s_b)
		{
//			ft_printf("PILE B apres pivot :\n");
			ft_lstiter(*s_b, &ft_lstprint_int);
		}*/


		//PREMIERE RECURSION
		if (data.rev_rotate_a != NULL)
		{
//			ft_printf("QS RRA /\\ rra = %d\n", *(int*)data.rev_rotate_a->content);
			ft_quick_sort(s_a, s_b, *s_a, data.rev_rotate_a);
		}
		else if (data.push_a != NULL)
		{
//			ft_printf("QS PA /\\ pa = %d\n", *(int*)data.push_a->content);
			ft_quick_sort(s_a, s_b, *s_a, data.push_a);
		}
		else if (data.pivot == 'a')
		{
//			ft_printf("QS BASE\n");
			end = ft_lst_end(*s_a);
			ft_quick_sort(s_a, s_b, *s_a, end);
		}

		//DEUXIEME RECURSION
		if (data.rev_rotate_b != NULL)
		{
//			ft_printf("QS RRB /\\ rrb = %d\n", *(int*)data.rev_rotate_b->content);
			ft_quick_sort(s_a, s_b, *s_b, data.rev_rotate_b);
		}
		if (data.push_b != NULL)
		{
//			ft_printf("QS PB /\\ pb = %d\n", *(int*)data.push_b->content);
			ft_quick_sort(s_a, s_b, *s_b, data.push_b);
		}
		else
		{
//			ft_printf("No QS 2 ni RRB ni PB\n");
			if (*s_b)
				ft_printf("%s\n", ft_push_a(s_a, s_b));
		}
	}
	else
		ft_printf("%s\n", ft_push_a(s_a, s_b));
}
