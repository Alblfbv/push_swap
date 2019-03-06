/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 23:00:17 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/06 18:25:32 by allefebv         ###   ########.fr       */
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
	int			flag;

	if (argc == 1)
		return (0);
	ft_init_stacks(&stacks);
	flag = 0;
	if (!ft_stack_create(stacks.s_a, argv + 1, argc - 1, &flag))
	{
		ft_delete_stacks(&stacks);
		ft_printf("Error\n");
		return (1);
	}
	if (flag == 1)
	{
		ft_delete_stacks(&stacks);
		return (1);
	}
	ft_quick_sort(&stacks, *stacks.s_a, ft_lst_end(*stacks.s_a));
	ft_kompressor(&stacks);
	ft_lstiter(*stacks.instruct, &ft_lstprint_str);
	ft_delete_stacks(&stacks);
	return (0);
}
