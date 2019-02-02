/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:40:17 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/02 16:54:32 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_a == NULL)
		return ("PB appelle alors que vide");
	ft_lstadd(stack_b, ft_lstnew((*stack_a)->content, (*stack_a)->content_size));
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	free(tmp->content);
	free(tmp);
	return ("pb");
}
