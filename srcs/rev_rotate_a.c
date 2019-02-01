/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:44:05 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/01 22:42:55 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rev_rotate_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*before_last;
	t_list	*last;

	(void)stack_b;
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	before_last = *stack_a;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
}
