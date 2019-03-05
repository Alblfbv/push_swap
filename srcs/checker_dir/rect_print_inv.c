/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_print_inv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:11:53 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/05 12:02:38 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_put_a(t_visu *visu, t_rect *rects, t_rev_tab rev_tab, int rest)
{
	int	i;
	int	j;

	j = 0;
	while (rev_tab.size_a)
	{
		i = 0;
		while (rects[i].nb != rev_tab.a[j])
		{
			i++;
		}
		rest = rest + rects[i].rect.h;
		rects[i].rect.x = visu->win_w / 4 - rects[i].rect.w / 2;
		rects[i].rect.y = visu->win_h - rest;
		SDL_SetRenderDrawColor(visu->renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(visu->renderer, &(rects[i].rect));
		j++;
		(rev_tab.size_a)--;
	}
}

static void	ft_put_b(t_visu *visu, t_rect *rects, t_rev_tab rev_tab, int rest)
{
	int	i;
	int	j;

	j = 0;
	while (rev_tab.size_b)
	{
		i = 0;
		while (rects[i].nb != rev_tab.b[j])
		{
			i++;
		}
		rest = rest + rects[i].rect.h;
		rects[i].rect.x = (visu->win_w / 2) +
							(visu->win_w / 4 - rects[i].rect.w / 2);
		rects[i].rect.y = visu->win_h - rest;
		SDL_SetRenderDrawColor(visu->renderer, 0, 0, 0, 255);
		SDL_RenderFillRect(visu->renderer, &(rects[i].rect));
		j++;
		(rev_tab.size_b)--;
	}
}

void		ft_put_rects_inv(t_visu *visu, t_rect *rects, t_rev_tab rev_tab)
{
	int	rest;

	rest = 0;
	ft_put_a(visu, rects, rev_tab, rest);
	rest = 0;
	ft_put_b(visu, rects, rev_tab, rest);
}
