/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:06:36 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/13 14:15:31 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_swap_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*new_first;
	t_list	*new_second;
	t_list	*third;

	(void)stack_b;
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ("SA appelle alors que moins de 2 elem");
	new_first = (*stack_a)->next;
	third = (*stack_a)->next->next;
	new_second = (*stack_a);
	(*stack_a) = new_first;
	(*stack_a)->next = new_second;
	(*stack_a)->next->next = third;
	return ("sa");
}
