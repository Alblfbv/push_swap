/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 23:02:37 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/27 14:50:24 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INSTRUCT 11
# define MIN_QS_SIZE 10

# include "libft.h"
# include <stdlib.h>

typedef struct	s_struct
{
	t_list		*end_s_a;
	t_list		*end_s_b;
	t_list		*end;
	t_list		*start;
	t_list		*pivot;
	int			rotate;
	char		list;
	int			end_start;
	int			end_null;
	int			med_flag;
}				t_struct;

typedef struct	s_stacks
{
	t_list		**s_a;
	t_list		**s_b;
	t_list		**instruct;
}				t_stacks;


typedef struct	s_fptr
{
	char		**type;
	char		*(*fptr[INSTRUCT])(t_list **stack_a, t_list **stack_b);
}				t_fptr;

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
t_list		*ft_reduce_size_a(t_list *s_a, t_struct *data);
void		ft_reduce_size_b(t_stacks *stacks, t_struct *data);
int			ft_2_elem_a(t_stacks *stacks, t_list *end);
int			ft_2_elem_b(t_stacks *stacks, t_list *end);
t_struct	*ft_chose_pivot(t_struct *data);
void		ft_kompressor(t_stacks *stacks);

void		ft_inst_swap_a(t_stacks *stacks);
void		ft_inst_swap_b(t_stacks *stacks);
void		ft_inst_push_a(t_stacks *stacks);
void		ft_inst_push_b(t_stacks *stacks);
void		ft_inst_rot_a(t_stacks *stacks);
void		ft_inst_rot_b(t_stacks *stacks);
void		ft_inst_rev_rot_a(t_stacks *stacks);
void		ft_inst_rev_rot_b(t_stacks *stacks);

int			ft_store_instructions(t_list **instructions);
void		ft_free_int_ptr(void *content, size_t size);
void		ft_classic_checker(t_stacks *stacks);
void		ft_visual_checker(t_stacks *stacks);
void		ft_init_fptr(t_fptr *instruct);
void		ft_del_fptr(t_fptr *instruct);

#endif
