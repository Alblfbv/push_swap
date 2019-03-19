/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 23:02:37 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/19 16:38:23 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INSTRUCT 11
# define MIN_QS_SIZE 10

# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <SDL2/SDL.h>

typedef struct		s_struct
{
	t_list			*end_s_a;
	t_list			*end_s_b;
	t_list			*end;
	t_list			*start;
	t_list			*pivot;
	int				rotate;
	char			list;
	int				end_start;
	int				end_null;
	int				med_flag;
}					t_struct;

typedef struct		s_stacks
{
	t_list			**s_a;
	t_list			**s_b;
	t_list			**instruct;
}					t_stacks;

typedef struct		s_fptr
{
	char			**type;
	char			*(*fptr[INSTRUCT])(t_list **stack_a, t_list **stack_b);
}					t_fptr;

typedef struct		s_visu
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	SDL_Rect		back_2;
	int				win_w;
	int				win_h;
	int				max_list;
	int				size_list;
	int				nb_small_px;
	int				nb_large_px;
	int				small_px;
	int				large_px;
}					t_visu;

typedef struct		s_rect
{
	SDL_Rect		rect;
	int				nb;
}					t_rect;

typedef struct		s_rev_tab
{
	int				*a;
	int				size_a;
	int				*b;
	int				size_b;
}					t_rev_tab;

int					ft_stack_create(
						t_list **stack_a, char **s_str, int len, int *flag);

char				*ft_push_a(t_list **stack_a, t_list **stack_b);
char				*ft_push_b(t_list **stack_a, t_list **stack_b);
char				*ft_swap_a(t_list **stack_a, t_list **stack_b);
char				*ft_swap_b(t_list **stack_a, t_list **stack_b);
char				*ft_swap_ab(t_list **stack_a, t_list **stack_b);
char				*ft_rotate_a(t_list **stack_a, t_list **stack_b);
char				*ft_rotate_b(t_list **stack_a, t_list **stack_b);
char				*ft_rotate_ab(t_list **stack_a, t_list **stack_b);
char				*ft_rev_rotate_a(t_list **stack_a, t_list **stack_b);
char				*ft_rev_rotate_b(t_list **stack_a, t_list **stack_b);
char				*ft_rev_rotate_ab(t_list **stack_a, t_list **stack_b);
void				ft_free_int_ptr(void *content, size_t size);

void				ft_quick_sort(t_stacks *stacks, t_list *start, t_list *end);
t_struct			*ft_process_partition_a(t_stacks *stacks, t_struct *data);
t_struct			*ft_process_rev_rot_a(t_stacks *stacks, t_struct *data);
t_struct			*ft_process_partition_b(t_stacks *stacks, t_struct *data);
t_struct			*ft_process_rev_rot_b(t_stacks *stacks, t_struct *data);
t_struct			*ft_find_median(t_struct *data);
t_list				*ft_reduce_size_a(t_list *s_a, t_struct *data);
void				ft_reduce_size_b(t_stacks *stacks, t_struct *data);
int					ft_2_elem_a(t_stacks *stacks, t_list *end);
int					ft_2_elem_b(t_stacks *stacks, t_list *end);
t_struct			*ft_chose_pivot(t_struct *data);
void				ft_kompressor(t_stacks *stacks);
int					ft_opti_3_a(t_stacks *stacks, t_struct *data);
int					ft_opti_3_b(t_stacks *stacks, t_struct *data);

void				ft_inst_swap_a(t_stacks *stacks);
void				ft_inst_swap_b(t_stacks *stacks);
void				ft_inst_push_a(t_stacks *stacks);
void				ft_inst_push_b(t_stacks *stacks);
void				ft_inst_rot_a(t_stacks *stacks);
void				ft_inst_rot_b(t_stacks *stacks);
void				ft_inst_rev_rot_a(t_stacks *stacks);
void				ft_inst_rev_rot_b(t_stacks *stacks);

int					ft_store_instructions(t_list **instructions);
void				ft_free_int_ptr(void *content, size_t size);
void				ft_classic_checker(t_stacks *stacks, int argc, char **argv);
void				ft_visual_checker(t_stacks *stacks, int argc, char **argv);
void				ft_init_rects(t_visu *visu, t_rect **rects, t_list *s_a);
void				ft_rects_success(t_visu *visu, t_rect **rects);
void				ft_init_fptr(t_fptr *instruct);
void				ft_del_fptr(t_fptr *instruct);
void				ft_put_rects(
						t_visu *visu, t_rect *rects, t_rev_tab rev_tab);
void				ft_put_rects_inv(
						t_visu *visu, t_rect *rects, t_rev_tab rev_tab);
void				ft_put_rects_inv2(
						t_visu *visu, t_rect *rects, t_rev_tab rev_tab);
void				ft_put_rects_s1(
						t_visu *visu, t_rect *rects, t_rev_tab rev_tab);
void				ft_put_rects_s2(
						t_visu *visu, t_rect *rects, t_rev_tab rev_tab);
void				ft_clear(t_visu *visu);
void				ft_clear_fail_1(t_visu *visu);
void				ft_clear_fail_2(t_visu *visu);
void				ft_clear_success_1(t_visu *visu);
void				ft_clear_success_2(t_visu *visu);
void				ft_create_tabs(
						t_list *s_a, t_list *s_b, t_rev_tab *rev_tab);
void				ft_free_tabs(t_rev_tab *rev_tab);
void				ft_sdl_initialize(
						t_visu *visu, t_rect **rects, t_stacks *stacks);
void				ft_sdl_end(t_visu *visu);
void				ft_failure(
						t_list *s_a, t_list *s_b, t_rect *rects, t_visu *visu);
void				ft_success(
						t_list *s_a, t_list *s_b, t_rect *rects, t_visu *visu);
int					ft_process_visual_sort(
						t_stacks stacks, t_rect *rects, t_visu *visu);

#endif
