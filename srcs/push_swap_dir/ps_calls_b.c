/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calls_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:48:59 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/05 13:50:13 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_inst_swap_b(t_stacks *stacks)
{
	if (*stacks->s_b && (*stacks->s_b)->next)
	{
		ft_lstadd_end(stacks->instruct,
		ft_lstnew(ft_swap_b(stacks->s_a, stacks->s_b), sizeof(char*)));
	}
}

void	ft_inst_push_b(t_stacks *stacks)
{
	if (*stacks->s_a)
	{
		ft_lstadd_end(stacks->instruct,
		ft_lstnew(ft_push_b(stacks->s_a, stacks->s_b), sizeof(char*)));
	}
}

void	ft_inst_rot_b(t_stacks *stacks)
{
	if (*stacks->s_b && (*stacks->s_b)->next)
	{
		ft_lstadd_end(stacks->instruct,
		ft_lstnew(ft_rotate_b(stacks->s_a, stacks->s_b), sizeof(char*)));
	}
}

void	ft_inst_rev_rot_b(t_stacks *stacks)
{
	if (*stacks->s_b && (*stacks->s_b)->next)
	{
		ft_lstadd_end(stacks->instruct,
		ft_lstnew(ft_rev_rotate_b(stacks->s_a, stacks->s_b), sizeof(char*)));
	}
}
