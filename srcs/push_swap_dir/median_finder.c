/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_finder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:23:35 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/13 15:05:53 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct	*ft_find_median(t_struct *data)
{
	int		size;
	int		*tab;
	int		i;
	t_list	*tmp;
	int		median;

	i = 0;
	size = ft_lst_n_size(data->start, data->end);
	tmp = data->start;
	tab = ft_memalloc(sizeof(int) * size);
	while (i < size && tmp != NULL)
	{
		tab[i] = *(int*)tmp->content;
		i++;
		tmp = tmp->next;
	}
	ft_sort(tab, size);
	median = tab[size / 2];
	tmp = data->start;
	while (*(int*)tmp->content != median)
		tmp = tmp->next;
	data->pivot = tmp;
	return (data);
}

/*static t_struct	*ft_split_stack(t_list **s_a, t_list **s_b, t_struct *data, t_list *pivot)
{
	if (data->pivot == 'B')
		ft_printf("%s\n", data->ft_push(s_a, s_b));
	while (*s_a != pivot)
	{
		if (*(int*)((*data->start)->content) < *(int*)pivot->content)
		{
			if (data->pivot == 'A')
			{
				ft_printf("%s\n", data->ft_push(s_a, s_b));
				if (data->first_push == NULL)
					data->first_push = *s_b;
			}
			else
			{
				ft_printf("%s\n", data->ft_rotate(s_a, s_b));
				data->rotate++;
			}
		}
		else if (*(int*)((*data->start)->content) > *(int*)pivot->content)
		{
			ft_printf("%s\n", data->ft_rotate(s_a, s_b));
			data->rotate = data->rotate + 1;
		}
	}
	if (data->pivot == 'A')
		ft_printf("%s\n", data->ft_push(s_a, s_b));
	return (data);
}*/
