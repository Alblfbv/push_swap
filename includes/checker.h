/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:32:31 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/13 17:25:49 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define INSTRUCT 11

# include "libft.h"
# include <stdlib.h>

typedef struct	s_fptr
{
	char		**type;
	char		*(*fptr[INSTRUCT])(t_list **stack_a, t_list **stack_b);
}				t_fptr;

int			ft_stack_create(t_list **stack_a, char **s_str, int len);
char		**ft_store_instructions(void);
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
void		ft_free_int_ptr(void *content, size_t size);

#endif
