/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:42:13 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/06 18:04:54 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_swap_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*new_first;
	t_list	*new_second;
	t_list	*third;

	(void)stack_a;
	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		new_first = (*stack_b)->next;
		third = (*stack_b)->next->next;
		new_second = (*stack_b);
		(*stack_b) = new_first;
		(*stack_b)->next = new_second;
		(*stack_b)->next->next = third;
		return ("sb");
	}
	return ("sb");
}
