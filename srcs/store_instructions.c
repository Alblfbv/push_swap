/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:14:05 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/01 22:06:58 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_check_line(char *line)
{
	if (!(ft_strequ(line, ft_strdup("pa"))) &&
		!(ft_strequ(line, ft_strdup("pb"))) &&
		!(ft_strequ(line, ft_strdup("sa"))) &&
		!(ft_strequ(line, ft_strdup("sb"))) &&
		!(ft_strequ(line, ft_strdup("ss"))) &&
		!(ft_strequ(line, ft_strdup("ra"))) &&
		!(ft_strequ(line, ft_strdup("rb"))) &&
		!(ft_strequ(line, ft_strdup("rr"))) &&
		!(ft_strequ(line, ft_strdup("rra"))) &&
		!(ft_strequ(line, ft_strdup("rrb"))) &&
		!(ft_strequ(line, ft_strdup("rrr"))))
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
	return (instructions);
}
