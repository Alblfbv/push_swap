/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:40:11 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/01 22:15:21 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rotate_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*before_last;
	t_list	*last;
	t_list	*second;

	(void)stack_a;
	second = (*stack_b)->next;
	before_last = *stack_b;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last = before_last->next;
	(*stack_b)->next = NULL;
	before_last->next = *stack_b;
	last->next = second;
	*stack_b = last;
}
