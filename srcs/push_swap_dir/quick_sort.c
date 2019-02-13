/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:37:10 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/13 17:07:19 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ft_printf("pivot = %d /\\ s_b = %d\n", *(int*)pivot->content, *(int*)(*s_b)->content);

/*if (*s_a)
	ft_printf("s_a = %d\n", *(int*)(*s_b)->content);
if (*s_b)
	ft_printf("s_b = %d\n", *(int*)(*s_b)->content);
*/

/*	ft_printf("pivot = %d\n", *(int*)data->pivot->content);
	ft_printf("end = %d\n", *(int*)data->end->content);
		if (s_b != NULL)
	{
		ft_printf("Liste b :\n");
		ft_lstiter(*s_b, &ft_lstprint_int);
	}
	if (s_a != NULL)
	{
		ft_printf("Liste a :\n");
		ft_lstiter(*s_a, &ft_lstprint_int);
	}
*/

void	ft_init_data(t_list **s_a, t_list **s_b, t_struct *data, t_list *end)
{
	data->first_rev_rotate = NULL;
	data->first_push = NULL;
	data->rotate = 0;
	data->end_start = 0;
	data->end = end;
	if (data->end == ft_lst_end(*s_a) || data->end == ft_lst_end(*s_b))
		data->end_null = 1;
	else
		data->end_null = 0;
}

t_struct	ft_pivot_a(t_list **s_a, t_list **s_b, t_struct *data)
{
	data->list = 'A';
	data->start = *s_a;
	data = ft_find_median(data);
	while (*s_a != data->end && !(data->end_start))
	{
		if (*s_a == data->pivot)
			ft_printf("%s\n", ft_swap_a(s_a, s_b));
		if (*s_a == data->end)
			data->end_start = 1;
		if (*(int*)(*s_a)->content < *(int*)data->pivot->content)
		{
			ft_printf("%s\n", ft_push_b(s_a, s_b));
			if (data->first_push == NULL)
				data->first_push = *s_b;
		}
		else if (*(int*)(*s_a)->content > *(int*)data->pivot->content)
		{
			ft_printf("%s\n", ft_rotate_a(s_a, s_b));
			data->rotate = data->rotate + 1;
		}
	}
	ft_printf("%s\n", ft_push_b(s_a, s_b));
	if (data->end_null == 0)
	{
		if (data->rotate != 0)
			data->first_rev_rotate = ft_lst_end(*s_a);
		data->rotate = data->rotate + 1;
		if ((*s_a)->next != NULL)
			while (--data->rotate)
				ft_printf("%s\n", ft_rev_rotate_a(s_a, s_b));
	}
	else
		data->end = ft_lst_end(*s_a);
	return (*data);
}

t_struct	ft_pivot_b(t_list **s_a, t_list **s_b, t_struct *data)
{
	data->list = 'B';
	data->start = *s_b;
	data = ft_find_median(data);
	ft_printf("%s\n", ft_push_a(s_a, s_b));
	while (*s_b != data->end && !(data->end_start))
	{
		if (*s_b == data->pivot)
			ft_printf("%s\n", ft_swap_b(s_a, s_b));
		if (*s_b == data->end)
			data->end_start = 1;
		if (*(int*)(*s_b)->content > *(int*)data->pivot->content)
		{
			ft_printf("%s\n", ft_push_a(s_a, s_b));
			if (data->first_push == NULL)
				data->first_push = *s_a;
		}
		else if (*(int*)(*s_b)->content < *(int*)data->pivot->content)
		{
			ft_printf("%s\n", ft_rotate_b(s_a, s_b));
			data->rotate = data->rotate + 1;
		}
	}
	if (data->end_null == 0)
	{
		if (data->rotate != 0)
			data->first_rev_rotate = ft_lst_end(*s_b);
		data->rotate = data->rotate + 1;
		if (data->rotate != 0)
			ft_printf("%s\n", ft_push_a(s_a, s_b));
		if ((*s_b) && (*s_b)->next != NULL)
			if (data->rotate != 0)
			{
				while (--data->rotate)
					ft_printf("%s\n", ft_rev_rotate_b(s_a, s_b));
				ft_printf("%s\n", ft_push_b(s_a, s_b));
			}
	}
	else
		data->end = ft_lst_end(*s_b);
	return (*data);
}

void	ft_quick_sort(t_list **s_a, t_list **s_b, t_list *start, t_list *end)
{
	t_struct	data;

	ft_init_data(s_a, s_b, &data, end);
	if (start != end)
	{
		//PIVOTS
		if (start == *s_a)
			data = ft_pivot_a(s_a, s_b, &data);
		else if (*s_b != NULL)
			data = ft_pivot_b(s_a, s_b, &data);

				//PREMIERE RECURSION
		if (data.first_rev_rotate != NULL && data.list == 'A')
			ft_quick_sort(s_a, s_b, *s_a, data.first_rev_rotate);
		else if (data.first_push != NULL && data.list == 'B')
			ft_quick_sort(s_a, s_b, *s_a, data.first_push);
		else if (data.end == ft_lst_end(*s_a))
			ft_quick_sort(s_a, s_b, *s_a, ft_lst_end(*s_a));

		//DEUXIEME RECURSION
		if (data.first_rev_rotate != NULL && *s_b && data.list == 'B')
			ft_quick_sort(s_a, s_b, *s_b, data.first_rev_rotate);
		else if (data.first_push != NULL && *s_b && data.list == 'A')
			ft_quick_sort(s_a, s_b, *s_b, data.first_push);
		else if (data.end == ft_lst_end(*s_b))
			ft_quick_sort(s_a, s_b, *s_b, ft_lst_end(*s_b));
	}
	else if ((*s_b) && (*s_b)->next == NULL)
		ft_printf("%s\n", ft_push_a(s_a, s_b));
}
