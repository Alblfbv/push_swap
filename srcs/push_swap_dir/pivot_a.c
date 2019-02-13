/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:18:50 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/13 13:44:13 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct	*ft_pivot_forth(t_list **s_a, t_list **s_b, t_struct *data)
{
	if (*s_a == data->pivot && data->pivot != data->end)
			ft_printf("%s\n", ft_swap_a(s_a, s_b));
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
