/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opti_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:02:10 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/06 14:46:27 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_opti_end_a(t_stacks *stacks, int *tab)
{
	if (tab[0] > tab[1] && tab[1] > tab[2])
	{
		ft_inst_swap_a(stacks);
		ft_inst_rev_rot_a(stacks);
	}
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] > tab[2])
		ft_inst_rot_a(stacks);
	else if (tab[0] < tab[1] && tab[0] > tab[2] && tab[1] > tab[2])
		ft_inst_rev_rot_a(stacks);
	else if (tab[0] < tab[1] && tab[0] < tab[2] && tab[1] > tab[2])
	{
		ft_inst_swap_a(stacks);
		ft_inst_rot_a(stacks);
	}
}

static int	ft_opti_sub_a1(t_stacks *stacks, int *tab)
{
	if (tab[0] > tab[1] && tab[1] > tab[2])
	{
		ft_inst_rot_a(stacks);
		ft_inst_swap_a(stacks);
		ft_inst_push_b(stacks);
		ft_inst_rev_rot_a(stacks);
		ft_inst_swap_a(stacks);
		ft_inst_push_a(stacks);
		return (1);
	}
	if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] > tab[2])
	{
		ft_inst_swap_a(stacks);
		ft_inst_push_b(stacks);
		ft_inst_swap_a(stacks);
		ft_inst_push_a(stacks);
		return (1);
	}
	return (0);
}

static void	ft_opti_sub_a2(t_stacks *stacks, int *tab)
{
	if (tab[0] < tab[1] && tab[0] > tab[2] && tab[1] > tab[2])
	{
		ft_inst_rot_a(stacks);
		ft_inst_swap_a(stacks);
		ft_inst_push_b(stacks);
		ft_inst_rev_rot_a(stacks);
		ft_inst_push_a(stacks);
	}
	else if (tab[0] < tab[1] && tab[0] < tab[2] && tab[1] > tab[2])
	{
		ft_inst_rot_a(stacks);
		ft_inst_swap_a(stacks);
		ft_inst_rev_rot_a(stacks);
	}
}

static void	ft_opti_sub_a(t_stacks *stacks, int *tab)
{
	if (!ft_opti_sub_a1(stacks, tab))
		ft_opti_sub_a2(stacks, tab);
}

int			ft_opti_3_a(t_stacks *stacks, t_struct *data)
{
	int	*tab;

	tab = (int*)malloc(sizeof(int) * 3);
	tab[0] = *(int*)(*stacks->s_a)->content;
	tab[1] = *(int*)(*stacks->s_a)->next->content;
	tab[2] = *(int*)(*stacks->s_a)->next->next->content;
	if (ft_lst_size(*stacks->s_a) == 3)
	{
		ft_opti_end_a(stacks, tab);
		free(tab);
		return (1);
	}
	if (ft_lst_n_size(*stacks->s_a, data->end) == 3)
	{
		ft_opti_sub_a(stacks, tab);
		free(tab);
		return (1);
	}
	free(tab);
	return (0);
}
