/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fptr_init_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:40:55 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/05 14:56:30 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_del_fptr(t_fptr *instruct)
{
	int	i;

	i = 0;
	while (i < INSTRUCT)
	{
		free(instruct->type[i]);
		i++;
	}
	free(instruct->type);
}

void	ft_init_fptr(t_fptr *instruct)
{
	instruct->type = (char**)malloc(sizeof(char*) * (INSTRUCT + 1));
	instruct->type[0] = ft_strdup("pa");
	instruct->type[1] = ft_strdup("pb");
	instruct->type[2] = ft_strdup("sa");
	instruct->type[3] = ft_strdup("sb");
	instruct->type[4] = ft_strdup("ss");
	instruct->type[5] = ft_strdup("ra");
	instruct->type[6] = ft_strdup("rb");
	instruct->type[7] = ft_strdup("rr");
	instruct->type[8] = ft_strdup("rra");
	instruct->type[9] = ft_strdup("rrb");
	instruct->type[10] = ft_strdup("rrr");
	instruct->type[INSTRUCT] = 0;
	instruct->fptr[0] = &ft_push_a;
	instruct->fptr[1] = &ft_push_b;
	instruct->fptr[2] = &ft_swap_a;
	instruct->fptr[3] = &ft_swap_b;
	instruct->fptr[4] = &ft_swap_ab;
	instruct->fptr[5] = &ft_rotate_a;
	instruct->fptr[6] = &ft_rotate_b;
	instruct->fptr[7] = &ft_rotate_ab;
	instruct->fptr[8] = &ft_rev_rotate_a;
	instruct->fptr[9] = &ft_rev_rotate_b;
	instruct->fptr[10] = &ft_rev_rotate_ab;
}
