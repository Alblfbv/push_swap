/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visualize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:54:45 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/05 12:01:19 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear(t_visu *visu)
{
	SDL_SetRenderDrawColor(visu->renderer, 8, 30, 40, 255);
	SDL_RenderClear(visu->renderer);
	SDL_SetRenderDrawColor(visu->renderer, 40, 5, 5, 255);
	SDL_RenderFillRect(visu->renderer, &(visu->back_2));
}

void	ft_clear_inv(t_visu *visu)
{
	SDL_SetRenderDrawColor(visu->renderer, 0, 0, 0, 255);
	SDL_RenderClear(visu->renderer);
	SDL_SetRenderDrawColor(visu->renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(visu->renderer, &(visu->back_2));
}

void	ft_clear_inv2(t_visu *visu)
{
	SDL_SetRenderDrawColor(visu->renderer, 255, 255, 255, 255);
	SDL_RenderClear(visu->renderer);
	SDL_SetRenderDrawColor(visu->renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(visu->renderer, &(visu->back_2));
}

void	ft_clear_end1(t_visu *visu)
{
	SDL_SetRenderDrawColor(visu->renderer, 8, 30, 40, 255);
	SDL_RenderClear(visu->renderer);
}

void	ft_clear_end2(t_visu *visu)
{
	SDL_SetRenderDrawColor(visu->renderer, 40, 5, 5, 255);
	SDL_RenderClear(visu->renderer);
}


void		ft_create_tabs(t_list *s_a, t_list *s_b, t_rev_tab *rev_tab)
{
	int	size_a;
	int	size_b;

	ft_printf("%d\n", ft_lst_size(s_a));
	rev_tab->size_a = ft_lst_size(s_a);
	rev_tab->size_b = ft_lst_size(s_b);
	rev_tab->a = (int*)malloc(sizeof(int) * rev_tab->size_a);
	rev_tab->b = (int*)malloc(sizeof(int) * rev_tab->size_b);
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

static void	ft_failure(t_list *stack_a, t_list *stack_b, t_rect *rects, t_visu *visu)
{
	t_rev_tab 	rev_tab;
	int			run;

	run = 1;
	ft_create_tabs(stack_a, stack_b, &rev_tab);
	while (run)
	{
		while (SDL_PollEvent(&(visu->event)))
		{
			if (visu->event.type == SDL_KEYDOWN &&
				visu->event.key.keysym.sym == SDLK_ESCAPE)
				run = 0;
		}
		ft_clear_inv(visu);
		ft_put_rects_inv(visu, rects, rev_tab);
		SDL_RenderPresent(visu->renderer);
		SDL_Delay(600);
		ft_clear_inv2(visu);
		ft_put_rects_inv2(visu, rects, rev_tab);
		SDL_RenderPresent(visu->renderer);
		SDL_Delay(600);
	}
}

static void	ft_success(t_list *stack_a, t_list *stack_b, t_rect *rects, t_visu *visu)
{
	t_rev_tab 	rev_tab;
	int			run;

	ft_rects_success(visu, &rects);
	run = 1;
	ft_create_tabs(stack_a, stack_b, &rev_tab);
	while (run)
	{
		while (SDL_PollEvent(&(visu->event)))
		{
			if (visu->event.type == SDL_KEYDOWN &&
				visu->event.key.keysym.sym == SDLK_ESCAPE)
				run = 0;
		}
		ft_clear_end1(visu);
		ft_put_rects_s1(visu, rects, rev_tab);
		SDL_RenderPresent(visu->renderer);
		SDL_Delay(600);
		ft_clear_end2(visu);
		ft_put_rects_s2(visu, rects, rev_tab);
		SDL_RenderPresent(visu->renderer);
		SDL_Delay(600);
	}
}

static void	ft_is_sorted(t_list *stack_a, t_list *stack_b, t_rect *rects, t_visu *visu)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = stack_a;
	tmp_b = stack_b;

	if (tmp_b != NULL)
	{
		ft_failure(stack_a, stack_b, rects, visu);
		return ;
	}
	while (tmp_a->next->next != NULL)
	{
		if (*(int*)tmp_a->content > *(int*)tmp_a->next->content)
		{
			ft_failure(stack_a, stack_b, rects, visu);
			return ;
		}
		tmp_a = tmp_a->next;
	}
	ft_success(stack_a, stack_b, rects, visu);
}

static int	ft_process_sort(t_stacks stacks, t_rect *rects, t_visu *visu)
{
	t_fptr		instruct;
	t_rev_tab	rev_tab;
	int			i;

	ft_init_fptr(&instruct);
	SDL_Delay(700);
	while (*stacks.instruct)
	{
		if (visu->size_list < 250)
			SDL_Delay(50);
		while (SDL_PollEvent(&(visu->event)))
		{
			if (visu->event.type == SDL_KEYDOWN &&
				visu->event.key.keysym.sym == SDLK_ESCAPE)
				return(0);
			if (visu->event.type == SDL_KEYDOWN &&
				visu->event.key.keysym.sym == SDLK_SPACE)
				SDL_Delay(4000);
		}
		i = 0;
		ft_create_tabs(*stacks.s_a, *stacks.s_b, &rev_tab);
		ft_clear(visu);
		ft_put_rects(visu, rects, rev_tab);
		SDL_RenderPresent(visu->renderer);
		while (i < INSTRUCT)
		{
			if (ft_strequ(instruct.type[i], (char*)((*stacks.instruct)->content)))
				instruct.fptr[i](stacks.s_a, stacks.s_b);
			i++;
		}
		*stacks.instruct = (*stacks.instruct)->next;
	}
	ft_create_tabs(*stacks.s_a, *stacks.s_b, &rev_tab);
	ft_clear(visu);
	ft_put_rects(visu, rects, rev_tab);
	SDL_RenderPresent(visu->renderer);
	ft_del_fptr(&instruct);
	return (1);
}

void	ft_sdl_initialize(t_visu *visu, t_rect **rects, t_stacks *stacks)
{
	visu->size_list = ft_lst_size(*stacks->s_a);
	*rects = (t_rect*)malloc(sizeof(t_rect) * visu->size_list);
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

void	ft_visualizer_main_loop(t_visu *visu, t_rect **rects, t_stacks stacks)
{
		if (!ft_process_sort(stacks, *rects, visu))
			return ;
		ft_is_sorted(*stacks.s_a, *stacks.s_b, *rects, visu);
}

void	ft_sdl_end(t_visu *visu)
{
	SDL_DestroyRenderer(visu->renderer);
	SDL_DestroyWindow(visu->window);
	SDL_Quit();
}

void	ft_visual_checker(t_stacks *stacks, int argc, char **argv)
{
	t_visu	visu;
	t_rect	*rects;

	if (!(ft_store_instructions(stacks->instruct)) ||
		ft_stack_create(stacks->s_a, argv + 2, argc -2) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	ft_sdl_initialize(&visu, &rects, stacks);
	ft_visualizer_main_loop(&visu, &rects, *stacks);
	ft_sdl_end(&visu);
}
