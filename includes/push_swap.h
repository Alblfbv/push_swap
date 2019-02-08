/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 23:02:37 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/07 20:04:19 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INSTRUCT 11

# include "libft.h"
# include <stdlib.h>

typedef struct	s_struct
{
	t_list		*rev_rotate_a;
	t_list		*rev_rotate_b;
	t_list		*push_b;
	t_list		*push_a;
	char		pivot;
}				t_struct;


int			ft_stack_create(t_list **stack_a, char **s_str, int len);

char		*ft_push_a(t_list **stack_a, t_list **stack_b);
char		*ft_push_b(t_list **stack_a, t_list **stack_b);
char		*ft_swap_a(t_list **stack_a, t_list **stack_b);
char		*ft_swap_b(t_list **stack_a, t_list **stack_b);
char		*ft_swap_ab(t_list **stack_a, t_list **stack_b);
char		*ft_rotate_a(t_list **stack_a, t_list **stack_b);
char		*ft_rotate_b(t_list **stack_a, t_list **stack_b);
char		*ft_rotate_ab(t_list **stack_a, t_list **stack_b);
char		*ft_rev_rotate_a(t_list **stack_a, t_list **stack_b);
char		*ft_rev_rotate_b(t_list **stack_a, t_list **stack_b);
char		*ft_rev_rotate_ab(t_list **stack_a, t_list **stack_b);

void		ft_select_sort(t_list **s_a, t_list **s_b, t_list **instructions);
void		ft_quick_sort(t_list **s_a, t_list **s_b, t_list *start, t_list *end);

#endif
