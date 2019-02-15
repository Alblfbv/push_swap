/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:35:29 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/15 18:38:42 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_rev_rotate_ab(t_list **stack_a, t_list **stack_b)
{
	ft_rev_rotate_a(stack_a, stack_b);
	ft_rev_rotate_b(stack_a, stack_b);
	return ("rrr");
}
