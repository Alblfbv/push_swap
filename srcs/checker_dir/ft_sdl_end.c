/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:32:41 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/05 14:52:33 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_failure(t_list *s_a, t_list *s_b, t_rect *rects, t_visu *visu)
{
	t_rev_tab	rev_tab;
	int			run;

	run = 1;
	ft_create_tabs(s_a, s_b, &rev_tab);
	while (run)
	{
		while (SDL_PollEvent(&(visu->event)))
		{
			if (visu->event.type == SDL_KEYDOWN &&
				visu->event.key.keysym.sym == SDLK_ESCAPE)
				run = 0;
		}
		ft_clear_fail_1(visu);
		ft_put_rects_inv(visu, rects, rev_tab);
		SDL_RenderPresent(visu->renderer);
		SDL_Delay(600);
		ft_clear_fail_2(visu);
		ft_put_rects_inv2(visu, rects, rev_tab);
		SDL_RenderPresent(visu->renderer);
		SDL_Delay(600);
	}
	ft_free_tabs(&rev_tab);
}

void	ft_success(t_list *s_a, t_list *s_b, t_rect *rects, t_visu *visu)
{
	t_rev_tab	rev_tab;
	int			run;

	ft_rects_success(visu, &rects);
	run = 1;
	ft_create_tabs(s_a, s_b, &rev_tab);
	while (run)
	{
		while (SDL_PollEvent(&(visu->event)))
		{
			if (visu->event.type == SDL_KEYDOWN &&
				visu->event.key.keysym.sym == SDLK_ESCAPE)
				run = 0;
		}
		ft_clear_success_1(visu);
		ft_put_rects_s1(visu, rects, rev_tab);
		SDL_RenderPresent(visu->renderer);
		SDL_Delay(600);
		ft_clear_success_2(visu);
		ft_put_rects_s2(visu, rects, rev_tab);
		SDL_RenderPresent(visu->renderer);
		SDL_Delay(600);
	}
	ft_free_tabs(&rev_tab);
}
