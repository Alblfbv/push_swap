/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:06:36 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/01 21:19:28 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap_a(t_list **stack_a, t_list **stack_b)
{
	t_list	tmp;

	(void)stack_b;
	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
	tmp.content = (*stack_a)->content;
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = tmp.content;
	}
}
