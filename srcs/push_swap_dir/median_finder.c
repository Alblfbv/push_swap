/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_finder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:23:35 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/18 19:14:41 by allefebv         ###   ########.fr       */
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
	free(tab);
	return (data);
}
