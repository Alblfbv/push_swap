/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:22:33 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/07 10:53:45 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_only_above_med(t_list *s_a, t_struct *data)
{
	t_list	*tmp;
	t_list	*pivot;

	tmp = s_a;
	pivot = data->pivot;
	while (*(int*)tmp->content >= *(int*)pivot->content && tmp != data->end)
		tmp = tmp->next;
	if (tmp == data->end && *(int*)tmp->content >= *(int*)pivot->content)
	{
		data->end_s_a = data->end;
		return (1);
	}
	return (0);
}

static int	ft_opti_med(t_stacks *stacks, t_struct *data)
{
	if (ft_lst_n_size(*stacks->s_a, data->end) > 3
		&& *(int*)(*(stacks->s_a))->content >= *(int*)data->pivot->content
		&& *(int*)(*stacks->s_a)->next->content < *(int*)data->pivot->content
		&& ft_only_above_med((*stacks->s_a)->next->next, data))
	{
		ft_inst_swap_a(stacks);
		ft_inst_push_b(stacks);
		data->med_flag = 1;
		return (1);
	}
	else if (ft_lst_n_size(*stacks->s_a, data->end) == 2
		&& (!ft_lst_is_sorted((*stacks->s_a)->next))
		&& *(int*)(*(stacks->s_a))->content >= *(int*)data->pivot->content
		&& *(int*)(*stacks->s_a)->next->content < *(int*)data->pivot->content)
	{
		ft_inst_swap_a(stacks);
		ft_inst_push_b(stacks);
		data->med_flag = 1;
		data->end_s_a = *stacks->s_a;
		return (1);
	}
	return (0);
}

t_struct	*ft_process_p_r_a(t_stacks *stacks, t_struct *data)
{
	if (ft_opti_med(stacks, data))
		return (data);
	if (*(int*)(*stacks->s_a)->content < *(int*)data->pivot->content)
	{
		ft_inst_push_b(stacks);
		if (data->end_s_b == NULL)
			data->end_s_b = *stacks->s_b;
	}
	else if (*(int*)(*stacks->s_a)->content >= *(int*)data->pivot->content)
	{
		ft_inst_rot_a(stacks);
		data->rotate = data->rotate + 1;
	}
	return (data);
}

t_struct	*ft_process_rra(t_stacks *stacks, t_struct *data)
{
	if (data->end_null == 0)
	{
		if (data->rotate != 0 && data->end_s_a == NULL)
			data->end_s_a = ft_lst_end(*stacks->s_a);
		if ((*stacks->s_a)->next != NULL)
			while (--data->rotate + 1)
				ft_inst_rev_rot_a(stacks);
	}
	else
		data->end_s_a = ft_lst_end(*stacks->s_a);
	return (data);
}

t_struct	*ft_process_partition_a(t_stacks *stacks, t_struct *data)
{
	while (*stacks->s_a != data->end && data->med_flag == 0)
		data = ft_process_p_r_a(stacks, data);
	if (data->med_flag == 0)
		data = ft_process_p_r_a(stacks, data);
	data = ft_process_rra(stacks, data);
	return (data);
}
