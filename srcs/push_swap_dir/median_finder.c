/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_finder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:23:35 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/05 13:22:06 by allefebv         ###   ########.fr       */
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

t_struct	*ft_find_median(t_struct *data)
{
	int		size;
	int		*sort_tab;
	int		i;
	t_list	*tmp;

	i = 0;
	size = ft_lst_n_size(data->start, data->end);
	tmp = data->start;
	sort_tab = ft_memalloc(sizeof(int) * size);
	while (i < size && tmp != NULL)
	{
		sort_tab[i] = *(int*)tmp->content;
		i++;
		tmp = tmp->next;
	}
	ft_sort(sort_tab, size);
	tmp = data->start;
	while (*(int*)tmp->content != sort_tab[size / 2])
		tmp = tmp->next;
	data->pivot = tmp;
	free(sort_tab);
	return (data);
}

t_struct	*ft_chose_pivot(t_struct *data)
{
	data = ft_find_median(data);
	return (data);
}
