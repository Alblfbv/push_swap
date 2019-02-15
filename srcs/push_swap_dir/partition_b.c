/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:51:10 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/15 17:07:39 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct	*ft_process_partition_b(t_stacks *stacks, t_struct *data)
{
	ft_lstadd_end(stacks->instruct, ft_lstnew(ft_push_a(stacks->s_a, stacks->s_b), sizeof(char*)));
	while (*(stacks->s_b) != data->end && !(data->end_start))
	{
		if (*(stacks->s_b) == data->pivot)
			ft_lstadd_end(stacks->instruct, ft_lstnew(ft_swap_b(stacks->s_a, stacks->s_b), sizeof(char*)));
		if (*(stacks->s_b) == data->end)
			data->end_start = 1;
		if (*(int*)(*(stacks->s_b))->content > *(int*)data->pivot->content)
		{
			ft_lstadd_end(stacks->instruct, ft_lstnew(ft_push_a(stacks->s_a, stacks->s_b), sizeof(char*)));
			if (data->first_push == NULL)
				data->first_push = *(stacks->s_a);
		}
		else if (*(int*)(*(stacks->s_b))->content < *(int*)data->pivot->content)
		{
			ft_lstadd_end(stacks->instruct, ft_lstnew(ft_rotate_b(stacks->s_a, stacks->s_b), sizeof(char*)));
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
			data->first_rev_rotate = ft_lst_end(*(stacks->s_b));
		if (data->rotate != 0)
			ft_lstadd_end(stacks->instruct, ft_lstnew(ft_push_a(stacks->s_a, stacks->s_b), sizeof(char*)));
		if ((*stacks->s_b) && (*stacks->s_b)->next != NULL && data->rotate != 0)
		{
			while (--data->rotate + 1)
				ft_lstadd_end(stacks->instruct, ft_lstnew(ft_rev_rotate_b(stacks->s_a, stacks->s_b), sizeof(char*)));
			ft_lstadd_end(stacks->instruct, ft_lstnew(ft_push_b(stacks->s_a, stacks->s_b), sizeof(char*)));
		}
	}
	else
		data->end = ft_lst_end(*(stacks->s_b));
	return (data);
}
