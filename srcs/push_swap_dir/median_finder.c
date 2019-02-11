/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_finder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:23:35 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/11 17:20:01 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static void	ft_find_median(t_list **s_a, t_list **s_b, t_struct **data)
{

}*/

static t_struct	*ft_split_stack(t_list **s_a, t_list **s_b, t_struct *data, t_list *pivot)
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
}

t_struct	ft_process_pivot(t_list **s_a, t_list **s_b, t_struct *data, t_list *pivot)
{
//	pivot = ft_find_median(s_a, s_b, data);
	data = ft_split_stack(s_a, s_b, data, pivot);
	return (*data);
}
