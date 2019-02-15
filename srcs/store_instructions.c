/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:14:05 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/15 18:39:26 by allefebv         ###   ########.fr       */
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

char	**ft_store_instructions(void)
{
	char	*line;
	char	*tmp;
	char	**instructions;

	tmp = ft_strnew(0);
	while (get_next_line(0, &line))
	{
		if (ft_check_line(line) == -1)
			return (NULL);
		tmp = ft_strextend(tmp, line);
		tmp = ft_strextend(tmp, " ");
		free(line);
	}
	instructions = ft_strsplit(tmp, ' ');
	free(line);
	free(tmp);
	return (instructions);
}
