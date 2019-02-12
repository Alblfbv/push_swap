/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:18:50 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/12 19:29:36 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct	*ft_pivot_back(t_list **s_a, t_list **s_b, t_struct *data)
{
	if (data->pivot_push == 1)
	{
		ft_printf("%s\n", ft_push_a(s_a, s_b));
		data->pivot_push = 0;
	}
	else if (data->pivot_rot == 1)
	{
		ft_printf("%s\n", ft_rev_rotate_a(s_a, s_b));
		data->pivot_rot = 0;
	}
	return (data);
}

t_struct	*ft_pivot_forth(t_list **s_a, t_list **s_b, t_struct *data)
{
	if (*s_a == data->pivot && data->pivot != data->end)
	{
		if (*(int*)(*s_a)->next->content < *(int*)data->pivot->content)
		{
			ft_printf("%s\n", ft_rotate_a(s_a, s_b));
			data->pivot_rot = 1;
		}
		else if (*(int*)(*s_a)->next->content > *(int*)data->pivot->content)
		{
			ft_printf("%s\n", ft_push_b(s_a, s_b));
			data->pivot_push = 1;
		}
	}
	return (data);
}

int			ft_check_loop(t_list **s_a, t_struct data)
{
	if (*(int*)data.pivot->content > *(int*)data.end->content &&
				ft_lst_is_inlist(*s_a, data.end))
		return (1);
	if (*(int*)data.pivot->content < *(int*)data.end->content)
		return (1);
	else
		return (0);
}
