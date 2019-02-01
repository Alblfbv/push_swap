/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:40:11 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/01 22:42:34 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rotate_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	t_list	*second;

	(void)stack_a;
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	second = (*stack_b)->next;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	(*stack_b)->next = NULL;
	last->next = *stack_b;
	*stack_b = second;
}
