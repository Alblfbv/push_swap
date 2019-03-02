/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visualize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:54:45 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/02 19:07:53 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TEST
#include "time.h"

static void	ft_is_sorted(t_list *stack_a, t_list *stack_b)
{
	if (stack_b != NULL)
		return ;
	while (stack_a->next->next != NULL)
	{
		if (*(int*)stack_a->content > *(int*)stack_a->next->content)
		{
			return ;
		}
		stack_a = stack_a->next;
	}
}

void	ft_clear(t_visu *visu)
{
	SDL_SetRenderDrawColor(visu->renderer, 37, 53, 79, 255);
	SDL_RenderClear(visu->renderer);
	SDL_SetRenderDrawColor(visu->renderer, 97, 126, 158, 255);
	SDL_RenderFillRect(visu->renderer, &(visu->back_2));
}

void		ft_put_rects(t_visu *visu, t_rect *rects, t_rev_tab rev_tab)
{
	int	i;
	int	j;
	int	rest;

	j = 0;
	rest = 0;
	while (rev_tab.size_a)
	{
		i = 0;
		while (rects[i].nb != rev_tab.a[j])
		{
			i++;
		}
		rest = rest + rects[i].rectangle.h;
		rects[i].rectangle.x = visu->win_w / 4 - rects[i].rectangle.w / 2;
		rects[i].rectangle.y = visu->win_h - rest;
		if (rects[i].nb > 0)
			SDL_SetRenderDrawColor(visu->renderer, 166, 119, 81, 255);
		else if (rects[i].nb < 0)
			SDL_SetRenderDrawColor(visu->renderer, 47, 128, 235, 255);
		else
			SDL_SetRenderDrawColor(visu->renderer, 245, 53, 72, 255);
		SDL_RenderFillRect(visu->renderer, &(rects[i].rectangle));
		j++;
		(rev_tab.size_a)--;
	}
	j = 0;
	rest = 0;
	while (rev_tab.size_b)
	{
		i = 0;
		while (rects[i].nb != rev_tab.b[j])
		{
			i++;
		}
		rest = rest + rects[i].rectangle.h;
		rects[i].rectangle.x = (visu->win_w / 2) + (visu->win_w / 4 - rects[i].rectangle.w / 2);
		rects[i].rectangle.y = visu->win_h - rest;
		if (rects[i].nb > 0)
			SDL_SetRenderDrawColor(visu->renderer, 92, 71, 51, 255);
		else if (rects[i].nb < 0)
			SDL_SetRenderDrawColor(visu->renderer, 0, 245, 120, 255);
		else
			SDL_SetRenderDrawColor(visu->renderer, 200, 120, 120, 255);
		SDL_RenderFillRect(visu->renderer, &(rects[i].rectangle));
		j++;
		(rev_tab.size_b)--;
	}

}

void		ft_create_tabs(t_list *s_a, t_list *s_b, t_rev_tab *rev_tab)
{
	int	size_a;
	int	size_b;

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

static void	ft_process_sort(t_stacks stacks, t_rect *rects, t_visu *visu)
{
	t_fptr		instruct;
	t_rev_tab	rev_tab;
	int			i;

	ft_init_fptr(&instruct);
	while (*stacks.instruct)
	{
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
	int				running;

	running = 1;
	while (running)
	{
		while (SDL_PollEvent(&(visu->event)))
		{
			if (visu->event.type == SDL_KEYDOWN &&
				visu->event.key.keysym.sym == SDLK_ESCAPE)
				running = 0;
		ft_process_sort(stacks, *rects, visu);
		ft_is_sorted(*stacks.s_a, *stacks.s_b);
		}
	}
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
		ft_printf("Error\n");
		return ;
	}
	ft_sdl_initialize(&visu, &rects, stacks);
	ft_visualizer_main_loop(&visu, &rects, *stacks);
	ft_sdl_end(&visu);
}
