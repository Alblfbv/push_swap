/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 23:00:17 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/02 18:32:40 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_instructions(t_list **s_a, t_list **s_b, t_list **instructions)
{
	t_list	*i;
	t_list	*j;
	t_list	*pos_min;

	i = *s_a;
	while (i->next->next != NULL)
	{
		pos_min = i;
		j = i->next;
		while (j != NULL)
		{
			//CHERCHER LE PLUS PETIT DANS A
			if (*(int*)(j->content) < *(int*)(pos_min->content))
				pos_min = j;
			j = j->next;
		}
		//AMENER LE PLUS PETIT EN HAUT DE A LE PLUS VITE POSSIBLE
		while (*s_a != pos_min)
		{
			ft_lstadd_end(instructions, ft_lstnew(ft_rotate_a(s_a, s_b), sizeof(char*)));
		}
		//DEPILER LE PLUS PETIT
		ft_lstadd_end(instructions, ft_lstnew(ft_push_b(s_a, s_b), sizeof(char*)));
		i = *s_a;
	}
	if ((*s_a)->content > (*s_a)->next->content)
		ft_lstadd_end(instructions, ft_lstnew(ft_swap_a(s_a, s_b), sizeof(char*)));
	//DEPILER B JUSQUA CE QUE B SOIT VIDE
	while (*s_b != NULL)
		ft_lstadd_end(instructions, ft_lstnew(ft_push_a(s_a, s_b), sizeof(char*)));
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
	ft_lstiter(instructions, &ft_lstprint_str);
	return (0);
}
