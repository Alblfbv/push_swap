/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_a_optis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:58:25 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/05 14:03:36 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_lst_max(t_list *s_a, t_list *end)
{
	if (s_a == NULL || end == NULL || s_a == end)
		return (0);
	while (*(int*)s_a->content < *(int*)end->content)
		s_a = s_a->next;
	if (s_a == end)
		return (1);
	return (0);
}

t_list		*ft_reduce_size_a(t_list *s_a, t_struct *data)
{
	while (ft_lst_max(s_a, data->end))
		data->end = ft_lst_find_prev(s_a, data->end);
	return (data->end);
}

int			ft_2_elem_a(t_stacks *stacks, t_list *end)
{
	if (end == (*stacks->s_a)->next)
	{
		ft_inst_swap_a(stacks);
		return (1);
	}
	return (0);
}
