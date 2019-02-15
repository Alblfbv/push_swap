/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:22:25 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/15 18:37:40 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	ft_del_fptr(t_fptr *instruct)
{
	int	i;

	i = 0;
	while (i < INSTRUCT)
	{
		free(instruct->type[i]);
		i++;
	}
	free(instruct->type);
	free(instruct);

}

static void	ft_init_fptr(t_fptr *instruct)
{
	instruct->type = (char**)malloc(sizeof(char*) * (INSTRUCT + 1));
	instruct->type[0] = ft_strdup("pa");
	instruct->type[1] = ft_strdup("pb");
	instruct->type[2] = ft_strdup("sa");
	instruct->type[3] = ft_strdup("sb");
	instruct->type[4] = ft_strdup("ss");
	instruct->type[5] = ft_strdup("ra");
	instruct->type[6] = ft_strdup("rb");
	instruct->type[7] = ft_strdup("rr");
	instruct->type[8] = ft_strdup("rra");
	instruct->type[9] = ft_strdup("rrb");
	instruct->type[10] = ft_strdup("rrr");
	instruct->type[INSTRUCT] = 0;
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

void		ft_process_sort(t_list **s_a, t_list **s_b, char **instructions)
{
	t_fptr	*instruct;
	int		i;
	int		j;

	i = 0;
	instruct = (t_fptr*)ft_memalloc(sizeof(t_fptr));
	ft_init_fptr(instruct);
	while (instructions[i] != 0)
	{
		j = 0;
		while (j < INSTRUCT)
		{
			if (ft_strequ(instruct->type[j], instructions[i]))
				instruct->fptr[j](s_a, s_b);
			j++;
		}
		i++;
	}
	ft_del_fptr(instruct);
}

static int	ft_is_sorted(t_list *stack_a, t_list *stack_b)
{
	if (stack_b != NULL)
		return (-1);
	while (stack_a->next->next != NULL)
	{
		if (*(int*)stack_a->content > *(int*)stack_a->next->content)
			return (-1);
		stack_a = stack_a->next;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	char		**instructions;
	int			i;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	if (argc == 1)
		return (0);
	if (!(instructions = ft_store_instructions()))
	{
		ft_printf("Error\n");
		return (1);
	}
	if (ft_stack_create(&stack_a, argv + 1, argc -1) == -1)
	{
		ft_printf("Error\n");
		return (1);
	}
	ft_process_sort(&stack_a, &stack_b, instructions);
	if (ft_is_sorted(stack_a, stack_b) == -1)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	i = 0;
	while (instructions[i] != 0)
		i++;
	ft_sstrdel(instructions, i);
	ft_lstdel(&stack_a, &ft_free_int_ptr);
	ft_lstdel(&stack_b, &ft_free_int_ptr);
	return (0);
}
