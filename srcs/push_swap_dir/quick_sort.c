/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:37:10 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/05 20:13:22 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_init_data(t_stacks *stacks, t_struct *data, t_list *end)
{
	data->end_s_a = NULL;
	data->end_s_b = NULL;
	data->rotate = 0;
	data->end_start = 0;
	data->med_flag = 0;
	data->end = end;
	if (data->end == ft_lst_end(*(stacks->s_a)) ||
		data->end == ft_lst_end(*(stacks->s_b)))
		data->end_null = 1;
	else
		data->end_null = 0;
}

t_struct	ft_partition_a(t_stacks *stacks, t_struct *data)
{
	data->list = 'A';
	data->start = *(stacks->s_a);
	data->end = ft_reduce_size_a(*(stacks->s_a), data);
	if (ft_2_elem_a(stacks, data->end))
		return (*data);
	if (ft_opti_3_a(stacks, data))
		return (*data);
	data = ft_chose_pivot(data);
	data = ft_process_partition_a(stacks, data);
	return (*data);
}

t_struct	ft_partition_b(t_stacks *stacks, t_struct *data)
{
	data->list = 'B';
	ft_reduce_size_b(stacks, data);
	if (data->end != *stacks->s_a && (!ft_2_elem_b(stacks, data->end)))
	{
		data->start = *(stacks->s_b);
		data = ft_find_median(data);
		data = ft_process_partition_b(stacks, data);
	}
	return (*data);
}

void		ft_quick_sort(t_stacks *stacks, t_list *start, t_list *end)
{
	t_struct	data;

	ft_init_data(stacks, &data, end);
	if (start != end)
	{
		if (start == *(stacks->s_a) && !(ft_lst_is_sorted(*stacks->s_a)))
			data = ft_partition_a(stacks, &data);
		else if (*(stacks->s_b) != NULL)
			data = ft_partition_b(stacks, &data);
		if (data.end_s_a != NULL && !(ft_lst_is_sorted(*stacks->s_a)))
			ft_quick_sort(stacks, *(stacks->s_a), data.end_s_a);
		if (data.end_s_b != NULL && *(stacks->s_b))
			ft_quick_sort(stacks, *(stacks->s_b), data.end_s_b);
	}
	else if (*(stacks->s_b) && start == *stacks->s_b)
		ft_inst_push_a(stacks);
}
