/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:51:10 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/20 18:25:55 by allefebv         ###   ########.fr       */
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

int			ft_2_elem_b(t_stacks *stacks, t_list *end)
{
	if (end == (*stacks->s_b)->next)
	{
		ft_lstadd_end(stacks->instruct,
		ft_lstnew(ft_swap_b(stacks->s_a, stacks->s_b), sizeof(char*)));
		ft_lstadd_end(stacks->instruct,
		ft_lstnew(ft_push_a(stacks->s_a, stacks->s_b), sizeof(char*)));
		ft_lstadd_end(stacks->instruct,
		ft_lstnew(ft_push_a(stacks->s_a, stacks->s_b), sizeof(char*)));
		return (1);
	}
	return (0);
}

t_struct	*ft_process_p_r_b(t_stacks *stacks, t_struct *data)
{
	if (*(int*)(*(stacks->s_b))->content >= *(int*)data->pivot->content)
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
				ft_lstadd_end(stacks->instruct,
				ft_lstnew(ft_rev_rotate_b(stacks->s_a, stacks->s_b), sizeof(char*)));
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
	while (*(stacks->s_b) != data->end)
		data = ft_process_p_r_b(stacks, data);
	data = ft_process_p_r_b(stacks, data);
	data = ft_process_rrb(stacks, data);
	return (data);
}
