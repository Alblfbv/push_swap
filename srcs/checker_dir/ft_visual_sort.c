/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:42:07 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/07 12:37:48 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sdl_event(t_visu *visu)
{
	while (SDL_PollEvent(&(visu->event)))
	{
		if (visu->event.type == SDL_KEYDOWN
			&& visu->event.key.keysym.sym == SDLK_ESCAPE)
			return (0);
		if (visu->event.type == SDL_KEYDOWN
			&& visu->event.key.keysym.sym == SDLK_SPACE)
			SDL_Delay(4000);
	}
	return (1);
}

static void	ft_display(t_stacks stcks, t_rect *rec, t_visu *vis, t_rev_tab *rev)
{
	ft_create_tabs(*stcks.s_a, *stcks.s_b, rev);
	ft_clear(vis);
	ft_put_rects(vis, rec, *rev);
	SDL_RenderPresent(vis->renderer);
}

static void	ft_process_instruct(t_fptr instruct, t_stacks stacks)
{
	int	i;

	i = 0;
	while (i < INSTRUCT)
	{
		if (ft_strequ(instruct.type[i],
			(char*)((*stacks.instruct)->content)))
			instruct.fptr[i](stacks.s_a, stacks.s_b);
		i++;
	}
}

int			ft_process_visual_sort(t_stacks stacks, t_rect *rects, t_visu *visu)
{
	t_fptr		instruct;
	t_rev_tab	rev_tab;

	ft_init_fptr(&instruct);
	SDL_Delay(500);
	while (*stacks.instruct)
	{
		if (!ft_sdl_event(visu))
		{
			ft_del_fptr(&instruct);
			return (0);
		}
		if (visu->size_list <= 250)
			SDL_Delay(5000 / visu->size_list);
		ft_display(stacks, rects, visu, &rev_tab);
		ft_process_instruct(instruct, stacks);
		*stacks.instruct = (*stacks.instruct)->next;
		ft_free_tabs(&rev_tab);
	}
	ft_display(stacks, rects, visu, &rev_tab);
	ft_del_fptr(&instruct);
	ft_free_tabs(&rev_tab);
	return (1);
}
