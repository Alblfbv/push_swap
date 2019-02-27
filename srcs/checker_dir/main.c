/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:22:25 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/27 14:35:36 by allefebv         ###   ########.fr       */
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

void		ft_process_sort(t_list **s_a, t_list **s_b, t_list *instructions)
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
		return ;
	while (stack_a->next->next != NULL)
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
	ft_process_sort(stacks.s_a, stacks.s_b, *stacks.instruct);
	ft_is_sorted(*stacks.s_a, *stacks.s_b);
	ft_delete_stacks(&stacks);
	return (0);
}
