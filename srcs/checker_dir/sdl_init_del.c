/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:20:20 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/19 18:44:13 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_tabs(t_list *s_a, t_list *s_b, t_rev_tab *rev_tab)
{
	int	size_a;
	int	size_b;

	rev_tab->size_a = ft_lst_size(s_a);
	rev_tab->size_b = ft_lst_size(s_b);
	if (!(rev_tab->a = (int*)malloc(sizeof(int) * rev_tab->size_a)))
		exit(1);
	if (!(rev_tab->b = (int*)malloc(sizeof(int) * rev_tab->size_b)))
		exit(1);
	size_a = rev_tab->size_a;
	size_b = rev_tab->size_b;
	while (s_a)
	{
		rev_tab->a[size_a - 1] = *(int*)s_a->content;
		s_a = s_a->next;
		size_a--;
	}
	while (s_b)
	{
		rev_tab->b[size_b - 1] = *(int*)s_b->content;
		s_b = s_b->next;
		size_b--;
	}
}

void	ft_free_tabs(t_rev_tab *rev_tab)
{
	free(rev_tab->a);
	free(rev_tab->b);
}

void	ft_sdl_initialize(t_visu *visu, t_rect **rects, t_stacks *stacks)
{
	visu->size_list = ft_lst_size(*stacks->s_a);
	if (!(*rects = (t_rect*)malloc(sizeof(t_rect) * visu->size_list)))
		exit(1);
	SDL_Init(SDL_INIT_VIDEO);
	visu->window = SDL_CreateWindow("push_swap",
					SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
					0, 0, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP);
	visu->renderer = SDL_CreateRenderer(visu->window, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_GetWindowSize(visu->window, &(visu->win_w), &(visu->win_h));
	visu->back_2.x = visu->win_w / 2;
	visu->back_2.y = 0;
	visu->back_2.w = visu->win_w / 2;
	visu->back_2.h = visu->win_h;
	ft_init_rects(visu, rects, *stacks->s_a);
}

void	ft_sdl_end(t_visu *visu)
{
	SDL_DestroyRenderer(visu->renderer);
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
	SDL_DestroyWindow(visu->window);
	SDL_Quit();
}
