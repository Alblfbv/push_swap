/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 23:00:17 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/27 14:12:58 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		main(int argc, char **argv)
{
	t_stacks	stacks;
	
	if (argc == 1)
		return (0);
	ft_init_stacks(&stacks);
	if (ft_stack_create(stacks.s_a, argv + 1, argc -1) == -1)
	{
		ft_printf("Error\n");
		return (1);
	}
	ft_quick_sort(&stacks, *stacks.s_a, ft_lst_end(*stacks.s_a));
	ft_kompressor(&stacks);
	ft_lstiter(*stacks.instruct, &ft_lstprint_str);
	ft_delete_stacks(&stacks);
	return (0);
}
