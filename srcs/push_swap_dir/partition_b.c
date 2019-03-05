/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:51:10 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/05 14:09:21 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_only_under_med(t_list *s_b, t_struct *data)
{
	t_list	*tmp;
	t_list	*pivot;

	tmp = s_b;
	pivot = data->pivot;
	while (*(int*)tmp->content < *(int*)pivot->content && tmp != data->end)
		tmp = tmp->next;
	if (tmp == data->end && *(int*)tmp->content < *(int*)pivot->content)
	{
		data->end_s_b = data->end;
		return (1);
	}
	return (0);
}

t_struct	*ft_process_p_r_b(t_stacks *stacks, t_struct *data)
{
	if ((ft_lst_n_size(*stacks->s_b, data->end) >= 3 &&
		*(int*)(*stacks->s_b)->content < *(int*)data->pivot->content &&
		*(int*)(*stacks->s_b)->next->content >= *(int*)data->pivot->content &&
		ft_only_under_med((*stacks->s_b)->next->next, data)))
	{
		ft_inst_swap_b(stacks);
		ft_inst_push_a(stacks);
		data->med_flag = 1;
	}
	else if ((ft_lst_n_size(*stacks->s_b, data->end) == 2 &&
		*(int*)(*(stacks->s_b))->content < *(int*)data->pivot->content &&
		*(int*)(*stacks->s_b)->next->content >= *(int*)data->pivot->content))
	{
		ft_inst_swap_b(stacks);
		ft_inst_push_a(stacks);
		data->med_flag = 1;
		data->end_s_b = *stacks->s_b;
	}
	else if (*(int*)(*(stacks->s_b))->content >= *(int*)data->pivot->content)
	{
		ft_inst_push_a(stacks);
		if (data->end_s_a == NULL)
			data->end_s_a = *(stacks->s_a);
	}
	else if (*(int*)(*(stacks->s_b))->content < *(int*)data->pivot->content)
	{
		ft_inst_rot_b(stacks);
		data->rotate = data->rotate + 1;
	}
	return (data);
}

t_struct	*ft_process_rrb(t_stacks *stacks, t_struct *data)
{
	if (data->end_null == 0)
	{
		if ((*stacks->s_b) && (*stacks->s_b)->next != NULL && data->rotate != 0)
		{
			while (--data->rotate + 1)
			{
				ft_inst_rev_rot_b(stacks);
				if (data->end_s_b == NULL)
					data->end_s_b = *(stacks->s_b);
			}
		}
	}
	else
		data->end_s_b = ft_lst_end(*(stacks->s_b));
	return (data);
}

t_struct	*ft_process_partition_b(t_stacks *stacks, t_struct *data)
{
	while (*stacks->s_b != data->end && data->med_flag == 0)
		data = ft_process_p_r_b(stacks, data);
	if (data->med_flag == 0)
		data = ft_process_p_r_b(stacks, data);
	data = ft_process_rrb(stacks, data);
	return (data);
}
