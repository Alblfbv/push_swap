/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:37:10 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/11 18:17:56 by allefebv         ###   ########.fr       */
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

t_struct	ft_pivot_a(t_list **s_a, t_list **s_b, t_list *end, t_struct *data)
{
	data->pivot = end;
	ft_init_data(data);
	data->first_run = 1;
	data->list = 'A';
	while (*s_a != data->pivot)
	{
		if (*(int*)(*s_a)->content < *(int*)data->pivot->content)
		{
			ft_printf("%s\n", ft_push_b(s_a, s_b));
			if (data->first_push == NULL)
				data->first_push = *s_b;
		}
		else if (*(int*)(*s_a)->content > *(int*)data->pivot->content)
			ft_printf("%s\n", ft_rotate_a(s_a, s_b));
	}
	ft_printf("%s\n", ft_push_b(s_a, s_b));
	return (*data);
}

t_struct	ft_pivot_b(t_list **s_a, t_list **s_b, t_list *end, t_struct *data)
{
	data->pivot = end;
	ft_init_data(data);
	data->list = 'A';
	while (*s_a != data->pivot)
	{
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
	if (data->rotate != 0)
		data->first_rev_rotate = ft_lst_end(*s_a);
	data->rotate = data->rotate + 1;
	if ((*s_a)->next != NULL)
		while (--data->rotate)
			ft_printf("%s\n", ft_rev_rotate_a(s_a, s_b));
	return (*data);
}

t_struct	ft_pivot_c(t_list **s_a, t_list **s_b,  t_list *end, t_struct *data)
{
	data->pivot = end;
	ft_init_data(data);
	data->list = 'B';
	ft_printf("%s\n", ft_push_a(s_a, s_b));
	while (*s_b != data->pivot)
	{
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
	return (*data);
}


void	ft_quick_sort(t_list **s_a, t_list **s_b, t_list *start, t_list *end)
{
	t_struct	data;

	if (start != end)
	{
		//PIVOTS
		if (start == *s_a && end == ft_lst_end(*s_a))
			data = ft_pivot_a(s_a, s_b, end, &data);
		else if (start == *s_a && end != ft_lst_end(*s_a))
			data = ft_pivot_b(s_a, s_b, end, &data);
		else if (*s_b != NULL)
			data = ft_pivot_c(s_a, s_b, end, &data);

		//PREMIERE RECURSION
		if (data.first_rev_rotate != NULL && data.list == 'A')
			ft_quick_sort(s_a, s_b, *s_a, data.first_rev_rotate);
		else if (data.first_push != NULL && data.list == 'B')
			ft_quick_sort(s_a, s_b, *s_a, data.first_push);
		else if (data.first_run == 1)
			ft_quick_sort(s_a, s_b, *s_a, ft_lst_end(*s_a));

		//DEUXIEME RECURSION
		if (data.first_rev_rotate != NULL && *s_b && data.list == 'B')
			ft_quick_sort(s_a, s_b, *s_b, data.first_rev_rotate);
		else if (data.first_push != NULL && *s_b && data.list == 'A')
			ft_quick_sort(s_a, s_b, *s_b, data.first_push);
	}
	else if ((*s_b) && (*s_b)->next == NULL)
		ft_printf("%s\n", ft_push_a(s_a, s_b));
}
