/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classic_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:42:08 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/06 16:21:05 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_process_sort(t_list **s_a, t_list **s_b, t_list *instructions)
{
	t_fptr	instruct;
	int		i;

	ft_init_fptr(&instruct);
	while (instructions)
	{
		i = 0;
		while (i < INSTRUCT)
		{
			if (ft_strequ(instruct.type[i], (char*)(instructions->content)))
				instruct.fptr[i](s_a, s_b);
			i++;
		}
		instructions = instructions->next;
	}
	ft_del_fptr(&instruct);
}

static void	ft_is_sorted(t_list *stack_a, t_list *stack_b)
{
	if (stack_b != NULL)
	{
		ft_printf("KO\n");
		return ;
	}
	while (stack_a->next != NULL)
	{
		if (*(int*)stack_a->content > *(int*)stack_a->next->content)
		{
			ft_printf("KO\n");
			return ;
		}
		stack_a = stack_a->next;
	}
	ft_printf("OK\n");
}

void		ft_classic_checker(t_stacks *stacks, int argc, char **argv)
{
	int	flag;

	flag = 0;
	if (!ft_stack_create(stacks->s_a, argv + 1, argc - 1, &flag))
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	if (flag == 1)
		return ;
	if (!(ft_store_instructions(stacks->instruct)))
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	ft_process_sort(stacks->s_a, stacks->s_b, *stacks->instruct);
	ft_is_sorted(*stacks->s_a, *stacks->s_b);
}
