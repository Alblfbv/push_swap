/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opti_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:02:10 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/05 20:13:19 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_opti_end_a(t_stacks *stacks, int *tab)
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

void	ft_opti_sub_a(t_stacks *stacks, int *tab)
{
	if (tab[0] > tab[1] && tab[1] > tab[2])
	{
		ft_inst_rot_a(stacks);
		ft_inst_swap_a(stacks);
		ft_inst_push_b(stacks);
		ft_inst_rev_rot_a(stacks);
		ft_inst_swap_a(stacks);
		ft_inst_push_a(stacks);
	}
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] > tab[2])
	{
		ft_inst_swap_a(stacks);
		ft_inst_push_b(stacks);
		ft_inst_swap_a(stacks);
		ft_inst_push_a(stacks);
	}
	else if (tab[0] < tab[1] && tab[0] > tab[2] && tab[1] > tab[2])
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

int		ft_opti_3_a(t_stacks *stacks, t_struct *data)
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

/*int		ft_opti_3_b(t_stacks *stacks, t_struct *data)
{
	if (ft_lst_size(*stacks->s_b) == 3)
		ft_opti_end_b(t_stacks *stacks, t_struct *data);
	else
		ft_opti_sub_b(t_stacks *stacks, t_struct *data);
}*/
