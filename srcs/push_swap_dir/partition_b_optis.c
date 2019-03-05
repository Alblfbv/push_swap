/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_b_optis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:57:34 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/05 14:03:16 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_lst_max_start(t_stacks *stacks, t_struct *data)
{
	t_list	*tmp;

	if (*stacks->s_b == NULL || data->end == NULL)
		return (0);
	if ((*stacks->s_b)->next == NULL || *stacks->s_b == data->end)
	{
		ft_inst_push_a(stacks);
		return (0);
	}
	tmp = (*stacks->s_b)->next;
	while (tmp != data->end &&
		*(int*)(*stacks->s_b)->content > *(int*)tmp->content)
		tmp = tmp->next;
	if (tmp == data->end &&
		*(int*)(*stacks->s_b)->content > *(int*)data->end->content)
		return (1);
	return (0);
}

void		ft_reduce_size_b(t_stacks *stacks, t_struct *data)
{
	while (ft_lst_max_start(stacks, data))
		ft_inst_push_a(stacks);
}

int			ft_2_elem_b(t_stacks *stacks, t_list *end)
{
	if (end == (*stacks->s_b)->next && end != NULL)
	{
		ft_inst_swap_b(stacks);
		ft_inst_push_a(stacks);
		ft_inst_push_a(stacks);
		return (1);
	}
	return (0);
}
