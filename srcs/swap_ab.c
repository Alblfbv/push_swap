/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:44:18 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/15 18:39:56 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_swap_ab(t_list **stack_a, t_list **stack_b)
{
	ft_swap_a(stack_a, stack_b);
	ft_swap_b(stack_a, stack_b);
	return ("ss");
}
