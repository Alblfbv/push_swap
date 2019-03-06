/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fptr_init_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:40:55 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/06 18:16:10 by allefebv         ###   ########.fr       */
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

void	ft_init_instruct_type(t_fptr *instruct)
{
	if (!(instruct->type = (char**)malloc(sizeof(char*) * (INSTRUCT + 1))))
		exit(1);
	if (!(instruct->type[0] = ft_strdup("pa")))
		exit(1);
	if (!(instruct->type[1] = ft_strdup("pb")))
		exit(1);
	if (!(instruct->type[2] = ft_strdup("sa")))
		exit(1);
	if (!(instruct->type[3] = ft_strdup("sb")))
		exit(1);
	if (!(instruct->type[4] = ft_strdup("ss")))
		exit(1);
	if (!(instruct->type[5] = ft_strdup("ra")))
		exit(1);
	if (!(instruct->type[6] = ft_strdup("rb")))
		exit(1);
	if (!(instruct->type[7] = ft_strdup("rr")))
		exit(1);
	if (!(instruct->type[8] = ft_strdup("rra")))
		exit(1);
	if (!(instruct->type[9] = ft_strdup("rrb")))
		exit(1);
	if (!(instruct->type[10] = ft_strdup("rrr")))
		exit(1);
	instruct->type[INSTRUCT] = 0;
}

void	ft_init_fptr(t_fptr *instruct)
{
	ft_init_instruct_type(instruct);
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
