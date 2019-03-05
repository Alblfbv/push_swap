/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kompressor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:04:30 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/05 13:48:18 by allefebv         ###   ########.fr       */
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
	free(elem1->next->content);
	elem1->next->content = ft_strdup(str);
	free(elem1->content);
	free(elem1);
}

int		ft_useless_inst_del(t_list **alst, t_list *prev, t_list *elem1)
{
	if ((ft_strequ((char*)elem1->content, "ra") &&
		ft_strequ((char*)elem1->next->content, "rra")) ||
		(ft_strequ((char*)elem1->content, "rra") &&
		ft_strequ((char*)elem1->next->content, "ra")) ||
		(ft_strequ((char*)elem1->content, "rrb") &&
		ft_strequ((char*)elem1->next->content, "rb")) ||
		(ft_strequ((char*)elem1->content, "rb") &&
		ft_strequ((char*)elem1->next->content, "rrb")) ||
		(ft_strequ((char*)elem1->content, "pb") &&
		ft_strequ((char*)elem1->next->content, "pa")) ||
		(ft_strequ((char*)elem1->content, "pa") &&
		ft_strequ((char*)elem1->next->content, "pb")))
	{
		ft_del_instruct(alst, prev, elem1);
		return (1);
	}
	return (0);
}

int		ft_double_inst_merge(t_list **alst, t_list *prev, t_list *elem1)
{
	if ((ft_strequ((char*)elem1->content, "rra") &&
		ft_strequ((char*)elem1->next->content, "rrb")) ||
		(ft_strequ((char*)elem1->content, "rrb") &&
		ft_strequ((char*)elem1->next->content, "rra")))
	{
		ft_merge_instruct(alst, prev, elem1, "rrr");
		return (1);
	}
	else if ((ft_strequ((char*)elem1->content, "ra") &&
			ft_strequ((char*)elem1->next->content, "rb")) ||
			(ft_strequ((char*)elem1->content, "rb") &&
			ft_strequ((char*)elem1->next->content, "ra")))
	{
		ft_merge_instruct(alst, prev, elem1, "rr");
		return (1);
	}
	else if ((ft_strequ((char*)elem1->content, "sa") &&
			ft_strequ((char*)elem1->next->content, "sb")) ||
			(ft_strequ((char*)elem1->content, "sb") &&
			ft_strequ((char*)elem1->next->content, "sa")))
	{
		ft_merge_instruct(alst, prev, elem1, "ss");
		return (1);
	}
	return (0);
}

void	ft_kompressor(t_stacks *stacks)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *stacks->instruct;
	prev = NULL;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (ft_useless_inst_del(stacks->instruct, prev, tmp))
		{
			tmp = *stacks->instruct;
			prev = NULL;
		}
		else if (ft_double_inst_merge(stacks->instruct, prev, tmp))
		{
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
