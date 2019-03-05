/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:40:17 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/05 13:18:20 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*start_a;
	t_list	*start_b;

	if (*stack_a == NULL)
		return ("PB appelle alors que vide");
	start_a = *stack_a;
	if (*stack_b)
		start_b = *stack_b;
	else
		start_b = NULL;
	*stack_a = (*stack_a)->next;
	*stack_b = start_a;
	(*stack_b)->next = start_b;
	return ("pb");
}
