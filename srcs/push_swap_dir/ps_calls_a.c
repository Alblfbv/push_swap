/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calls_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:51:48 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/05 13:50:10 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_inst_swap_a(t_stacks *stacks)
{
	if (*stacks->s_a && (*stacks->s_a)->next)
	{
		ft_lstadd_end(stacks->instruct,
		ft_lstnew(ft_swap_a(stacks->s_a, stacks->s_b), sizeof(char*)));
	}
}

void	ft_inst_push_a(t_stacks *stacks)
{
	if (*stacks->s_b)
	{
		ft_lstadd_end(stacks->instruct,
		ft_lstnew(ft_push_a(stacks->s_a, stacks->s_b), sizeof(char*)));
	}
}

void	ft_inst_rot_a(t_stacks *stacks)
{
	if (*stacks->s_a && (*stacks->s_a)->next)
	{
		ft_lstadd_end(stacks->instruct,
		ft_lstnew(ft_rotate_a(stacks->s_a, stacks->s_b), sizeof(char*)));
	}
}

void	ft_inst_rev_rot_a(t_stacks *stacks)
{
	if (*stacks->s_a && (*stacks->s_a)->next)
	{
		ft_lstadd_end(stacks->instruct,
		ft_lstnew(ft_rev_rotate_a(stacks->s_a, stacks->s_b), sizeof(char*)));
	}
}
