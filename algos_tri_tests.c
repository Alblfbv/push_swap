/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_tri_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 12:46:27 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/02 13:31:34 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

int	*bubble_sort(int *list, int size)
{
	int	i;
	int	tmp;
	int	swap;

	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (i < size - 1)
		{
			if (list[i] > list[i + 1])
			{
				tmp = list[i + 1];
				list[i + 1] = list[i];
				list[i] = tmp;
				swap = 1;
			}
			i++;
		}
	}
	return (list);
}

int	*insertion_sort(int *list, int size)
{
	int	i;
	int	j;
	int	x;

	i = 1;
	while (i < size)
	{
		x = list[i];
		j = i;
		while (j > 0 && list[j - 1] > x)
		{
			list[j] = list[j - 1];
			j = j - 1;
		}
		list[j] = x;
		i++;
	}
	return (list);
}

int	*selection_sort(int *list, int size)
{
	int	i;
	int	j;
	int	pos_min;

	i = 0;
	while (i < size - 1)
	{
		pos_min = i;
		j = i + 1;
		while (j < size)
		{
			if (list[j] < list[pos_min])
				pos_min = j;
			j++;
		}
		j = list[i];
		list[i] = pos_min;
		list[pos_min] = j;
		i++;
	}
	return (list);
}

int	main(void)
{
	int	list[] = {1, -4, 12, -5, -6, 7, 15, 45, 0, -2};
	int	*sorted_bubble;
	int	*sorted_insertion;
	int	*sorted_selection;
	int	i;

	sorted_bubble = bubble_sort(list, 10);
	sorted_insertion = insertion_sort(list, 10);
	sorted_selection = selection_sort(list, 10);
	i = 0;
	ft_printf("BUBBLE -\n");
	while (i < 10)
	{
		ft_printf("%d\n", sorted_bubble[i]);
		i++;
	}
	i = 0;
	ft_printf("\nINSERTION -\n");
	while (i < 10)
	{
		ft_printf("%d\n", sorted_insertion[i]);
		i++;
	}
	ft_printf("\nSELECTION -\n");
	i = 0;
	while (i < 10)
	{
		ft_printf("%d\n", sorted_selection[i]);
		i++;
	}

	return (0);
}
