/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:44:26 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/02 17:48:41 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_b == NULL)
		return ("PA appelle alors que vide");
	ft_lstadd(stack_a, ft_lstnew((*stack_b)->content, (*stack_b)->content_size));
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	free(tmp->content);
	free(tmp);
	return ("pa");
}
