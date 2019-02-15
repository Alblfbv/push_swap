/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:43:11 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/15 18:38:55 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_rotate_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	t_list	*second;

	(void)stack_b;
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ("RA appelle alors que nul");
	second = (*stack_a)->next;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	(*stack_a)->next = NULL;
	last->next = *stack_a;
	*stack_a = second;
	return ("ra");
}
