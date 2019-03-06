/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opti_3_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 11:31:00 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/06 18:25:22 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_opti_end_b2(t_stacks *stacks, int *tab)
{
	if (tab[0] < tab[1] && tab[1] < tab[2])
	{
		ft_inst_rot_b(stacks);
		ft_inst_swap_b(stacks);
		ft_inst_push_a(stacks);
		ft_inst_push_a(stacks);
		ft_inst_push_a(stacks);
		return (1);
	}
	else if (tab[0] < tab[1] && tab[0] < tab[2] && tab[1] > tab[2])
	{
		ft_inst_rot_b(stacks);
		ft_inst_push_a(stacks);
		ft_inst_push_a(stacks);
		ft_inst_push_a(stacks);
		return (1);
	}
	return (0);
}

void	ft_opti_end_b(t_stacks *stacks, int *tab)
{
	if (!ft_opti_end_b2(stacks, tab))
	{
		if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
		{
			ft_inst_rev_rot_b(stacks);
			ft_inst_push_a(stacks);
			ft_inst_push_a(stacks);
			ft_inst_push_a(stacks);
		}
		else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
		{
			ft_inst_swap_b(stacks);
			ft_inst_push_a(stacks);
			ft_inst_push_a(stacks);
			ft_inst_push_a(stacks);
		}
	}
}

int		ft_opti_sub_b2(t_stacks *stacks, int *tab)
{
	if (tab[0] < tab[1] && tab[1] < tab[2])
	{
		ft_inst_rot_b(stacks);
		ft_inst_swap_b(stacks);
		ft_inst_push_a(stacks);
		ft_inst_push_a(stacks);
		ft_inst_rev_rot_b(stacks);
		ft_inst_push_a(stacks);
		return (1);
	}
	else if (tab[0] < tab[1] && tab[0] < tab[2] && tab[1] > tab[2])
	{
		ft_inst_swap_b(stacks);
		ft_inst_push_a(stacks);
		ft_inst_swap_b(stacks);
		ft_inst_push_a(stacks);
		ft_inst_push_a(stacks);
		return (1);
	}
	return (0);
}

void	ft_opti_sub_b(t_stacks *stacks, int *tab)
{
	if (!ft_opti_sub_b2(stacks, tab))
	{
		if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
		{
			ft_inst_push_a(stacks);
			ft_inst_swap_b(stacks);
			ft_inst_push_a(stacks);
			ft_inst_swap_a(stacks);
			ft_inst_push_a(stacks);
		}
		else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
		{
			ft_inst_swap_b(stacks);
			ft_inst_push_a(stacks);
			ft_inst_push_a(stacks);
			ft_inst_push_a(stacks);
		}
	}
}

int		ft_opti_3_b(t_stacks *stacks, t_struct *data)
{
	int	*tab;

	if (!(tab = (int*)malloc(sizeof(int) * 3)))
		exit(1);
	tab[0] = *(int*)(*stacks->s_b)->content;
	tab[1] = *(int*)(*stacks->s_b)->next->content;
	tab[2] = *(int*)(*stacks->s_b)->next->next->content;
	if (ft_lst_size(*stacks->s_b) == 3)
	{
		ft_opti_end_b(stacks, tab);
		free(tab);
		return (1);
	}
	else if (ft_lst_n_size(*stacks->s_b, data->end) == 3)
	{
		ft_opti_sub_b(stacks, tab);
		free(tab);
		return (1);
	}
	free(tab);
	return (0);
}
