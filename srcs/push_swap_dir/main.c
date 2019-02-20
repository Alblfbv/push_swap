/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 23:00:17 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/20 17:46:40 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_instructions(t_stacks *stacks)
{
	//ft_selection_sort(s_a, s_b, instructions);
	ft_quick_sort(stacks, *(stacks->s_a), ft_lst_end(*(stacks->s_a)));
}

int		main(int argc, char **argv)
{
	t_stacks	stacks;
	t_list		*stack_a;
	t_list		*stack_b;
	t_list		*instructions;
	
	stack_a = NULL;
	stack_b = NULL;
	instructions = NULL;
	if (argc == 1)
		return (0);
	if (ft_stack_create(&stack_a, argv + 1, argc -1) == -1)
	{
		ft_printf("Error\n");
		return (1);
	}
	stacks.s_a = &stack_a;
	stacks.s_b = &stack_b;
	stacks.instruct = &instructions;
	ft_find_instructions(&stacks);
	ft_kompressor(&stacks);
	
	ft_lstiter(instructions, &ft_lstprint_str);
/*
	if (stack_b != NULL)
	{
		ft_printf("Liste b :\n");
		ft_lstiter(stack_b, &ft_lstprint_int);
	}
	if (stack_a != NULL)
	{
		ft_printf("Liste a :\n");
		ft_lstiter(stack_a, &ft_lstprint_int);
	}
	*/

	ft_lstdel(&stack_a, &ft_free_int_ptr);
	ft_lstdel(&stack_b, &ft_free_int_ptr);
	ft_lstdel(&instructions, &ft_free_int_ptr);
	return (0);
}
