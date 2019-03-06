/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:47:20 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/06 16:20:54 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	ft_check_duplicates(t_list *stack_a)
{
	t_list *tmp;

	while (stack_a->next != NULL)
	{
		tmp = stack_a->next;
		while (tmp != NULL)
		{
			if (*(int*)(tmp->content) == *(int*)(stack_a->content))
				return (0);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}

static int	ft_stack_fill(t_list **stack_a, char **argv, int len, int *tmp)
{
	char	**s_str;
	int		j;

	while (len)
	{
		s_str = ft_strsplit(*argv, ' ');
		j = 0;
		while (s_str[j] != 0)
		{
			if (ft_check_int(s_str[j]) == -1)
			{
				ft_sstrdel(s_str, j + 1);
				return (0);
			}
			*tmp = ft_atoi(s_str[j]);
			ft_lstadd_end(stack_a, ft_lstnew(tmp, sizeof(int*)));
			j++;
		}
		ft_sstrdel(s_str, j);
		len--;
		argv++;
	}
	return (1);
}

int			ft_stack_create(t_list **stack_a, char **argv, int len, int *flag)
{
	int		tmp;

	if (!ft_stack_fill(stack_a, argv, len, &tmp))
		return (0);
	if (!(*stack_a))
	{
		*flag = 1;
		return (1);
	}
	if (!ft_check_duplicates(*stack_a))
		return (0);
	return (1);
}
