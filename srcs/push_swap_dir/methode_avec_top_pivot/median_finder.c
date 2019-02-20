/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_finder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:23:35 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/20 15:54:04 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_find_pos(int to_find, int *tab)
{
	int	i;

	i = 0;
	while (tab[i] != to_find)
		i++;
	return (i);
}

int			ft_opti_median(int *sort_tab, int *unsort_tab, int size)
{
	int	min;
	int	max;
	int	opti_pos;
	int	tmp_pos;

	max = ((float)(size / 2) * (float)1.12); 
	min = ((float)(size / 2) * (float)0.88);
	opti_pos = ft_find_pos(sort_tab[min], unsort_tab);
	while (min < max)
	{
		min++;
		tmp_pos = ft_find_pos(sort_tab[min], unsort_tab);
		if (opti_pos < tmp_pos)
			opti_pos = tmp_pos;
	}
	return (unsort_tab[opti_pos]);
}

t_struct	*ft_find_median(t_struct *data)
{
	int		size;
	int		*sort_tab;
	int		*unsort_tab;
	int		i;
	t_list	*tmp;
	int		median;

	i = 0;
	size = ft_lst_n_size(data->start, data->end);
	tmp = data->start;
	unsort_tab = ft_memalloc(sizeof(int) * size);
	sort_tab = ft_memalloc(sizeof(int) * size);
	while (i < size && tmp != NULL)
	{
		unsort_tab[i] = *(int*)tmp->content;
		sort_tab[i] = *(int*)tmp->content;
		i++;
		tmp = tmp->next;
	}
	ft_sort(sort_tab, size);
	median = ft_opti_median(sort_tab, unsort_tab, size);
	tmp = data->start;
	while (*(int*)tmp->content != median)
		tmp = tmp->next;
	data->pivot = tmp;
	free(unsort_tab);
	free(sort_tab);
	return (data);
}

t_struct	*ft_chose_pivot(t_struct *data)
{
	data = ft_find_median(data);
	return (data);
}
