/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:43:11 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/01 21:53:11 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rotate_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*before_last;
	t_list	*last;
	t_list	*second;

	(void)stack_b;
	second = (*stack_a)->next;
	before_last = *stack_a;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last = before_last->next;
	(*stack_a)->next = NULL;
	before_last->next = *stack_a;
	last->next = second;
	*stack_a = last;
}
