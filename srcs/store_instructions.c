/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:14:05 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/05 13:52:57 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_line(char *line)
{
	if (!(ft_strequ(line, "pa")) &&
		!(ft_strequ(line, "pb")) &&
		!(ft_strequ(line, "sa")) &&
		!(ft_strequ(line, "sb")) &&
		!(ft_strequ(line, "ss")) &&
		!(ft_strequ(line, "ra")) &&
		!(ft_strequ(line, "rb")) &&
		!(ft_strequ(line, "rr")) &&
		!(ft_strequ(line, "rra")) &&
		!(ft_strequ(line, "rrb")) &&
		!(ft_strequ(line, "rrr")))
		return (-1);
	return (1);
}

int			ft_store_instructions(t_list **instructions)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (ft_check_line(line) == -1)
			return (0);
		ft_lstadd_end(instructions, ft_lstnew(line, sizeof(char*)));
		free(line);
	}
	free(line);
	return (1);
}
