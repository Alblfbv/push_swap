/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:37:10 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/15 18:20:53 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ft_printf("pivot = %d /\\ s_b = %d\n", *(int*)pivot->content, *(int*)(*s_b)->content);

/*if (*s_a)
	ft_printf("s_a = %d\n", *(int*)(*s_b)->content);
if (*s_b)
	ft_printf("s_b = %d\n", *(int*)(*s_b)->content);
*/

/*	ft_printf("pivot = %d\n", *(int*)data->pivot->content);
	ft_printf("end = %d\n", *(int*)data->end->content);
		if (s_b != NULL)
	{
		ft_printf("Liste b :\n");
		ft_lstiter(*s_b, &ft_lstprint_int);
	}
	if (s_a != NULL)
	{
		ft_printf("Liste a :\n");
		ft_lstiter(*s_a, &ft_lstprint_int);
	}
*/

void	ft_init_data(t_stacks *stacks, t_struct *data, t_list *end)
{
	data->first_rev_rotate = NULL;
	data->first_push = NULL;
	data->end_s_a = NULL;
	data->end_s_b = NULL;
	data->rotate = 0;
	data->end_start = 0;
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
	data = ft_find_median(data);
	data = ft_process_partition_a(stacks, data);
	data = ft_process_rev_rot_a(stacks, data);
	return (*data);
}

t_struct	ft_partition_b(t_stacks *stacks, t_struct *data)
{
	data->list = 'B';
	data->start = *(stacks->s_b);
	data = ft_find_median(data);
	data = ft_process_partition_b(stacks, data);
	data = ft_process_rev_rot_b(stacks, data);
	return (*data);
}

void	ft_quick_sort(t_stacks *stacks, t_list *start, t_list *end)
{
	t_struct	data;

	ft_init_data(stacks, &data, end);
	if (start != end)
	{
		//PIVOTS
		if (start == *(stacks->s_a))
			data = ft_partition_a(stacks, &data);
		else if (*(stacks->s_b) != NULL)
			data = ft_partition_b(stacks, &data);

		//PREMIERE RECURSION
		if (data.end_s_a != NULL && *(stacks->s_a))
			ft_quick_sort(stacks, *(stacks->s_a), data.end_s_a);
		//DEUXIEME RECURSION
		if (data.end_s_b != NULL && *(stacks->s_b))
			ft_quick_sort(stacks, *(stacks->s_b), data.end_s_b);
	}
	else if (*(stacks->s_b) && (*(stacks->s_b))->next == NULL)
		ft_lstadd_end(stacks->instruct,
		ft_lstnew(ft_push_a(stacks->s_a, stacks->s_b), sizeof(char*)));
}
