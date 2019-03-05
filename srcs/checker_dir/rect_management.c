/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 19:26:15 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/05 12:04:23 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rect_h(t_visu *visu)
{
	visu->nb_small_px = visu->size_list;
	visu->nb_large_px = 0;
	visu->small_px = visu->win_h / visu->size_list;
	visu->large_px = visu->small_px + 1;
	while (visu->small_px * visu->nb_small_px +
			visu->large_px * visu->nb_large_px != visu->win_h)
	{
		visu->nb_small_px--;
		visu->nb_large_px++;
	}
}

void	ft_visu_max(t_visu *visu, t_list *s_a)
{
	visu->max_list = *(int*)s_a->content;
	while (s_a != NULL)
	{
		if (*(int*)s_a->content > visu->max_list)
			visu->max_list = *(int*)s_a->content;
		if ((*(int*)s_a->content) * -1 > visu->max_list)
			visu->max_list = (*(int*)s_a->content * -1);
		s_a = s_a->next;
	}
}

void	ft_rect_whnb(t_visu *visu, t_rect **rects, t_list *s_a, int i)
{
	while (s_a)
	{
		(*rects + i)->nb = *(int*)s_a->content;
		if (visu->nb_small_px)
		{
			(*rects + i)->rect.h = visu->small_px;
			visu->nb_small_px--;
		}
		else if (!visu->nb_small_px && visu->nb_large_px)
		{
			(*rects + i)->rect.h = visu->large_px;
			visu->nb_large_px--;
		}
		if ((*rects + i)->nb < 0)
			(*rects + i)->rect.w = ((*rects + i)->nb * -1) *
									(visu->win_w / 2) / visu->max_list;
		else if ((*rects + i)->nb > 0)
			(*rects + i)->rect.w = (*rects + i)->nb *
									(visu->win_w / 2) / visu->max_list;
		else
			(*rects + i)->rect.w = visu->win_w / 2 / visu->max_list / 2;
		s_a = s_a->next;
		i++;
	}
}

void	ft_init_rects(t_visu *visu, t_rect **rects, t_list *s_a)
{
	int		i;

	i = 0;
	ft_rect_h(visu);
	ft_visu_max(visu, s_a);
	ft_rect_whnb(visu, rects, s_a, i);
}

void	ft_rects_success(t_visu *visu, t_rect **rects)
{
	int		i;

	i = 0;
	while (i < visu->size_list)
	{
		(*rects + i)->rect.w = (*rects + i)->rect.w * 2;
		i++;
	}
}
