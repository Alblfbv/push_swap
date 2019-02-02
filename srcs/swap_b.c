/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:42:13 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/02 17:05:32 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_swap_b(t_list **stack_a, t_list **stack_b)
{
	t_list	tmp;

	(void)stack_a;
	if (*stack_b != NULL && (*stack_b)->next != NULL)
		return ("SB appelle alors que moins de 2 elem");
	tmp.content = (*stack_b)->content;
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->next->content = tmp.content;
	return ("sb");
}
