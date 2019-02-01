/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:47:20 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/01 22:56:13 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_check_int(char *s)
{
	int			i;
	int			sign;
	long long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	if (!(ft_isdigit(s[i])))
		return (-1);
	while (ft_isdigit(s[i]))
	{
		if ((sign == 1 && nb * 10 + s[i] - 48 > 2147483647) ||
			(sign == -1 && nb * 10 + s[i] - 48 > 2147483648))
			return (-1);
		nb = nb * 10 + s[i] - 48;
		i++;
	}
	if (s[i] != '\0')
		return (-1);
	return (1);
}

int		ft_stack_create(t_list **stack_a, char **s_str, int len)
{
	int	i;
	int	*tmp;

	i = 0;
	tmp = (int*)malloc(sizeof(int));
	while (i < len)
	{
		if (ft_check_int(s_str[i]) == -1)
			return (-1);
		*tmp = ft_atoi(s_str[i]);
		ft_lstadd_end(stack_a, ft_lstnew(tmp, sizeof(int*)));
		i++;
	}
	free(tmp);
	return (0);
}
