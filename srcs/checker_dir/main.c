/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:22:25 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/27 14:45:23 by allefebv         ###   ########.fr       */
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
	int			i;
	int			visu;

	i = 0;
	visu = 0;
	if (argc == 1)
		return (0);
	ft_init_stacks(&stacks);
	if (argc == 3 && (ft_strequ(argv[1], "-v") || ft_strequ(argv[2], "-v")))
		visu = 1;
	if (!(ft_store_instructions(stacks.instruct)) ||
		ft_stack_create(stacks.s_a, argv + 1, argc -1) == -1)
	{
		ft_printf("Error\n");
		return (1);
	}
	if (visu == 1)
		ft_visual_checker(&stacks);
	else
		ft_classic_checker(&stacks);
	ft_delete_stacks(&stacks);
	return (0);
}
