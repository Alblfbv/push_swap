/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 19:26:15 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/02 19:07:50 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_round(float nb)
{
	if (nb - (int)nb > 0.5)
		return ((int)nb);
	return ((int)nb + 1);
}

void	ft_rect_h(t_visu *visu)
{
	visu->nb_small_px = visu->size_list;
	visu->nb_large_px = 0;
	visu->small_px = visu->win_h / visu->size_list;
	visu->large_px = visu->small_px + 1;
	while (visu->small_px * visu->nb_small_px + visu->large_px * visu->nb_large_px != visu->win_h)
	{
		visu->nb_small_px--;
		visu->nb_large_px++;
	}
}

void	ft_init_rects(t_visu *visu, t_rect **rects, t_list *s_a)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = s_a;
	visu->max_list = *(int*)tmp->content;
	ft_rect_h(visu);
	while (tmp->next != NULL)
	{
		if (*(int*)tmp->content > visu->max_list)
			visu->max_list = *(int*)tmp->content;
		tmp = tmp->next;
	}
	while (s_a)
	{
		(*rects + i)->nb = *(int*)s_a->content;
		if (visu->nb_small_px)
		{
			(*rects + i)->rectangle.h = visu->small_px;
			visu->nb_small_px--;
		}
		else if (!visu->nb_small_px && visu->nb_large_px)
		{
			(*rects + i)->rectangle.h = visu->large_px;
			visu->nb_large_px--;
		}
		if ((*rects + i)->nb < 0)
			(*rects + i)->rectangle.w = ((*rects + i)->nb * -1) * (visu->win_w / 2) / visu->max_list;
		else if ((*rects + i)->nb > 0)
			(*rects + i)->rectangle.w = (*rects + i)->nb * (visu->win_w / 2) / visu->max_list;
		else
			(*rects + i)->rectangle.w = 1 * (visu->win_w / 2) / visu->max_list / 2;
		s_a = s_a->next;
		i++;
	}
}
