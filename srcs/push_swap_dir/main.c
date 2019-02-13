/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 23:00:17 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/13 15:06:56 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_instructions(t_list **s_a, t_list **s_b, t_list **instructions)
{
	(void)instructions;
	t_list	*end;
	//ft_selection_sort(s_a, s_b, instructions);
	end = ft_lst_end(*s_a);
	ft_quick_sort(s_a, s_b, *s_a, end);
}

int		main(int argc, char **argv)
{
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
	/*ft_printf("LISTE INITIALE --- \n");
	if (stack_b != NULL)
	{
		ft_printf("Liste b :\n");
		ft_lstiter(stack_b, &ft_lstprint_int);
	}
	if (stack_a != NULL)
	{
		ft_printf("Liste a :\n");
		ft_lstiter(stack_a, &ft_lstprint_int);
	}*/

	ft_find_instructions(&stack_a, &stack_b, &instructions);
/*	if (stack_b != NULL)
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
	//ft_lstiter(instructions, &ft_lstprint_str);
	return (0);
}
