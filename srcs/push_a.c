/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:44:26 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/01 19:28:06 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_b == NULL)
		return ;
	ft_lstadd(stack_a, ft_lstnew((*stack_b)->content, (*stack_b)->content_size));
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	free(tmp);
}
