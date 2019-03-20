/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:22:25 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/20 15:15:08 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init_stacks(t_stacks *stacks)
{
	if (!(stacks->s_a = (t_list**)malloc(sizeof(t_list*))))
		exit(1);
	*stacks->s_a = NULL;
	if (!(stacks->s_b = (t_list**)malloc(sizeof(t_list*))))
		exit(1);
	*stacks->s_b = NULL;
	if (!(stacks->instruct = (t_list**)malloc(sizeof(t_list*))))
		exit(1);
	*stacks->instruct = NULL;
}

static void	ft_delete_stacks(t_stacks *stacks)
{
	ft_lstdel(stacks->s_a, &ft_free_int_ptr);
	free(stacks->s_a);
	ft_lstdel(stacks->s_b, &ft_free_int_ptr);
	free(stacks->s_b);
	ft_lstdel(stacks->instruct, &ft_free_int_ptr);
	free(stacks->instruct);
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
