/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 23:00:17 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/05 19:08:28 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_struct_init(t_struct *data)
{
	data->p_b = -1;
	data->p_a = -1;
	data->r_a = -1;
	data->r_b = -1;
	data->rr_a = -1;
	data->rr_b = -1;
	data->call = '0';
	data->sorted_part = NULL;
}

void	ft_find_instructions(t_list **s_a, t_list **s_b, t_list **instructions)
{
	t_struct data;
	//ft_selection_sort(s_a, s_b, instructions);
	ft_struct_init(&data);
	ft_quick_sort(s_a, s_b, instructions, &data);
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
	ft_find_instructions(&stack_a, &stack_b, &instructions);
	//ft_lstiter(instructions, &ft_lstprint_str);
	ft_printf("Liste b :\n");
	ft_lstiter(stack_b, &ft_lstprint_int);
	//ft_printf("Liste a :\n");
	//ft_lstiter(s_a, &ft_lstprint_int);
	return (0);
}
