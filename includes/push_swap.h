/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 23:02:37 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/15 16:00:08 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INSTRUCT 11

# include "libft.h"
# include <stdlib.h>

typedef struct	s_struct
{
	t_list		*first_rev_rotate;
	t_list		*first_push;
	t_list		*end;
	t_list		*start;
	t_list		*pivot;
	int			rotate;
	char		list;
	int			end_start;
	int			end_null;
}				t_struct;

typedef struct	s_stacks
{
	t_list		**s_a;
	t_list		**s_b;
	t_list		**instruct;
}				t_stacks;

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
void		ft_free_int_ptr(void *content, size_t size);

void		ft_quick_sort(t_stacks *stacks, t_list *start, t_list *end);
t_struct	*ft_process_partition_a(t_stacks *stacks, t_struct *data);
t_struct	*ft_process_rev_rot_a(t_stacks *stacks, t_struct *data);
t_struct	*ft_process_partition_b(t_stacks *stacks, t_struct *data);
t_struct	*ft_process_rev_rot_b(t_stacks *stacks, t_struct *data);
t_struct	*ft_find_median(t_struct *data);

#endif
