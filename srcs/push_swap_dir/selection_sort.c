/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 19:01:32 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/05 13:41:52 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_select_sort(t_list **s_a, t_list **s_b, t_list **instructions)
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
