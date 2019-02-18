/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:51:10 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/18 19:19:54 by allefebv         ###   ########.fr       */
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
		ft_lstadd_end(stacks->instruct,
		ft_lstnew(ft_push_a(stacks->s_a, stacks->s_b), sizeof(char*)));
		return (0);
	}
	tmp = (*stacks->s_b)->next;

	while (*(int*)(*stacks->s_b)->content > *(int*)tmp->content && tmp != data->end)
		tmp = tmp->next;
	if (tmp == data->end && *(int*)(*stacks->s_b)->content > *(int*)data->end->content)
		return (1);
	return (0);
}

void		ft_reduce_size_b(t_stacks *stacks, t_struct *data)
{
	while (ft_lst_max_start(stacks, data))
		ft_lstadd_end(stacks->instruct,
		ft_lstnew(ft_push_a(stacks->s_a, stacks->s_b), sizeof(char*)));
}

t_struct	*ft_process_partition_b(t_stacks *stacks, t_struct *data)
{
	while (*(stacks->s_b) != data->end && !(data->end_start))
	{
		if (*(stacks->s_b) == data->pivot)
			ft_lstadd_end(stacks->instruct,
			ft_lstnew(ft_swap_b(stacks->s_a, stacks->s_b), sizeof(char*)));
		if (*(stacks->s_b) == data->end)
			data->end_start = 1;
		if (*(int*)(*(stacks->s_b))->content > *(int*)data->pivot->content)
		{
			ft_lstadd_end(stacks->instruct,
			ft_lstnew(ft_push_a(stacks->s_a, stacks->s_b), sizeof(char*)));
			if (data->end_s_a == NULL)
				data->end_s_a = *(stacks->s_a);
		}
		else if (*(int*)(*(stacks->s_b))->content < *(int*)data->pivot->content)
		{
			ft_lstadd_end(stacks->instruct,
			ft_lstnew(ft_rotate_b(stacks->s_a, stacks->s_b), sizeof(char*)));
			data->rotate = data->rotate + 1;
		}
	}
	return (data);
}

t_struct	*ft_process_rev_rot_b(t_stacks *stacks, t_struct *data)
{
	if (data->end_null == 0)
	{
		if (data->rotate != 0)
		{
			data->end_s_b = ft_lst_end(*(stacks->s_b));
			ft_lstadd_end(stacks->instruct,
			ft_lstnew(ft_push_a(stacks->s_a, stacks->s_b), sizeof(char*)));
		}
		if ((*stacks->s_b) && (*stacks->s_b)->next != NULL && data->rotate != 0)
		{
			while (--data->rotate + 1)
				ft_lstadd_end(stacks->instruct,
				ft_lstnew(ft_rev_rotate_b(stacks->s_a, stacks->s_b), sizeof(char*)));
			ft_lstadd_end(stacks->instruct,
			ft_lstnew(ft_push_b(stacks->s_a, stacks->s_b), sizeof(char*)));
		}
	}
	else
		data->end_s_b = ft_lst_end(*(stacks->s_b));
	return (data);
}
