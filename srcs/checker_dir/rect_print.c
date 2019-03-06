/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:45:06 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/06 14:07:57 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_put_lst_a(t_visu *visu, t_rect *rects, t_rev_tab rev_t, int rest)
{
	int	i;
	int	j;

	j = 0;
	while (rev_t.size_a)
	{
		i = 0;
		while (rects[i].nb != rev_t.a[j])
		{
			i++;
		}
		rest = rest + rects[i].rect.h;
		rects[i].rect.x = visu->win_w / 4 - rects[i].rect.w / 2;
		rects[i].rect.y = visu->win_h - rest;
		if (rects[i].nb > 0)
			SDL_SetRenderDrawColor(visu->renderer, 164, 188, 196, 255);
		else if (rects[i].nb < 0)
			SDL_SetRenderDrawColor(visu->renderer, 10, 148, 207, 255);
		else
			SDL_SetRenderDrawColor(visu->renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(visu->renderer, &(rects[i].rect));
		j++;
		(rev_t.size_a)--;
	}
}

static void	ft_put_lst_b(t_visu *visu, t_rect *rects, t_rev_tab rev_t, int rest)
{
	int	i;
	int	j;

	j = 0;
	while (rev_t.size_b)
	{
		i = 0;
		while (rects[i].nb != rev_t.b[j])
		{
			i++;
		}
		rest = rest + rects[i].rect.h;
		rects[i].rect.x = (visu->win_w / 2) +
							(visu->win_w / 4 - rects[i].rect.w / 2);
		rects[i].rect.y = visu->win_h - rest;
		if (rects[i].nb > 0)
			SDL_SetRenderDrawColor(visu->renderer, 161, 153, 150, 255);
		else if (rects[i].nb < 0)
			SDL_SetRenderDrawColor(visu->renderer, 232, 109, 43, 255);
		else
			SDL_SetRenderDrawColor(visu->renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(visu->renderer, &(rects[i].rect));
		j++;
		(rev_t.size_b)--;
	}
}

void		ft_put_rects(t_visu *visu, t_rect *rects, t_rev_tab rev_tab)
{
	int	rest;

	rest = 0;
	ft_put_lst_a(visu, rects, rev_tab, rest);
	rest = 0;
	ft_put_lst_b(visu, rects, rev_tab, rest);
}
