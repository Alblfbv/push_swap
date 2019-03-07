/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:54:45 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/07 12:38:16 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_is_sorted(t_list *s_a, t_list *s_b, t_rect *rects, t_visu *visu)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = s_a;
	tmp_b = s_b;
	if (tmp_b != NULL)
	{
		ft_failure(s_a, s_b, rects, visu);
		return ;
	}
	while (tmp_a->next != NULL)
	{
		if (*(int*)tmp_a->content > *(int*)tmp_a->next->content)
		{
			ft_failure(s_a, s_b, rects, visu);
			return ;
		}
		tmp_a = tmp_a->next;
	}
	ft_success(s_a, s_b, rects, visu);
}

void		ft_visual_checker(t_stacks *stacks, int argc, char **argv)
{
	t_visu	visu;
	t_rect	*rects;
	int		flag;

	flag = 0;
	if (!ft_stack_create(stacks->s_a, argv + 2, argc - 2, &flag))
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	if (flag == 1)
		return ;
	if (!ft_store_instructions(stacks->instruct))
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	ft_sdl_initialize(&visu, &rects, stacks);
	if (!ft_process_visual_sort(*stacks, rects, &visu))
	{
		ft_sdl_end(&visu);
		return ;
	}
	ft_is_sorted(*(stacks->s_a), *(stacks->s_b), rects, &visu);
	ft_sdl_end(&visu);
}
