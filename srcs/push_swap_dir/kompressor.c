/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kompressor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:04:30 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/20 17:58:33 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_del_instruct(t_list **alst, t_list *prev, t_list *elem1)
{
	if (prev == NULL)
		*alst = (*alst)->next->next;
	else
		prev->next = prev->next->next->next;
	free(elem1->next->content);
	free(elem1->next);
	free(elem1->content);
	free(elem1);
}

void	ft_merge_instruct(t_list **alst, t_list *prev, t_list *elem1, char *str)
{
	if (prev == NULL)
		*alst = (*alst)->next;
	else
		prev->next = prev->next->next;
	elem1->next->content = ft_strdup(str);
	free(elem1->content);
	free(elem1);
}

int		ft_analyse(t_list **alst, t_list *prev, t_list *elem1)
{
	if ((ft_strequ((char*)elem1->content, "ra") && ft_strequ((char*)elem1->next->content, "rra")) ||
		(ft_strequ((char*)elem1->content, "rra") && ft_strequ((char*)elem1->next->content, "ra")) ||
		(ft_strequ((char*)elem1->content, "rrb") && ft_strequ((char*)elem1->next->content, "rb")) ||
		(ft_strequ((char*)elem1->content, "rb") && ft_strequ((char*)elem1->next->content, "rrb")) ||
		(ft_strequ((char*)elem1->content, "pb") && ft_strequ((char*)elem1->next->content, "pa")) ||
		(ft_strequ((char*)elem1->content, "pa") && ft_strequ((char*)elem1->next->content, "pb")))
	{
		ft_del_instruct(alst, prev, elem1);
		return (1);
	}
	else if (ft_strequ((char*)elem1->content, "rra") && ft_strequ((char*)elem1->next->content, "rrb"))
	{
		ft_merge_instruct(alst, prev, elem1, "rrr");
		return (1);
	}
	else if (ft_strequ((char*)elem1->content, "ra") && ft_strequ((char*)elem1->next->content, "rb"))
	{
		ft_merge_instruct(alst, prev, elem1, "rr");
		return (1);
	}
	else if (ft_strequ((char*)elem1->content, "sa") && ft_strequ((char*)elem1->next->content, "sb"))
	{
		ft_merge_instruct(alst, prev, elem1, "ss");
		return (1);
	}
	return (0);
}

void	ft_kompressor(t_stacks *stacks)
{
	int	kompress;
	t_list	*tmp;
	t_list	*prev;

	kompress = 1;
	while (kompress)
	{
		kompress = 0;
		tmp = *stacks->instruct;
		prev = NULL;
		while (tmp->next != NULL)
		{
			if(ft_analyse(stacks->instruct, prev, tmp))
			{
				kompress = 1;
				tmp = *stacks->instruct;
				prev = NULL;
			}
			else
			{
				prev = tmp;
				tmp = tmp->next;
			}
		}
	}
}
