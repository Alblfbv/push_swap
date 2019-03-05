/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:22:25 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/05 17:16:47 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	ft_init_stacks(t_stacks *stacks)
{
	stacks->s_a = (t_list**)malloc(sizeof(t_list*));
	*stacks->s_a = NULL;
	stacks->s_b = (t_list**)malloc(sizeof(t_list*));
	*stacks->s_b = NULL;
	stacks->instruct = (t_list**)malloc(sizeof(t_list*));
	*stacks->instruct = NULL;
}

static void	ft_delete_stacks(t_stacks *stacks)
{
	ft_lstdel(stacks->s_a, &ft_free_int_ptr);
	ft_lstdel(stacks->s_b, &ft_free_int_ptr);
	ft_lstdel(stacks->instruct, &ft_free_int_ptr);
}

int			main(int argc, char **argv)
{
	t_stacks	stacks;
	int			visu;

	visu = 0;
	if (argc == 1)
		return (0);
	ft_init_stacks(&stacks);
	if (ft_strequ(argv[1], "-v"))
		visu = 1;
	if (visu == 1)
		ft_visual_checker(&stacks, argc, argv);
	else
		ft_classic_checker(&stacks, argc, argv);
	ft_delete_stacks(&stacks);
	return (0);
}
