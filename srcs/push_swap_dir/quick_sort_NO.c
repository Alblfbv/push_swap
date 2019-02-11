/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:37:10 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/11 16:39:20 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ft_printf("pivot = %d /\\ s_b = %d\n", *(int*)pivot->content, *(int*)(*s_b)->content);

void	ft_init_data(t_struct *data)
{
	data->first_rev_rotate = NULL;
	data->first_push = NULL;
	data->rotate = 0;
	data->first_run = 0;
}

t_struct	ft_pivot_a(t_list **s_a, t_list **s_b, t_list *end)
{
	t_list		*pivot;
	t_struct	data;

	pivot = end;
	ft_init_data(&data);
	data.first_run = 1;
	data.pivot = 'A';
	while (*s_a != pivot)
	{
		if (*(int*)(*s_a)->content < *(int*)pivot->content)
		{
			ft_printf("%s\n", ft_push_b(s_a, s_b));
			if (data.first_push == NULL)
				data.first_push = *s_b;
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
	ft_init_data(&data);
	data.pivot = 'A';
	while (*s_a != pivot)
	{
		if (*(int*)(*s_a)->content < *(int*)pivot->content)
		{
			ft_printf("%s\n", ft_push_b(s_a, s_b));
			if (data.first_push == NULL)
				data.first_push = *s_b;
		}
		else if (*(int*)(*s_a)->content > *(int*)pivot->content)
		{
			ft_printf("%s\n", ft_rotate_a(s_a, s_b));
			rotate_a++;
		}
	}
	ft_printf("%s\n", ft_push_b(s_a, s_b));
	if (rotate_a != 0)
		data.first_rev_rotate = ft_lst_end(*s_a);
	rotate_a++;
	if ((*s_a)->next != NULL)
		while (--rotate_a)
			ft_printf("%s\n", ft_rev_rotate_a(s_a, s_b));
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
	data.pivot = 'B';
	ft_printf("%s\n", ft_push_a(s_a, s_b));
	while (*s_b != pivot)
	{
		if (*(int*)(*s_b)->content > *(int*)pivot->content)
		{
			ft_printf("%s\n", ft_push_a(s_a, s_b));
			if (data.first_push == NULL)
				data.first_push = *s_a;
		}
		else if (*(int*)(*s_b)->content < *(int*)pivot->content)
		{
			ft_printf("%s\n", ft_rotate_b(s_a, s_b));
			rotate_b++;
		}
	}
	if (rotate_b != 0)
		data.first_rev_rotate = ft_lst_end(*s_b);
	rotate_b++;
	if (rotate_b)
		ft_printf("%s\n", ft_push_a(s_a, s_b));
	if ((*s_b) && (*s_b)->next != NULL)
		if (rotate_b)
		{
			while (--rotate_b)
				ft_printf("%s\n", ft_rev_rotate_b(s_a, s_b));
			ft_printf("%s\n", ft_push_b(s_a, s_b));
		}
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
			data = ft_pivot_a(s_a, s_b, end);
		else if (start == *s_a && end != end_s_a)
			data = ft_pivot_b(s_a, s_b, end);
		else if (*s_b != NULL)
			data = ft_pivot_c(s_a, s_b, end);

		//PREMIERE RECURSION
		if (data.first_rev_rotate != NULL && data.pivot == 'A')
			ft_quick_sort(s_a, s_b, *s_a, data.first_rev_rotate);
		else if (data.first_push != NULL && data.pivot == 'B')
			ft_quick_sort(s_a, s_b, *s_a, data.first_push);
		else if (data.first_run == 1)
			ft_quick_sort(s_a, s_b, *s_a, ft_lst_end(*s_a));

		//DEUXIEME RECURSION
		if (data.first_rev_rotate != NULL && *s_b && data.pivot == 'B')
			ft_quick_sort(s_a, s_b, *s_b, data.first_rev_rotate);
		else if (data.first_push != NULL && *s_b && data.pivot == 'A')
			ft_quick_sort(s_a, s_b, *s_b, data.first_push);
	}
	else if ((*s_b) && (*s_b)->next == NULL)
		ft_printf("%s\n", ft_push_a(s_a, s_b));
}
