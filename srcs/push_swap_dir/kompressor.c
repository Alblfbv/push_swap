/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kompressor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:04:30 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/19 16:56:40 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_del_instruct(t_list *prev, t_list *instruct)
{
	t_list	*next;

	next = instruct->next;
	free(instruct->content);
	free(instruct);
	prev->next = next;
}

int		ft_analyse(t_list *inst1, t_list *inst2)
{
	if (ft_strequ((char*)inst1->content, "ra") &&
		ft_strequ((char*)inst2->content, "rra"))
	{
		ft_del_instruct()

		return(1);
	}
}

void	ft_kompressor(t_stacks *stacks)
{
	int	kompress;
	t_list	*tmp;

	kompress = 1;
	while (kompress)
	{
		tmp = stacks->instruct;
		while (tmp->next != NULL)
		{
			kompress = ft_analyse(tmp, tmp->next);
			if (kompress == 1)

				ft_lstdelone()
		}
	}
}
