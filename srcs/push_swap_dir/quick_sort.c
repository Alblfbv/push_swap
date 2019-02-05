/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 19:00:55 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/05 19:08:25 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static void		ft_struct_init(t_struct *data)
{
	data->p_b = -1;
	data->p_a = -1;
	data->r_a = -1;
	data->r_b = -1;
	data->rr_a = -1;
	data->rr_b = -1;
	data->call = '0';
	data->sorted_part = NULL;
}*/

static void	ft_part_a(t_list **s_a, t_list **s_b, t_struct *data)
{
	t_list	*pivot;
	t_list	*start;

	pivot = *s_a;
	printf("pivot : %d\n", *(int*)pivot->content);
	while (pivot->next != data->sorted_part && pivot->next != NULL)
		pivot = pivot->next;
	printf("pivot : %d\n", *(int*)pivot->content);
	while (pivot != start)
	{
		if (*(int*)(*s_a)->content < *(int*)pivot->content)
		{
			printf("start : %d\n", *(int*)(*s_a)->content);
			ft_push_b(s_a, s_b);
			data->p_b++;
		}
		else
			ft_rotate_a(s_a, s_b);
			data->r_a++;
	}
	ft_push_b(s_a, s_b);
}

static void	ft_part_b(t_list **s_a, t_list **s_b, t_struct *data)
{
	t_list	*pivot;
	t_list	*start;

	pivot = *s_b;
	while (data->p_b)
	{
		pivot = pivot->next;
		data->p_b--;
	}
	ft_push_a(s_a, s_b);
	data->sorted_part = *s_a;
	start = *s_b;
	while (pivot != start)
	{
		if (*(int*)start->content < *(int*)pivot->content)
		{
			ft_push_a(s_a, s_b);
			data->p_a++;
		}
		else
			ft_rotate_b(s_a, s_b);
			data->r_b++;
	}
	if (data->p_a == 1)
		data->sorted_part = *s_a;
}

static void	ft_partition(t_list **s_a, t_list **s_b, t_struct *data)
{	
	if (data->call == 'a')
	{
		ft_printf("Liste a :\n");
		ft_lstiter(*s_a, &ft_lstprint_int);
		ft_part_a(s_a, s_b, data);
	}
//	else
//		ft_part_b(s_a, s_b, data);
}	

void	ft_quick_sort(t_list **s_a, t_list **s_b, t_list **instruct, t_struct *data)
{
	printf("%d", data->p_b);
	if (data->sorted_part != *s_a)
	{
		ft_partition(s_a, s_b, data);
	}
	if (*s_a != data->sorted_part && *s_a != NULL)
	{
		data->call = 'a';
		ft_quick_sort(s_a, s_b, instruct, data);
	}
	printf("%d", data->p_b);
	if (*s_b != NULL)
	{
		data->call = 'b';
//		ft_quick_sort(s_a, s_b, instruct, data);
	}
}
