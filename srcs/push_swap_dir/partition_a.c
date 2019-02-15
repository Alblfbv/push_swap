/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:22:33 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/15 17:07:31 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct	*ft_process_partition_a(t_stacks *stacks, t_struct *data)
{
	while (*(stacks->s_a) != data->end && !(data->end_start))
	{
		if (*(stacks->s_a) == data->pivot)
			ft_lstadd_end(stacks->instruct, ft_lstnew(ft_swap_a(stacks->s_a, stacks->s_b), sizeof(char*)));
		if (*stacks->s_a == data->end)
			data->end_start = 1;
		if (*(int*)(*(stacks->s_a))->content < *(int*)data->pivot->content)
		{
			ft_lstadd_end(stacks->instruct, ft_lstnew(ft_push_b(stacks->s_a, stacks->s_b), sizeof(char*)));
			if (data->first_push == NULL)
				data->first_push = *stacks->s_b;
		}
		else if (*(int*)(*(stacks->s_a))->content > *(int*)data->pivot->content)
		{
			ft_lstadd_end(stacks->instruct, ft_lstnew(ft_rotate_a(stacks->s_a, stacks->s_b), sizeof(char*)));
			data->rotate = data->rotate + 1;
		}
	}
	ft_lstadd_end(stacks->instruct, ft_lstnew(ft_push_b(stacks->s_a, stacks->s_b), sizeof(char*)));
	return (data);
}

t_struct	*ft_process_rev_rot_a(t_stacks *stacks, t_struct *data)
{
	if (data->end_null == 0)
	{
		if (data->rotate != 0)
			data->first_rev_rotate = ft_lst_end(*(stacks->s_a));
		if ((*(stacks->s_a))->next != NULL)
			while (--data->rotate + 1)
				ft_lstadd_end(stacks->instruct, ft_lstnew(ft_rev_rotate_a(stacks->s_a, stacks->s_b), sizeof(char*)));
	}
	else
		data->end = ft_lst_end(*(stacks->s_a));
	return (data);
}
